# **dr-quine**
##### _Project ALGORITHME_
알고리즘 프로젝트
##### _Resume: This project is about making you discover the recursion theorem of Kleene!_
요약: 이 프로젝트는 여러분이 클레이니의 재귀 정리를 발견하도록 도와줄 것입니다!

# Table des matières

| Chapter | Contents                                          | page |
| :-----: | :------------------------------------------------ | :--: |
|    1    | [**Foreword**](#Chapter-1)                        |  2   |
|    2    | [**Introduction**](#Chapter-2)                    |  3   |
|    3    | [**Objectives**](#Chapter-3)                      |  4   |
|    4    | [**General Instructions**](#Chapter-3-1)          |  5   |
|    5    | [**Mandatory Part**](#Chapter-3-2)                |  6   |
|    6    | [**Bonus part**](#Chapter-3-3)                    |  10  |
|    7    | [**Submission and peer-evaluation**](#Chapter-4)  |  11  |

# **Chapitre 1**
## Foreword

![kleene](https://user-images.githubusercontent.com/49232918/150882609-9728ee86-9b49-4122-ad68-a0602b53f4aa.png)

# **Chapitre 2**
## Introduction

##### _A quine is a computer program (a kind of metaprogram) whose output and source code are identical._
프로그램의 출력과 그 프로그램의 소스 코드가 같은 컴퓨터 프로그램(일종의 매타프로그램)을 콰인이라고 부릅니다.
##### _As a challenge or for fun, some programmers try to write the shortest quine in a given programming language._
도전으로 또는 장난으로 일부 프로그래머들은 특정 언어의 가장 짧은 콰인을 만들어보기도 합니다.
##### _The operation that consist of simply opening the source file and displaying it is considered cheating._
단순하게 소스 파일을 열어 그 내용을 출력하는 행위는 부정 행위로 간주합니다.
##### _More generally, a program that uses any data entry cannot be considered a valid quine._
더 일반적으로는, 어떤 형태로든 데이터를 입력받는 프로그램은 올바른 콰인이 아닙니다.
##### _A trivial solution is a program whose source code is empty._
하나의 단순하고 멍청한 솔루션은 소스코드가 비어있는 프로그램입니다.
##### _Indeed, the execution of such a program produces for most languages no output, that is to say the source code of the program._
당연하게도, 대부분의 언어에서 빈 소스를 실행시키면 어떤 출력도 생성되지 않고, 이를 소스코드와 같다고 말할 수도 있습니다.

# **Chapitre 3**
## Objectives

##### _This project invites you to confront the principle of self-reproduction and the problems that derive from  it._
이번 프로젝트는 여러분을 셀프 복제의 원칙과 그것으로부터 파생되는 문제들을 직면하도록 요청할 것입니다.
##### _It is a perfect introduction to more complex projects, particularly malware projects._
더 복잡한 프로젝트, 특히 악성 프로젝트에 대한 완벽한 소개가 될 것입니다.
##### _For the curious ones, I strongly recommend that you watch everything related to fixed points!_
호기심이 많은 분들을 위해, 고정소수점과 관련된 모든 것들을 살펴보기를 강력하게 추천합니다.

# **Chapitre 4**
## General Instructions

- ##### _This project will be corrected by humans only._
  이번 프로젝트는 사람에 의해서만 채점됩니다.
- ##### _You must use **C/ASM** and submit a `Makefile`._
  **C** 또는 **ASM** 을 사용해야 하며, `Makefile` 을 제출해야 합니다.
- ##### _Your `Makefile` must compile the project and must contain the usual rules. It must recompile and re-link the program only if necessary._
  `Makefile` 은 프로젝트를 컴파일해야 하며, 반드시 기본적인 규칙을 포함해야 합니다. 또한 반드시 필요할 때만 recompile, re-link 해야 합니다.
- ##### _You have to handle errors carefully. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc)._
  에러를 주의 깊게 처리해야 합니다. 여러분의 프로그램은 그 어떤 방법으로도 예상치 못한 방법으로 종료되지 않아야 합니다 (Segmentation fault, bus error, double free, etc).
- ##### _You can ask your questions on the forum, on slack..._
  포럼이나 슬랙에 질문할 수 있습니다.

# **Chapitre 5**
## Mandatory Part

##### _For this project, you will have to recode three different programs, each with different properties._
이번 프로젝트에서, 여러분은 서로 다른 속성을 갖는 세 개의 프로그램을 만들어야 합니다.
##### _Each programs will have to be coded in C and in Assembly, and respectivly in a folder named `C` and `ASM`, each folders containing its own Makefile with the usual rules._
각각의 프로그램은 C와 어셈블리로 코드되어야 하고, 각 코드는 `C` 와 `ASM` 폴더에, 각 폴더에는 기본 규칙이 포함된 각자의 Makefile 을 가져야 합니다.
##### _You can validate this project with the C part only, however we strongly invite you to realize the Assembly part for all the next projects in this branch._
이번 프로젝트를 C만으로 통과할 수 있지만, 어셈블리를 이해하고 같이 하는 것이 이 브랜치의 다음 프로젝트를 수행하는데 있어 수월할 것입니다.
##### _The first program must have the features below:_
첫 번째 프로그램은 다음 기능을 가져야 합니다:
- ##### _The  executable must be named `Colleen`._
  실행 파일의 이름은 `Colleen` 입니다.
- ##### _When executed, the program must display on the standard output an output identical to the source code of the file used to compile  the program._
  실행되면, 프로그램은 표준 출력으로 프로그램을 컴파일하는데 사용한 소스 파일을 출력해야 합니다.
- ##### _The source code must contain at least:_
  소스 코드는 최소한 다음을 포함해야 합니다:
  - ##### _A main function._
    메인 함수
  - ##### _Two different comments._
    두 개의 다른 주석
  - ##### _One of the comments must be present in the main function._
    메인 함수에 포함된 하나의 주석
  - ##### _One of the comments must be present outside of your program._
    프로그램 바깥에 존재하는 하나의 주석
  - ##### _Another function in addition to the main function (which of course will be called)_
    메인 함수 외 다른 함수 (당연하게도 호출되어야 함)
##### _See the example below:_
다음 예제를 참고하세요:
```
$> ls -al
total 12
drwxr-xr-x 2 root root 4096 Feb 2 13:26 .
drwxr-xr-x 2 root root 4096 Feb 2 13:26 ..
-rw-r--r-- 1 root root 647 Feb 2 13:26 Colleen.c
$> clang -Wall -Wextra -Werror -o Colleen Colleen.c; ./Colleen > tmp_colleen ; diff tmp_Colleen Colleen.c
$> _
```
##### _For the second program:_
다음은 두 번째 프로그램의 기능입니다:
- ##### _The executable must be named `Grace`._
  실행 파일의 이름은 `Grace` 입니다.
- ##### _When executed, the program writes in a file named `Grace_kid.c`/`Grace_kid.s` the source code of the file used to compile the program._
  실행되면, 프로그램은 `Grace_kid.c`/`Grace_kid.s` 이름의 파일로 프로그램이 컴파일될 때 사용된 소스 파일을 출력해야 합니다.
- ##### _The source code must strickly contain:_
  소스 코드는 철저하게 다음을 포함해야 합니다:
  - ##### _No main declared._
    선언되지 않은 메인
  - ##### _Three defines only._
    오직 세 개의 매크로
  - ##### _One comments._
    하나의 주석
- ##### _The program will run by calling a macro._
  프로그램은 매크로를 호출하는 방식으로 실행됩니다.

##### _See the example below:_
다음 예제를 참고하세요:
```
$> ls -al
total 12
drwxr-xr-x 2 root root 4096 Feb 2 13:30 .
drwxr-xr-x 4 root root 4096 Feb 2 13:29 ..
-rw-r--r-- 1 root root 362 Feb 2 13:30 Grace.c
$>  clang -Wall -Wextra -Werror -o Grace Grace.c; ./Grace ; diff Grace.c Grace_kid.c
$> ls -al
total 24
drwxr-xr-x 2 root root 4096 Feb 2 13:30 .
drwxr-xr-x 4 root root 4096 Feb 2 13:29 ..
-rwxr-xr-x 1 root root 7240 Feb 2 13:30 Grace
-rw-r--r-- 1 root root 362 Feb 2 13:30 Grace.c
-rw-r--r-- 1 root root 362 Feb 2 13:30 Grace_kid.c
$> _
```

##### _For the last program:_
마지막 프로그램에 대한 기능입니다:
- ##### _The executable must be named `Sully`._
  실행 파일의 이름은 `Sully` 입니다.
- ##### _When executed, the program writes in a file named `Sully_X.c`/`Sully_X.s`._
  실행되면, 프로그램은 `Sully_X.c`/`Sully_X.s` 파일을 작성합니다.
- ##### _The `X` will be an integer given in the source._
  `X` 는 소스에 주어진 정수입니다.
- ##### _Once the file is created, the program compiles this file and then runs the new program (which will have the name of its source file)._
  파일이 생성된 후, 프로그램은 해당 파일을 컴파일한 후 컴파일된 프로그램(소스 파일의 이름을 가진)을 실행시킵니다.
- ##### _Stopping the program depends on the file name : the resulting program will be executed only if the integer `X` is greater than 0._
  프로그램을 멈추는 것은 파일의 이름에 달렸습니다. 컴파일 된 프로그램은 정수 `X`가 0보다 클 때만 실행됩니다.
- ##### _An integer is therefore present in the source of your program and will have to evolve by decrementing every time you create a source file from the execution of the program._
  따라서 정수는 프로그램의 소스에 포함되어야 하며, 프로그램의 실행으로 소스 파일이 생성될 때마다 감소하는 방향으로 변할 것입니다.
- ##### _You have no constraints on the source code, apart from the integer that will be set to 5 at first._
  소스 코드의 제한 사항은 없지만, 예외적으로 정수의 초기값은 5로 설정해야 합니다.
##### _See the example below:_
다음 예제를 참고하세요:
```
$> clang -Wall -Wextra -Werror ../Sully.c -o Sully ; ./Sully
$> ls -al | grep Sully | wc -l
13
$> diff ../Sully.c Sully_0.c
1c1
< int i = 5;
---
> int i = 0;
$> diff Sully_3.c Sully_2.c
1c1
< int i = 3;
---
> int i = 2;
$> _
```
##### _A comment must look like :_
주석은 다음과 같아야 합니다 :
```
$> nl comment.c
 1  /*
 2    This program will print its own source when run.
 3  */
```
##### _A program without a declared main must look like :_
메인이 정의되지 않은 프로그램은 다음과 같아야 합니다 :
```
$> nl macro.c
 1  #include
 2  #define FT(x)int main(){ /* code */ }
    [..]
 5  FT(xxxxxxxx)
```
> :information_source:
> ##### _Using advanced macros is strongly recommended for this project._
> 이번 프로젝트에서는 강력한 매크로를 사용하는 것을 강력히 권장합니다.

> :warning:
> ##### _For the smarty pants (or not)... just reading the source and displaying it is considered to be cheating._
> 잘난채하는 사람들을 위해... 단순히 소스를 읽고 출력하는 것은 부정 행위로 간주합니다.
> ##### _The use of argv/argc is also considered cheating._
> argv/argc를 사용하는 것 역시 부정 행위로 간조합니다.
# **Chapitre 6**
## Bonus part
> :warning:
> ##### _We will look at your bonuses if and only if your mandatory part is EXCELLENT._
> 오직 mandatory 파트가 **완벽** 해야지만 보너스를 확인할 것입니다.
> ##### _This means that your must complete entirely the mandatory part, in C and in Assembly, beginning to end, and your error management must be flawless, even in cases of twisted or bad usage._
> 이는 여러분이 반드시 mandatory 파트 전체를, C와 어셈블리로, 처음부터 끝까지 끝내야 하고, 에러 처리는 이상하거나 잘못된 사용 방법으로도 흠잡을 곳 없이 완벽해야 한다는 것을 의미합니다.
> ##### _If that's not  the case, your bonuses will be totally IGNORED_
> 만약 그렇지 않다면, 여러분의 보너스는 완벽히 **무시** 될 것입니다.

##### _The only Bonus accepted during the evaluation is to have redone this project entirely in the language of your choice._
평가 중 인정받을 수 있는 유일한 보너스는 이번 프로젝트를 여러분이 선택한 다른 언어로 완전히 다시 작성하는 것입니다.

> :information_source:
> ##### _In case of a language without define/macro, you will naturally have to adapt the program accordingly._
> define/macro 가 없는 언어의 경우, 해당 기능을 자연스럽게 대체할 수 있는 무언가를 찾아야 할 것입니다.
# **Chapitre 7**
## Submission and peer-evaluation
- ##### _Submit your work on your GiT repository as usual. Only the work on your repository will be graded._
  평소대로 GiT에 결과물을 제출하세요. 레포지토리에 올라온 결과물만 평가됩니다.
