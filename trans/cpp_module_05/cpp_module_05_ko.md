# page 0

## C++ - Module 05
## C++ - 모듈 05

### Repetition and Exceptions

Summary: This document contains the subject for Module 05 of the C++ modules.  
요약: 이 문서에는 C ++ 모듈의 모듈 05에 대한 주제가 포함되어 있습니다.  

# page 1

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__General rules__]() | 2 |
| II | [__Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!__]() | 4 |
| III | [__Exercise 01: Form up, maggots!__]() |  6 |
| IV | [__Exercise 02: No, you need form 28B, not 28C...__]() |  7 |
| V | [__Exercise 03: At least this beats coffee-making__]() |  9 |
| VI | [__Exercise 04: That’s the way I like it, nice and boring__]() |  10 |
| VII | [__Exercise 05: Endless red-tape generator__]() |  13 |

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
## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

```
Exercise : 00
Mommy, when I grow up, I want to be a bureaucrat!
Turn-in directory : ex00/
Files to turn in : Bureaucrat.hpp Bureaucrat.cpp main.cpp
Forbidden functions : None
```

Please note that exception classes do not need to be in Coplien’s Form. Every other
class needs to be in Coplien.  
Today, we’re going to create an artificial nightmare of offices, corridors, forms, and
waiting in line. Sounds fun? No? Too bad.  

First, we start by the smallest cog in the vast bureaucratic machine: the Bureaucrat.  

It must have a constant name, and a grade, that ranges from 1 (highest possible) to
150 (lowest possible). Any attempt to create a Bureaucrat with an invalid grade must
throw an exception, which will be either a Bureaucrat::GradeTooHighException or a
Bureaucrat::GradeTooLowException.  

You will provide getters for both these attributes (getName and getGrade), and two
functions to increment or decrement the grade. Both these functions will throw the same
exceptions as before if the grade gets too high or too low. Remember, grade 1 is highest,
150 is lowest, so incrementing a grade 3 gives you a grade 2...  

The exceptions you throw must be catchable by a block like:  

# page 5

```c++
try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}
```

You will provide an overload of the << operator to ostream that outputs something
like <name>, bureaucrat grade <grade>.  

Of course, you will provide a main function to prove you did all this well.  

# page 6

## Chapter III
## 챕터 III
## Exercise 01: Form up, maggots!

```
Exercise : 01
Form up, maggots!
Turn-in directory : ex01/
Files to turn in : Same as before + Form.cpp Form.hpp
Forbidden functions : None
```

Now that we have bureaucrats, better give them something to do with their time.
What better occupation than a stack of forms to fill out?  

Make a Form class. It has a name, a boolean indicating whether it is signed (at
the beginning, it’s not), a grade required to sign it, and a grade required to execute it.
The name and grades are constant, and all these attributes are private (not protected).
The grades are subject to the same constraints as in the Bureaucrat, and exceptions
will be thrown if any of them are out of bounds, Form::GradeTooHighException and
Form::GradeTooLowException.  

Same as before, make getters for all attributes, and an overload of the << operator
to ostream that completely describes the state of the form.  

You will also add a beSigned function that takes a Bureaucrat, and makes the form
signed if the bureaucrat’s grade is high enough. Always remember, grade 1 is better than
grade 2. If the grade is too low, throw a Form::GradeTooLowException.  

Also add a signForm function to the Bureaucrat. If the signing is successful, it will
print something like "<bureaucrat> signs <form>", otherwise it will print something
like "<bureaucrat> cannot sign <form> because <reason>".  

Add whatever’s needed to test this to your main.  

# page 7

## Chapter IV
## 챕터 IV
## Exercise 02: No, you need form 28B, not 28C...

```
Exercise : 02
No, you need form 28B, not 28C...
Turn-in directory : ex02/
Files to turn in : Same as before + ShrubberyCreationForm.[hpp,cpp]
RobotomyRequestForm.[hpp,cpp] PresidentialPardonForm.[hpp,cpp]
Forbidden functions : None
```
 
Now that you have basic forms, you will make a few forms that actually do something.  

Create a few concrete forms:  

- ShrubberyCreationForm (Required grades: sign 145, exec 137). Action: Create
a file called <target>_shrubbery, and write ASCII trees inside it, in the current
directory.

- RobotomyRequestForm (Required grades: sign 72, exec 45). Action: Makes some
drilling noises, and tell us that <target> has been robotomized successfully 50% of
the time. Otherwise, tell us it’s a failure.

- PresidentialPardonForm (Required grades: sign 25, exec 5). Action: Tells us
<target> has been pardoned by Zafod Beeblebrox.

All of these will have to take only one parameter in their constructor, which will represent the target of the form. For example, "home" if you want to plant a shrubbery at home. Remember the form’s attributes need to remain private, and in the base class.  

Now you need to add a method execute(Bureaucrat const & executor) const to the base form, and implement a method actually executing the form’s action in all the concrete forms. You have to check that the form is signed, and that the bureaucrat attempting to execute the form has a high enough grade, else you will throw an appropriate exception. Whether you want to make these checks in every concrete class or make the check in the base class then calling another method to actually execute the action is up to you, but one way is obviously prettier than the other one. In any event, the base form must be an abstract class.

# page 8

