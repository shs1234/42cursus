let activeWebSocket = null;
let activeEventListeners = [];
// only used in games
keys = {};

function manageWebSocket(url) {
    if (activeWebSocket) {
        console.log('Closing previous WebSocket connection');
        activeWebSocket.close();
        activeWebSocket = null;
    }

    console.log(`Setting up new WebSocket connection to ${url}`);
    const newSocket = new WebSocket(url);

    newSocket.onopen = function(e) {
        console.log('WebSocket connection established');
    };

    newSocket.onclose = function(event) {
        if (event.wasClean) {
            console.log(`Connection closed cleanly, code=${event.code} reason=${event.reason}`);
        } else {
            console.log('Connection died');
        }
        activeWebSocket = null;
    };

    newSocket.onerror = function(error) {
        console.log(`WebSocket error: ${error.message}`);
    };

    activeWebSocket = newSocket;
    return newSocket;
}

document.addEventListener("DOMContentLoaded", function() {
    let path = window.location.pathname.split('/');
    let page = path[1] || 'main';
    let id = path[2];  // For game or other pages that might need an ID

    switch (page) {
        case 'local-2p':
            load2PlayerGameContent(true);
            break;
        case 'local-4p':
            load4PlayerGameContent(true);
            break;
        case 'login':
            loadLoginScreen(true);
            break;
        case 'auth':
            loadAuthScreen(true);
            break;
        case 'list':
            loadListContent(true);
            break;
        case 'gamelist':
            loadGameListContent(true);
            break;
        case 'game':
            if (id) {
                loadGameContent(true, id);
            } else {
                loadMainContent(true);  // Fallback if no game ID is provided
            }
			break;
		case 'chat':
            if (id) {
                loadChatRoom(id, "Joined Room", false);
            } else {
                loadMainContent(true);
            }
            break;
        default:
            loadMainContent(true);
    }

    history.replaceState({ page: page, id: id }, '', window.location.pathname);

    document.querySelector('.navbar-brand').addEventListener('click', function(event) {
        event.preventDefault();
        loadMainContent(true);
    });

	window.addEventListener('popstate', function(event) {
		if (event.state) {
			switch (event.state.page) {
                case 'local-2p':
                    load2PlayerGameContent(false);
                    break;
                case 'local-4p':
                    load4PlayerGameContent(false);
                    break;
				case 'login':
					loadLoginScreen(false);
					break;
				case 'auth':
					loadAuthScreen(false);
					break;
				case 'list':
					loadListContent(false);
					break;
				case 'gamelist':
					loadGameListContent(false);
					break;
				case 'game':
					if (event.state.id) {
						loadGameContent(false, event.state.id);
					} else {
						loadMainContent(false);
					}
					break;
				case 'chatroom':
					if (event.state.id) {
						loadChatRoom(event.state.id, "Joined Room", false);
					} else {
						loadMainContent(false);
					}
					break;
				default:
					loadMainContent(false);
			}
		} else {
			loadMainContent(false);
		}
	});
});

function loadMainContent(updateHistory) {
	if (activeWebSocket) {
		activeWebSocket.close();
		activeWebSocket = null;
	}
    if (updateHistory) {
        history.pushState({ page: 'main' }, '', '/main/');
    }
    fetch("/main-content/")
        .then(response => response.text())
        .then(html => {
            document.getElementById('dynamic-content').innerHTML = html;
            attachPlayGameButtonListener();
        })
        .catch(error => {
            console.error('Error loading main content:', error);
        });
}

function loadLoginScreen(updateHistory) {
	if (activeWebSocket) {
		activeWebSocket.close();
		activeWebSocket = null;
	}
    if (updateHistory) {
        history.pushState({ page: 'login' }, '', '/login/');
    }
    fetch("/login-content/")
        .then(response => response.text())
        .then(html => {
            document.getElementById('dynamic-content').innerHTML = html;
        })
        .catch(error => {
            console.error('Error loading login content:', error);
        });
}

function loadAuthScreen(updateHistory) {
    const params = new URLSearchParams(window.location.search);
    const code = params.get('code');

    if (updateHistory) {
        history.pushState({ page: 'auth', code: code }, '', `/auth/?code=${code}`);
    }

    fetch(`https://localhost/api/oauth/callback42?code=${code}`, {
        method: 'GET',
        headers: {
            'Accept': 'application/json',
            'X-CSRFToken': getCSRFToken()
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.email) {
            document.getElementById('dynamic-content').innerHTML = `
                <div class="alert alert-success" role="alert">Email received: ${data.email}</div>
                <div class="mb-3">
                    <input type="text" id="verification-code" class="form-control" placeholder="Enter your 6-digit code" maxlength="6" />
                    <button onclick="submitVerificationCode('${data.email}');" class="btn btn-primary mt-2">Verify</button>
                </div>
            `;
        } else {
            showBootstrapAlert("Failed to retrieve email.");
            window.history.back();
        }
    })
    .catch(error => {
        console.error('Error fetching email:', error);
        showBootstrapAlert("Error fetching email. Please try again.");
        window.history.back();
    });
}

function loadListContent(updateHistory) {
	if (activeWebSocket) {
		activeWebSocket.close();
		activeWebSocket = null;
	}
    if (!isUserInfoStored()) {
        window.location.href = '/login/';
        return;
    }

    if (updateHistory) {
        history.pushState({ page: 'list' }, '', '/list/');
    }

    Promise.all([updateUserProfile(), getFriendsList()])
        .then(([_, friendsList]) => {
            displayUserProfile();
            displayFriendsList(friendsList);
        })
        .catch(error => {
            console.error('Error loading content:', error);
            showBootstrapAlert("Error loading content. Please try again.");
        });
}

function loadGameListContent(updateHistory) {
	if (activeWebSocket) {
		activeWebSocket.close();
		activeWebSocket = null;
	}
    if (!isUserInfoStored()) {
        window.location.href = '/login/';
        return;
    }

    if (updateHistory) {
        history.pushState({ page: 'gamelist' }, '', '/gamelist/');
    }

    const apiURL = "https://localhost/api/room/";
    const headers = {
        "Accept": "application/json",
        "X-CSRFToken": getCSRFToken(),
        "Authorization": `Bearer ${localStorage.getItem('jwt_token')}`
    };

    fetch(apiURL, { method: 'GET', headers: headers })
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            displayGameList(data);
        })
        .catch(error => {
            console.error('Error loading game list:', error);
            showBootstrapAlert("Failed to load game list. Please try again.");
        });
}

function displayGameList(rooms) {
    const listContainer = document.getElementById('dynamic-content');
    listContainer.innerHTML = `
        <div class="container mt-4">
            <h3 class="mb-4">Game Rooms</h3>
            <div class="row mb-3">
                <div class="col">
                    <button class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#createRoomModal">Create Room</button>
                </div>
                <div class="col text-end">
                    <button class="btn btn-secondary" onclick="loadGameListContent(false)">Refresh List</button>
                </div>
            </div>
            <div class="list-group">
                ${rooms.map(room => `
                    <div class="list-group-item list-group-item-action d-flex justify-content-between align-items-center">
                        <div>
                            <h5 class="mb-1">${room.title}</h5>
                            <small>Participants: ${room.current_participants}/${room.max_participants}</small>
                        </div>
                        <button class="btn btn-primary btn-sm" ${(room.isPlaying || room.current_participants >= room.max_participants) ? 'disabled' : ''} onclick="joinRoom(${room.id})">Join</button>
                    </div>
                `).join('')}
            </div>
        </div>

        <!-- Create Room Modal -->
        <div class="modal fade" id="createRoomModal" tabindex="-1" aria-labelledby="createRoomModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="createRoomModalLabel">Create New Room</h5>
                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                        <form id="createRoomForm">
                            <div class="mb-3">
                                <label for="roomTitle" class="form-label">Room Title</label>
                                <input type="text" class="form-control" id="roomTitle" maxlength="20" required>
                            </div>
                            <div class="mb-3">
                                <label class="form-label">Max Participants</label>
                                <input type="hidden" id="maxParticipants" name="maxParticipants" value="2"> <!-- Default value -->
                                <div class="d-grid gap-2">
                                    <button class="btn btn-outline-primary participant-button" type="button" data-number="2" onclick="setMaxParticipants(2)">2</button>
                                    <button class="btn btn-outline-primary participant-button" type="button" data-number="4" onclick="setMaxParticipants(4)">4</button>
                                </div>
                            </div>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                        <button type="button" class="btn btn-primary" onclick="createRoom()">Create Room</button>
                    </div>
                </div>
            </div>
        </div>

        <style>
            .participant-button.active {
                background-color: #007bff; /* Bootstrap primary color */
                color: white;
            }
        </style>
    `;
}

