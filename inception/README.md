# Inception

Inception 과제는 Docker와 Docker Compose를 활용하여 컨테이너 기반 환경을 구축하고 관리하는 방법을 배우는 프로젝트입니다. 이 과제에서는 여러 서비스를 컨테이너로 나누고 이를 효율적으로 배포 및 관리하는 기술을 익힙니다.

---

## 프로젝트 목표
- 컨테이너 기술의 기본 이해
- Docker 이미지를 생성하고 컨테이너를 실행하는 방법 학습
- Docker Compose를 사용해 여러 컨테이너를 하나의 서비스로 관리
- 웹 애플리케이션 배포 환경 설정

---

## 필수 요건

### 1. 기본 서비스 구성
- Nginx: HTTP 서버 설정
- MariaDB: 데이터베이스 서버
- WordPress: 블로그 플랫폼

### 2. 추가 요구사항
- 각 서비스는 별도의 컨테이너에서 실행되어야 합니다.
- Nginx는 HTTPS를 지원해야 하며, 자체 인증서 또는 Let's Encrypt 인증서를 사용할 수 있습니다.
- 모든 데이터는 컨테이너를 제거한 후에도 유지되어야 합니다. (볼륨 사용)
- 모든 구성 파일은 버전 관리를 통해 관리되어야 합니다.

---

## 디렉토리 구조
```
project-directory/
├── Makefile
├── srcs/
│   ├── requirements/
│   │   ├── mariadb/
│   │   │   ├── Dockerfile
│   │   │   ├── conf/
│   │   │   │   ├── 50-server.cnf
│   │   │   ├── tools/
│   │   │   │   ├── script.sh
│   │   ├── wordpress/
│   │   │   ├── Dockerfile
│   │   │   ├── tools/
│   │   │   │   ├── script.sh
│   │   ├── nginx/
│   │   │   ├── Dockerfile
│   │   │   ├── conf/
│   │   │   │   ├── default
│   │   │   ├── tools/
│   │   │   │   ├── script.sh
│   ├── docker-compose.yml
```

---

## 사용 방법

1. **Docker 설치**
   - Docker와 Docker Compose가 설치되어 있어야 합니다.

2. **저장소 클론**
   ```bash
   git clone <repository-url>
   cd project-directory
   ```

3. **Docker Compose 실행**
   ```bash
   docker-compose up --build
   ```

4. **서비스 접근**
   - 웹 브라우저를 통해 `https://<your-domain>`으로 접근

---

## 유용한 명령어

- **컨테이너 상태 확인**
  ```bash
  docker ps
  ```

- **컨테이너 중지 및 제거**
  ```bash
  docker-compose down
  ```

- **로그 확인**
  ```bash
  docker-compose logs
  ```

---

## 참고 자료
- [Docker 공식 문서](https://docs.docker.com/)
- [Docker Compose 공식 문서](https://docs.docker.com/compose/)
- [Nginx 설정 가이드](https://nginx.org/en/docs/)
- [MariaDB 공식 문서](https://mariadb.org/)
- [WordPress Codex](https://wordpress.org/support/)

---
