# page 0

## C++ - Module 06

### C++ Casts

Summary: This document contains the subject for Module 06 of the C++ modules.  
요약: 이 문서에는 C ++ 모듈의 모듈 06에 대한 주제가 포함되어 있습니다.  

# page 1

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__General rules__]() | 2 |
| II | [__Bonus rules__]() | 4 |
| III | [__Exercise 00: Scalar conversion__]() |  5 |
| IV | [__Exercise 01: Serialization__]() |  7 |
| V | [__Exercise 02: Identify real type__]() |  8 |

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
## Bonus rules
## 보너스 규칙

- For each exercise, any cast situation is solved by a specific cast. The evaluation will
check if your choice corresponds to the expected cast.

- 각 연습 문제에 제시된 `cast` 상황은 특정 `cast`에 의해 해결됩니다. 평가는 선택이 예상된 `cast` 동작과 일치하는지 확인하세용.

# page 5

## Chapter III
## 챕터 III
## Exercise 00: Scalar conversion
## 연습 문제 00: 스칼라 변환

```
Exercise 00
Exercise 00: Scalar conversion
Turn-in directory : ex00/
Files to turn in : Any file you need and a Makefile
Allowed functions : Any function to convert from a string to an int, a float or a double. This will help, but won’t do the whole job.
```

```
연습 문제 : 00
연습 문제 00: 스칼라 변환
제출 디렉터리 : ex00/
제출할 파일 : 필요한 모든 파일과 Makefile
허용 함수 : string에서 int, float 또는 double로 변환하는 모든 함수. 이 함수들은 도움을 줄 순 있지만 전체 과제를 수행하지는 않습니다.
```

Write a program that takes a string representation of a C++ literal value (in its most common form) as a parameter. This literal must belong to one of the following a scalar types: char, int, float or double. Only the decimal notation will be used.  

C++ literal value(가장 일반적인 형식)의 `string` 표현을 매개 변수로 사용하는 프로그램을 작성합니다. 이 `literal`은 반드시 char, int, float 또는 double과 같은 스칼라 유형 중 하나에 속해야합니다. 십진수 표기법만 사용됩니다.  

Examples of char literal values: ’c’, ’a’... To simplify, please note that: non displayable characters can’t be passed as a parameter to your program, and if a conversion to char is not displayable, output a notification instead.  

`char literal value`의 예 : 'c', 'a'... 단순화하기 위해, 메모 해주세요: 표시할 수 없는 문자는 프로그램에 매개 변수로 전달할 수 없으며, `char`로의 변환이 표시될 수 없는 경우 알림을 대신 출력하세요.  

Examples of int literal values: 0, -42, 42...  

`int literal value`의 예 : 0, -42, 42 ...  

Examples of float literal values: 0.0f, -4.2f, 4.2f... You will also accept these pseudo literals as well, you know, for science: -inff, +inff and nanf.  

`float literal value`의 예: 0.0f, -4.2f, 4.2f... 과학을 위해 이러한 의사 리터럴도 허용합니다: -inff, + inff 및 nanf.  

Examples of double literal values: 0.0, -4.2, 4.2... You will also accept these pseudo literals as well, you know, for fun: -inf, +inf and nan.  

`double literal value`의 예: 0.0, -4.2, 4.2... 재미로 다음과 같은 의사 리터럴도 허용합니다: -inf, + inf 및 nan  

Your program must detect the literal’s type, acquire that literal in the right type (so it’s not a string anymore), then convert it explicitly to each of the three other types and display the results using the same formatting as below. If a conversion does not make sense or overflows, display that the conversion is impossible. You can include any header you need to handle numeric limits and special values.  

프로그램은 `literal`의 타입을 감지하고 올바른 유형의 `literal`을 획득한 다음(더 이상 문자열이 아님), 다른 세가지 유형으로 명시적으로 변환하고 아래와 같은 형식을 사용하여 결과를 표시해야합니다. 변환이 의미가 없거나 `overflow`시 변환이 불가능함을 표시하세요. 숫자 제한 및 특수 값을 처리하는 데 필요한 헤더를 포함할 수 있습니다.  