function createRoom() {
    const title = document.getElementById('roomTitle').value;
    const maxParticipants = document.getElementById('maxParticipants').value;

    if (!title || title.length > 20) {
        showBootstrapAlert("Room title must be between 1 and 20 characters.", "danger");
        return;
    }

    const data = {
        title: title,
        max_participants: parseInt(maxParticipants)
    };

    fetch('https://localhost/api/room/create/', {
        method: 'POST',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json',
            'X-CSRFToken': getCSRFToken(),
            'Authorization': `Bearer ${localStorage.getItem('jwt_token')}`
        },
        body: JSON.stringify(data)
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
	.then(data => {
		console.log('Room created:', data);
		showBootstrapAlert("Room created successfully!", "success");
		bootstrap.Modal.getInstance(document.getElementById('createRoomModal')).hide();
		loadChatRoom(data.id, data.title, true);
	})
    .catch(error => {
        console.error('Error creating room:', error);
        showBootstrapAlert("Failed to create room. Please try again.", "danger");
    });
}

function loadChatRoom(roomId, roomName, updateHistory = true) {
    if (updateHistory) {
        history.pushState({ page: 'chatroom', id: roomId }, '', `/chat/${roomId}`);
    }

    const content = `
        <style>
            #chat-log, #chat-message-input, #chat-message-submit {
                display: none;
            }
            .room-card {
                border-radius: 15px;
                box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            }
            .participant-list {
                max-height: 300px;
                overflow-y: auto;
            }
            .btn-custom {
                border-radius: 20px;
                padding: 10px 20px;
                font-weight: bold;
            }
        </style>
        <div class="container mt-5">
            <div class="row justify-content-center">
                <div class="col-md-8">
                    <div class="card room-card">
                        <div class="card-header bg-primary text-white">
                            <h2 class="mb-0">Room: <span id="roomTitle">${roomName}</span></h2>
                        </div>
                        <div class="card-body">
                            <div class="row">
                                <div class="col-md-6">
                                    <div class="card mb-3">
                                        <div class="card-header bg-info text-white">
                                            Room Status
                                        </div>
                                        <div class="card-body">
                                            <p class="mb-1">Participants: <span id="currentParticipants" class="badge bg-secondary">0</span>/<span id="maxParticipants" class="badge bg-secondary">0</span></p>
                                            <p class="mb-0">Ready: <span id="readyParticipants" class="badge bg-success">0</span>/<span id="maxParticipantsReady" class="badge bg-success">0</span></p>
                                        </div>
                                    </div>
                                    <div class="card">
                                        <div class="card-header bg-info text-white">
                                            Participants
                                        </div>
                                        <div class="card-body participant-list">
                                            <ul id="participantsList" class="list-group list-group-flush"></ul>
                                        </div>
                                    </div>
                                </div>
                                <div class="col-md-6">
                                    <textarea id="chat-log" class="form-control mb-3" rows="10" readonly></textarea>
                                    <input id="chat-message-input" type="text" class="form-control mb-3" placeholder="Type your message...">
                                    <div class="d-grid gap-2">
                                        <button id="chat-message-submit" class="btn btn-primary btn-custom">Send</button>
                                        <button id="ready" class="btn btn-success btn-custom">Ready</button>
                                        <button id="start" class="btn btn-danger btn-custom">Start</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    `;

    document.getElementById('dynamic-content').innerHTML = content;

    setupWebSocket(roomId);
    setupChatEventListeners();
}

function setupWebSocket(roomId) {
    const url = `wss://localhost/ws/chat/${roomId}/?token=${localStorage.getItem('jwt_token')}`;
    const chatSocket = manageWebSocket(url);

    chatSocket.onmessage = function(e) {
        try {
            const data = JSON.parse(e.data);
            if (data.message) {
                const messageData = JSON.parse(data.message);
                if (messageData.action && messageData.room_data) {
                    console.log("Received room data:", messageData);
                    updateRoomUI(messageData.room_data);
                    updateParticipantsList(messageData.room_data.players);

                    // Update room title
                    if (messageData.action === 'join' && messageData.room_data.title) {
                        document.getElementById('roomTitle').textContent = messageData.room_data.title;
                    }

                    if (messageData.action === 'start') {
                        console.log("Game is starting:", messageData.text);
                        const sessionInfo = JSON.parse(messageData.room_data.session);
                        loadGameContent(true, roomId, sessionInfo);
                    }
                }
            }
            if (data.text) {
                document.querySelector('#chat-log').value += (data.text + '\n');
            }
        } catch (error) {
            console.error("Error parsing message:", error);
            if (typeof e.data === "string") {
                document.querySelector('#chat-log').value += (e.data + '\n');
            }
        }
    };

    chatSocket.onclose = function(e) {
        console.error('Chat socket closed unexpectedly');
    };

    window.chatSocket = chatSocket;
}

function updateParticipantsList(players) {
    const participantsList = document.getElementById('participantsList');
    if (participantsList) {
        participantsList.innerHTML = players.map(player => `
            <li class="list-group-item d-flex justify-content-between align-items-center">
                ${player}
                <span class="badge bg-primary rounded-pill">Player</span>
            </li>
        `).join('');
    }
}

function updateRoomUI(roomData) {
    if (roomData) {
        const { current_participants, ready_participants, max_participants } = roomData;
        document.getElementById('currentParticipants').textContent = current_participants;
        document.getElementById('readyParticipants').textContent = ready_participants;
        document.getElementById('maxParticipants').textContent = max_participants;
        document.getElementById('maxParticipantsReady').textContent = max_participants;
    }
    const readyButton = document.getElementById('ready');
    const startButton = document.getElementById('start');
    if (document.getElementById('readyParticipants').textContent == "0") {
        readyButton.disabled = false;
    }
    if (document.getElementById('readyParticipants').textContent < document.getElementById('maxParticipantsReady').textContent) {
        startButton.disabled = true;
    } else {
        startButton.disabled = false;   
    }
}



function setupChatEventListeners() {
    document.querySelector('#chat-message-input').focus();
    document.querySelector('#chat-message-input').onkeyup = function(e) {
        if (e.key === 'Enter') {
            document.querySelector('#chat-message-submit').click();
        }
    };

    document.querySelector('#chat-message-submit').onclick = function(e) {
        const messageInputDom = document.querySelector('#chat-message-input');
        const text = messageInputDom.value;
        console.log("Sending message:", text); // Log the message being sent
        window.chatSocket.send(JSON.stringify({
            "action": "message",
            'text': text
        }));
        messageInputDom.value = '';
    };

    // 수정된 부분: Ready 버튼의 초기 상태를 관리
    const readyButton = document.querySelector('#ready');
    readyButton.onclick = function(e) {
        if (!readyButton.disabled) {
            window.chatSocket.send(JSON.stringify({
                'action': 'ready'
            }));
            readyButton.disabled = true; // 버튼을 비활성화
        }
    };

	// Start의 버튼의 초기 상태를 disable
	const startButton = document.querySelector('#start');
	startButton.disabled = true;
	startButton.onclick = function(e) {
		if (!startButton.disabled) {
			window.chatSocket.send(JSON.stringify({
				'action': 'start'
			}));
			startButton.disabled = true; // 버튼을 비활성화
		}
	};
}


function joinRoom(roomId) {
    console.log(`Joining room with ID: ${roomId}`);
    loadChatRoom(roomId, "Joined Room", true);
}

function updateUserProfile() {
    const token = localStorage.getItem('jwt_token');
    if (!token) {
        return Promise.reject("No token found");
    }

    return fetch('https://localhost/api/accounts/profile/', {
        method: 'GET',
        headers: {
            'Accept': 'application/json',
            'Authorization': `Bearer ${token}`
        }
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => {
        localStorage.setItem('user_id', data.id);
        localStorage.setItem('username', data.username);
        localStorage.setItem('user_email', data.email);
        localStorage.setItem('avatar', data.avatar || '/static/images/not.PNG');
    })
    // .catch(error => {
    //     console.error('Error updating user profile:', error);
    //     showBootstrapAlert("Failed to update user profile. Please try again.");
    // });
}

function displayUserProfile() {
    const userDetails = {
        username: localStorage.getItem('username'),
        email: localStorage.getItem('user_email'),
        avatar: localStorage.getItem('avatar') || '/static/images/not.PNG',
    };

    const content = `
        <div class="container mt-4">
            <div class="row">
                <div class="col-md-6">
                    <div class="card mb-4">
                        <div class="card-body">
                            <h2 class="card-title">User Profile</h2>
                            <div class="text-center mb-3">
                                <img src="${userDetails.avatar}" alt="User Avatar" class="img-fluid rounded-circle" style="width: 150px; height: 150px; cursor: pointer;" onclick="changeAvatar()" id="avatarImage">
                                <input type="file" id="avatarInput" style="display: none;" accept="image/*">
                            </div>
                            <p><strong>Username:</strong></p>
                            <input type="text" id="newUsername" class="form-control mb-3" value="${userDetails.username}">
                            <button class="btn btn-primary" onclick="updateUsername()">Update Username</button>
                            <p class="mt-3"><strong>Email:</strong> ${userDetails.email}</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-6">
                    <div class="card mb-4">
                        <div class="card-body">
                            <h2 class="card-title">Friends List</h2>
                            <div id="friendsList" class="d-flex flex-wrap justify-content-start mb-3">
                                <!-- Friends will be dynamically added here -->
                            </div>
                            <div class="mt-3">
                                <h3>Add Friend</h3>
                                <div class="input-group mb-3">
                                    <input type="text" id="friendUsername" class="form-control" placeholder="Enter friend's username">
                                    <button class="btn btn-primary" type="button" onclick="addFriend()">Add Friend</button>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-12">
                    <button class="btn btn-primary" onclick="loadGameListContent(true)">View Game Rooms</button>
                </div>
                <div class="col-12 mt-4">
                    <div class="card">
                        <div class="card-body">
                            <h2 class="card-title">Match History</h2>
                            <div id="matchHistory">
                                <!-- Match history will be dynamically added here -->
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    `;

    document.getElementById('dynamic-content').innerHTML = content;
    document.getElementById('avatarInput').addEventListener('change', uploadAvatar);
    
    // Load match history and game statistics
    loadMatchHistory();
}

function updateUsername() {
    const newUsername = document.getElementById('newUsername').value;
    const token = localStorage.getItem('jwt_token');

    if (!newUsername || newUsername.length < 3) {
        showBootstrapAlert("Username must be at least 3 characters long.", "warning");
        return;
    }

    fetch('https://localhost/api/accounts/profile/', {
        method: 'PATCH',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json',
            'Authorization': `Bearer ${token}`
        },
        body: JSON.stringify({ username: newUsername })
    })
    // .then(response => {
    //     if (!response.ok) {
    //         throw new Error('Failed to update username');
    //     }
    //     return response.json();
    // })
	.then(response => response.json())
	.then(data => {
		if (data.jwt_token) {
			localStorage.setItem('jwt_token', data.jwt_token);
			localStorage.setItem('user_id', data.user_id);
			localStorage.setItem('user_email', data.user_email);
			localStorage.setItem('username', data.username);
			localStorage.setItem('avatar', data.avatar || '/static/images/not.PNG');
			window.location.href = '/list/';
		} else {
			alert("Verification failed.");
		}
	})
    .then(data => {
        localStorage.setItem('username', data.username);
        showBootstrapAlert("Username updated successfully!", "success");
        displayUserProfile();  // 업데이트된 사용자 이름을 표시하기 위해 프로필을 다시 로드합니다.
    })
    .catch(error => {
        console.error('Error updating username:', error);
        showBootstrapAlert("Failed to update username. Please try again.", "danger");
    });
}

// 환경에 따른 기본 URL 설정
const API_BASE_URL = window.location.origin.includes('localhost') 
    ? 'https://localhost'
    : window.location.origin;


function loadMatchHistory() {
    const username = localStorage.getItem('username');
    const token = localStorage.getItem('jwt_token');

    if (!username || !token) {
        console.error('Username or token is missing');
        showBootstrapAlert("Authentication information is missing. Please log in again.", "danger");
        return;
    }

    const apiUrl = `${API_BASE_URL}/transcendence/api/user-session-history/${username}/`;
    console.log('Fetching match history from:', apiUrl);

    fetch(apiUrl, {
        method: 'GET',
        headers: {
            'Accept': 'application/json',
            'Authorization': `Bearer ${token}`
        },
        credentials: 'include'
    })
    .then(response => {
        console.log('Response status:', response.status);
        console.log('Response headers:', [...response.headers.entries()]);
        if (!response.ok) {
            return response.text().then(text => {
                throw new Error(`HTTP error! status: ${response.status}, message: ${text}`);
            });
        }
        return response.json();
    })
    .then(data => {
        console.log('Received data:', data);
        displayMatchHistory(data);
        displayGameStatistics(data);
    })
    .catch(error => {
        console.error('Error fetching match history:', error);
        let errorMessage = "Failed to load match history. ";
        if (error.message.includes("404")) {
            errorMessage += "The requested resource was not found. Please check if the API endpoint is correct.";
        } else if (error.message.includes("Failed to fetch")) {
            errorMessage += "There was a network error. Please check your internet connection and try again.";
        } else {
            errorMessage += error.message;
        }
        showBootstrapAlert(errorMessage, "danger");
        displayMatchHistory([]);
        displayGameStatistics([]);
    });
}

function displayGameStatistics(matches) {
    const currentUsername = localStorage.getItem('username');
    let totalGames = matches.length;
    let wins = 0;

    matches.forEach(match => {
        // This loop accounts for both tournament-style and 1-vs-1 matches.
        if (match.match && match.match.length > 0) {
            // Get the final match in a series to determine the overall winner in tournaments.
            const finalMatch = match.match[match.match.length - 1];
            if (finalMatch.winner === currentUsername) {
                wins++;
            }
        }
    });

    let winRate = totalGames > 0 ? (wins / totalGames) : 0;

    const statsHtml = `
        <div class="card mb-4">
            <div class="card-body">
                <h4 class="card-title">Game Statistics</h4>
                <p><strong>Total Games:</strong> ${totalGames}</p>
                <p><strong>Wins:</strong> ${wins}</p>
                <p><strong>Win Rate:</strong> ${(winRate * 100).toFixed(2)}%</p>
            </div>
        </div>
    `;

    // Find the right place to insert the statistics
    const profileCard = document.querySelector('.card-body');
    if (profileCard) {
        profileCard.insertAdjacentHTML('beforeend', statsHtml);
    } else {
        console.error('Profile card not found');
    }
}

function fetchWithFallback(mainUrl, fallbackUrl, token) {
    return fetch(mainUrl, {
        method: 'GET',
        headers: {
            'Accept': 'application/json',
            'Authorization': `Bearer ${token}`
        },
        mode: 'cors'
    })
    .then(response => {
        if (!response.ok) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }
        return response.json();
    })
    .catch(error => {
        console.warn(`Failed to fetch from main URL: ${error.message}. Trying fallback URL.`);
        return fetch(fallbackUrl, {
            method: 'GET',
            headers: {
                'Accept': 'application/json',
                'Authorization': `Bearer ${token}`
            }
        })
        .then(response => {
            if (!response.ok) {
                throw new Error(`HTTP error! status: ${response.status}`);
            }
            return response.json();
        });
    });
}

