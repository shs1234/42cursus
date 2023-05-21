# page 0

## C++ - Module 03
## C++ - 모듈 03

### Inheritance

Summary: This document contains the subject for Module 03 of the C++ modules.  
요약: 이 문서에는 C ++ 모듈의 모듈 03에 대한 주제가 포함되어 있습니다.  

# page 1

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__General rules__]() | 2 |
| II | [__Exercise 00: Aaaaand... OPEN!__]() | 4 |
| III | [__Exercise 01: Serena, my love!__]() |  6 |
| IV | [__Exercise 02: Repetitive work__]() |  8 |
| V | [__Exercise 03: Now it’s easier!__]() |  9 |
| VI | [__Exercise 04: Ultimate assault shoebox__]() |  10 |

# page 2

## Chapter I
## 챕터 I
## General rules
## 일반적인 규칙

- Any function implemented in a header (except in the case of templates), and any unprotected header, means 0 to the exercise.

- 헤더에 구현된 어떤 기능 (템플릿의 경우 제외) 및 보호되지 않은 헤더는 평가 과정에서 0을 의미합니다.

- Every output goes to the standard output, and will be ended by a newline, unless specified otherwise.

- 모든 출력은 표준 출력으로 전달되며 달리 지정하지 않는 한 개행으로 끝납니다.

- The imposed filenames must be followed to the letter, as well as class names, function names and method names.

- 부과된 파일 이름 뒤에는 클래스 이름, 함수 이름 및 메소드 이름뿐만 아니라 문자가 와야합니다.

- Remember: You are coding in C++ now, not in C anymore. Therefore:
  - The following functions are FORBIDDEN, and their use will be punished by a 0, no questions asked: *alloc, *printf and free.
  - You are allowed to use basically everything in the standard library. HOWEVER, it would be smart to try and use the C++-ish versions of the functions you are used to in C, instead of just keeping to what you know, this is a new language after all. And NO, you are not allowed to use the STL until you actually are supposed to (that is, until module 08). That means no vectors/lists/maps/etc... or anything that requires an include \<algorithm> until then.

- 기억하세요: 이제 당신은 더 이상 C가 아닌 C++로 코딩하고 있습니다. 따라서:
  - \*alloc, \*printf 및 free와 같은 함수는 금지되어 있으며 사용시 0으로 처벌됩니다.
  - 기본적으로 표준 라이브러리의 모든 것을 사용할 수 있습니다. 그러나 알고 있는 내용을 그대로 유지하는 대신 이것은 결국 새로운 언어이기 때문에, C에서 익숙한 함수의 C++ 버전을 사용하는 것이 현명할 것입니다. STL을 사용하기로 되어있는 모듈(cpp module 08) 전 까지는 STL 을 사용하실 수 없습니다. 즉, 그때까지 벡터/리스트/맵/등등 또는 \<algorithm> 헤더에 포함된 어떤 것도 쓸 수 없음을 의미합니다.

- Actually, the use of any explicitly forbidden function or mechanic will be punished by a 0, no questions asked.

- 실제로, 명시적으로 금지된 기능이나 방법은 가차없이 0점으로 처벌됩니다.

- Also note that unless otherwise stated, the C++ keywords "using namespace" and "friend" are forbidden. Their use will be punished by a -42, no questions asked.

- 또한 달리 명시되지 않는 한 C++ 키워드 "using namespace" 및 "friend"는 금지됩니다. 그들의 사용은 가차없이 -42로 처벌될 것입니다.

- Files associated with a class will always be ClassName.hpp and ClassName.cpp, unless specified otherwise.

- 클래스와 연관된 파일은 달리 지정하지 않는 한 항상 ClassName.hpp 및 ClassName.cpp입니다.

- Turn-in directories are ex00/, ex01/, . . . , exn/.

- 제출 디렉토리는 ex00 /, ex01 /,. . . , exn/ 입니다.

- You must read the examples thoroughly. They can contain requirements that are not obvious in the exercise’s description. If something seems ambiguous, you don’t understand C++ enough.

- 예제를 철저히 읽어야합니다. 여기에는 연습 설명에서 명확하지 않은 요구 사항이 포함될 수 있습니다. 모호해 보이는 것이 있으면 C++를 충분히 이해하지 못하는 것입니다.

- Since you are allowed to use the C++ tools you learned about since the beginning, you are not allowed to use any external library. And before you ask, that also means no C++11 and derivates, nor Boost or anything your awesomely skilled friend told you C++ can’t exist without.

- 처음부터 배운 C++ 도구를 사용할 수 있으므로 외부 라이브러리를 사용할 수 없습니다. 미리 말씀드리지만, C++11, Boost, 프로그래밍을 잘하는 친구가 c++은 이거 없으면 시체라고 추천한 툴들을 포함한 그 어떤 외부 라이브러리도 사용할 수 없습니다