Finish this by adding an executeForm(Form const & form) function to the bureaucrat. It must attempt to execute the form, and if it’s a success, print something like \<bureaucrat> executes \<form>. If not, print an explicit error message.

Add whatever you need to your main to test that everything works.

# page 9

## Chapter V
## 챕터 V
## Exercise 03: At least this beats coffee-making

```
Exercise : 03
At least this beats coffee-making
Turn-in directory : ex03/
Files to turn in : Same as before + Intern.hpp Intern.cpp
Forbidden functions : None
```

Because filling out forms is annoying enough, it would just be cruel to ask our bureaucrats to write them entirely by themselves. No, we’ll just have an intern do that.  

You’re going to create the Intern class. The intern has no name, no grade, no defining characteristics whatsoever, we only care that it does its job.  

The intern has one important thing, the makeForm function. It takes two strings, the
first representing the name of a form, and the second one being the target for the form. It
will return, as a pointer to Form, a pointer to whichever concrete form class is represented
by the first parameter, initialized with the second parameter. It will print something like
"Intern creates \<form>" to the standard output. If it’s using a worse method, like
if/elseif/elseif/else branchings, or some other ugly stuff like this, it will not be accepted
during the evaluation. If the requested form is not known, print an explicit error message.  

For example, this would create a RobotomyRequestForm targeted on "Bender":  

```c++
{
Intern someRandomIntern;
Form* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

Your main must, of course, test all of this.  

# page 10

## Chapter VI
## 챕터 VI
## Exercise 04: That’s the way I like it, nice and boring

```
Exercise : 04
That’s the way I like it, nice and boring
Turn-in directory : ex04/
Files to turn in : Same as before + OfficeBlock.cpp OfficeBlock.hpp
Forbidden functions : None
```

```diff
- This exercise does not offer any points but is still useful. You can do it, or not.
```

The Central Bureaucracy, being the haven of order and organization that it is, is
constituted of cleanly arranged office blocks. Each of these blocks requires an intern and
two bureaucrats to function, and is capable of creating, signing and executing forms, all
by just giving it an order. Cool, isn’t it?  

So, make an OfficeBlock class. It will be constructed by passing pointers to (or references to, you decide depending on what’s appropriate) one intern, one signing bureaucrat
and one executing bureaucrat. It can also be constructed empty. No other construction
must be possible (No copy, no assignation).  

It will have functions to set a new intern, signing bureaucrat, or executing bureaucrat.  

Its only "useful" function will be doBureaucracy, it takes a form name and a target
name. It will attempt to, in order, make the intern create the requested form, have the
first bureaucrat sign it, and have the second bureaucrat execute it. The messages printed
by the intern and bureaucrats will provide a log of what’s happening. When an error
occurs, it must result in an exception being raised from this function: You are free to modify what you did before to make this elegant. Remember: Specific errors are always cool.  

# page 11

Of course, if not all three spots in the block are filled, no bureaucracy can be done.  

As usual, your main must be... well you know the drill.  

# page 12

For example, the following block of code may produce the following output:  

```c++
int main()
{
Intern idiotOne;
Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
OfficeBlock ob;
ob.setIntern(idiotOne);
ob.setSigner(bob);
ob.setExecutor(hermes);
try
{
ob.doBureaucracy("mutant pig termination", "Pigley");
}
catch (Some::SpecificException & e)
{
/* specific known error happens, say something */
}
catch (std::exception & e)
{
/* oh god, unknown error, what to do ?! */
}
}
```

```sh
$> ./ex04
Intern creates a Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on Pigley (Unsigned)
Bureaucrat Bobby Bobson (Grade 123) signs a Mutant Pig Termination Form (s.grade 130, ex.grade 50)
targeted on Pigley (Unsigned)
Bureaucrat Hermes Conrad (Grade 37) executes a Mutant Pig Termination Form (s.grade 130, ex.grade 50)
targeted on Pigley (Signed)
That'll do, Pigley. That'll do...
$>
```

# page 13

## Chapter VII
## 챕터 VII
## Exercise 05: Endless red-tape generator

```
Exercise : 05
Endless red-tape generator
Turn-in directory : ex05/
Files to turn in : Same as before + CentralBureaucracy.cpp CentralBureaucracy.hpp
Forbidden functions : None
```

```diff
- This exercise does not offer any points but is still useful. You can do it, or not.
```

Now you just have to wrap this all up into a neat little package.  

Create the CentralBureaucracy class. It will be created without parameters, and at
its creation will have 20 empty office blocks.  

It will be possible to "feed" bureaucrats to the object. Interns will be generated automatically, without user intervention, because let’s face it, interns are a dime a dozen.  

Bureaucrats that are fed to the object will be used to fill seats in its office blocks. If no
seats are available, you can either reject them, or store them in a waiting area somewhere.  

After that, it will be possible to queue targets in the object, using a queueUp function
that takes a string, the name of the person in queue.  

Finally, when a doBureaucracy function is called, some random bit of bureaucracy
will be done to each one of them, first arrived first served, by each office block in sequence.  

# page 14

So, here’s what your main function might look like:  

- Create the Central Bureaucracy
- Create 20 random bureaucrats and feed them to the Central Bureaucracy
- Queue up a large number of targets in the Central Bureaucracy
- Call the doBureaucracy function and watch magic happen