function displayMatchHistory(matches) {
    const matchHistoryContainer = document.getElementById('matchHistory');
    if (!matchHistoryContainer) {
        console.error('Match history container not found');
        return;
    }

    if (!Array.isArray(matches) || matches.length === 0) {
        matchHistoryContainer.innerHTML = '<p>No matches played yet or failed to load match history.</p>';
        return;
    }

    const matchesHtml = matches.map(match => {
        if (!match || !match.match || !Array.isArray(match.match) || match.match.length === 0) {
            console.error('Invalid match data:', match);
            return '';
        }

        const date = new Date(match.created_at).toLocaleString();
        const currentUsername = localStorage.getItem('username');

        let headerHtml = '';
        let playersHtml = '';
        let winnerHtml = '';
        let resultHtml = '';

        if (match.match.length > 1) {
            // 4인 토너먼트
            const allPlayers = [...new Set(match.match.flatMap(m => [m.player1, m.player2]))];
            const finalMatch = match.match[match.match.length - 1];
            const winner = finalMatch.winner;
            const result = winner === currentUsername ? 'Won' : 'Lost';

            headerHtml = `<strong>Tournament</strong><br>`;
            playersHtml = `<strong>Players:</strong> ${allPlayers.join(' vs ')}<br>`;
            winnerHtml = `<strong>Winner:</strong> ${winner}<br>`;
            resultHtml = `<strong>Result:</strong> ${result}<br>`;
        } else {
            // 2인 매치
            const matchData = match.match[0];
            const result = matchData.winner === currentUsername ? 'Won' : 'Lost';

            headerHtml = `<strong>1 vs 1</strong><br>`;
            playersHtml = `<strong>Players:</strong> ${matchData.player1} vs ${matchData.player2}<br>`;
            winnerHtml = `<strong>Winner:</strong> ${matchData.winner}<br>`;
            resultHtml = `<strong>Result:</strong> ${result}<br>`;
        }

        return `
            <div class="card mb-2">
                <div class="card-body">
                    <h5 class="card-title">${headerHtml}Date: ${date}</h5>
                    <p class="card-text">
                        ${playersHtml}
                        ${winnerHtml}
                        ${resultHtml}
                    </p>
                </div>
            </div>
        `;
    }).join('');

    matchHistoryContainer.innerHTML = matchesHtml;
}