# page 6

Examples:  
예:  

```sh
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

# page 7

## Chapter IV
## 챕터 IV
## Exercise 01: Serialization
## 연습 문제 01: 직렬화

```
Exercise 01
Exercise 01: Serialization
Turn-in directory : ex01/
Files to turn in : Any file you need and a Makefile
Allowed functions : None
```

```
연습 문제 01
연습 문제 01: 직렬화
제출 디렉터리 : ex01/
제출할 파일 : 필요한 모든 파일과 Makefile
허용 함수 : 없음
```

Write a function "void * serialize(void);". This function will return the address on the heap of a sequence of bytes that represent a piece of serialized data. The serialized data is the concatenation of a random array of 8 alphanumerical characters, a random integer and a second random array of 8 alphanumerical characters. Feel free to use anything you like to generate the random values.  

"void * serialize (void);" 함수를 작성하세요. 이 함수는 직렬화된 데이터 조각을 나타내는 연속적인 바이트의 힙의 주소를 반환합니다. 직렬화된 데이터는 8개의 영숫자 문자로 구성된 임의 배열, 임의의 정수 및 8개의 영숫자 문자로 구성된 두 번째 임의 배열의 결합입니다. 임의의 값을 생성하기 위해 원하는 것을 자유롭게 사용하세요.  

Write a function "Data * deserialize(void * raw);". This function will deserialize the raw data to a Data structure defined as "struct Data { std::string s1; int n; std::string s2; };" allocated on the heap.  

"Data * deserialize (void * raw);"함수를 작성하세요. 이 함수는 `raw` 데이터를 힙에 할당된 "struct Data { std::string s1; int n; std::string s2; };"로 정의된 데이터 구조로 역직렬화합니다.  

Wrap these two functions in a program that proves that everything works as intended.  

모든 것이 의도한대로 작동함을 보여주는 이 두 함수를 프로그램에 만들어 마무리 해보아요.  

# page 8

## Chapter V
## 챕터 V
## Exercise 02: Identify real type
## 연습 문제 02: 실제 유형 식별

```
Exercise 02
Exercise 02: Identify real type
Turn-in directory : ex02/
Files to turn in : Any file you need and a Makefile
Allowed functions : None
```

```
연습 문제 02
연습 문제 02: 실제 유형 식별
제출 디렉터리 : ex02/
제출할 파일 : 필요한 모든 파일과 Makefile
허용 함수 : 없음
```

Create a class Base that only possesses a public virtual destructor. Create three empty classes A, B and C that publicly inherit from Base.  

`public virtual destructor`만 소유하는 클래스 Base를 생성합니다. Base에서 공개적으로 상속하는 세 개의 빈 클래스 A, B 및 C를 생성합니다.  

Write a function "Base * generate(void);" that randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free to use anything you like for the randomness.  

"Base * generate(void);" 함수를 작성하세요. A, B 또는 C를 무작위로 인스턴스화하고 인스턴스를 Base 포인터로 반환합니다. 임의성을 위해 원하는 것을 자유롭게 사용하세요.  

Write a function "void identify_from_pointer(Base * p);" that displays "A", "B" or "C" according to the real type of p.  

p의 실제 타입에 따라 "A", "B" 또는 "C"를 출력하는 "void identity_from_pointer(Base * p);" 함수를 작성하세요.  

Write a function "void identify_from_reference(Base & p);" that displays "A", "B" or "C" according to the real type of p.  

p의 실제 타입에 따라 "A", "B" 또는 "C"를 출력하는 "void identify_from_reference(Base & p);" 함수를 작성하세요.  

Wrap these three functions in a program that prooves that everything works as intended. Including <typeinfo> is forbidden.  

모든 것이 의도한대로 작동함을 보여주는 이 세가지 함수를 프로그램에 만들어 마무리 해보아요. `<typeinfo>`를 포함하는 것은 금지되어 있습니다.  