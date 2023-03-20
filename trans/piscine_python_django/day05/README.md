# **D05 - Piscine Python-Django**

## 쟝고 - ORM

_요약: 오늘은 쟝고의 ORM에 대해 알아봅시다._

##### _번역 오류 및 오역 제보는 42seoul_club_translate 채널 또는 @jiychoi 로 연락주세요._

<br>

# Contents

| Chapter | Contents                                 | page |
| :-----: | :--------------------------------------- | :--: |
|    1    | [**Instructions**](#Chapter-1)           |  2   |
|    2    | [**Today's specific rules**](#Chapter-2) |  3   |
|    3    | [**Exercise 00**](#Chapter-3)            |  5   |
|    4    | [**Exercise 01**](#Chapter-4)            |  6   |
|    5    | [**Exercise 02**](#Chapter-5)            |  7   |
|    6    | [**Exercise 03**](#Chapter-6)            |  9   |
|    7    | [**Exercise 04**](#Chapter-7)            |  11  |
|    8    | [**Exercise 05**](#Chapter-8)            |  13  |
|    9    | [**Exercise 06**](#Chapter-9)            |  15  |
|   10    | [**Exercise 07**](#Chapter-10)           |  17  |
|   11    | [**Exercise 08**](#Chapter-11)           |  19  |
|   12    | [**Exercise 09**](#Chapter-12)           |  21  |
|   13    | [**Exercise 10**](#Chapter-13)           |  23  |

<br>

# **Chapter 1**

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

- `python3` 인터프리터를 사용하세요.

- 모든 과제는 독립적이어야 합니다. 만약에 요구하는 기능이 이전 과제에서 다뤄졌던 경우, 현재 과제 폴더에 복사해 오세요.

- 어플리케이션과 관련된 모든 경로들은 프로젝트 폴더 내의 `urls.py`에 정의되어 있어야 합니다.

- `djangotraining`이라 이름붙여진 `postgresql` 데이터베이스에서 작업하셔야 합니다. `djangouser`이라는 역할 (role) 을 생성하고, 비밀번호를 `secret` 이라 설정하세요. 해당 역할은 모든 권한을 가져야 합니다.

- 레포지토리 폴더가 곧 쟝고 프로젝트여야 합니다. 프로젝트명은 이번 과제 날짜 (ex: day05) 로 설정하여야 합니다.

- 각 과제 (exercises) 별로 분리하여 작업하기 위해 쟝고의 어플리케이션 콘셉트를 이용할 것입니다. 모든 과제는 각 과제명 (ex: ex00, ex01,...) 으로 이름지어진 쟝고 어플리케이션에 존재하여야 하고, 어플리케이션은 레포지토리의 루트 디렉토리에 있어야 합니다.

- 쟝고 프로젝트는 적절히 설정되어 과제의 모든 요구사항에 부합하여야 합니다. 평가 도중 설정을 건드리는 것은 금지됩니다.

- 과제의 어떤 migration도 제출할 수 없습니다.

- 각 과제별로 `ORM`을 언급하는 부분이 있다면, `Django`의 ORM을 사용하여야 합니다. `SQL`은 한 줄도 사용하지 마세요.

- 각 과제별로 `SQL`을 언급하는 부분이 있다면, `psycopg2` 라이브러리를 이용하여 `SQL`의 모든 리퀘스트를 처리하여야 합니다.

다음은 krichard라는 학생의 Day42 과제 2개에 대한 제출 폴더 구조입니다 :

```sh
|-- krichard
| |-- .
| |-- ..
| |-- .git
| |-- .gitignore
| |-- d42
| | |-- __init__.py
| | |-- settings.py
| | |-- urls.py
| | |-- wsgi.py
| |-- ex00
| | |-- admin.py
| | |-- apps.py
| | |-- forms.py
| | |-- __init__.py
| | |-- models.py
| | |-- tests.py
| | |-- urls.py
| | |-- views.py
| |-- ex01
| | |-- admin.py
| | |-- apps.py
| | |-- forms.py
| | |-- __init__.py
| | |-- models.py
| | |-- tests.py
| | |-- urls.py
| | |-- views.py
| |-- manage.py
```

> 💡 <br>
> 현명하게 작업하세요: 코드를 분석하여 사용하기 쉽게 구성하세요. 시간을 꽤 절약할 수 있을 겁니다.

<br>

# Chapter 3

## Exercise 00

<br>

| **Piscine**                 | Exercise 00 |
| --------------------------- | ----------- |
| Exercise 00 : SQL-표 만들기 |
| **제출할 폴더**             | ex00/       |
| **제출할 파일**             |             |
| **허용되는 함수**           |             |

<br>

ex00이라는 이름의 쟝고 어플리케이션을 만들고, 다음 URL을 통해 접근 가능한 뷰를 만드세요 : `127.0.0.1:8000/ex00/init`

해당 뷰는 `psycopg2` 라이브러리를 이용하여 Postgresql로 이루어진 SQL 테이블을 생성하고, 생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

SQL 테이블은 다음과 같이 구현되어야 합니다:

- `ex00_movies` 라는 이름이어야 합니다.

- 테이블이 생성된 적 없을 때만 생성하여야 합니다.

- 다음 필드만을 포함하여야 합니다:

  - `title`: unique, variable character chain, 64 byte maximum size, non null.

  - `episode_nb`: integer, PRIMARY KEY.

  - `opening_crawl`: text, can be null, no size limit.

  - `director`: variable character chain, non null, 32 bytes maximum size.

  - `producer`: variable character chain, non null, 128 bytes maximum size.

  - `release_date`: date (without time), non null.

<br>

# Chapter 4

## Exercise 01

<br>

| **Piscine**                 | Exercise 01 |
| --------------------------- | ----------- |
| Exercise 01 : ORM-표 만들기 |
| **제출할 폴더**             | ex01/       |
| **제출할 파일**             |             |
| **허용되는 함수**           |             |

<br>

두 번째 어플리케이션 `ex01`에 `Movies`라 이름붙여진 `Django` 모델을 만드세요.

- `title`: unique, variable character chain, 64 byte maximum size, non null.

- `episode_nb`: integer, PRIMARY KEY.

- `opening_crawl`: text, can be null, no size limit.

- `director`: variable character chain, non null, 32 bytes maximum size.

- `producer`: variable character chain, non null, 128 bytes maximum size.

- `release_date`: date (without time), non null.

해당 모델은 `title` 어트리뷰트를 다시 전송할 수 있도록 `__str__` 메소드를 재정의하여야 합니다.

<br>

# Chapter 5

## Exercise 02

<br>

| **Piscine**                   | Exercise 02 |
| ----------------------------- | ----------- |
| Exercise 02 : SQL-데이터 삽입 |
| **제출할 폴더**               | ex02/       |
| **제출할 파일**               |             |
| **허용되는 함수**             |             |

<br>

`Django` 어플리케이션 `ex02`를 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex02/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex02_movies` 가 되어야 합니다.

  생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex02/populate`: 다음 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  - episode_nb: 1 - title: The Phantom Menace - director: George Lucas - producer: Rick McCallum - release_date: 1999-05-19

  - episode_nb: 2 - title: Attack of the Clones - director: George Lucas - producer: Rick McCallum - release_date: 2002-05-16

  - episode_nb: 3 - title: Revenge of the Sith - director: George Lucas - producer: Rick McCallum - release_date: 2005-05-19

  - episode_nb: 4 - title: A New Hope - director: George Lucas - producer: Gary Kurtz, Rick McCallum - release_date: 1977-05-25

  - episode_nb: 5 - title: The Empire Strikes Back - director: Irvin Kershner - producer: Gary Kurtz, Rick McCallum - release_date: 1980-05-17

  - episode_nb: 6 - title: Return of the Jedi - director: Richard Marquand - producer: Howard G. Kazanjian, George Lucas, Rick McCallum - release_date: 1983-05-25

  - episode_nb: 7 - title: The Force Awakens - director: J. J. Abrams - producer: Kathleen Kennedy, J. J. Abrams, Bryan Burk - release_date: 2015-12-11

  생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex02/display`: `ex02_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>

# Chapter 6

## Exercise 03

​
<br>

| **Piscine**                   | Exercise 03 |
| ----------------------------- | ----------- |
| Exercise 03 : ORM-데이터 삽입 |
| **제출할 폴더**               | ex03/       |
| **제출할 파일**               |             |
| **허용되는 함수**             |             |

<br>

`Django` 어플리케이션 `ex03`을 만드세요. 어플리케이션 내에는 `ex01`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요.

해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex03/populate`: 다음 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  - episode_nb: 1 - title: The Phantom Menace - director: George Lucas - producer: Rick McCallum - release_date: 1999-05-19

  - episode_nb: 2 - title: Attack of the Clones - director: George Lucas - producer: Rick McCallum - release_date: 2002-05-16

  - episode_nb: 3 - title: Revenge of the Sith - director: George Lucas - producer: Rick McCallum - release_date: 2005-05-19

  - episode_nb: 4 - title: A New Hope - director: George Lucas - producer: Gary Kurtz, Rick McCallum - release_date: 1977-05-25

  - episode_nb: 5 - title: The Empire Strikes Back - director: Irvin Kershner - producer: Gary Kurtz, Rick McCallum - release_date: 1980-05-17

  - episode_nb: 6 - title: Return of the Jedi - director: Richard Marquand - producer: Howard G. Kazanjian, George Lucas, Rick McCallum - release_date: 1983-05-25

  - episode_nb: 7 - title: The Force Awakens - director: J. J. Abrams - producer: Kathleen Kennedy, J. J. Abrams, Bryan Burk - release_date: 2015-12-11

생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex03/display`: `Movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

> ℹ️ <br>
> 평가 시에는, migration이 테스트 전에 이루어질 것입니다.

<br>

# Chapter 7

## Exercise 04

​
<br>

| **Piscine**                   | Exercise 04 |
| ----------------------------- | ----------- |
| Exercise 04 : SQL-데이터 삭제 |
| **제출할 폴더**               | ex04/       |
| **제출할 파일**               |             |
| **허용되는 함수**             |             |

<br>

`Django` 어플리케이션 `ex04`를 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex04/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex04_movies` 가 되어야 합니다.

  생성에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex04/populate`: `ex02`에서 명시된 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  지워진 데이터를 모두 재삽입하여야 합니다.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex04/display`: `ex04_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex04/remove`: 영화 제목을 `submit` 버튼, `remove` 버튼과 함께 드랍다운 리스트로 출력하는 `HTML` 페이지를 표시하세요.

  영화 제목들은 `ex04_movies` 테이블에 있는 제목을 가져오시면 됩니다.

  폼의 유효성이 검사된 후, 선택한 영화는 데이터베이스에서 지워지고, 폼은 남은 영화 제목으로 업데이트된 리스트를 다시 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>

# Chapter 8

## Exercise 05

​
<br>

| **Piscine**                   | Exercise 05 |
| ----------------------------- | ----------- |
| Exercise 05 : ORM-데이터 삭제 |
| **제출할 폴더**               | ex05/       |
| **제출할 파일**               |             |
| **허용되는 함수**             |             |

<br>

`Django` 어플리케이션 `ex05`를 만드세요. `ex01`에서 요구한 것과 똑같은 모델을 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex05/populate`: `ex03`에서 명시된 데이터를 직전 뷰에서 만든 테이블에 삽입하세요.

  지워진 데이터를 모두 재삽입하여야 합니다.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex05/display`: `movies` 모델에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요. 최종적으로 공백인 필드 (void field) 도 포함하여 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex05/remove`: 영화 제목을 `submit` 버튼, `remove` 버튼과 함께 드랍다운 리스트로 출력하는 `HTML` 페이지를 표시하세요.

  영화 제목들은 `Movies` 모델에 있는 제목을 가져오시면 됩니다.

  폼의 유효성이 검사된 후, 선택한 영화는 데이터베이스에서 지워지고, 폼은 남은 영화 제목으로 업데이트된 리스트를 다시 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

> ℹ️ <br>
> 평가 시에는, migration이 테스트 전에 이루어질 것입니다.

<br>

# Chapter 9

## Exercise 06

​
<br>

| **Piscine**                       | Exercise 06 |
| --------------------------------- | ----------- |
| Exercise 06 : SQL-데이터 업데이트 |
| **제출할 폴더**                   | ex06/       |
| **제출할 파일**                   |             |
| **허용되는 함수**                 |             |

<br>

`Django` 어플리케이션 `ex06`을 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex06/init`: `ex00`에서 요구한 것과 똑같은 특성을 가진 테이블을 만드세요. 단 이름은 `ex06_movies` 가 되어야 하고, 다음과 같은 추가 필드를 포함해야 합니다:

  - `created` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다.

  - `updated` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다. 또한 다음과 같은 트리거를 이용하여 자동으로 현재 시간과 날짜로 업데이트되어야 합니다.

  ```sql
  CREATE OR REPLACE FUNCTION update_changetimestamp_column()
  RETURNS TRIGGER AS $$
  BEGIN
  NEW.updated = now();
  NEW.created = OLD.created;
  RETURN NEW;
  END;
  $$ language 'plpgsql';
  CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
  ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
  update_changetimestamp_column();
  ```

- `127.0.0.1:8000/ex06/populate`: `ex02`의 테이블에 직전 뷰에서 만든 테이블의 데이터를 붙이세요.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex06/display`: `ex06_movies` 테이블에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex06/update`: 폼의 송신과 수신을 관리해야 합니다. 후자는 `ex06_movies`의 영화들을 드랍다운 메뉴로 구성하여 선택하고, 두 번째 필드에 텍스트를 적을 수 있어야 합니다. 폼의 유효성이 검사될 때, 뷰는 선택한 영화의 `opening_crawl` 필드를 `ex06_movies` 테이블의 폼에 작성한 텍스트로 대체하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

<br>

# Chapter 10

## Exercise 07

​
<br>

| **Piscine**                       | Exercise 07 |
| --------------------------------- | ----------- |
| Exercise 07 : ORM-데이터 업데이트 |
| **제출할 폴더**                   | ex07/       |
| **제출할 파일**                   |             |
| **허용되는 함수**                 |             |

<br>

`Django` 어플리케이션 `ex07`를 만드세요. `ex01`에서 요구한 것과 똑같은 모델을 만들되, 다음 필드를 추가하세요:

- `created` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다.

- `updated` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되고, 매번 자동으로 현재 시간과 날짜로 업데이트되어야 합니다.

해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex07/populate`: `ex02`에서 명시된 데이터를 직전 뷰에서 만든 모델에 채워넣으세요.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex05/display`: `Movies` 모델에 있는 모든 내용을 `HTML` 표 형식으로 표시하세요.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

- `127.0.0.1:8000/ex05/update`: 폼의 송신과 수신을 관리해야 합니다. 후자는 `Movies` 테이블의 영화들을 드랍다운 메뉴로 구성하여 선택하고, 두 번째 필드에 텍스트를 적을 수 있어야 합니다. 폼의 유효성이 검사될 때, 뷰는 선택한 영화의 `opening_crawl` 필드를 `Movies` 모델의 폼에 작성한 텍스트로 대체하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

> ℹ️ <br>
> 평가 시에는, migration이 테스트 전에 이루어질 것입니다.

<br>

# Chapter 11

## Exercise 08

​
<br>

| **Piscine**               | Exercise 08 |
| ------------------------- | ----------- |
| Exercise 08 : SQL-외부 키 |
| **제출할 폴더**           | ex08/       |
| **제출할 파일**           |             |
| **허용되는 함수**         |             |

<br>

`Django` 어플리케이션 `ex08`을 만드세요. 해당 어플리케이션에선, 다음과 같은 url을 통해 접근 가능한 뷰가 있어야 합니다:

- `127.0.0.1:8000/ex08/init`: 두 개의 테이블을 포함하여야 합니다.

첫 번째 테이블은 `ex08_planets`로 이름붙여져야 하고, 다음과 같은 필드를 포함해야 합니다:

- `id`: serial, primary key

- `name`: unique, variable character chain, 64 byte maximum size, non null.

- `climate`: variable character chain.

- `diameter`: integer.

- `orbital_period`: integer.

- `population`: big integer.

- `rotation_period`: integer.

- `surface_water`: boolean.

- `terrain`: variable character chain, 128 bytes maximum size.

두 번째 테이블은 `ex08_people`로 이름붙여져야 하고, 다음과 같은 필드를 포함해야 합니다:

- `id`: serial, primary key.

- `name`: unique, variable character chain, 64 byte maximum size, non null.

- `birth_year`: variable character chain, 32 byte maximum size.

- `gender`: variable character chain, 32 byte maximum size.

- `eye_color`: variable character chain, 32 byte maximum size.

- `hair_color`: variable character chain, 32 byte maximum size.

- `height`: integer.

- `mass`: boolean.

- `homeworld`: variable character chain, 64 byte maximum size, foreign key, referencing the name column of the 08_planets table.

- `127.0.0.1:8000/ex08/populate`: `people.csv`, `planets.csv`로부터 값을 받아 두 테이블에 데이터를 각각 넣어주어야 합니다. 당연히 알맞은 이름의 테이블에 넣어야겠죠? `ex08_people`과 `ex08_planets` 말이에요.

  삽입에 성공했을 때 'OK' 라는 메시지를 담은 페이지를 리턴해야 합니다. 생성에 실패하면, 문제점을 알려주는 에러 메시지를 리턴해야 합니다.

- `127.0.0.1:8000/ex08/display`: 모든 캐릭터의 이름과 고향별 (homeworld), 해당 세계의 기후 (`바람` 혹은 적당한 `바람`)을 캐릭터의 이름 순으로 표시하여야 합니다.

  존재하는 데이터가 없거나, 에러 발생 시에는 페이지에 `No data available` 이라는 문장만 보여야 합니다.

> 💡 <br>
> psycopg2의 copy_from 메소드를 검색해보세요.

<br>

# Chapter 12

## Exercise 09

​
<br>

| **Piscine**               | Exercise 09 |
| ------------------------- | ----------- |
| Exercise 09 : ORM-외부 키 |
| **제출할 폴더**           | ex09/       |
| **제출할 파일**           |             |
| **허용되는 함수**         |             |

<br>

`Django` 어플리케이션 `ex09`을 만들고, 두 개의 모델을 생성하세요. 첫 번째 모델의 이름은 `Planets`이고, 다음과 같은 필드를 포함해야 합니다:

- `name`: unique, variable character chain, 64 byte maximum size, non null.

- `climate`: variable character chain.

- `diameter`: integer.

- `orbital_period`: integer.

- `population`: big integer.

- `rotation_period`: integer.

- `surface_water`: boolean.

- `terrain`: character chains.

- `created` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다.

- `updated` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되고, 매번 자동으로 현재 시간과 날짜로 업데이트되어야 합니다.

해당 모델은 `name` 어트리뷰트를 다시 전송할 수 있도록 `__str__()` 메소드를 재정의하여야 합니다.

두 번째 모델은 `People`로 이름붙여져야 하고, 다음과 같은 필드를 포함해야 합니다:

- `name`: character chain, 64 byte maximum size, non null.

- `birth_year`: character chain, 32 byte maximum size.

- `gender`: character chain, 32 byte maximum size.

- `eye_color`: character chain, 32 byte maximum size

- `hair_color`: character chain, 32 byte maximum size.

- `height`: integer.

- `mass`: boolean.

- `homeworld`: character chain, 64 byte maximum size, foreign key referencing the `name` column of this app’s `Planets` table.

- `created` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되어야 합니다.

- `updated` 시간 & 날짜 타입 (datetime type). 생성되었을 때, 자동으로 현재 시간과 날짜로 세팅되고, 매번 자동으로 현재 시간과 날짜로 업데이트되어야 합니다.

해당 모델 또한 `name` 어트리뷰트를 다시 전송할 수 있도록 `__str__()` 메소드를 재정의하여야 합니다.

이 어플리케이션에선, `127.0.0.1:8000/ex08/display`로 접근 가능한 뷰를 생성하셔야 합니다.

해당 뷰에서는 모든 캐릭터의 이름과 고향별 (homeworld), 해당 세계의 기후 (`바람` 혹은 적당한 `바람`)을 캐릭터의 이름 순으로 `HTML` 표에 표시하여야 합니다.

존재하는 데이터가 없을 때에는, `"No data available, please use the following command line before use:"` 메시지와 함께 명령문 (command line) 이 이어져야 합니다.

이 명령문은 해당 레포지토리의 루트 경로에서 실행되어야 하며, `ex09_initial_data.json` 파일 (오늘의 resource에 제공된 그것입니다) 내의 모든 데이터들을 방금 만든 모델에 삽입하여야 합니다.

해당 파일들을 레포지토리에 넣어 제출하세요.

> ℹ️ <br>
> 평가 시에는, migration이 테스트 전에 이루어질 것입니다.

<br>

# Chapter 13

## Exercise 10

​
<br>

| **Piscine**                       | Exercise 10 |
| --------------------------------- | ----------- |
| Exercise 10 : ORM-다수에서 다수로 |
| **제출할 폴더**                   | ex10/       |
| **제출할 파일**                   |             |
| **허용되는 함수**                 |             |

<br>

`ex10` 이라는 쟝고 앱을 만들고 3개의 모델을 생성하세요 :

- `Planets`와 `People`: 두 모델은 `ex09`의 그것과 완벽히 똑같아야 합니다.

- `Movies`: 이 모델은 필드 `characters` 를 추가해야 하는 것 빼고는 `ex01`의 그것과 같아야 합니다.

이것은 `People` 모델의 `many to many` 타입이며, `People` 테이블 내의 모든 영화 주인공들을 리스트로 만들 수 있어야 합니다.

모델을 채우는 데에 필요한 자료는 오늘의 resource에 제공된 `ex10_initial_data.json`에 포함되어 있습니다.

이 앱에서는, `127.0.0.1:8000/ex10` URL에서 접근 가능한 뷰 또한 생성하여야 합니다. 뷰에서는 다음과 같은 필드를 필수적으로 포함한 폼을 보여주어야 합니다:

- `Movies minimum release date` : date

- `Movies maximum release date` : date

- `Planet diameter greater than` : number

- `Character gender`: `People` 모델의 서로 다른 `gender` 필드값을 드랍다운 리스트 형식으로 보여야 합니다. 같은 값은 두 번 등장하지 않습니다.

뷰가 검증된 후에는, 값 검색 후 반환, 결과값 출력까지 완수해야 합니다.

결과값은 `character gender` 필드의 값과 성별이 매치되는 캐릭터여야 하며, 해당 캐릭터의 등장 영화 개봉일은 `Movies minimum release date`와 `Movies maximum release date` 사이의 값이어야 하고, 그들의 고향별은 `Planet diameter greater than` 보다 지름이 커야 합니다.

결과값이 없을 경우엔, `""Nothing corresponding to your research"` 메시지가 표시되어야 합니다. 모든 결과값은 다음 요소와 함께 출력되어야 합니다:

- 캐릭터 이름

- 성별

- 영화 제목

- 고향별 이름

- 고향별 지름

예를 들어: 영화 개봉일이 1900-01-01 부터 2000-01-01 사이이고, 고향별의 지름이 11000보다 큰 여성 캐릭터의 검색 결과값은 :

- A New Hope - Leia Organa - female - Alderaan - 12500
- The Phantom Menace - Padmé Amidala - female - Naboo - 12120
- Return of the Jedi - Leia Organa - female - Alderaan - 12500
- Return of the Jedi - Mon Mothma - female - Chandrila - 13500
- The Empire Strikes Back -Leia Organa - female - Alderaan - 12500

> 💡 <br>
> 몇몇 캐릭터가 같은 영화에 동시에 등장할 수도 있고, 한 캐릭터가 여러 영화에 등장할 수도 있습니다. <br> 이것은 many to many relation이라고 불립니다. 이러한 경우에는, 해당 테이블 사이에 중간 테이블을 만들어야 합니다. <br> 중간 테이블의 각 열은 (독창적인 (unique)) 상호 참조 관계이며: 첫 번째 참조는 영화의 테이블, 두 번째 참조는 캐릭터의 테이블 (또는 그 반대) 입니다. 여러분의 모델이 구성되고 migration이 성공하면, 이 테이블을 postgre 콘솔에서 확인할 수 있을 것입니다.