function getFriendsList() {
    const token = localStorage.getItem('jwt_token');
    if (!token) {
        return Promise.reject("No token found");
    }

    return fetch('https://localhost/api/accounts/friendship', {
        method: 'GET',
        headers: {
            'Accept': 'application/json',
            'Authorization': `Bearer ${token}`
        }
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    });
}

function addFriend() {
    const friendUsername = document.getElementById('friendUsername').value;
    const token = localStorage.getItem('jwt_token');

    if (!friendUsername) {
        showBootstrapAlert("Please enter a username", "warning");
        return;
    }

    fetch('https://localhost/api/accounts/friendship', {
        method: 'POST',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json',
            'Authorization': `Bearer ${token}`
        },
        body: JSON.stringify({ username: friendUsername })
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => {
        showBootstrapAlert("Friend added successfully!", "success");
        document.getElementById('friendUsername').value = ''; // Clear the input
        // Refresh the friends list
        getFriendsList().then(friends => displayFriendsList(friends));
    })
    .catch(error => {
        console.error('Error adding friend:', error);
        showBootstrapAlert("Failed to add friend. Please try again.", "danger");
    });
}

function displayFriendsList(friends) {
    const friendsListContainer = document.getElementById('friendsList');
    friendsListContainer.innerHTML = friends.map(friend => `
        <div class="friend-item m-2 position-relative" data-bs-toggle="tooltip" data-bs-placement="top" 
             title="${friend.username}">
            <img src="${friend.avatar || '/static/images/not.PNG'}" alt="${friend.username}" 
                 class="rounded-circle" style="width: 60px; height: 60px;">
            <span class="position-absolute bottom-0 end-0 translate-middle p-2 border border-light rounded-circle ${friend.online_status ? 'bg-success' : 'bg-secondary'}"></span>
        </div>
    `).join('');

    // Initialize tooltips
    var tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'))
    var tooltipList = tooltipTriggerList.map(function (tooltipTriggerEl) {
        return new bootstrap.Tooltip(tooltipTriggerEl)
    });
}

function changeAvatar() {
    document.getElementById('avatarInput').click();
}

