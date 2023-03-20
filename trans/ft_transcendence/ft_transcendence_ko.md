## ft_transcendence

## 초월

Soon you will know that you’ve already known things that you thought you didn’t know

몰랐다고 생각했던 것들이 사실은 이미 알고있었다는 걸 곧 알게 될겁니다.

Summary: ft_transcendence is a project on a language you should have never worked with. With a framework that you should have never heard of. To do something that you’ve never done before. Remind yourself of the beginning of your journey in computer science. Now look where you are standing. Time to shine.

요약 : ft_transcendence 는 여러분들이 전에 **해본 적 없는 것**을 **써본적 없는 언어**로 **들어본 적 없는 framework** 를 이용해 만드는 프로젝트입니다. 여러분이 처음 코딩을 시작했을 때를 떠올려보세요. 그리고 나서 지금 여러분이 어떤지 한번 보세요. 자, 이제 여러분의 재능을 펼칠 시간입니다.

## Contents

| Chapter | Contents                                       | Page |
| :-----: | :--------------------------------------------- | :--: |
|   1.1   | [**Overview**](#11-overview)                   |  2   |
|   1.2   | [**Security concerns**](#12-security-concerns) |  3   |
|   1.3   | [**User Account**](#13-user-account)           |  3   |
|   1.4   | [**Chat**](#14-chat)                           |  3   |
|   1.5   | [**Game**](#15-game)                           |  4   |
|   1.6   | [**Guilds**](#16-guilds)                       |  4   |
|   1.7   | [**Tournament**](#17-tournament)               |  5   |
|   1.8   | [**Admin**](#18-admin)                         |  5   |

## Mandatory part

## 필수 항목

## 1.1 Overview

## 1.1 개요

In this subject you will need to build a website for the mighty pong contest.

이 프로젝트에서는 위대한 Pong 게임 대회 웹사이트를 만드는 것입니다.

Your website will help user run pong tournament and play against each other.

여러분의 웹사이트는 유저들이 Pong 게임 토너먼트를 수행하고 상대방과 서로 경쟁을 할 수 있도록 해주는 사이트 입니다.

There will be an admin view, chat with moderators, real time multiplayer online games. There will be guilds and wars!

이 웹사이트에는 관리자 화면, 채팅, 실시간 멀티플레이 온라인 게임이 있습니다. 길드 그리고 전쟁도 있구요!

You will need to follow thoses rules:

여러분은 다음의 규칙을 따라야 합니다.

- Your website backend should be written in Rails 6.X.X
- 웹사이트 back-end 는 반드시 Rails 6.X.X 를 사용합니다
- You must use a postgresql database 12.1 and no other databases.
- 데이터베이스는 postgresql 12.1 을 사용하고 다른 DB 는 안됩니다.
- The front end must be written with the help of https://backbonejs.org/ version 1.4.X
- front-end 는 반드시 https://backbonejs.org/ 에 있는 version 1.4.X 을 사용해야합니다.
- Your website should be a single page app, but user should be able to use the back button on the browser https://en.wikipedia.org/wiki/Singlepage_application
- 여러분의 웹사이트는 single page app 이어야 하지만, 사용자는 웹브라우저의 `뒤로가기` 버튼을 사용할 수 있어야 합니다. https://en.wikipedia.org/wiki/Singlepage_application
- Your website must be usable on the latest version to date on Google Chrome, Firefox, Safari.
- 여러분의 웹사이트는 반드시 최신 버전의 Google Chrome, Firefox, Safari 에서 사용 가능해야합니다.
- There must be no unhandled errors or warning when browsing through the website.
- 웹사이트를 웹브라우저에서 사용할 때 처리되지 않은 에러나 경고메시지는 절대 있어서는 안 됩니다.
- You can use as many gems as you want and any js library (except REACT JS and FRAMEWORK like vue.js, angular etc...).
- 여러분은 원하는 만큼의 gem 과 js 라이브러리를 사용할 수 있습니다. (단, REACT JS와 vue.js, angular 등 과 같은 js 프레임워크는 안됩니다)
- Everything should run with a single call to docker-compose up -–build
- docker-compose up --build 명령어 하나로 모든 것들을 실행해야합니다.
  .

:warning: You should read the difference between a library and a framework

:warning: library 와 framework 의 차이점이 무엇인지 읽어보세요.

:warning: You should look at route and router

:warning: route 와 router 도 알아보세요.

## 1.2 Security concerns

## 1.2 보안 이슈

Because you are creating a fully-working website, there are a few security concerns that you will have to tackle
여러분은 완전하게 동작하는 웹사이트를 만들어야 하기 때문에 몇가지 보안 사항들을 다루어야 합니다.

- Any password stored in your database must be encrypted
- 데이터베이스에 있는 비밀번호는 반드시 암호화 되어야 합니다.
- Your website must be protected against SQL injections
- 웹사이트는 SQL 인젝션 공격으로 부터 보호되어야 합니다.
- You must implement some kind of server-side validation for forms and any user input
- 폼(form) 이나 유저가 입력한 데이터 유효성을 검사하기 위한 서버 쪽 기능을 구현해야만 합니다.

## 1.3 User Account

## 1.3 사용자 계정

- A user must login using the oauth system of 42 intranet
- 사용자는 42 인트라넷 oauth 시스템을 사용해 로그인해야만 합니다.
- A user must be able to choose a unique name that will be displayed on the website
- 사용자는 웹사이트에 표시될 고유한 이름을 고를 수 있어야 합니다.
- A user has a number of victory and loss and other stats (ladder level, number of won tournaments, achievements etc...)
- 사용자는 승수와 패배수 그리고 다른 상태정보를 가질 수 있습니다. (ladder 레벨, 토너먼트에서 이긴 횟수, 성과 등)
- A user must have an avatar generated or uploaded by the user
- 사용자는 자동 생성 또는 유저에 의해 업로드된 아바타를 가질 수 있습니다.
- A user must be able to activate a 2 factor authentication (like google authenticator or a sms etc...)
- 사용자는 2단계 인증을 활성화 할 수 있습니다.(google authenticator, sms 등)
- A user can be in 1 guild at a time
- 사용자는 한 번당 하나의 길드에만 소속될 수 있습니다.
- A user can add other users as friends, and see their current status (online, offline, in a game...)
- 사용자는 다른 사용자를 `친구등록` 할 수 있고, 그들의 상태창을 볼 수 있습니다. (온라인, 오프라인, 게임중 ...)
- Each user has a match history (including duel, ladder or tournaments games) that can be consulted by anyone logged-in
- 각 사용자들은 로그인 한 사람이면 누구든지 확인 가능한 매치 전적 기록을 가지고 있습니다. (듀얼, 래더 또는 토너먼트 게임)

## 1.4 Chat

## 1.4 채팅

- Users must be able to create channels public/private or protected by a password
- 사용자는 public/private 채널 또는 패스워드로 보호되는 채널을 만들 수 있어야 합니다.
- Users must be able to send direct messages to other user
- 사용자는 다른 사용자에게 직접 메세지를 보낼 수 있어야 합니다.
- Users must be able to block other user and therefore they will not see their messages anymore
- 사용자는 다른 유저를 차단하고 그들의 메세지를 더 이상 볼 수 없게 할 수 있어야 합니다.
- A user that create a new channel is automatically its owner until he leaves the channel
- 채널을 생성한 사용자는 자동적으로 그가 떠날 때까지는 소유자가 됩니다.

  - owner of a channel can add/change/remove a password to access to the channel
  - 채널의 소유자는 채널 접근을 위한 비밀번호를 추가/변경/삭제할 수 있습니다.
  - owner can select user to be administrator and is also administrator of the channel
  - 채널의 소유자는 채널의 관리자이며, 다른 유저를 관리자가 되도록 선택할 수 있습니다.
    - administrator can ban or mute users for a certain amount of time
    - 관리자는 일정 시간동안 유저들을 강퇴(ban)하고 차단(mute) 할 수 있습니다.

- Through the chat interface users should be able to ask other player to do a Pong match
- 사용자의 채팅 화면상으로 다른 플레이어에게 Pong 게임을 신청할 수 있습니다.
- Through the chat interface users must be able to see other players profiles
- 사용자의 채팅 화면상으로 다른 플레이어들의 프로필을 볼 수 있습니다.

## 1.5 Game

## 1.5 게임

The main purpose of this website is to play pong against other players and show everyone how good you are!

이 웹사이트의 주 목적은 다른 사람들과 Pong 게임을 하는 것이고 여러분이 얼마나 게임을 잘 하는지 다른 사람에게 보여주는 것입니다!

Therefore we should be able to play pong directly on the website and live against an other player.

그러므로 우리는 웹사이트상에서 Pong 을 바로 시작할 수 있어야 하며 상대와 대결을 할 수 있어야 합니다.

It can be in a canvas or it can be with 3d effects, it can be ugly but it must be a pong like the one from 1972.

`canvas` 나 3d 효과를 사용할 수 있으며 못 생길 수 있지만 1972년에서 온 Pong 게임이어야 합니다.

If you want to, you can add power ups, different maps etc... but user must be able to play a default pong game without any added stuff.

여러분이 원한다면 파워업이나 다른 맵등 다른 것들을 추가 할 수 있지만... 사용자는 반드시 어떤 추가적 요소 없이 기본적인 Pong 게임을 할 수 있어야 합니다.

The game must be responsive!

게임은 반드시 responsive(반응성) 이어야만 합니다!

Other users can watch the game live without interfering in it.

다른 유저들은 게임을 방해하지 않고 실시간으로 관전이 가능합니다.

:warning:Think about network issue, like disconnects or lag. The user experience should be the best possible.

:warning: 연결이 끊어지거나 늘어짐(lag) 같은 네트워크 이슈를 고려하세요. 사용자 경험이 가능한 가장 좋아야 합니다.

## 1.6 Guilds

## 1.6 길드

- Users must be able to create guilds with unique names
- 사용자는 고유한 이름을 가진 길드(들)을 만들 수 있습니다.
- A guild must also have a unique anagram of 5 letters max that will be shown before the name of a user in the chat
- 길드는 반드시 고유한 5개의 글자로된 별칭(anagram)을 가지며, 채팅 상에서 유저의 이름 앞에 표시됩니다.
- Each time a member of the guild wins a game, some points are added to the guild’s points
- 매번 길드원이 승리할 때마다 그 중 일부 포인트들은 길드 포인트에 추가됩니다.
- There must be a ranking page of all guilds, visible to any logged-in user
- 로그인한 유저들은 길드 랭킹페이지를 볼 수 있어야만 합니다.
- A guild has a owner and officers
- 길드는 소유자(owner)와 사무자(officers)를 가지고 있습니다.
- Guild can declare war to an other guild
- 길드는 다른 길드에게 전쟁을 선포할 수 있습니다.

  - A war has a start date, an end date and a number of point that the guilds are ready to lose/win as prize for the war
  - 전쟁에는 시작 날짜, 끝나는 날짜 그리고 승리/패배한 길드에게 주어지는 포인트수가 있습니다.
  - A war also has a timetable where random fights can be asked, it’s called a "War time"
  - 전쟁은 또한 랜덤 싸움이 일어날 수 있는 소위 'War time' 이라는 시간대가 있습니다.

    - When the "War time" is active a member can ask to fight randomly any one from the other guild, if no one of the other guild answer the call after a certain amount of time, the match is automatically won
    - 'War time' 이 활성화 될 때, 길드원이 다른 길드원에게 랜덤하게 싸움을 걸 수 있으며, 만약 다른 길드원이 싸움을 건 후 일정 시간 동안 응답이 없으면 그 경기는 자동 승으로 인정됩니다.
    - Guilds can set the maximum of unanswered match calls per "War time"
    - 길드는 매 'War time' 동안 싸움에 응답하지 않은 최대 횟수를 설정할 수 있습니다.
    - There can be only one "War time" match at the same time, to avoid big guilds to flood small ones.
    - 큰 길드들이 작은 길드에게 몰리는 것을 방지하기 위해 'War time' 매치는 동시에 단 한번만 있을 수 있습니다.

  - Both guild must agree on all terms of the war and the type of match that will count in the war (with or without add-on etc...)
  - 두 길드는 전쟁 약관에 반드시 동의해야하며 전쟁에 카운트될 경기 타입을 정해야만 합니다. (add-on 을 쓸거냐 안쓸거냐 등..)

    - If the guilds agree, any matchs played on ladder or during a tournament will count towards the war effort
    - 만약 두 길드가 동의하면, ladder 나 토너먼트에서 이루어진 경기들도 전쟁 공헌치(effort)로 인정됩니다.
    - If the guilds add add-ons, only the matchs using said add-ons will count towards the war effort
    - 만약 길드가 add-on을 추가할 경우, 오직 add-on 경기들만 전쟁 공헌치로 카운트합니다.
    - During a war, if a member of a guild duels someone from the other guild, the winner will earn war point for his guild
    - 전쟁이 진행되는 동안, 한 길드의 멤버가 다른 길드의 누군가와 경기를 하는 경우 승자가 해당 길드의 전쟁 포인트를 얻습니다.

  - At the end of the war the guild with the highest number of war points will receive the prize from the other guild
  - 전쟁이 끝난 후 더 높은 전쟁 포인트를 가진 길드가 다른 길드로 부터 보상을 획득합니다.
  - A guild can be in one war only at a time
  - 길드는 한 번에 하나의 전쟁에만 참여할 수 있습니다.

- Each guild has a war history page, visible to any logged-in user
- 각 길드는 전쟁 기록 페이지(war history page)가 있으며 로그인한 유저라면 누구든지 볼 수 있습니다.

## 1.7 Tournament

## 1.7 토너먼트

There must a permanent ladder tournament with a match making system with a ladder system. (https://en.wikipedia.org/wiki/Ladder_tournament)

ladder 매칭 시스템을 이용하는 ladder 토너먼트가 영구적으로 존재해야합니다.(https://en.wikipedia.org/wiki/Ladder_tournament)

Users can play on the ladder, with a rating system, or play casually, without it affecting their rating.

유저는 등급시스템(rating system)을 사용하여 래더에서 플레이 하거나, 등급에 영향을 주지 않는 플레이를 할 수 있습니다.

There also must be tournaments that can be created by admininstrators or automatically.

또한 운영자에 의해 생성되거나 자동으로 생성되는 토너먼트가 존재해야합니다.

Rules of said tournament (round robin, single/double eliminations, swiss...) is up to you.

여러가지 토너먼트 규칙 중 (round robin, single/double eliminations, swiss...) 어떤 토너먼트의 규칙을 사용하는지는 여러분에게 달려 있습니다.

User will be allowed to register to the tournament in a timeframe before said tournament.

유저는 해당 토너먼트 시간 전에 토너먼트 등록을 할 수 있습니다.

You can add incentives to tournaments, like title for the winner or other cool stuff.

우승자 타이틀, 또는 다른 멋진 것들을 인센티브로 추가할 수 있습니다.

## 1.8 Admin

## 1.8 관리자

Some user can be appointed administrator of the website.
일부 유저는 해당 웹사이트의 관리자로 지정 될 수 있습니다.

- They can create tournaments
- 관리자는 토너먼트를 생성할 수 있습니다.
- Destroy chat channels
- 채팅 채널을 삭제할 수 있습니다.
- Ban users
- 유저를 강제 퇴장시킬 수 있습니다.
- See any chat channels without being listed in it
- 어느 채팅 채널이든 그 채널에 속하지 않아도 해당 메세지를 볼 수 있습니다.
- Give or remove rights in a chat channel to a user
- 해당 채팅 채널의 유저에게 권한을 주거나 삭제할 수 있습니다.
- Give or remove rights in a guild to a user
- 길드에 속한 유저에게 권한을 주거나 삭제할 수 있습니다.
