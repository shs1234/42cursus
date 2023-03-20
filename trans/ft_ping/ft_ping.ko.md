# ft_ping

##### Summary: This project is about recoding the ping command.

요약: ping 명령어를 다시 만드는 프로젝트입니다.

# Contents

| Chapter | Contents                                      | page |
| :-----: | :-------------------------------------------- | :--: |
|    1    | [**Introduction**](#Chapter-1)                |  2   |
|    2    | [**General Instructions**](#Chapter-2)        |  3   |
|    3    | [**Mandatory part**](#Chapter-3)              |  5   |
|    4    | [**Bonus part**](#Chapter-4)                  |  6   |
|    5    | [**Turn-in and peer evaluation**](#Chapter-5) |  7   |

# Chapter I

## Introduction

##### Ping is the name of a command that allows to test the accessibility of another machine through the IP network.

ping은 ip 네트워크를 통해 다른 기계에 접근할 수 있는지 테스트할 때 사용되는 명령어의 이름입니다.

##### The command measures also the time taken to receive a response, called round-trip time.

이 명령어는 응답이 돌아올 때 까지의 시간인 왕복 지연시간(RTT: rount-trip time)을 측정해주기도 합니다.

# Chapter II

## General Instructions

- ##### This project will be corrected by humans only. You’re allowed to organise and name your files as you see fit, but you must follow the following rules
- 이 프로젝트는 사람들에게만 평가받습니다. 원하는대로 파일 구성이나 파일 이름을 정할 수 있지만, 아래의 규칙들을 따라야 합니다.
- ##### You must use C and submit a Makefile
- C언어를 사용해야 하며, Makefile을 작성해야 합니다.
- ##### Your Makefile must compile the project and must contain the usual rules. It must recompile and re-link the program only if necessary.
- Makefile은 프로젝트를 컴파일함과 동시에 일반적인 명령어들을 포함해야합니다. 다시 컴파일되거나 다시 링킹되는 일은 꼭 필요할 때만 일어나야합니다.
- ##### You have to handle errors carefully. In no way can your program quit in an unex- pected manner (Segmentation fault, bus error, double free, etc).
- 에러를 꼼꼼하게 제어해야합니다. 예상치못한 프로그램 종료는 없어야합니다. (Segmentation fault, bus error, double free, 등등)
- ##### Within the mandatory part, you are allowed to use the following functions:
- 기본 파트에서 아래의 함수들을 사용할 수 있습니다: - getpid - getuid - getaddrinfo - freeaddinfo - gettimeofday - inet_ntop - inet_pton - exit - signal - alarm - setsockopt - recvmsg - sendto - socket - printf와 그 친구들 - libft 함수들 - 보너스 파트를 구현할 때는 평가하는동안 정당화 할 수 있는 아무 함수나 사용하는 것이 허용됩니다. 신중하게 선택하세요.
  > :warning:
  >
  > ##### ATTENTION: Usage of fcntl, poll et ppoll is strictly forbidden
  >
  > 주의사항: fcntl, poll과 ppoll은 엄격하게 금지됩니다.

# Chapter III

## Mandatory Part

- ##### The executable must be named ft_ping.
- 실행파일의 이름은 ft_ping이여야합니다.
- ##### You have to manage the -v -h options.
- -v -h 옵션을 구현해야합니다.
  > :warning:
  >
  > ##### The -v option here will also allow us to see the results in case of a problem or an error linked to the packets, which logically shouldn’t force the program to stop (the modification of the TTL value can help to force an error).
  >
  > -v 옵션을 사용하면 문제 또는 패킷에 연결된 오류의 경우 결과를 볼 수 있기 때문에 논리적으로 프로그램을 강제로 중지해서는 안 됩니다(TTL 값 수정은 오류를 강제하는 데 도움이 될 수 있음)
- ##### You will have to manage a simple IPv4 (address/hostname) as parameters.
- 간단한 IPv4(주소/호스트이름)을 인자로써 사용해아합니다.
- ##### You will have to manage FQDN without doing the DNS resolution in the packet return
- 패킷 반환에서 DNS 확인을 수행하지 않고 FQDN을 관리해야 합니다.
  > :bulb:
  >
  > ##### You are allowed to use all the functions of the printf family as well as one global variable
  >
  > 하나의 전역변수와 printf 가족들을 사용할 수 있습니다.

> :warning:
>
> ##### For the smarty pants (or not)... Obviously you are NOT allowed to call a real ping.
>
> 잘난척하는 놈들을 위해 (아님말고)... 진짜 ping 명령어를 호출하는 것은 분명히 금지됩니다.

# Chapter IV

## Bonus Part

> :warning:
>
> ##### We will look at your bonuses if and only if your mandatory part is EXCELLENT.
>
> 기본 파트가 완벽할 경우에만 보너스 파트를 검토합니다.
>
> ##### This means that your must complete the mandatory part, beginning to end, and your error management must be flawless, even in cases of twisted or bad usage. If that’s not the case, your bonuses will be totally IGNORED
>
> 꼭 기본 파트를 처음부터 끝까지, 잘못된 사용에도 에러 하나 없이 완수해야합니다. 그렇지 않으면 보너스 파트는 무시됩니다.

##### Find below a few ideas of interesting bonuses:

아래에서 흥미로운 보너스 아이디어를 찾아보세요:

- ##### IPv6 management
- IPv6 기능 지원
- ##### Additional -f -m -l -I -m -M -n -w -W -p -Q -S -t -T flags...
- -f -m -l -I -m -M -n -w -W -p -Q -S -t -T 옵션들 구현
  > :bulb:
  >
  > ##### -V is not a bonus
  >
  > -V 옵션은 보너스가 아닙니다.

# Chapter V

## Turn-in and peer evaluation

- ##### Submit your work on your GiT repository as usual. Only the work on your reposi- tory will be graded
- 평소처럼 GiT repo에 작업물을 제출하십시오. repo에 있는 작업물만 평가될겁니다.
- ##### You have to be in a VM with a Linux kernel > 3.14. Note that grading was designed on a Debian 7.0 stable
- Linux 커널이 3.14 이상인 VM에 있어야 합니다. 채점은 Debian 7.0 안정 버전에서 설계되었습니다.
