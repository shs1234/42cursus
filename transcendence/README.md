# Transcendence

## 📌 프로젝트 개요

풀스택 웹 애플리케이션을 직접 설계하고 구현하는 것이 목표입니다.\
사용자는 OAuth2를 이용한 로그인 후, 온라인 Pong 게임을 즐길 수 있습니다.

---

## 🚀 주요 기능

### 1. 🔑 로그인 및 인증

- JWT를 이용한 인증 토큰 발급 및 관리
- 2FA (Two-Factor Authentication) 지원
- 원격 인증 시스템 (OAuth 2.0을 이용한 보안 로그인)

### 2. 🏓 실시간 Pong 게임

- WebSocket을 이용한 멀티플레이 게임
- 동일 키보드를 이용한 로컬 2인 플레이
- 원격 플레이어와의 온라인 대전 (Remote players module)
- 3명 이상의 다인 플레이 지원 (Multiple players module)
- 승패 기록 저장 및 랭킹 시스템

### 3. 🎮 토너먼트 시스템

- 다수의 플레이어가 참가하는 토너먼트 모드
- 토너먼트 진행 과정과 경기 순서 시각화
- 매치메이킹 시스템 (참가자 자동 대진 편성)

### 4. 👥 친구 시스템

- 친구 추가 및 삭제 기능
- 친구의 온라인 상태 확인

### 5. ⚙️ 표준 사용자 관리 시스템

- 회원가입 및 보안 로그인 지원
- 고유한 닉네임을 선택하여 토너먼트 참가 가능
- 사용자 정보 수정 기능
- 아바타 업로드 및 기본 이미지 제공
- 경기 기록 (날짜 및 세부 정보 포함) 조회 기능

## 🏗️ 마이크로서비스 아키텍처

- 독립적인 기능별 마이크로서비스 분리(MSA)
- RESTful API 또는 메시지 큐를 이용한 서비스 간 통신
- 유지보수 및 확장성을 고려한 설계
- Docker Compose 기반 컨테이너 오케스트레이션
- 마이크로서비스 구성:
  - `ft_users`: 사용자 관리 및 인증
  - `ft_games`: 게임 로직 및 웹소켓 처리
  - `ft_rooms`: 게임 방 및 채팅 기능
  - `front`: 프론트엔드 서버
  - `ft_nginx`: Nginx 리버스 프록시 및 로드 밸런싱
  - `ft_db`: PostgreSQL 데이터베이스

---

## 🛠 기술 스택

### **Frontend**

- Vanilla JavaScript, HTML, CSS
- Bootstrap (프론트엔드 UI 프레임워크)

### **Backend**

- Django (백엔드 프레임워크)
- PostgreSQL (데이터베이스)

### **기타**

- WebSocket
- Docker (컨테이너 환경 구성)
- OAuth2 (42 API 연동)
- JWT (토큰 기반 인증)
- CI/CD (Docker Compose)
- Nginx 웹서버 (프록시, SSL)

---


## 📂 프로젝트 구조

```plaintext
📦 transcendence
├── 📂 front    # Django 기반 프론트엔드 애플리케이션
├── 📂 users    # 사용자 관리 및 인증 마이크로서비스
├── 📂 games    # Pong 게임 관련 마이크로서비스
├── 📂 rooms    # 게임 방 및 채팅 시스템 마이크로서비스
├── 📂 nginx    # Nginx 리버스 프록시 설정
├── 📂 db       # PostgreSQL 데이터베이스 (Docker 컨테이너에서 관리)
├── 📜 docker-compose.yml # Docker 컨테이너 오케스트레이션
```

---
## ⚙️ 설치 및 실행 방법

### 1️⃣ **프로젝트 클론**

```sh
git clone https://github.com/shs1234/42cursus.git
cd transcendence
```

### 2️⃣ **환경 변수 설정**
`.env_example` 파일명을 `.env`로 바꾸고 환경 변수 내용을 입력하세요.

### 3️⃣ **Docker 실행**

```sh
docker-compose up --build
```