# page 3

- You may be required to turn in an important number of classes. This can seem tedious, unless you’re able to script your favorite text editor.

- 상당한 수의 클라스들을 제출해야 할 수도 있습니다. 좋아하는 텍스트 편집기를 스크립팅 할 수 없다면 지루해 보일 수 있습니다.

- Read each exercise FULLY before starting it! Really, do it.

- 시작하기 전에 각 연습 문제를 완전히 읽으십시오! 정말로, 하세요.

- The compiler to use is clang++.

- 사용할 컴파일러는 clang ++입니다.

-  Your code has to be compiled with the following flags : -Wall -Wextra -Werror.

- 다음 플래그를 사용하여 코드를 컴파일해야합니다: -Wall -Wextra -Werror.

- Each of your includes must be able to be included independently from others. Includes must contains every other includes they are depending on, obviously.

- 각 includes는 다른 것들과 독립적으로 포함될 수 있어야합니다. Includes는 분명히 그들이 의존하는 다른 모든 include를 포함해야합니다.

- In case you’re wondering, no coding style is enforced during in C++. You can use any style you like, no restrictions. But remember that a code your peer-evaluator can’t read is a code she or he can’t grade.

- 혹시 궁굼할까봐 말씀드리지만, C++에서는 코딩 스타일이 강제되지 않습니다. 제한없이 원하는 스타일을 사용할 수 있습니다. 하지만 동료 평가자가 읽을 수 없는 코드는 점수를 매길 수 없는 코드라는 점을 기억하세요.

- Important stuff now : You will NOT be graded by a program, unless explictly stated in the subject. Therefore, you are afforded a certain amount of freedom in how you choose to do the exercises. However, be mindful of the constraints of each exercise, and DO NOT be lazy, you would miss a LOT of what they have to offer !

- 지금 중요한 사항 : 서브젝트에 명시적으로 언급되지 않는 한 프로그램에 의해 평가되지 않습니다. 따라서 연습 문제를 선택하는 방법에 있어 어느 정도의 자유가 주어집니다. 그러나 각 연습 문제의 제약을 염두에 두고 게을러지지 마세요, 그들이 제공해야하는 많은 것을 놓칠 것입니다 !

- It’s not a problem to have some extraneous files in what you turn in, you may choose to separate your code in more files than what’s asked of you. Feel free, as long as the result is not graded by a program.

- 제출한 파일에 관련없는 파일이 있는 것은 문제가 되지 않습니다. 요청한 것보다 더 많은 파일에서 코드를 분리하도록 선택할 수 있습니다. 결과가 프로그램에 의해 평가되지 않는한 자유롭게 평가하시면 됩니다.

- Even if the subject of an exercise is short, it’s worth spending some time on it to be absolutely sure you understand what’s expected of you, and that you did it in the best possible way.

- 연습 문제의 주제가 짧더라도 자신에게 기대되는 바를 이해하고 가능한 최선의 방법으로 수행했는지 확인하기 위해 시간을 할애 할 가치가 있습니다.

- By Odin, by Thor! Use your brain!!!

- 오딘, 토르! 머리를 써라!!!

# page 4

## Chapter II
## 챕터 II
## Exercise 00: Aaaaand... OPEN!

```
Exercise : 00
Aaaaand... OPEN!
Turn-in directory : ex00/
Files to turn in : FragTrap.cpp FragTrap.hpp main.cpp
Forbidden functions : None
```

Here you have to make a class that models the FR4G-TP assault robot/shoebox.  

The class will be called FragTrap, and will have the following attributes, initialized
to the specified values:  

- Hit points (100)
- Max hit points (100)
- Energy points (100)
- Max energy points (100)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (30)
- Ranged attack damage (20)
- Armor damage reduction (5)

You will also give it a few functions to make it more life-like:  

- rangedAttack(std::string const & target)
- meleeAttack(std::string const & target)
- takeDamage(unsigned int amount)
- beRepaired(unsigned int amount)

# page 5

In all of these functions, you have to display something to describe what happens.
For example, the rangedAttack function may display something along the lines of:  

__FR4G-TP <name> attacks <target> at range, causing <damage> points of damage!__

The constructor and destructor must also display something, so people can see they
have been called properly. Bonus points if these messages are funny references (If you
don’t know what a FR4G-TP is, Google it at least, and use a few well-chosen quotes ...)  

A few constraints:  

- The number of hit points can never exceed the number of max hit points. Same for
the energy points. If, for example, you repair too much HP, then you set them to
the max HP number. In the same way, they can’t fall below 0.

- When you take damage, you have to take your armor damage reduction into account.

