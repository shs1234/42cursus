# **D02 - Piscine Python-Django**

## 파이썬 기초 2

_요약: 오늘은 P00에서 새롭게 배운 파이썬 기술을 들고 실리콘 밸리를 정복하러 떠나볼 겁니다!._

##### _번역 오류 및 오역 제보는 42seoul_club_translate 채널 또는 @jiychoi 로 연락주세요._

<br>

# Contents

| Chapter | Contents                                 | page |
| :-----: | :--------------------------------------- | :--: |
|    1    | [**Preamble**](#Chapter-1)               |  2   |
|    2    | [**Instructions**](#Chapter-2)           |  3   |
|    3    | [**Today's specific rules**](#Chapter-3) |  4   |
|    4    | [**Exercise 00**](#Chapter-4)            |  5   |
|    5    | [**Exercise 01**](#Chapter-5)            |  7   |
|    6    | [**Exercise 02**](#Chapter-6)            |  8   |
|    7    | [**Exercise 03**](#Chapter-7)            |  10  |
|    8    | [**Exercise 04**](#Chapter-8)            |  12  |
|    9    | [**Exercise 05**](#Chapter-9)            |  14  |
|   10    | [**Exercise 06**](#Chapter-10)           |  16  |

<br>

# **Chapter 1**

## Preamble

<br>

이것은 '자유 소프트웨어 노래' 의 가사입니다:

```
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Hoarders can get piles of money,
That is true, hackers, that is true.
But they cannot help their neighbors;
That’s not good, hackers, that’s not good.
When we have enough free software
At our call, hackers, at our call,
We’ll kick out those dirty licenses
Ever more, hackers, ever more.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
Join us now and share the software;
You’ll be free, hackers, you’ll be free.
```

<br>

# **Chapter 2**

## Instructions

<br>

노골적인 모순이 없는 이상, 해당 지침은 Python Django Piscine 모든 날짜에 적용됩니다.

- 이 페이지에 있는 내용만이 레퍼런스로 적용됩니다. 루머를 믿지 마세요!

- 조심하세요! 과제를 제출하기 한 시간 전까지도 해당 문서는 변경될 수 있습니다.

- 이번 과제들은 난이도별로 배치되어 있습니다 - 쉬운 것부터 어려운 것 까지요. 만약 쉬운 과제가 제대로 작동하지 않으면, `우리는 절 대` 어려운 과제를 (완벽하게 구현하였더라도) 채점하지 않을 것입니다.

- 파일과 디렉토리에 적절한 권한 설정을 해 주었는지 확인하세요.

- 각 과제별로 **제출 필수사항**을 지키셔야 합니다.

- 여러분의 과제는 같은 피씨너들에게 채점받고 점수가 매겨질 것입니다.

- 그리고 그 뒤에, 뮬리넷이라는 프로그램에 의해 채점되고 점수가 매겨질 것입니다. 뮬리넷은 여러분의 과제를 정말 엄격하고 꼼꼼하게 채점할 것입니다. 또한 모든 작업은 자동으로 진행되므로, 여러분이 뮬리넷과 협상하는 것은 불가능합니다. 좋지 못한 결과를 깜짝 선물로 받고 싶지 않다면, 철저히 과제에 임하세요.

- 쉘 과제들은 `/bin/sh`에 의해 실행될 수 있어야 합니다.

- 여러분은 **절대로** 명시된 제출 파일 외의 다른 파일들을 폴더 내에 남겨두시면 **안됩니다.**

- 질문 있으세요? 오른쪽 동료에게 물어보세요. 아니면 왼쪽 동료한테 물어보세요.

- 여러분이 참고할 만한 가이드는 `Google / man / 인터넷` 등이 있습니다.

- 인트라나 슬랙의 피씬 채널에서 토의하는 것을 잊지 마세요!

- 예시를 꼼꼼히 살펴보세요. 과제에 명시되지 않은 상세한 부분들이 들어있을 수도 있으니까요..

<br>

# Chapter 3

## Today's specific rules

- 전역에 코드를 작성하지 마세요. 우리는 함수를 원해요!

- 다른 말이 명시되어 있지 않은 이상, 모든 제출 파일은 다음과 같이 끝나야 합니다 :

```
if __name__ == '__main__':
    # 여러분이 수행할 동작과 오류 처리
```

- 처리되지 않은 예외는 과제를 무효화할 것입니다. 심지어 테스트해야 하는 오류가 발생했더라도 말이죠..

- 각 과제별 설명란의 'Authorized functions' 에 명시되어 있는 함수 / 라이브러리 외에는 import가 절대 금지됩니다.

<br>

# Chapter 4

## Exercise 00

<br>

| **Piscine**                           | Exercise 00                             |
| ------------------------------------- | --------------------------------------- |
| Exercise 00 : 실리콘 밸리를 정복하라! |
| **제출할 폴더**                       | ex00/                                   |
| **제출할 파일**                       | `render.py, myCV.template, settings.py` |
| **허용되는 함수**                     | `import sys, os, re`                    |

<br>

여러분은 방금 놀라운 개발자 양성 코스를 완벽하게 통과했습니다! 이제 여러분은 인생을 영원히 바꿔줄 새로운 관점으로 세상을 보게 됩니다. 여러분은 방금 딱 하나의 목표를 가지고 실리콘 밸리에 도착했습니다 : 대박 쩌는 기술로 혁신적인 이력서 생성기를 개발하고 구인구직 업계의 빌 게이츠가 되겠다는 목표 말이죠!

그래서 여러분이 해야할 일은... 해당 기술을 직접 만들어야 합니다.

`.template` 확장자의 파일을 인자로 받는 `render.py` 프로그램을 만드세요. 프로그램은 파일의 내용물을 읽고, 몇몇 패턴을 `settings.py`에 선언된 값으로 변경하고 (`settings.py`에서 `if __name__ == '__main__'` 블록은 필요하지 않습니다.), 결과물을 `.html` 확장자로 저장해야 합니다.

여러분은 다음과 같은 예시를 직접 만든 프로그램에 _시험해 보셔야_ 합니다 :

```sh
$> cat settings.py
name = "duoquadragintian"
$> cat file.template
<p>"-Who are you?
-A {name}!"</p>
$> python3 render.py file.template
$> cat file.html
<p>"-Who are you?
-A duoquadragintian!"</p>
```

잘못된 파일 확장자, 존재하지 않는 파일 또는 잘못된 인자값 개수 등의 예외는 알맞게 처리되어야 합니다.

여러분은 `myCV.template` 파일을 제출해야 하고, 해당 파일은 HTML로 변환되었을 때 최소한 html과 이력서의 기본 구조 (`doctype, head, body`, 페이지의 title, 이력서 작성자의 이름과 성씨, 나이와 직업) 를 포함해야 합니다. 물론, 이러한 정보들은 `.template` 파일에 직접적으로 표시되진 않을 것입니다.

> 💡 <br>
> help(globals), 키워드 확장...

<br>

# Chapter 5

## Exercise 01

<br>

| **Piscine**                                                           | Exercise 01 |
| --------------------------------------------------------------------- | ----------- |
| Exercise 01 : 스타트업 설립하고 인턴 모집하기. 10년 정도의 경력 필요. |
| **제출할 폴더**                                                       | ex01/       |
| **제출할 파일**                                                       | `intern.py` |
| **허용되는 함수**                                                     |             |

<br>

이 머나먼 여정을 혼자 떠나기엔 부족합니다. 여러분은 ~~커피를 타줄~~ 여러분을 도와줄 사람을 고용하기로 했습니다. 인턴이 더 나을 것 같네요? (고용비가 싸니까요)

다음 기능을 가진 `Intern` 클래스를 생성하세요 :

- `builder` 는 문자 체인을 매개 변수로 받아 `Name` 속성 (attribute) 에 값을 할당해줍니다. `"My name? I’m nobody, an intern, I have no name."` 이 기본값으로 설정됩니다.

- `__str__()` 메소드는 인스턴스의 `Name` 속성을 리턴합니다.

- 간단한 `__str__()` 메소드를 갖는 `coffee` 클래스는 `""This is the worst coffee you ever tasted."` 라는 문자 체인을 반환합니다.

- `work()` 메소드는 `"I’m just an intern, I can’t do that..."` 이라는 텍스트를 갖는 딱 하나의 예외만을 제시합니다. (basic (Exception) 형식을 사용하세요.)

- `make-coffee()` 메소드는 여러분이 `Intern` 클래스에 추가했던 `Coffee` 클래스의 인스턴스 하나를 리턴합니다.

테스트 시에는, `Intern` 클래스의 인스턴스 두 개를 생성해볼 것입니다. 하나는 이름이 없고, 하나는 "Mark" 라는 이름을 가질 거에요.

두 인스턴스의 이름을 출력하세요. Mark에게 커피를 끓여달라 하고 그 결과를 출력하세요. 다른 인턴에겐 일을 시키세요. 테스트 시에는 예외들을 전부 관리해 주어야 합니다.

<br>

# Chapter 6

## Exercise 02

<br>

| **Piscine**                 | Exercise 02    |
| --------------------------- | -------------- |
| Exercise 02 : 5 클래스 1 컵 |
| **제출할 폴더**             | ex02/          |
| **제출할 파일**             | `beverages.py` |
| **허용되는 함수**           |                |

<br>

커피는 좋지만, 여러분이 원하는 음료를 고를 수 있다면 더욱 좋겠죠! 다음 기능을 가진 `HotBeverage` 클래스를 생성하세요 :

- 0.30이라는 값을 가진 `price` 속성

- `"hot beverage"` 라는 값을 가진 `name` 속성

- 인스턴스의 설명을 리턴하는 `description()` 메소드. 설명 값은 `"Just some hot water in a cup."` 입니다.

- 인스턴스의 설명을 다음과 같은 형식으로 리턴하는 `__str__()` 메소드 :

```
name : <name attribute>
price : <price attribute limited to two decimal points>
description : <instance's description>
```

인스턴스에 대해서, HotBeverage 인스턴스는 다음과 같이 출력되어야 합니다 :

```
name : hot beverage
price : 0.30
description : Just some hot water in a cup.
```

그리고 다음과 같은 `HotBeverage`의 파생 클래스를 작성하세요 :

```
커피 :
name : "coffee"
price : 0.40
description : "A coffee, to stay awake."

차 :
name : "tea"
price : 0.30
description : "Just some hot water in a cup."

초콜릿 :
name : "chocolate"
price : 0.50
description : "Chocolate, sweet chocolate..."

카푸치노 :
name : "cappuccino"
price : 0.45
description : “Un po’ di Italia nella sua tazza!”
```

> ⚠ <br>
> 반드시 재정의할 필요가 있는 것만 재정의해야 합니다. 고쳐야 될 점이랑, 재정의할 것만... (cf.[DRY](https://en.wikipedia.org/wiki/Don't_repeat_yourself))

테스트 과정에선, `HotBeverage, Coffee, Tea, Chocolate`와 `Cappuccino`를 인스턴스화하고 출력해볼 것입니다.

<br>

# Chapter 7

## Exercise 03

​
<br>

| **Piscine**                    | Exercise 03                |
| ------------------------------ | -------------------------- |
| Exercise 03 : 영광의 커피머씬! |
| **제출할 폴더**                | ex03/                      |
| **제출할 파일**                | `machine.py, beverages.py` |
| **허용되는 함수**              | `import random`            |

<br>
​
짜잔! 여러분의 회사가 제대로 굴러가고 있군요! 여러분이 받은 첫 번째 기부금으로 회사 부지를 마련할 수 있었습니다. 여러분은 이제 커피를 내려줄 인턴도 있고 건물 입구에 경관 정돈용 10레벨짜리 식물도 있네요.

그렇지만 아직 모든 것이 완벽하지는 않습니다. 여러분 인턴이 만드는 커피는 맛이 기분 나쁘도록 없어요! 이 흙덩어리에는 최저시급의 반도 아깝습니다. 그말인즉 여러분들만의 성공을 위해 새로운 설비를 들일 때가 왔습니다!

다음 기능을 만족하는 `CoffeeMachine` 클래스를 만드세요:

- 생성자 (builder).

- `HotBeverage` 클래스를 상속하는 `EmptyCup` 클래스, 이름 (name)은 `"empty cup"`, 가격 (price)은 `0.90`이고 설명 (description)은 `"An empty cup?! Gimme my money back!"` 이어야 합니다.

  내부의 클래스를 사용하기 위해 지난번 과제의 `beverages.py` 파일을 복사해오세요.

- 예외(`Exception`) 클래스를 상속한 `BrokenMachineException` 클래스를 만들고, 텍스트(text)는 `"This coffee machine has to be repaired."` 여야 합니다. 텍스트는 반드시 예외의 생성자(builder)에서 정의되어야 합니다.

- 커피머신을 고쳐서 다시 뜨거운 음료를 내릴 수 있게 할 `repair()` 메소드

- 다음 조건을 만족하는 `serve()` 메소드:

  - **인자**: `HotBeverage` 클래스에서 분기한 클래스를 인자로 받아들일 `self`가 아닌 특별한 인자

  - **반환값**: 메서드는 인자에 기반한 클래스 인스턴스나, 랜덤하게 `EmptyCup` 인스턴스를 반환합니다.

  - **노후화**: 기계가 싸구려라서 10번 사용하면 고장나 버립니다.

  - **고장났을 떄**: `serve()` 메소드를 호출하면 `repair()`메소드를 호출하기 전까지 `CoffeeMachine.BrokenMachineException`를 반환해야 합니다.

  - **수리하기**: `repair()` 메소드를 호출한 후 `serve()`메서드는 음료 10개를 내리고 다시 부숴지기 전까지 예외를 일으키지 않고 정상적으로 작동해야 합니다.

테스트에서 `CoffeeMachine` 클래스의 인스턴스를 만드세요. 기계가 박살날 때까지 `beverages.py`파일의 다양한 음료들을 주문한 다음 나온 음료들을 출력하세요. (그 다음에는 예외들을 확인할 겁니다) 기계를 고친 후 기계가 다시 박살날 때까지 처음부터 다시 진행하세요. (다시 한번 예외를 관리해야 합니다!)
​
<br>

# Chapter 8

## Exercise 04

​
<br>

| **Piscine**                                   | Exercise 04 |
| --------------------------------------------- | ----------- |
| Exercise 04 : 간단한 클래스 ft. 리처드 스톨먼 |
| **제출할 폴더**                               | ex04/       |
| **제출할 파일**                               | `elem.py`   |
| **허용되는 함수**                             |             |

<br>

이제 WEB 가시성 작업을 할 때가 왔습니다. 여러분은 이번에 새롭게 익힌 파이썬 기술들을 이용하여 HTML 컨텐츠들을 효율적으로 디자인하고 싶지만, 그 전에 "초월자" 에게 조언을 듣는 것이 좋다고 판단하였습니다. 여러분은 인턴을 제물로 바쳐 _프로그래밍의 신_ 을 소환하기로 했습니다.

커피머신도 있으니, 이제 인턴은 쓸모가 없잖아요.. 불태워버리죠...

[성(聖) **IGNU**시우스](https://stallman.org/saint.html)가 여러분 앞에 나타나 신성한 계시를 내립니다:

```
HTML 요소들은 거의 비슷한 구조를 공유하는 것을 알고 있느냐?
(태그, 컨텐츠, 속성 등..)
구조를 매번 다시 적는 것보다 파이썬에 전해져 내려오는 신성한 힘을 사용하여
공유되는 구조를 담은 클래스를 만들어 쉽고 간단하게 상속하는 것이 현명할 지어다.
```

말을 마치고 나서야 성 IGNU시우스는 여러분이 작업중이던 Mac을 보더니 사색이 되어, 테스트 파일과 미완성 클래스만을 남겨둔 채 부리나케 날아가 버렸습니다. 여러분은 서둘러 다음 조건을 만족하는 `Elem` 클래스를 만들어야 합니다.. (클래스 내부의 `[...]`을 적절하게 채워넣어야 합니다):

- 원소의 이름, `HTML` 속성과 타입 (심플 또는 이중 태그) 을 인자로 받아들이는 생성자.

- element의 HTML 코드를 반환하는 `__str__()` 메서드.

- 컨텐츠 끝에 원소를 추가할 수 있게 할 `add_content()` 메서드.

- 내장 `Exception` 서브 클래스.

과제를 잘 수행하였다면, 여러분의 `Elem` 클래스를 이용하여 어떠한 `HTML` 원소와 컨텐츠도 표현할 수 있을 것입니다. 끝으로 :

- 부록에 tarball로 제공된 `tests.py` 파일이 제대로 동작해야 합니다. (assertion error 금지, 테스트 결과가 명시적으로 Success 라 출력되어야 합니다.) 당연히, 저희는 과제에서 수행하라고 하지 않은 기능까지 테스트할 정도로 악랄한 사람들이 아닙니다. 하하하... 아니고말고요... 진짜로요.

- 또한 `Elem` 클래스의 도움을 받아 다음 구조를 모방하여 출력해야 합니다:

```html
<html>
  <head>
    <title>"Hello ground!"</title>
  </head>
  <body>
    <h1>"Oh no, not again!"</h1>
    <img src="http://i.imgur.com/pfp3T.jpg" />
  </body>
</html>
```

<br>

# Chapter 9

## Exercise 05

​
<br>

| **Piscine**                     | Exercise 05              |
| ------------------------------- | ------------------------ |
| Exercise 05 : 직접 요소 만들기! |
| **제출할 폴더**                 | ex05/                    |
| **제출할 파일**                 | `elem.py`, `elements.py` |
| **허용되는 함수**               |                          |

<br>
​
축하합니다! 이제 아무 HTML element와 컨텐츠를 만들 수 있게 되었네요. 하지만, 인자로 원소와 속성을 일일히 적어서 인스턴스를 매번 생성하는 건 조금 지루한 작업이지요. 그런 여러분들께 레거시 코드를 이용하여 훨씬 쓰기 쉬운 하위 클래스들을 만들어낼 기회를 드리겠습니다!

지난 번 과제에서 만들었던 `Elem` 클래스를 상속받는 다음 클래스들을 만드세요:

- `html, head, body`
- `title`
- `meta`
- `img`
- `table, th, tr, td`
- `ul, ol, li`
- `h1`
- `h2`
- `p`
- `div`
- `span`
- `hr`
- `br`

각 클래스의 생성자는 컨텐츠를 첫 번째 인자로 받을 수 있어야 하고,

```python
print( Html( [Head(), Body()] ) )`
```

는 다음과 같은 결과를 내보내야 합니다.

```html
<html>
  <head></head>
  <body></body>
</html>
```

`Elem` 내부의 기능들을 현명하게 재사용하세요. 반드시 **상속**을 사용해야 합니다.

이 클래스들이 어떻게 작동하는지, 여러분이 직접 작성한 몇 가지 테스트를 이용하여 기능들을 전부 시연하여야 합니다. 이 클래스들을 작성한 뒤엔 인자값으로 태그의 이름이나 형식을 지정할 필요가 없어지니 아주 간편하지요. 또한 이제 `Elem` 클래스를 직접 인스턴스화할 필요도 없습니다. 사실, 지금부터 `Elem` 클래스의 인스턴스 생성은 **금지**됩니다.

`Elem` 클래스를 직접 사용하는 것보다 파생 클래스들을 사용하는 것의 장점을 알아보기 위해, 지난번 과제에서 만들어냈던 `HTML` 문서 구조를 다시 만들어 보세요. 반드시 새롭게 만든 클래스들을 사용하여야 합니다.

```html
<html>
  <head>
    <title>"Hello ground!"</title>
  </head>
  <body>
    <h1>"Oh no, not again!"</h1>
    <img src="http://i.imgur.com/pfp3T.jpg" />
  </body>
</html>
```

훨씬 간단하죠! 그렇지 않나요? :)

<br>

# Chapter 10

## Exercise 06

​
<br>

| **Piscine**            | Exercise 06                     |
| ---------------------- | ------------------------------- |
| Exercise 06: 검증하기. |
| **제출할 폴더**        | ex06/                           |
| **제출할 파일**        | `Page.py, elem.py, elements.py` |
| **허용되는 함수**      |                                 |

<br>

여러분들이 지금까지 대단한 성과를 내고 있음에도 불구하고, 아직도 처리할 것들이 조금 남아 있습니다. 여러분은 지금 딱 이런 기분이죠: 우리는 누구보다 제약과 도전을 좋아하니까, `HTML` 문서 구조에도 표준 규범 (Norm) 을 적용하는 것은 어떨까?

지금 바로 이전 과제들에서 만들었던 클래스들을 현재 과제 폴더에 복사해오세요!

`Page` 클래스를 만드세요. 해당 클래스의 생성자 (builder)는 `Elem`을 상속받는 클래스 인스턴스를 인자로 받아와야 합니다.

`Page` 클래스는 `is_valid()` 메소드를 이식해야 합니다. 해당 메소드는 다음의 모든 규칙을 지켰을 때 `True`를, 하나라도 지키지 않았을 때 `False`를 전송합니다.

- 만약, 트리 경로에 위치한 노드가 다음과 같은 타입이 아닐 때 : `html, head, body, title, meta, img, table, th, tr, td , ul, ol, li, h1, h2, p, div, span, hr, br 그리고 Text`, 해당 트리는 유효하지 않다고 판단합니다.

- `Html`은 엄격하게 Head **다음에** Body를 가져야 합니다.

- `Head`는 딱 하나의 `Title`만을 가져야 합니다.

- `Body`와 `Div`는 다음과 같은 요소들만을 가져야 합니다 : `H1, H2, Div, Table, Ul, Ol, Span, 그리고 Text`.

- `Title, H1, H2, Li, Th, Td`는 딱 하나의 `Text`만을 가져야 합니다.

- `p`는 `Text`만을 포함해야 합니다.

- `Span`은 `Text`와 `p`만을 포함해야 합니다.

- `Ul`과 `Ol`은 적어도 한 개의 `Li`만을 가져야 하며, `Li`외의 다른 종류의 요소는 불허합니다.

- `Tr`은 적어도 한 개 이상의 `Th` 또는 `Td`만을 가져야 하며, `Th`와 `Td` 끼리는 상호 배타적 (Mutually Exclusive)이어야 합니다.

- `Table`은 하위 원소로 `Tr`만을 가져야 합니다.

여러분의 `Page` 클래스는 다음과 같은 것도 가능해야 합니다:

- 인스턴스를 `출력` 할 때 `HTML` 코드를 화면에 보여줍니다. 조심하세요: `HTML` 코드는 루트 요소 타입이 `Html`일 때만 doctype 다음에 출력되어야 합니다.

- `write_to_file` 메소드를 이용하여 `HTML` 코드를 파일로 출력할 수 있어야 합니다. 해당 메소드는 파일명을 인자값으로 받습니다. 조심하세요: `HTML` 코드는 루트 요소 타입이 `Html`일 때만 doctype 다음에 이어서 저장되어야 합니다.

여러분이 정한 여러 테스트케이스에 대해 `Page` 클래스가 동작하는 것을 시연하고, 위의 모든 기능을 제대로 수행하는 것을 보이세요.
