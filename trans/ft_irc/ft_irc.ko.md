# ft_irc

**Internet Relay Chat**

##### _Summary: This project is about creating your own IRC server. You will use an actual IRC client to connect to your server and test it. Internet is ruled by solid standards protocols that allow connected computers to interact with each other. It’s always a good thing to know._

_요약: 이번 프로젝트의 목표는 IRC 서버를 직접 만들어보는 것입니다. 여러분의 서버에 실제 IRC 클라이언트를 연결하여 테스트해 볼 겁니다. 인터넷은 견고한 표준 프로토콜을 통해 연결된 컴퓨터들이 서로 상호작용할 수 있도록 도와줍니다. 알아서 나쁠 것은 없겠죠._

##### _Version: 6_

_버전 6_

<br>

# **Contents**

| Chapter | Contents                                     | Page |
| :-----: | :------------------------------------------: | :--: |
|    1    | [**Introduction**](#Chapter-1) | 2    |
|    2    | [**General Rules**](#Chapter-2)               | 3    |
|    3    | [**Mandatory Part**](#Chapter-3)           | 4    |
|    3.1    | [**Requirements**](#Chapter-3)           |  5   |
|    3.2    | [**For MacOS only**](#Chapter-3)           | 6    |
|    3.3    | [**Test example**](#Chapter-3)           | 6    |
|    4    | [**Bonus Part**](#Chapter-4)                   | 7    |
|    5    | [**Submissions and peer-evaluation**](#Chapter-5)                   | 8    |

<br>

# **Chapter 1**

## Introduction

##### _**Internet Relay Chat** or IRC is a text-based communication protocol on the Internet. It offers real-time messaging that can be either public or private. Users can exchange direct messages and join group channels._

Internet Relay Chat, 줄여서 IRC는 텍스트 기반의 인터넷 통신 프로토콜입니다. IRC는 공개 / 비공개 실시간 대화를 지원하며, 유저는 다이렉트 메시지를 주고받거나 그룹 채널에 접속할 수 있습니다.

##### _IRC clients connect to IRC servers in order to join channels. IRC servers are connected together to form a network._

IRC 클라이언트들은 채널에 접속하기 위해 IRC 서버에 연결하여야 합니다. IRC 서버들은 상호간에 연결되어 있으며, 이를 통해 네트워크를 형성합니다.

<br>

# **Chapter 2**

## General Rules

- ##### _Your program should not crash in any circumstances (even when it runs out of memory), and should not quit unexpectedly. If it happens, your project will be considered non-functional and your grade will be 0._

  여러분이 작성하신 프로그램은 어떠한 상황에서도 (메모리가 부족한 경우에도)  중단되거나 예기치 않게 종료되어서는 안 됩니다. 만약 이와 같은 일이 발생한다면, 제대로 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

- ##### _You have to turn in a `Makefile` which will compile your source files. It must not relink._

  여러분의 코드를 컴파일할 `Makefile`을 함께 제출하세요. `Makefile`은 리링크되어서는 안 됩니다.

- ##### _Your `Makefile` must at least contain the rules: `$(NAME), all, clean, fclean and re`._

  `Makefile`은 최소한 `$(NAME), all, clean, fclean, re` 규칙을 포함해야 합니다.

- ##### _Compile your code with `c++` and the flags `-Wall -Wextra -Werror`_

  `c++` 와 `-Wall -Wextra -Werror` 플래그를 이용해서 컴파일하세요.

- ##### _Your code must comply with the **C++ 98 standard**. Then, it should still compile if you add the flag `-std=c++98`._

  여러분의 코드는 **C++ 98 표준** 에 맞춰 작성되어야 합니다. 또한, `-std=c++98` 플래그를 추가해도 컴파일이 되어야 합니다.

- ##### _Try to always develop using the most `C++` features you can (for example, choose `<cstring>` over `<string.h>`). You are allowed to use `C` functions, but always prefer their `C++` versions if possible._

  `C++` 에서 제공하는 기능을 최대한 활용하여 개발하세요. (예를 들면, `<string.h>` 대신 `<cstring>` 을 사용하세요) `C` 함수를 사용하는 것은 허용되지만, 가능하다면 `C++` 버전의 함수를 쓰시는 것이 좋습니다.

- ##### _Any external library and `Boost` libraries are forbidden._

  외부 라이브러리와 `Boost` 라이브러리는 사용이 금지됩니다.

<br>

# **Chapter 3**

## Mandatory Part

| **프로그램 이름**            | `ircserv`                                                                                                                                                                                                 |
| ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **제출할 파일**              | `Makefile, *.{h, hpp}, *.cpp, *.tpp, *.ipp, 추가 설정 파일들`                                                                                                                                                                               |
| **Makefile 규칙**            | `NAME, all, clean, fclean, re`                                                                                                                                                                           |
| **인자**                     | `port: 연결한 포트번호`<br>`password: 연결에 사용되는 비밀번호`                                                                                                                                                                                        |
| **사용가능한 <br>외부 함수** | `C++ 98에 존재하는 모든 함수들`<br>`socket, setsockopt, getsockname, getprotobyname, gethostbyname, getaddrinfo, freeaddrinfo, bind, connect, listen, accept, htons, htonl, ntohs, ntohl, inet_addr, inet_ntoa, send, recv, signal, lseek, fstat, fcntl, poll (or equivalent)`                                                                                  |
| **직접 만든 libft**          | `n/a`                                                                                                                                                                                               |
| **설명**                     | `C++ 98로 IRC 서버 만들기` |

##### _You have to develop an IRC server in C++ 98._

여러분은 IRC 서버를 C++98로 구현해야 합니다.

##### _You **mustn’t** develop a client._

클라이언트는 **만들지 마세요.**

##### _You **mustn’t** handle server-to-server communication._

서버간 통신도 구현하실 **필요 없습니다.**

##### _Your executable will be run as follows:_

여러분의 결과물은 다음과 같이 실행됩니다:

`./ircserv <port> <password>`

- ##### _`port`: The port number on which your IRC server will be listening to for incoming IRC connections._

  `port`: 여러분의 서버가 들어오는 IRC 연결을 받아들일 포트 번호.

- ##### _`password`: The connection password. It will be needed by any IRC client that tries to connect to your server_

  `password`: 연결 시에 사용되는 비밀번호. IRC 클라이언트가 여러분의 서버에 접속하기 위해 필요합니다.

> ℹ️ <br>
>
> ##### _Even if `poll()` is mentionned in the subject and the evaluation scale, you can use any equivalent such as `select()`, `kqueue()`, or `epoll()`._
>
> 과제와 평가 기준에 `poll()` 이 명시되어 있긴 하지만, `select()`, `kqueue()`, `epoll()` 등 비슷한 함수를 사용하셔도 무방합니다.

<br>

# **Chapter 3.1**

## Requirements

- ##### _The server must be capable of handling multiple clients at the same time and never hang._

  서버는 동시에 여러 클라이언트의 요청을 처리할 수 있어야 하며, 지연되면 안 됩니다.

- ##### _Forking is not allowed. All I/O operations must be non-blocking._

  Forking은 허용되지 않습니다. 모든 입출력 처리는 논블로킹이어야 합니다.

- ##### _Only 1 `poll()` (or equivalent) can be used for handling all these operations (read, write, but also listen, and so forth)._

  모든 동작을 처리하는 데에는 (읽기, 쓰기, 요청 듣기 등등) 단 하나의 `poll()` (또는 그와 유사한 함수) 만 사용하여야 합니다.

> ⚠️<br>
>
> ##### _Because you have to use non-blocking file descriptors, it is possible to use read/recv or write/send functions with no `poll()` (or equivalent), and your server wouldn’t be blocking. But it would consume more system resources._
>
> 논블로킹 파일 서술자 (file descriptors) 를 사용해야 하기 때문에, `poll()` (또는 유사한 함수들) 를 굳이 사용하지 않고도 `read/recv` 또는 `write/send` 함수들을 사용할 수 있으며, 이런 경우에도 서버는 블로킹되지 않습니다. 다만 시스템 자원을 더 많이 소모할 것입니다.
> ##### _Thus, if you try to `read/recv` or `write/send` in any file descriptor without using `poll()` (or equivalent), your grade will be 0._
>
> 따라서, 만약 `poll()` (또는 유사한 함수들) 없이 임의의 파일 서술자에`read/recv` 또는 `write/send` 함수를 사용할 경우, 0점을 받게 됩니다.

- ##### _Several IRC clients exist. You have to choose one of them as a reference. Your reference client will be used during the evaluation process._

  시중에 여러 IRC 클라이언트가 존재합니다. 그 중 하나를 선택해서 참조 자료로 사용하세요. 여러분이 선택한 IRC 클라이언트가 평가 중에 사용될 것입니다.

- ##### _Your reference client must be able to connect to your server without encountering any error._

  참조 클라이언트는 어떠한 오류도 없이 여러분의 서버에 접속할 수 있어야 합니다.

- ##### _Communication between client and server has to be done via TCP/IP (v4 or v6)._

  클라이언트와 서버간 커뮤니케이션은 TCP/IP (v4 또는 v6) 으로 이루어져야 합니다.

- ##### _Using your reference client with your server must be similar to using it with any official IRC server. However, you only have to implement the following features:_

  여러분의 서버에 참조 클라이언트를 접속하면 다른 공식 IRC 서버와 비슷하게 동작하여야 합니다. 다만, 아래의 기능들만 구현하세요.

  - ##### _You must be able to authenticate, set a nickname, a username, join a channel, send and receive private messages using your reference client._

    인증 절차를 밟고, 닉네임과 유저명을 설정할 수 있어야 하며, 채널에 접속하고, 참조 클라이언트를 이용하여 비밀 메시지를 주고받을 수 있어야 합니다.

  - ##### _All the messages sent from one client to a channel have to be forwarded to every other client that joined the channel._

    한 클라이언트에서 채널로 보내지는 모든 메시지는 해당 채널에 접속한 모든 다른 클라이언트들에게 전송되어야 합니다.

  - ##### _You must have operators and regular users._

    운영자와 일반 유저가 존재해야 합니다.

  - ##### _Then, you have to implement the commands that are specific to operators._

    또한, 운영자만이 사용할 수 있는 명령들을 구현하여야 합니다.

- ##### _Of course, you are expected to write a clean code._

  당연하지만, 코드는 깨끗하게 작성하세요.

<br>

# **Chapter 3.2**

## For MacOS only

> ℹ️ <br>
>
> ##### _Since MacOS doesn’t implement `write()` the same way as other Unix OSes, you are allowed to use `fcntl()`. You must use file descriptors in non-blocking mode in order to get a behavior similar to the one of other Unix OSes._
>
> MacOS 는 다른 Unix 계열 OS와 다르게 `write()` 함수의 구현 방식이 조금 다릅니다. 이런 경우, `fcntl()` 사용이 허용됩니다. 다른 Unix 계열 OS와 비슷하게 동작하기 위해서는, 파일 서술자를 논블로킹 모드로 사용하여야 합니다.

> ⚠️<br>
>
> ##### _However, you are allowed to use `fcntl()` only as follows: `fcntl(fd, F_SETFL, O_NONBLOCK);` Any other flag is forbidden._
>
> 다만, `fcntl()` 은 `fcntl(fd, F_SETFL, O_NONBLOCK);` 형식으로만 사용되어야 합니다. 다른 플래그는 사용을 금지합니다.

<br>

# **Chapter 3.3**

## Test example

##### _Verify absolutely every possible error and issue (receiving partial data, low bandwidth, and so forth)._

최대한 많은 오류와 이슈를 발생시켜 보세요 (데이터 일부분만 받기, 낮은 대역폭 등).

##### _To ensure that your server correctly processes everything that you send to it, the following simple test using `nc` can be done:_

`nc`를 사용해서 다음의 테스트를 수행하면, 여러분의 서버가 수신받은 내용을 제대로 처리하고 있는지 확인할 수 있습니다.

```sh
\$> nc 127.0.0.1 6667
com^Dman^Dd
\$>
```

##### _Use `ctrl+D` to send the command in several parts: `’com’`, then `’man’`, then ’`d\n`’._

`ctrl+D` 를 이용해서 명령을 몇 개의 조각으로 나눠서 보내보세요. '`com`', '`man`' 그리고 '`d\n`' 이렇게 말이죠.

##### _In order to process a command, you have to first aggregate the received packets in order to rebuild it._

명령을 처리하기 위해선, 수신받은 패킷을 이어 붙여 주어야 합니다.

<br>

# **Chapter 4**

## Bonus Part

##### _Here are the extra features you can add to your IRC server so it looks even more like and actual IRC server:_

아래의 내용들을 여러분의 IRC 서버에 추가하시면, 실제 상용화된 IRC 서버와 더욱 비슷하게 느껴질 것입니다.

- ##### _Handle file transfer._

  파일 송수신.

- ##### _A bot._

  봇.

> ⚠️ <br>
>
> ##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
>
> 보너스는 필수로 구현해야 하는 파트가 **완벽할 때**만 평가될 것입니다. '완벽함' 이란, 모든 필수 파트가 전부 구현되어 있어야 하며 오작동하는 부분이 없어야 함을 의미합니다. 필수로 구현해야 하는 파트에서 **만점**을 받지 못한다면, 보너스 항목은 채점되지 않습니다.

<br>

# **Chapter 5**

## Submission and peer correction

##### _Turn in your assignment in your `Git` repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct._

항상 그래왔듯, 여러분의 결과물을 `GIT` 레포지토리에 제출하세요. 평가 중에는 레포지토리에 있는 과제물만이 채점될 것입니다. 파일의 이름이 틀리진 않았는지 반복적으로 체크하는 것을 잊지 마세요.

##### _You are encouraged to create test programs for your project even though they won’t be submitted and won’t be graded. Those tests could be especially useful to test your server during defense, but also your peer’s if you have to evaluate another `ft_irc` one day. Indeed, you are free to use whatever tests you need during the evaluation process._

**이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도,** 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 평가 시간에 여러분의 서버를 테스트할 때 뿐만 아니라, 여러분이 다른 동료의 `ft_irc`를 평가할 때에도 요긴하게 사용될 거에요. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

> ℹ️ <br>
>
> ##### _Your reference client will be used during the evaluation process._
>
> 평가 과정에서 여러분이 고른 참조용 클라이언트가 사용됩니다.