function uploadAvatar(event) {
    const file = event.target.files[0];
    if (!file) return;

    const formData = new FormData();
    formData.append('avatar', file);

    fetch('https://localhost/api/accounts/profile/avatar', {
        method: 'PATCH',
        headers: {
            'Accept': 'application/json',
            'Authorization': `Bearer ${localStorage.getItem('jwt_token')}`
        },
        body: formData
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => {
        const newAvatarUrl = data.avatar || `${localStorage.getItem('avatar')}?t=${new Date().getTime()}`;
        localStorage.setItem('avatar', newAvatarUrl);
        document.getElementById('avatarImage').src = newAvatarUrl;
        showBootstrapAlert("Avatar updated successfully!", "success");
    })
    .catch(error => {
        console.error('Error updating avatar:', error);
        showBootstrapAlert("Failed to update avatar. Please try again.");
    });
}

function isUserInfoStored() {
    return localStorage.getItem('jwt_token') && localStorage.getItem('user_id') &&
           localStorage.getItem('user_email') && localStorage.getItem('username');
}

function submitVerificationCode(email) {
    const code = document.getElementById('verification-code').value;
    if (code.length === 6) {
        fetch('https://localhost/api/oauth/verify-email', {
            method: 'POST',
            headers: {
                'Accept': 'application/json',
                'Content-Type': 'application/json',
                'X-CSRFToken': getCSRFToken()
            },
            body: JSON.stringify({
                email: email,
                code: code
            })
        })
        .then(response => response.json())
        .then(data => {
            if (data.jwt_token) {
                localStorage.setItem('jwt_token', data.jwt_token);
                localStorage.setItem('user_id', data.user_id);
                localStorage.setItem('user_email', data.user_email);
                localStorage.setItem('username', data.username);
                localStorage.setItem('avatar', data.avatar || '/static/images/not.PNG');
                window.location.href = '/list/';
            }
        })
        .catch(error => {
            console.error('Error verifying code:', error);
            alert("Verification error. Please try again.");
        });
    } else {
        alert("Please enter a 6-digit code.");
    }
}

function getCSRFToken() {
    const cookies = document.cookie.split(';');
    for (let i = 0; i < cookies.length; i++) {
        const cookie = cookies[i].trim();
        if (cookie.startsWith('csrftoken=')) {
            return cookie.substring('csrftoken='.length);
        }
    }
    return 'fallback-csrf-token';
}

function attachPlayGameButtonListener() {
    const playButton = document.querySelector('.play-game-btn');
    if (playButton) {
        playButton.removeEventListener('click', playGameClicked);
        playButton.addEventListener('click', playGameClicked);
    }
    const playButton2 = document.querySelector('.play-game-btn2');
    if (playButton2) {
        playButton2.addEventListener('click', function () {
            window.location.href = '/local-2p/';
        });
    }
    const playButton4 = document.querySelector('.play-game-btn4');
    if (playButton4) {
        playButton4.addEventListener('click', function () {
            window.location.href = '/local-4p/';
        });
    }
}

function playGameClicked() {
    if (isUserInfoStored()) {
        window.location.href = '/list/';
    } else {
        window.location.href = '/login/';
    }
}

function showBootstrapAlert(message, type = "danger") {
    const alertPlaceholder = document.getElementById('dynamic-content');
    if (!alertPlaceholder) {
        console.error('Alert placeholder not found');
        return;
    }

    const wrapper = document.createElement('div');
    wrapper.innerHTML = [
        `<div class="alert alert-${type} alert-dismissible fade show" role="alert">`,
        `   <strong>${type === "success" ? "Success!" : "Error!"}</strong> ${message}`,
        '   <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>',
        '</div>'
    ].join('');

    alertPlaceholder.insertBefore(wrapper, alertPlaceholder.firstChild);

    // Use a unique identifier for each alert
    const alertId = 'alert-' + Date.now();
    wrapper.firstChild.id = alertId;

    setTimeout(() => {
        const alertToRemove = document.getElementById(alertId);
        if (alertToRemove && alertToRemove.parentNode) {
            alertToRemove.parentNode.removeChild(alertToRemove);
        }
    }, 3000);
}

function setMaxParticipants(number) {
    const maxParticipantsInput = document.getElementById('maxParticipants');
    const buttons = document.querySelectorAll('.participant-button');

    buttons.forEach(button => {
        if (parseInt(button.dataset.number) === number) {
            button.classList.add('active');
        } else {
            button.classList.remove('active');
        }
    });

    if (!maxParticipantsInput) {
        console.error('Max Participants input not found');
        return;
    }
    maxParticipantsInput.value = number;
}

function loadGameContent(updateHistory, roomId, sessionInfo) {
    if (updateHistory) {
        history.pushState({ page: 'game', id: roomId }, '', `/game/${roomId}`);
    }

    const content = `
        <style>
            .game-container {
                background-color: #f8f9fa;
                border-radius: 15px;
                box-shadow: 0 10px 20px rgba(0, 0, 0, 0.1);
                overflow: hidden;
                padding: 20px;
            }
            #gameCanvas {
                border: 2px solid #007bff;
                border-radius: 10px;
                box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
                display: block;
                margin: 0 auto;
            }
            .score-card {
                background-color: #ffffff;
                border-radius: 10px;
                box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
                transition: all 0.3s ease;
                margin-bottom: 15px;
            }
            .score-card:hover {
                transform: translateY(-5px);
                box-shadow: 0 4px 8px rgba(0, 0, 0, 0.15);
            }
            .player-name {
                font-weight: bold;
                color: #007bff;
            }
            .game-controls {
                background-color: #e9ecef;
                border-radius: 10px;
                padding: 15px;
                margin-top: 20px;
            }
            .btn-control {
                width: 60px;
                height: 60px;
                font-size: 24px;
                border-radius: 50%;
                margin: 0 10px;
            }
            @media (max-width: 768px) {
                .btn-control {
                    width: 50px;
                    height: 50px;
                    font-size: 20px;
                }
            }
        </style>
        <div class="container-fluid mt-3">
            <div class="row justify-content-center">
                <div class="col-lg-10 col-md-12">
                    <div class="game-container">
                        <h2 class="text-center mb-3">2D Ping Pong Championship</h2>
                        <div class="row mb-3">
                            <div class="col-md-6">
                                <div class="score-card p-2">
                                    <h5 class="player-name" id="player1Name">Player 1</h5>
                                    <p class="mb-0">Score: <span id="player1Score" class="badge bg-primary">0</span></p>
                                </div>
                            </div>
                            <div class="col-md-6">
                                <div class="score-card p-2">
                                    <h5 class="player-name" id="player2Name">Player 2</h5>
                                    <p class="mb-0">Score: <span id="player2Score" class="badge bg-primary">0</span></p>
                                </div>
                            </div>
                        </div>
                        <div class="text-center mb-3">
                            <canvas id="gameCanvas" width="600" height="800"></canvas>
                        </div>
                        <div class="game-controls text-center">
                            <h5 class="mb-2">Game Controls</h5>
                            <button id="leftBtn" class="btn btn-primary btn-control">←</button>
                            <button id="rightBtn" class="btn btn-primary btn-control">→</button>
                        </div>
                        <div class="mt-3 text-center">
                            <p class="text-muted mb-2">Use 'A' and 'D' keys or buttons to move left and right</p>
                            <button id="leaveGameBtn" class="btn btn-danger">Leave Game</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    `;

    document.getElementById('dynamic-content').innerHTML = content;

    const canvas = document.getElementById('gameCanvas');
    const ctx = canvas.getContext('2d');

    const paddleWidth = 100;
    const paddleHeight = 10;
    const ballRadius = 10;

    let player1 = { x: 250, y: canvas.height - paddleHeight - 10, score: 0, username: 'Player1' };
    let player2 = { x: 250, y: 10, score: 0, username: 'Player2' };
    let ball = { x: 300, y: 200 };

    function draw() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        
        // Draw paddles
        ctx.fillStyle = 'blue';
        ctx.fillRect(player1.x, player1.y, paddleWidth, paddleHeight);
        ctx.fillRect(player2.x, player2.y, paddleWidth, paddleHeight);
        
        // Draw ball
        ctx.beginPath();
        ctx.arc(ball.x, ball.y, ballRadius, 0, Math.PI * 2);
        ctx.fillStyle = 'red';
        ctx.fill();
        ctx.closePath();
        
        // Draw scores
        ctx.font = '20px Arial';
        ctx.fillStyle = 'black';
        ctx.fillText(player1.username + ': ' + player1.score, 10, canvas.height - 20);
        ctx.fillText(player2.username + ': ' + player2.score, 10, 30);
    }

    function setupGameWebSocket(sessionId) {
        const jwt_token = localStorage.getItem('jwt_token');
        const url = `wss://localhost/ws/game/${sessionId}/?token=${jwt_token}`;
        
        const socket = manageWebSocket(url);

        socket.onopen = function(e) {
            console.log('WebSocket connection established');
        };

        socket.onmessage = function(event) {
            try {
                const outerData = JSON.parse(event.data);
                
                if (outerData.type == "ping") {
                    console.log('Received:', outerData);
                    socket.send(JSON.stringify({
                        type: "pong",
                        username: localStorage.getItem('username')
                    }));
                    return;
                }

                const data = JSON.parse(outerData.message);
                
                console.log('Received:', data);

				if (data.event === "session_end" || (data.winner && data.winner !== localStorage.getItem('username'))) {
                    // alert("Game Over!");
					// if (data.event === "session_end") {
					// 	alert("Winner : " + localStorage.getItem('winner'));
					// }
					localStorage.removeItem('winner');
                    if (activeWebSocket) {
                        activeWebSocket.close();
                        activeWebSocket = null;
                    }
                    localStorage.removeItem('gameSessionId');
                    loadGameListContent(true);
                } else if (data.winner) {
					// local storage에 winner 저장
					localStorage.setItem('winner', data.winner);
				} else if (data.matchId && data.player1 && data.player2 && data.ball) {
                    player1.x = data.player1.paddle_pos.x;
                    player1.y = data.player1.paddle_pos.y;
                    player2.x = data.player2.paddle_pos.x;
                    player2.y = data.player2.paddle_pos.y;
                    player1.score = data.player1.score;
                    player2.score = data.player2.score;
                    player1.username = data.player1.username;
                    player2.username = data.player2.username;
                    ball.x = data.ball.pos.x;
                    ball.y = data.ball.pos.y;
                    
                    // Update player names and scores in HTML
                    document.getElementById('player1Name').textContent = player1.username;
                    document.getElementById('player2Name').textContent = player2.username;
                    document.getElementById('player1Score').textContent = player1.score;
                    document.getElementById('player2Score').textContent = player2.score;
                    
                    draw();
                } else if (data.event === "session_end") {
                    // alert("Game Over! Winner: " + tmp_winner);
                    // if (activeWebSocket) {
                    //     activeWebSocket.close();
                    //     activeWebSocket = null;
                    // }
                    localStorage.removeItem('gameSessionId');
                    loadGameListContent(true);
                }
            } catch (error) {
                console.error('Error parsing message:', error);
                console.log('Raw message:', event.data);
            }
        };

        return socket;
    }

	let sessionId;
    if (sessionInfo && sessionInfo.session_id) {
        sessionId = sessionInfo.session_id;
        localStorage.setItem('gameSessionId', sessionId);
    } else {
        sessionId = localStorage.getItem('gameSessionId');
    }

    if (sessionId) {
        const socket = setupGameWebSocket(sessionId);
        setupGameEventListeners(socket);
    } else {
        console.error('No session ID available');
        showBootstrapAlert("Failed to load game session. Please try again.");
        loadGameListContent(true);
    }

    function setupGameEventListeners(socket) {
		removeGameEventListeners(); // 기존 리스너 제거
	
		const keyUpListener = function(event) {
			if (event.key === 'a' || event.key === 'A') {
				socket.send(JSON.stringify({username: localStorage.getItem('username'), action: "l"}));
			} else if (event.key === 'd' || event.key === 'D') {
				socket.send(JSON.stringify({username: localStorage.getItem('username'), action: "r"}));
			}
		};
		document.addEventListener('keyup', keyUpListener);
		activeEventListeners.push({ type: 'keyup', fn: keyUpListener });
	
		const leftBtn = document.getElementById('leftBtn');
		const rightBtn = document.getElementById('rightBtn');
		const leaveGameBtn = document.getElementById('leaveGameBtn');
	
		if (leftBtn) {
			const leftBtnListener = function() {
				socket.send(JSON.stringify({username: localStorage.getItem('username'), action: "l"}));
			};
			leftBtn.addEventListener('click', leftBtnListener);
			activeEventListeners.push({ type: 'click', element: leftBtn, fn: leftBtnListener });
		}
	
		if (rightBtn) {
			const rightBtnListener = function() {
				socket.send(JSON.stringify({username: localStorage.getItem('username'), action: "r"}));
			};
			rightBtn.addEventListener('click', rightBtnListener);
			activeEventListeners.push({ type: 'click', element: rightBtn, fn: rightBtnListener });
		}
	
		if (leaveGameBtn) {
			const leaveGameBtnListener = function() {
				if (confirm("Are you sure you want to leave the game?")) {
					if (activeWebSocket) {
						activeWebSocket.close();
					}
					localStorage.removeItem('gameSessionId');
					loadGameListContent(true);
				}
			};
			leaveGameBtn.addEventListener('click', leaveGameBtnListener);
			activeEventListeners.push({ type: 'click', element: leaveGameBtn, fn: leaveGameBtnListener });
		}
	}
    // 초기 그리기
    draw();
}

