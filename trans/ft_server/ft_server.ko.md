# page 0

Ft_server

요약: 이번 프로젝트의 과제는 시스템 관리입니다. 여러분은 도커를 발견하고 여러분의 첫 번째 웹 서버를 구축할 것입니다.

# page 1

Contents
| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__Introduction__]() | 2 |
| II | [__General instructions__]() | 3 |
| III | [__Mandatory part__]() |  4 |

# page 2

Chapter 1

Introduction

이번 주제는 여러분에게 시스템 관리에 대해서 소개하려 합니다. 스크립트를 사용하여 업무를 자동화하는 것이 중요하다는 것을 깨닫게 될 것입니다. 이를 위해, 여러분은 "도커"라는 기술을 발견하여 그것을 완전한 웹 서버를 설치하는 데 사용할 것입니다. 이 서버는 여러 서비스를 실행할 것입니다: Wordpress, phpMyAdmin, 그리고 SQL database.

# page 3

Chapter 2

General instructions

* 서버 구성에 필요한 모든 파일을 srcs 폴더 안에 넣어놔야 합니다.

* **Dockerfile**은 저장소의 루트에 있어야 합니다. 그것은 여러분의 컨테이너를 만들 것입니다. 도커-컴포즈를 사용할 수 없습니다.
* WordPress 웹 사이트에서 필요한 모든 파일은 srcs 폴더 안에 있어야 합니다.

# page 4

Chpater 3

Mandatory part

* 오직 하나의 도커 컨테이너에만, Ngnix로 웹 서버를 구축해야 합니다. 그 컨테이너 OS는 debian buster이어야 합니다.
* 웹 서버는 동시에 여러 서비스를 실행시킬 수 있어야 합니다. 이 서비스는 WordPress 웹 사이트, phpMyAdmin 그리고 MySQL이 될 것입니다. SQL 데이터베이스가 WordPress 및 phpMyAdmin과 함께 연동되어 작동이 잘 되는지 확인해야 할 것입니다.
* 여러분의 서버는 SSL 프로토콜을 사용할 수 있어야 합니다.
* URL에 따라 서버가 올바른 웹 사이트로 이동하는지 확인해야 할 것입니다.
* 당신의 서버가 autoindex로 실행 중인지 확인해야 하며, 그 autoindex는 비활성화가 가능해야 합니다.
