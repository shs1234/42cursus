# **D01 - Piscine Python-Django**

## 파이썬 기초

_요약: 오늘은 Python의 통사론 (Syntactics) 과 의미론 (Semantics) 기초를 배울 여행을 떠나 봅니다._

##### _번역 오류 및 오역 제보는 42seoul_club_translate 채널 또는 @jiychoi 로 연락주세요._

<br>

# Contents

| Chapter | Contents                                                        | page |
| :-----: | :-------------------------------------------------------------- | :--: |
|    1    | [**Preamble**](#Chapter-1)                                      |  2   |
|    2    | [**Instructions**](#Chapter-2)                                  |  3   |
|    3    | [**Today's specific rules**](#Chapter-3)                        |  4   |
|    4    | [**Exercise 00 : my first variables**](#Chapter-4)              |  5   |
|    5    | [**Exercise 01 : Numbers**](#Chapter-5)                         |  6   |
|    6    | [**Exercise 02 : My first dictionary**](#Chapter-6)             |  7   |
|    7    | [**Exercise 03 : Key search**](#Chapter-7)                      |  9   |
|    8    | [**Exercise 04 : Search by value**](#Chapter-8)                 |  10  |
|    9    | [**Exercise 05 : Search by key or value**](#Chapter-9)          |  11  |
|   10    | [**Exercise 06 : Dictionary sorting**](#Chapter-10)             |  12  |
|   11    | [**Exercise 07 : Periodic table of the elements**](#Chapter-11) |  13  |

<br>

# **Chapter 1**

## Preamble

<br>

The Zen of Python, by Tim Peters

```
Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.
Special cases aren’t special enough to break the rules.
Although practicality beats purity.
Errors should never pass silently.
Unless explicitly silenced.
In the face of ambiguity, refuse the temptation to guess.
There should be one– and preferably only one –obvious way to do it.
Although that way may not be obvious at first unless you’re Dutch.
Now is better than never.
Although never is often better than *right* now.
If the implementation is hard to explain, it’s a bad idea.
If the implementation is easy to explain, it may be a good idea.
Namespaces are one honking great idea – let’s do more of those!
```

> ℹ️ <br>
> import this

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

- 모든 제출 파일은 다음과 같은 함수 호출로 끝나야 합니다 :

```
if __name__ == '__main__':
your_function( whatever, parameter, is, required )
```

- 해당 환경에서 여러분은 오류 관리를 해도 괜찮습니다.

- 각 과제별 설명란의 'Authorized functions' 에 명시되어 있는 함수 / 라이브러리 외에는 import 하지 마세요.

- open 함수의 예외 처리는 굳이 안 해주어도 괜찮습니다.

- `python3` 인터프리터를 사용합니다.

<br>

# Chapter 4

## Exercise 00 : my first variables

<br>

| **Piscine**           | Exercise 00 |
| --------------------- | ----------- |
| Exercise 00 : 첫 변수 |
| **제출할 폴더**       | ex00/       |
| **제출할 파일**       | `var.py`    |
| **허용되는 함수**     | n/a         |

<br>

`my_var` 함수를 정의하는 `var.py` 스크립트를 작성하세요. 해당 함수에서는, 9개의 서로 다른 자료형을 가진 변수를 선언하고 표준 출력으로 출력해야 합니다. 여러분의 출력물은 정확히 이렇게 생겨야 합니다 :

```sh
$> python3 var.py
42 has a type <class 'int'>
42 has a type <class 'str'>
quarante-deux has a type <class 'str'>
42.0 has a type <class 'float'>
True has a type <class 'bool'>
[42] has a type <class 'list'>
{42: 42} has a type <class 'dict'>
(42,) has a type <class 'tuple'>
set() has a type <class 'set'>
$>
```

당연히, 출력부에 명시적으로 변수 자료형을 적는 행위는 **엄격히 금지됩니다**. 다음 지침을 참고하여, 스크립트의 끝에서 함수를 불러와야 한다는 점을 잊지 마세요 :

```py
if __name__ == '__main__':
my_var()
```

<br>

# Chapter 5

## Exercise 01 : Numbers

<br>

| **Piscine**        | Exercise 01  |
| ------------------ | ------------ |
| Exercise 01 : 숫자 |
| **제출할 폴더**    | ex01/        |
| **제출할 파일**    | `numbers.py` |
| **허용되는 함수**  | `n/a`        |

<br>

이 과제에서는, 여러분이 원하는 대로 함수를 마음껏 선언하셔도 되고, 개수나 이름도 상관 없습니다.

`d01.tar.gz` tarball 안의 `ex01` 폴더에는 `numbers.txt`가 들어있으며, 해당 텍스트 파일에는 1부터 100까지의 숫자가 콤마 (,) 로 구분되어 나열되어 있습니다.

`numbers.py` 라 이름붙여진 `python` 스크립트를 작성하세요. 해당 스크립트를 실행시키면 `numbers.txt`를 읽어들이고, 한 줄에 하나씩 표준 출력으로 출력하되, 콤마 없이 출력해야 합니다.

<br>

# Chapter 6

## Exercise 02 : My first Dictionary

<br>

| **Piscine**               | Exercise 02      |
| ------------------------- | ---------------- |
| Exercise 02 : 첫 딕셔너리 |
| **제출할 폴더**           | ex02/            |
| **제출할 파일**           | `var_to_dict.py` |
| **허용되는 함수**         | `N.A.`           |

<br>

다시 한번, 해당 과제에서는 여러분이 원하는 대로 자유롭게 함수를 선언하시면 됩니다. 이후 과제에서도 명시적으로 부인되지 않는 이상, 해당 내용을 반복해서 말하진 않을게요.

`var_to_dict.py` 라는 스크립트를 작성하세요. 그리고 해당 리스트를 여러분의 함수 중 하나에 복사하세요 :

```python
d = [
('Hendrix' , '1942'),
('Allman' , '1946'),
('King' , '1925'),
('Clapton' , '1945'),
('Johnson' , '1911'),
('Berry' , '1926'),
('Vaughan' , '1954'),
('Cooder' , '1947'),
('Page' , '1944'),
('Richards' , '1943'),
('Hammett' , '1962'),
('Cobain' , '1967'),
('Garcia' , '1942'),
('Beck' , '1944'),
('Santana' , '1947'),
('Ramone' , '1948'),
('White' , '1975'),
('Frusciante', '1970'),
('Thompson' , '1949'),
('Burton' , '1939')
]
```

여러분의 스크립트는 이 변수를 딕셔너리 타입으로 변환하여야 합니다. 연도는 key가 되고, 음악가의 이름은 value가 됩니다. 또한 다음과 같은 깔끔한 형식으로 딕셔너리를 표준 출력해야 합니다 :

```
1970 : Frusciante
1954 : Vaughan
1948 : Ramone
1944 : Page Beck
1911 : Johnson
...
```

> ℹ️ <br>
> 실제 동작 결과와 해당 예시의 순서는 일치할 필요가 없습니다. 이것은 자연스러운 동작입니다. 왠지 아시나요?

<br>

# Chapter 7

## Exercise 03: Key search

​
<br>

| **Piscine**              | Exercise 03       |
| ------------------------ | ----------------- |
| Exercise 03 : Key로 찾기 |
| **제출할 폴더**          | ex03/             |
| **제출할 파일**          | `capital_city.py` |
| **허용되는 함수**        | `import sys`      |

<br>
​
이것은 여러분의 프로그램의 함수 내부에 수정하지 않고 복사해 넣어야 하는 딕셔너리들입니다.

```python
states = {
"Oregon" : "OR",
"Alabama" : "AL",
"New Jersey": "NJ",
"Colorado" : "CO"
}
capital_cities = {
"OR": "Salem",
"AL": "Montgomery",
"NJ": "Trenton",
"CO": "Denver"
}
```

주를 인자로 받아 (예: `Oregon`) 그 주도를 (예: `Salem`) 표준 출력으로 나타내는 프로그램을 작성하세요. 만약에 인자에 해당하는 답안이 없다면 `Unknown State`를 출력해야 합니다. 만약 주어진 인자가 없거나 - 또는 너무 많다면 - 아무것도 하지 않고 종료되어야 합니다.

```sh
$> python3 capital_city.py Oregon
Salem
$> python3 capital_city.py Ile-De-France
Unknown state
$> python3 capital_city.py
$> python3 capital_city.py Oregon Alabama
$> python3 capital_city.py Oregon Alabama Ile-De-France
$>
```

<br>​

# Chapter 8

## Exercise 04 : Search by value

<br>

| **Piscine**                | Exercise 04  |
| -------------------------- | ------------ |
| Exercise 04 : Value로 찾기 |
| **제출할 폴더**            | ex04/        |
| **제출할 파일**            | `state.py`   |
| **허용되는 함수**          | `import sys` |

<br>
​
직전에 주어진 것과 똑같은 사전 자료형 값을 사용합니다. 다시 한 번 값을 바꾸지 않은 채로 여러분의 프로그램 내 함수에 복사해넣으세요.

이번에는 ex03과는 반대로 주도를 입력으로 받아 그에 해당하는 주를 출력하는 프로그램을 제작하세요. 그 외에는 지난번 과제와 똑같이 동작해야 합니다.

```sh
$> python3 state.py Salem
Oregon
$> python3 state.py Paris
Unknown capital city
$> python3 state.py
$>
```

​<br>

# Chapter 9

## Exercise 05: Search by key or value

​
<br>

| **Piscine**                         | Exercise 05  |
| ----------------------------------- | ------------ |
| Exercise 05 : Key 또는 Value로 찾기 |
| **제출할 폴더**                     | ex05/        |
| **제출할 파일**                     | `all_in.py`  |
| **허용되는 함수**                   | `import sys` |

<br>

​이전 (ex03, ex04)에서 주어진 것과 똑같은 사전 자료형 값을 사용합니다. 다시 한 번 값을 바꾸지 않은 채로 여러분의 프로그램 내 함수에 복사해 오세요. 여러분은 다음과 같이 동작하는 프로그램을 작성하여야 합니다:

- 프로그램은 동작에 사용될 몇 개의 단어가 쉼표로 구분된 문자열 하나를 인자로 받아야 합니다.

- 문자열 안의 각 단어들마다, 프로그램은 그 단어가 주인지, 주도인지, 아니면 어느 것도 아닌지 판별해야 합니다.

- 프로그램은 단어의 대소문자를 구별해서는 안됩니다. 띄어쓰기의 개수 또한 고려 대상이 아닙니다.

- 입력받은 인자가 없거나 너무 많다면 프로그램은 아무것도 출력해선 안됩니다.

- 문자열 내에 두 쉼표가 연속해서 나온다면, 프로그램은 아무것도 출력하지 않습니다.

- 프로그램은 결과를 줄바꿈으로 구별하여 출력해야 하며, 다음 양식에 엄격하게 맞아야 합니다:

```sh
$> python3 all_in.py "New jersey, Tren ton, NewJersey, Trenton, toto, , sAlem"
Trenton is the capital of New Jersey
Tren ton is neither a capital city nor a state
NewJersey is neither a capital city nor a state
Trenton is the capital of New Jersey
toto is neither a capital city nor a state
Salem is the capital of Oregon
$>
```

​<br>

# Chapter 10

## Exercise 06: Dictionary Sorting

​
<br>

| **Piscine**                | Exercise 06  |
| -------------------------- | ------------ |
| Exercise 06: 사전 정렬하기 |
| **제출할 폴더**            | ex06/        |
| **제출할 파일**            | `my_sort.py` |
| **허용되는 함수**          | `N.A`        |

<br>
​
다음 딕셔너리를 여러분의 함수 중 하나에 붙여넣으세요:

```python3
d = {
'Hendrix' : '1942',
'Allman' : '1946',
'King' : '1925',
'Clapton' : '1945',
'Johnson' : '1911',
'Berry' : '1926',
'Vaughan' : '1954',
'Cooder' : '1947',
'Page' : '1944',
'Richards' : '1943',
'Hammett' : '1962',
'Cobain' : '1967',
'Garcia' : '1942',
'Beck' : '1944',
'Santana' : '1947',
'Ramone' : '1948',
'White' : '1975',
'Frusciante': '1970',
'Thompson' : '1949',
'Burton' : '1939',
}
```

음악가들의 이름을 연도별 오름차순으로, 같은 해에 대해서는 알파벳 순으로 정렬하는 프로그램을 만드세요. 한 줄에 한 사람씩, 연도는 표기하지 않습니다.
​
<br>

# Chapter 11

## Exercise 07: Periodic table of the elements

​
<br>

| **Piscine**           | Exercise 07         |
| --------------------- | ------------------- |
| Exercise 07: 주기율표 |
| **제출할 폴더**       | ex07/               |
| **제출할 파일**       | `periodic_table.py` |
| **허용되는 함수**     | `import sys`        |

<br>

부록에 있는 `d01.tar.gz` 타르볼의 `ex07/` 서브폴더에는 주기율표를 프로그래머용 양식으로 적은 `periodic_table.txt` 파일이 있습니다.

이 파일을 이용하여 적절한 포맷으로 주기율표를 보여주는 `HTML` 페이지를 만들어내는 프로그램을 작성하세요.

- 각 원소는 `HTML` 테이블의 ‘박스’ 내부에 있어야만 합니다.

- 원소들의 이름은 반드시 4단계 타이틀 헤더로 감싸져야 합니다.

- 원소들의 속성은 리스트로 표시되어야 합니다. 최소한 원자번호, 원자기호, 그리고 원자량이 표시되어야 합니다.

- 최소한 구글에 나오는 맨델레예브의 주기율표 레이아웃과 비슷하게 보여져야 합니다. 필요한 곳에는 빈 칸과 빈 줄바꿈이 있어야 합니다.

여러분의 프로그램은 결과 파일로 `periodic_table.html`을 생성해야 합니다. 당연히 이 `HTML` 파일은 어떤 브라우저에서도 읽을 수 있어야 하며 반드시 `W3C` 기준을 충족해야 합니다.

프로그램을 원하는 대로 자유롭게 작성하세요. 다시 쓸 것 같은 기능이 있다면 코드를 쪼개는 데에 망설이지 마세요. html 태그를 css "인라인" 스타일을 이용해 입맛대로 꾸미는 것도 가능합니다. (표에 테두리 색을 넣을 때를 떠올려보세요). 원한다면 `periodic_table.css` 파일까지도 생성할 수도 있습니다.

아래는 결과물이 어떠한 형식이어야 하는 지 감을 주기 위해 발췌한 출력 결과입니다.

```html
[...]
    <table>
        <tr>
            <td style="border: 1px solid black; padding:10px">
                <h4>Hydrogen</h4>
                    <ul>
                        <li>No 42</li>
                        <li>H</li>
                        <li>1.00794</li>
                        <li>1 electron</li>
                    <ul>
    </td>
[...]
```
