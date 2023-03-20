# Pipex

##### _Summary: This project is the discovery in detail and by programming of a UNIX mechanism that you already know._

_요약: 이 프로젝트에서는 여러분이 이미 알고 계신 UNIX 동작 원리를 프로그래밍을 통해 상세히 파헤쳐볼 것입니다._

##### _Version: 2_

_버전 2_

<br>

# Contents

| Chapter |                     Contents                     | page |
| :-----: | :----------------------------------------------: | :--: |
|    I    |            [**Foreword**](#Chapter-1)            |  2   |
|   II    |      [**Common Instructions**](#Chapter-2)       |  3   |
|   III   |           [**Objectives**](#Chapter-3)           |  5   |
|   IV    |           [**Bonus part**](#Chapter-4)           |  6   |
|    V    | [**Submission and peer correction**](#Chapter-5) |  7   |

<br>

# Chapter 1

## Foreword

- ##### _**Cristina**: "`Go dance salsa somewhere :)`"_

  **크리스티나**: "`나랑 살사 춤이나 추러 가지 않을래?` :)"

<br>

# Chapter 2

## Common Instructions

- ##### _Your project must be written in C._

  여러분의 프로젝트는 C언어로 작성되어야 합니다.

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._

  프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 존재할 경우, 그 또한 norm 검사에 포함되며 norm error가 있을 시 0점을 받게 됩니다.

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

  정의되지 않은 동작을 제외하고, 여러분이 작성하신 프로그램이 예기치 않게 중단되어서는 안 됩니다. (예를 들어, segmentation fault, bus error, double free 등) 만약 여러분의 프로그램이 예기치 않게 종료된다면, 제대로 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

  필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납될 수 없습니다.

- ##### _If the subject requires it, you must submit a `Makefile` which will compile your source files to the required output with the flags `-Wall`, `-Wextra` and `-Werror`, and your Makefile must not relink._

  과제에서 필요한 경우, `-Wall -Wextra -Werror` 플래그를 지정하여 컴파일을 수행하는 `Makefile`을 제출해야 합니다. Makefile은 relink 되어서는 안 됩니다.

- ##### _Your `Makefile` must at least contain the rules $(NAME), all, clean, fclean and re._

  `Makefile`은 최소한 `$(NAME), all, clean, fclean, re` 규칙을 포함해야 합니다.

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_`bonus.{c/h}`. Mandatory and bonus part evaluation is done separately._

  프로젝트에 보너스를 제출하려면, Makefile에 `bonus` 규칙을 포함해야 합니다. 이 보너스 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 또는 함수들을 추가하여야 합니다. 보너스 과제는 반드시 \_`bonus.{c/h}`라는 별도의 파일에 있어야 합니다. 반드시 수행하여야 하는 메인 파트의 평가와 보너스 파트의 평가는 별도로 이뤄집니다.

- ##### _If your project allows you to use your `libft`, you must copy its sources and its associated `Makefile` in a `libft` folder with its associated `Makefile`. Your project’s `Makefile` must compile the library by using its `Makefile`, then compile the project._

  만일 프로젝트에서 여러분의 `libft` 사용을 허용한다면, libft 소스들과 관련 `Makefile`을 함께 루트 폴더 안에 있는 `libft` 폴더에 복사해야 합니다. 프로젝트의 `Makefile`은 우선 `libft`의 `Makefile`을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

  **이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도,** 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 수 있게 도울 것입니다. 또한, 평가를 진행할 때 이러한 테스트 프로그램들이 특히 유용하다는 사실을 알게 될 것입니다. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._

  할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이 매겨질 것입니다. Deepthought가 평가하는 과제의 경우엔, 동료평가 이후에 Deepthought가 수행됩니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

- ##### _The executable file must be named `pipex`._

  실행 파일명은 반드시 `pipex` 여야 합니다.

- ##### _You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc). If you are unsure, handle the errors like the shell command `< file1 cmd1 | cmd2 > file2`._

  여러분은 반드시 오류를 세심하게 처리하셔야 합니다. 어떠한 이유 (Segmentation fault, bus error, double free 등) 에서도 프로그램이 예상치 못하게 종료되면 안 됩니다. 오류 처리에 확신이 들지 않는다면, 쉘 커맨드 `< file1 cmd1 | cmd2 > file2` 와 같이 처리하시면 됩니다.

- ##### _Your program cannot have memory leaks._

  프로그램에 메모리 누수가 발생하면 안 됩니다.

- ##### _You are allowed to use the following functions:_

  다음과 같은 함수들을 사용 가능합니다 :

  - `access`
  - `open`
  - `unlink`
  - `close`
  - `read`
  - `write`
  - `malloc`
  - `waitpid`
  - `wait`
  - `free`
  - `pipe`
  - `dup`
  - `dup2`
  - `execve`
  - `fork`
  - `perror`
  - `strerror`
  - `exit`

<br>

# Chapter 3

## Objectives

##### _Your objective is to code the Pipex program._

여러분의 목표는 Pipex 프로그램을 작성하는 것입니다.

##### _It should be executed in this way:_

프로그램은 다음과 같이 실행될 것입니다:

```sh
$> ./pipex file1 cmd1 cmd2 file2
```

##### _Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters._

설명해 드리자면: file1과 file2는 파일명이고, cmd1과 cmd2에는 쉘 명령어와 그에 대한 인자값이 들어갑니다.

##### _The execution of the pipex program should do the same as the next shell command:_

pipex 프로그램의 동작 결과는 다음 명령줄을 쉘에서 실행할 때의 결과와 동일하여야 합니다.

```sh
$> < file1 cmd1 | cmd2 > file2
```

## Chapter 3.1 Examples

```sh
$> ./pipex infile ``ls -l'' ``wc -l'' outfile
```

##### _should be the same as “< infile ls -l | wc -l > outfile”_

는 “< infile ls -l | wc -l > outfile” 와 같이 동작하여야 합니다.

```sh
$> ./pipex infile ``grep a1'' ``wc -w'' outfile
```

##### _should be the same as “< infile grep a1 | wc -w > outfile”_

는 “< infile grep a1 | wc -w > outfile” 와 같이 동작하여야 합니다.

<br>

# Chapter 4

## Bonus part

> ⚠️ <br>
>
> ##### _Bonuses will be evaluated only if your mandatory part is PERFECT. By PERFECT we naturally mean that it needs to be complete, that it cannot fail, even in cases of nasty mistakes like wrong uses, etc. It means that if your mandatory part does not obtain ALL the points during the grading, your bonuses will be entirely IGNORED._
>
> 보너스는 필수로 구현해야 하는 파트가 **완벽할 때**만 평가될 것입니다. 저희가 말하는 '완벽함' 이란, 어떠한 경우에도 - 잘못된 사용과 같은 끔찍한 실수 등 - 실패하지 않고 동작해야 한다는 의미입니다. 쉽게 말하자면, 필수로 구현해야 하는 파트에서 **만점**을 받지 못한다면, 보너스는 완전히 '**무시될**' 것입니다.

- ##### _Handle multiple pipes :_

  다중 파이프 구현하기:

```sh
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

- ##### _Must be equivalent to :_

  의 결과값은 다음과 같아야 합니다:

```sh
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

- ##### _Support « and » when the first parameter is "here_doc"_

  첫 번째 인자값이 "here_doc" 일 경우 <<와 >> 구현하기

```sh
$> ./pipex here_doc LIMITER cmd cmd1 file
```

- ##### _Must be equivalent to:_
  의 결과값은 다음과 같아야 합니다:

```sh
cmd << LIMITER | cmd1 >> file
```

<br>

# Chapter 5

## Submission and peer correction

- ##### _Submit your work on your `GiT` repository as usual. Only the work on your repository will be graded._

  항상 그래왔듯, 여러분의 결과물을 `GIT` 레포지토리에 제출하세요. 레포지토리에 있는 과제물만이 채점될 것입니다.