function removeGameEventListeners() {
    activeEventListeners.forEach(listener => {
        if (listener.element) {
            listener.element.removeEventListener(listener.type, listener.fn);
        } else {
            document.removeEventListener(listener.type, listener.fn);
        }
    });
    activeEventListeners = [];
}

// 페이지 로드 시 게임 컨텐츠 로드 (새로고침 대응)
window.addEventListener('load', function() {
    const path = window.location.pathname.split('/');
    if (path[1] === 'game' && path[2]) {
        const roomId = path[2];
        loadGameContent(false, roomId);
    }
});

window.onbeforeunload = function() {
    if (activeWebSocket) {
        activeWebSocket.close();
        activeWebSocket = null;
    }
};

function cleanupBeforePageChange() {
    removeGameEventListeners();
    if (activeWebSocket) {
        activeWebSocket.close();
    }
}

window.onbeforeunload = cleanupBeforePageChange;
window.addEventListener('popstate', cleanupBeforePageChange);


function load2PlayerGameContent(updateHistory) {
    if (activeWebSocket) {
        activeWebSocket.close();
        activeWebSocket = null;
    }
    if (updateHistory) {
        history.pushState({ page: 'local-2p' }, '', '/local-2p/');
    }
    const content = `
            <style>
            #gameCanvas {
                display: block;
                margin: 0 auto;
                border: 2px solid black;
            }
        </style>
    <div class="container mt-4">
        <h2 class="text-center mb-4">2 Player Pong Game</h2>
        <canvas id="gameCanvas" width="600" height="800"></canvas>
    </div>
`;
    document.getElementById('dynamic-content').innerHTML = content;
    const canvas = document.getElementById('gameCanvas');
    const ctx = canvas.getContext('2d');

    const game = new GameLogic(canvas);
    let gameOver = false;

    function drawPaddle(x, y) {
        ctx.fillStyle = 'blue';
        ctx.fillRect(x, y, game.player[0].width, game.player[0].height);
    }

    function drawBall(x, y) {
        ctx.beginPath();
        ctx.arc(x, y, game.ball.radius, 0, Math.PI * 2);
        ctx.fillStyle = 'red';
        ctx.fill();
        ctx.closePath();
    }

    function drawScore() {
        ctx.font = '24px Arial';
        ctx.fillStyle = 'black';
        ctx.fillText('Player 1: ' + game.player_score[0], 10, canvas.height - 20);
        ctx.fillText('Player 2: ' + game.player_score[1], 10, 30);
    }

    function draw() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);

        drawPaddle(game.player[0].x, game.player[0].y);
        drawPaddle(game.player[1].x, game.player[1].y);
        drawBall(game.ball.x, game.ball.y);
        drawScore();

        if (gameOver) {
            ctx.font = '48px Arial';
            ctx.fillStyle = 'black';
            ctx.textAlign = 'center';
            ctx.fillText('Game Over', canvas.width / 2, canvas.height / 2 - 20);
            ctx.font = '24px Arial';
            ctx.fillText('Winner: ' + (game.player_score[0] > game.player_score[1] ? 'Player 1' : 'Player 2'), canvas.width / 2, canvas.height / 2 + 20);
        }
    }

    function updatePositions() {
        if (gameOver) return;

        gameOver = game.update();
        draw();
    }

    function setupGameEventListeners() {
        const playerSpeed = 5;

        document.addEventListener('keydown', function (event) {
            keys[event.key.toLowerCase()] = true;  // 눌린 키 상태를 저장 (소문자로 통일)
        
            // // 플레이어 1의 이동 처리 (A, D 키로 이동)
            // if (keys['a']) {
            //     game.player[0].dx = -playerSpeed;  // 왼쪽으로 이동
            // } else if (keys['d']) {
            //     game.player[0].dx = playerSpeed;   // 오른쪽으로 이동
            // }
        
            // // 플레이어 2의 이동 처리 (J, L 키로 이동)
            // if (keys['j']) {
            //     game.player[1].dx = -playerSpeed;  // 왼쪽으로 이동
            // } else if (keys['l']) {
            //     game.player[1].dx = playerSpeed;   // 오른쪽으로 이동
            // }
        });
        
        document.addEventListener('keyup', function (event) {
            keys[event.key.toLowerCase()] = false;  // 키를 놓으면 상태를 업데이트
        
            // // 플레이어 1의 이동 멈춤 처리 (A, D 키가 모두 놓였을 때)
            // if (!keys['a'] && !keys['d']) {
            //     game.player[0].dx = 0;
            // }
        
            // // 플레이어 2의 이동 멈춤 처리 (J, L 키가 모두 놓였을 때)
            // if (!keys['j'] && !keys['l']) {
            //     game.player[1].dx = 0;
            // }
        });
        // document.addEventListener('keydown', function (event) {
        //     if (event.key === 'a' || event.key === 'A') {
        //         game.player[0].dx = -playerSpeed;
        //     } else if (event.key === 'd' || event.key === 'D') {
        //         game.player[0].dx = playerSpeed;
        //     } else if (event.key === 'j' || event.key === 'J') {
        //         game.player[1].dx = -playerSpeed;
        //     } else if (event.key === 'l' || event.key === 'L') {
        //         game.player[1].dx = playerSpeed;
        //     }
        // });
        
        // document.addEventListener('keyup', function (event) {
            //     if (event.key === 'a' || event.key === 'A' || event.key === 'd' || event.key === 'D') {
                //         game.player[0].dx = 0;
                //     } else if (event.key === 'j' || event.key === 'J' || event.key === 'l' || event.key === 'L') {
                    //         game.player[1].dx = 0;
                    //     }
                    // });
                    
                    setInterval(updatePositions, 1000 / 30); // 60 FPS
                }
                
                setupGameEventListeners();
                draw();  // Initial draw
            }
            