Finish by adding a vaulthunter_dot_exe(std::string const & target) function,
that will effect a semi-random attack on the target. Make it so each time it is called, it
chooses a (preferably) funny attack chosen at random from a pool of at least 5 possible
attacks. Whatever you want to use to accomplish this is fine, but as usual, the more
elegant your method, the better. This function costs 25 energy points to run. If you
don’t have enough energy points, it will do nothing else than print something indicating
it’s out of energy.  

You will provide a main function, with enough tests to demonstrate that your code is
functional.  

# page 6

## Chapter III
## 챕터 III
## Exercise 01: Serena, my love!

```
Exercise : 01
Serena, my love!
Turn-in directory : ex01/
Files to turn in : Same as previous exercise + ScavTrap.cpp ScavTrap.hpp
Forbidden functions : None
```

Because we can’t ever have enough Claptraps, now you will make another one that
serves a slightly different purpose: Manning the door of your soon-to-be evil lair, and
challenging people who want to come in.  

The class will be named ScavTrap, and will have these attributes:  

- Hit points (100)
- Max hit points (100)
- Energy points (50)
- Max energy points (50)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (20)
- Ranged attack damage (15)
- Armor damage reduction (3)

Add the same functions as in the FragTrap, but the constructor, destructor, and attacks have to use different outputs. After all, a Claptrap has to have some measure of
individuality.  

# page 7

The one exception will be that the ScavTrap doesn’t have a vaulthunter_dot_exe
function. Instead, it has a challengeNewcomer function, which makes the ScavTrap
choose a challenge at random from a set of various (and hopefully funny) challenges you
will have to invent, and print it on the standard output.  

Extend your main function to test both classes.  

# page 8

## Chapter IV
## 챕터 IV
## Exercise 02: Repetitive work

```
Exercise : 02
Repetitive work
Turn-in directory : ex02/
Files to turn in : Same as previous exercise + ClapTrap.cpp ClapTrap.hpp
Forbidden functions : None
```

Making Claptraps is probably starting to get on your nerves, isn’t it?  

Well, before you can work less, you have to work more.  

Now you will make a ClapTrap class, that both FragTrap and ScavTrap will inherit
from.  

You will put all the common functions in the ClapTrap class, but the specific functions
must remain where they are. In other words, you must make sure that the FragTrap
and ScavTrap classes contain only what isn’t shared between the both of them, and put
everything they both share in the parent class.  

The ClapTrap class will have its own construction and destruction messages. Also,
proper construction/destruction chaining must be present (When you build a FragTrap,
you must start by building a ClapTrap... Destruction is in reverse order), and the tests
have to show it.  

# page 9

## Chapter V
## 챕터 V
## Exercise 03: Now it’s easier!

```
Exercise : 03
Now it’s easier!
Turn-in directory : ex03/
Files to turn in : Same as previous exercise + NinjaTrap.cpp NinjaTrap.hpp
Forbidden functions : None
```

Using everything you have done before, make a NinjaTrap, with the following attributes:  

- Hit points (60)
- Max hit points (60)
- Energy points (120)
- Max energy points (120)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (60)
- Ranged attack damage (5)
- Armor damage reduction (0)

Its special attack will be the ninjaShoebox function. There will be multiple functions
with the same signature, each taking a reference to a different Claptrap as parameter (including the NinjaTrap), and having a different action. Too bad there isn’t a way to make
it take ANY Claptrap but still react in specific ways... Oh well, you’ll see tomorrow. Even
I don’t know what it does exactly, make it do something funny.  

As usual, your main will be extended to test the new class.  

Do you notice how easy it is to make a new Claptrap now that you have a parent
class for it?  

# page 10

## Chapter VI
## 챕터 VI
## Exercise 04: Ultimate assault shoebox

```
Exercise : 04
Ultimate assault shoebox
Turn-in directory : ex04/
Files to turn in : Same as previous exercise + SuperTrap.cpp SuperTrap.hpp
Forbidden functions : typeid() and more, read the warnings
```

Now, you will combine the best of both worlds by making a Claptrap that’s half Fragtrap, half Ninjatrap.  

It will be named SuperTrap, and it will inherit from both the FragTrap AND the
NinjaTrap.  

Its attributes and functions will be chosen from either of its parent classes:  

- Hit points (Fragtrap)
- Max hit points (Fragtrap)
- Energy points (Ninjatrap)
- Max energy points (Ninjatrap)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (Ninjatrap)
- Ranged attack damage (Fragtrap)
- Armor damage reduction (Fragtrap)
- rangedAttack (Fragtrap)
- meleeAttack (Ninjatrap)

# page 11

It will have the special attacks of both.  

As usual, your main will be extended to test the new class.  

Of course, the Claptrap part of the Supertrap will have to be created once, and only
once... Yes, there’s a trick. Look it up.  