function load4PlayerGameContent(updateHistory) {
    if (activeWebSocket) {
        activeWebSocket.close();
        activeWebSocket = null;
    }
    if (updateHistory) {
        history.pushState({ page: 'local-4p' }, '', '/local-4p/');
    }

    const content = `
        <style>
            #gameCanvas {
                display: block;
                margin: 0 auto;
                border: 2px solid black;
            }
            .bracket {
                width: 600px;
                margin: 20px auto;
                text-align: center;
            }
            .round {
                display: flex;
                justify-content: space-around;
                margin-bottom: 20px;
            }
            .match {
                width: 150px;
                padding: 10px;
                background-color: #f1f1f1;
                border: 2px solid #ccc;
                border-radius: 10px;
                text-align: center;
                font-size: 18px;
                font-weight: bold;
                position: relative;
            }
            .match div {
                padding: 5px 0;
            }
            .winner {
                background-color: #d4edda;
                border-color: #c3e6cb;
            }
            #final {
                background-color: #f9e79f;
                border-color: #f7dc6f;
            }
            #final.match {
                background-color: #ffeeba;
                border-color: #ffeeba;
                font-size: 20px;
            }
        </style>
        <div class="container mt-4">
            <h2 class="text-center mb-4">4 Player Pong Tournament</h2>
            <canvas id="gameCanvas" width="600" height="800"></canvas>
            <div class="bracket">
                <div class="round">
                    <div class="match" id="match1">
                        <div>Player 1</div>
                        <div>Player 2</div>
                    </div>
                    <div class="match" id="match2">
                        <div>Player 3</div>
                        <div>Player 4</div>
                    </div>
                </div>
                <div class="round">
                    <div class="match" id="match3">
				<div class="winner" id="match1_winner"></div>
                        <div class="winner" id="match2_winner"></div>
                    </div>
                </div>
                <div class="round">
                    <div class="match" id="final_match">
                        <div class="winner" id="final_match_winner"></div>
                    </div>
                </div>
            </div>
            <div class="mt-3">
                <p><strong>Controls:</strong> 'A' (left) and 'D' (right) for bottom player, 'J' (left) and 'L' (right) for top player</p>
            </div>
        </div>
    `;

    document.getElementById('dynamic-content').innerHTML = content;

    const canvas = document.getElementById('gameCanvas');
    const ctx = canvas.getContext('2d');

    const game = new GameLogic(canvas);

    let gameOver = false;
    let match1_player1 = 'Player 1';
    let match1_player2 = 'Player 2';
    let match2_player1 = 'Player 3';
    let match2_player2 = 'Player 4';
    let gameCount = 0;
    let m1winner = '';
    let m2winner = '';

    function sleep(ms) {
        return new Promise(resolve => setTimeout(resolve, ms));
    }

    function drawPaddle(x, y) {
        ctx.fillStyle = 'blue';
        ctx.fillRect(x, y, game.player[0].width, game.player[0].height);
    }

    function drawBall(x, y) {
        ctx.beginPath();
        ctx.arc(x, y, game.ball.radius, 0, Math.PI * 2);
        ctx.fillStyle = 'red';
        ctx.fill();
        ctx.closePath();
    }

    function drawScore(name1, name2) {
        ctx.font = '24px Arial';
        ctx.fillStyle = 'black';
        ctx.textAlign = 'left';
        ctx.fillText(name1 + ': ' + game.player_score[0], 10, canvas.height - 20);
        ctx.fillText(name2 + ': ' + game.player_score[1], 10, 30);
    }

    function draw() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);

        drawPaddle(game.player[0].x, game.player[0].y);
        drawPaddle(game.player[1].x, game.player[1].y);
        drawBall(game.ball.x, game.ball.y);

        if (gameCount == 0) {
            drawScore(match1_player1, match1_player2);
        }
        else if (gameCount == 1) {
            drawScore(match2_player1, match2_player2);
        }
        else if (gameCount == 2) {
            drawScore(m1winner, m2winner);
        }

        if (gameOver) {
            ctx.font = '48px Arial';
            ctx.fillStyle = 'black';
            ctx.textAlign = 'center';
            ctx.fillText('Game Over', canvas.width / 2, canvas.height / 2 - 20);
            ctx.font = '24px Arial';
            let winner = '';
            if (gameCount == 0) {
                winner = game.player_score[0] > game.player_score[1] ? 'Player 1' : 'Player 2';
                document.getElementById('match1_winner').innerHTML = winner;
                m1winner = winner;
            }
            else if (gameCount == 1) {
                winner = game.player_score[0] > game.player_score[1] ? 'Player 3' : 'Player 4';
                document.getElementById('match2_winner').innerHTML = winner;
                m2winner = winner;
            }
            else if (gameCount == 2) {
                winner = game.player_score[0] > game.player_score[1] ? m1winner : m2winner;
                document.getElementById('final_match_winner').innerHTML = winner;
            }
            ctx.fillText('Winner: ' + winner, canvas.width / 2, canvas.height / 2 + 20);
        }
    }

    async function updatePositions() {
        if (gameOver) {
            if (gameCount == 3) return;
            // await sleep(3000);
            resetGame();
            return;
        }
        
        gameOver = game.update();
        draw();
        
        if (gameOver) {
            gameCount++;
        }
    }
    
    function setupGameEventListeners() {
        
        const playerSpeed = 5;

        document.addEventListener('keydown', function (event) {
            keys[event.key.toLowerCase()] = true;  // 눌린 키 상태를 저장 (소문자로 통일)
        
            // // 플레이어 1의 이동 처리 (A, D 키로 이동)
            // if (keys['a']) {
            //     game.player[0].dx = -playerSpeed;  // 왼쪽으로 이동
            // } else if (keys['d']) {
            //     game.player[0].dx = playerSpeed;   // 오른쪽으로 이동
            // }
        
            // // 플레이어 2의 이동 처리 (J, L 키로 이동)
            // if (keys['j']) {
            //     game.player[1].dx = -playerSpeed;  // 왼쪽으로 이동
            // } else if (keys['l']) {
            //     game.player[1].dx = playerSpeed;   // 오른쪽으로 이동
            // }
        });
        
        document.addEventListener('keyup', function (event) {
            keys[event.key.toLowerCase()] = false;  // 키를 놓으면 상태를 업데이트
        
            // // 플레이어 1의 이동 멈춤 처리 (A, D 키가 모두 놓였을 때)
            // if (!keys['a'] && !keys['d']) {
            //     game.player[0].dx = 0;
            // }
        
            // // 플레이어 2의 이동 멈춤 처리 (J, L 키가 모두 놓였을 때)
            // if (!keys['j'] && !keys['l']) {
            //     game.player[1].dx = 0;
            // }
        });
    }

    function resetGame() {
        game.player_score = [0, 0];
        gameOver = false;
        game.reset_ball();
    }

    function startGame() {
        setupGameEventListeners();
        setInterval(updatePositions, 1000 / 30); // 60 FPS
        draw(); // Initial draw
    }

    startGame();
}

class Subject {
    constructor() {
        this._observers = [];
    }

    attach(observer) {
        if (!this._observers.includes(observer)) {
            this._observers.push(observer);
        }
    }
    
    detach(observer) {
        const index = this._observers.indexOf(observer);
        if (index !== -1) {
            this._observers.splice(index, 1);
        }
    }
    
    notify(value, winner) {
        console.log(`Notifying observers: ${value} ${this._observers}`);
        for (let observer of this._observers) {
            observer.update(value, winner);
        }
        console.log("Notifying observers1");
    }
}

class GameLogic extends Subject {
    constructor() {
        super();
        this.max_score = 5;
        this.player = [
            new this.Paddle(250, 780, 100, 10),
            new this.Paddle(250, 10, 100, 10)
        ];
        this.ball = new this.Ball(400, 300, 10, 5, 5, 5);
        this.canvas_width = 600;
        this.canvas_height = 800;
        this.player_score = [0, 0];
        this.isComputer = false;
        this.matchId = null;
    }

    Paddle = class {
        constructor(x, y, width, height) {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.dx = 0;
        }
    }

    Ball = class {
        constructor(x, y, radius, speed, velocityX, velocityY) {
            this.x = x;
            this.y = y;
            this.radius = radius;
            this.speed = speed;
            this.velocityX = velocityX;
            this.velocityY = velocityY;
        }
    }

    ray_intersects_rectangle(ray_origin, ray_end, rect) {
        let dx = ray_end[0] - ray_origin[0];
        if (dx === 0) {
            if (rect.left <= ray_origin[0] && ray_origin[0] <= rect.right) {
                return (rect.top <= ray_origin[1] && ray_origin[1] <= rect.bottom) ||
                    (rect.top <= ray_end[1] && ray_end[1] <= rect.bottom);
            } else {
                return false;
            }
        }

        let tmin = (rect.left - ray_origin[0]) / (ray_end[0] - ray_origin[0]);
        let tmax = (rect.right - ray_origin[0]) / (ray_end[0] - ray_origin[0]);

        if (tmin > tmax) {
            [tmin, tmax] = [tmax, tmin];
        }

        let dy = ray_end[1] - ray_origin[1];
        if (dy === 0) {
            if (rect.top <= ray_origin[1] && ray_origin[1] <= rect.bottom) {
                return (rect.left <= ray_origin[0] && ray_origin[0] <= rect.right) ||
                    (rect.left <= ray_end[0] && ray_end[0] <= rect.right);
            } else {
                return false;
            }
        }

        let tymin = (rect.top - ray_origin[1]) / (ray_end[1] - ray_origin[1]);
        let tymax = (rect.bottom - ray_origin[1]) / (ray_end[1] - ray_origin[1]);

        if (tymin > tymax) {
            [tymin, tymax] = [tymax, tymin];
        }

        if (tmin > tymax || tymin > tmax) {
            return false;
        }

        if (tymin > tmin) {
            tmin = tymin;
        }
        if (tymax < tmax) {
            tmax = tymax;
        }

        return tmin >= 0 && tmin <= 1;
    }

    collision_ray_casting(ball, paddle) {
        let ballPrev = [ball.prevX, ball.prevY];
        let ballPos = [ball.x, ball.y];

        let paddleRect = {
            left: paddle.x - ball.radius,
            right: paddle.x + paddle.width + ball.radius,
            top: paddle.y - ball.radius,
            bottom: paddle.y + paddle.height + ball.radius
        };

        return this.ray_intersects_rectangle(ballPrev, ballPos, paddleRect);
    }

    update() {
        this.ball.prevX = this.ball.x;
        this.ball.prevY = this.ball.y;

        this.ball.x += this.ball.velocityX;
        this.ball.y += this.ball.velocityY;

        if (this.isComputer) {
            this.player[1].x += (this.ball.x - (this.player[1].x + this.player[1].width / 2)) * 0.05;
        }

        if (this.ball.x + this.ball.radius > this.canvas_width) {
            this.ball.velocityX = -this.ball.velocityX;
            this.ball.x = this.canvas_width - this.ball.radius;
        } else if (this.ball.x - this.ball.radius < 0) {
            this.ball.velocityX = -this.ball.velocityX;
            this.ball.x = this.ball.radius;
        }

        let player_index = this.ball.y > this.canvas_height / 2 ? 0 : 1;
        let player_paddle = this.player[player_index];

        if (this.collision_ray_casting(this.ball, player_paddle)) {
            let collide_point = this.ball.x - (player_paddle.x + player_paddle.width / 2);
            collide_point = collide_point / (player_paddle.width / 2);

            let angle_rad = (Math.PI / 4) * collide_point;

            let direction = this.ball.y > this.canvas_height / 2 ? -1 : 1;
            this.ball.velocityY = direction * this.ball.speed * Math.cos(angle_rad);
            this.ball.velocityX = this.ball.speed * Math.sin(angle_rad);

            this.ball.speed += 0.5;

            this.ball.x = this.ball.prevX;
            this.ball.y = this.ball.prevY;
        }

        if (this.ball.y - this.ball.radius < 0) {
            this.player_score[0] += 1;
            this.reset_ball();
        } else if (this.ball.y + this.ball.radius > this.canvas_height) {
            this.player_score[1] += 1;
            this.reset_ball();
        }

        if (this.player_score[0] >= this.max_score || this.player_score[1] >= this.max_score) {
            console.log("Game Over");
            if (this.player_score[0] > this.player_score[1]) {
                return 1;
                // this.notify(this.matchId, 0);
            } else {
                return 2;
                // this.notify(this.matchId, 1);
            }
        }

        if (keys['a']) {
            this.player[0].dx = -5;  // 왼쪽으로 이동
        } else if (keys['d']) {
            this.player[0].dx = 5;   // 오른쪽으로 이동
        } else {
            this.player[0].dx = 0;  // 키가 없으면 이동 멈춤
        }
    
        // 플레이어 2의 이동 처리 (J, L 키로 이동)
        if (keys['j']) {
            this.player[1].dx = -5;  // 왼쪽으로 이동
        } else if (keys['l']) {
            this.player[1].dx = 5;   // 오른쪽으로 이동
        } else {
            this.player[1].dx = 0;  // 키가 없으면 이동 멈춤
        }

        for (let i = 0; i < 2; i++) {
            this.player[i].x += this.player[i].dx;

            if (this.player[i].x < 0) {
                this.player[i].x = 0;
            }
            if (this.player[i].x + this.player[i].width > this.canvas_width) {
                this.player[i].x = this.canvas_width - this.player[i].width;
            }
            this.player[i].dx = 0;
        }
    }

    reset_ball() {
        this.ball.x = this.canvas_width / 2;
        this.ball.y = this.canvas_height / 2;
        this.ball.speed = 5;
        this.ball.velocityY = 5 * (Math.random() > 0.5 ? 1 : -1);
        this.ball.velocityX = 5 * (Math.random() > 0.5 ? 1 : -1);
    }
}
