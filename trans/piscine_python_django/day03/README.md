# **D03 - Piscine Python-Django**

## 파이썬-쟝고 연습 (파이썬 - 라이브러리들)

_요약: 오늘은 파이썬에서 유용하게 사용할 만한 라이브러리를 다루는 법을 알아보죠._

##### _번역 오류 및 오역 제보는 42seoul_club_translate 채널 또는 @jiychoi 로 연락주세요._

<br>

# Contents

| Chapter | Contents                                 | page |
| :-----: | :--------------------------------------- | :--: |
|    1    | [**Preamble**](#Chapter-1)               |  2   |
|    2    | [**Instructions**](#Chapter-2)           |  3   |
|    3    | [**Today's specific rules**](#Chapter-3) |  4   |
|    4    | [**Exercise 00**](#Chapter-4)            |  5   |
|    5    | [**Exercise 01**](#Chapter-5)            |  6   |
|    6    | [**Exercise 02**](#Chapter-6)            |  8   |
|    7    | [**Exercise 03**](#Chapter-7)            |  10  |
|    8    | [**Exercise 04**](#Chapter-8)            |  13  |
|    9    | [**Exercise 05**](#Chapter-9)            |  14  |

<br>

# **Chapter 1**

## Preamble

<br>

지오해싱 - 위키피디아, 지식의 백과사전
지오해싱이란 xkcd 웹코믹에 영향을 받은 야외 오락 활동입니다. 참가자들은 (컴퓨터 알고리즘에 의해 계산된) 랜덤한 좌표로 찾아가 범지구 위치결정 시스템 (GPS) 수신기 또는 다른 기기의 사진을 찍어 인증한 후, 해당 좌표로 찾아가기까지의 여정을 온라인상에 이야기해야 합니다. 전자기기가 아니더라도, 위치를 알아볼 수 있는 사진 인증 또한 허용됩니다.

[지오캐싱](https://www.geocaching.com/) 등과 같은 여타 야외 활동들이 명확한 목표를 제시하는 반면, 지오해싱은 무의미함에 재미를 느낀 플레이어들에 의해 주로 추진됩니다. 그 결과로 탄생한 지오해싱 커뮤니티와 문화는 대개 장난기가 많고, 지오해싱 과정 중에 발생하는 재미있는 상황들을 지지하며 전통적인 야외 활동들을 패러디하는 경향이 있습니다. 랜덤 좌표를 탐험한다는 것이 무조건 무의미한 것 또한 아닙니다. 몇몇 지오해싱 참가자들은 OpenStreetMap 프로젝트에 자신이 방문한 지역의 문서를 추가하기도 합니다.

[출처](https://en.wikipedia.org/wiki/Geohashing)

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
    여러분의_함수(필요하면, 사용할, 인자값을, 넣으세요)
```

- 에러 관리를 하셔도 좋습니다.

- 각 과제별 설명란의 'Authorized functions' 에 명시되어 있는 함수 / 라이브러리 외에는 import가 절대 금지됩니다.

- `python3` 인터프리터를 사용하세요.

<br>

# Chapter 4

## Exercise 00

<br>

| **Piscine**                 | Exercise 00        |
| --------------------------- | ------------------ |
| Exercise 00 : 중력 거스르기 |
| **제출할 폴더**             | ex00/              |
| **제출할 파일**             | `geohashing.py`    |
| **허용되는 함수**           | `sys, antigravity` |

<br>

이번 과제는 해당 pdf의 머리말 (preamble) 을 떠올리면서, 간단한 몸풀기를 해볼 겁니다. 하나도 안 어려워요.

`geohashing.py` 라는 프로그램을 만드세요. 필요한 만큼 인자값을 받고, geohash를 분명하게 계산한 후 그 결과물을 표준 출력으로 화면에 보여주어야 합니다.

에러가 발생했을 경우, 프로그램이 종료되기 전 적절한 에러 메시지를 화면에 보여야 합니다.

이 글이 도움이 될 거에요: [지오해싱 알고리즘](http://xkcd.com/426/)

<br>

# Chapter 5

## Exercise 01

<br>

| **Piscine**       | Exercise 01                  |
| ----------------- | ---------------------------- |
| Exercise 01 : pip |
| **제출할 폴더**   | ex01/                        |
| **제출할 파일**   | `my_script.sh my_program.py` |
| **허용되는 함수** | `path.py 모듈`               |

<br>

`path.py`는 Path 객체를 사용가능케 하며, 이 객체는 `os.path`를 조금 더 직관적으로 사용할 수 있게 돕습니다.

이번 과제에서는, 이 라이브러리를 설치하는 `bash` 스크립트를 만들고, 라이브러리를 사용하는 `Python` 프로그램을 작성해보도록 하겠습니다.

쉘 스크립트는 다음과 같은 절차를 지켜야 합니다:

- 당연히 확장자는 `.sh`여야 합니다. `쉘` 스크립트니까요.

- 반드시 pip의 버전을 표시하여야 합니다.

- 반드시 `path.py`의 개발자 버전을 `Github` 레포지토리로부터 받아서, 본인 과제 폴더 하위의 `local_lib` 폴더에 설치하여야 합니다. 만약 해당 폴더에 이미 설치되어 있다면, 재설치 시에 이를 부숴야 합니다. (crush it)

- `path.py` 설치 로그를 `.log` 확장자로 저장하여야 합니다.

- 라이브러리가 제대로 설치되었다면, 여러분이 만든 간단한 프로그램이 실행되어야 합니다.

파이썬 프로그램은 다음과 같은 절차만 제대로 지킨다면 자유롭게 구성하셔도 됩니다:

- 당연히 확장자는 `.py`여야 합니다. `파이썬`이니까요..

- 반드시 `path.py` 라이브러리를 방금 전에 쉘 스크립트로 설치한 경로로부터 불러와야 합니다.

- 프로그램은 반드시 폴더와 폴더 내부에 파일을 하나 만들어야 하고, 해당 파일에 아무 값을 쓴 다음 그것을 읽어들여 출력하는 과정이 필요합니다.

- 오늘의 규칙 (**[Today’s specific rules](#Chapter-3)**) 을 따라야 합니다.

<br>

# Chapter 6

## Exercise 02

<br>

| **Piscine**                    | Exercise 02                            |
| ------------------------------ | -------------------------------------- |
| Exercise 02 : API 리퀘스트하기 |
| **제출할 폴더**                | ex02/                                  |
| **제출할 파일**                | `request_wikipedia.py requirement.txt` |
| **허용되는 함수**              | `requests, json, dewiki, sys`          |

<br>
위키피디아는 여러분이 잘 알고 있는 놀라운 지식 공유의 장입니다. 또한 여러분이 가장 좋아하는 브라우저에서도 실행할 수 있고, 핸드폰으로도 실행 가능하죠. 이제 여러분에게 이 필수요소적인 웹사이트를 터미널에서 접근할 수 있는 도구를 만들 권리를 드리겠습니다.

그렇게 하기 위해선, `string` 형식의 패러미터를 받아 [위키피디아 API](https://www.mediawiki.org/wiki/API:Main_page)를 이용하여 검색하고, 그 결과값을 파일에 저장하는 `request_wikipedia.py` 프로그램을 만들어야 합니다. 프랑스 API나 영어 API 중 하나를 사용하시면 됩니다.

- 프로그램은 request에 오타가 나도 결과를 그대로 파일로 저장하여야 합니다. 원본 웹사이트에서 이것저것 넣어서 테스트해 보세요. 원본 웹사이트가 결과를 찾았다면, 여러분의 프로그램도 동일하게 작동해야 합니다.

- 결과값은 파일에 저장되기 전 `JSON`이나 `Wiki Markup` 형식으로 포맷되어선 안 됩니다!

- 파일명은 `검색한_키워드명.wiki`가 되어야 하고, 파일명에 공백이 있으면 안 됩니다.

- 받아온 패러미터가 없거나, 패러미터 형식이 이상하거나, 리퀘스트 오류가 발생하거나, 정보가 없거나, 서버 문제 등 오류가 발생하면, 파일이 생성되면 안 되며, 적절한 에러 메시지가 표시되어야 합니다.

- 여러분의 레포지토리에 `requirement.txt`를 포함하세요. 이는 여러분의 시스템이나 가상환경에 필요한 라이브러리를 설치하는 데에 사용됩니다.

> ℹ️ <br>
> dewiki 라이브러리는 완벽하지 않습니다. 저희는 완벽한 결과물을 요구하는 게 아니에요. 그건 과제의 목표가 아니니까요.

> 💡 <br>
> API 문서를 잘 읽어보세요. API를 사용했을 때 여러분이 받는 결과물의 구조를 잘 살펴보세요.

다음은 결과물의 예시입니다 :

```bash
$>python3 request_wikipedia.py "chocolatine"
$>cat chocolatine.wiki

	Une chocolatine designe :

	* une viennoiserie au chocolat, aussi appelee pain au chocolat ou couque au chocolat ;
	* une viennoiserie a la creme patissiere et au chocolat, aussi appelee suisse ;
	* une sorte de bonbon au chocolat ;
	* un ouvrage d'Anna Rozen

Malgre son usage ancien, le mot n'est entre dans le dictionnaire Petit Robert qu'en 2007 et dans lePetit Larousse qu'en 2011.

L'utilisation du terme "Chocolatine" se retrouve egalement au Quebec, dont la langue a evolue a partirdu vieux francais differemment du francais employe en Europe, mais cet usage ne prouve ni n'infirme aucune anteriorite, dependant du hasard de l'usage du premier commercant l'ayant introduitau Quebec.

References

Categorie:Patisserie
Categorie:Chocolat
```

<br>

# Chapter 7

## Exercise 03

​
<br>

| **Piscine**             | Exercise 03                               |
| ----------------------- | ----------------------------------------- |
| Exercise 03 : HTML 파서 |
| **제출할 폴더**         | ex03/                                     |
| **제출할 파일**         | `roads_to_philosophy.py, requirement.txt` |
| **허용되는 함수**       | `sys, requests, BeautifulSoup`            |

<br>

전설에 따르면, 여러분이 어떤 위키피디아 문서에서 시작하던간에, *기울임*이나 (괄호) 안의 링크를 제외한 문서 첫 번째 링크를 클릭하는 것을 반복하다 보면, 무조건 _Philosophy_ 문서에 도착한다고 합니다.

사실, 전설은 아닙니다! (놀란 척 좀 해주세요..) [이 문서를](https://en.wikipedia.org/wiki/Philosophy) 검증해 보면 아시겠지만요...

만약 여러분이 '나는 직접 눈으로 똑똑히 본 것만 믿겠다!' 하는 성향의 사람이라면, **반드시** 이 현상을 테스트하고, 거쳐간 모든 문서의 이름과 개수를 출력하는 `roads to philosophy` 프로그램을 만들어야 합니다.

프로그램의 이름은 `roads_to_philosophy.py`가 되어야 하고, 다음과 같은 동작을 수행해야 합니다:

- 프로그램은 문자열을 패러미터로 받아야 합니다. 문자열은 위키피디아에 딱 하나의 문서 검색결과와 매치되는 단어 또는 단어들의 조합이어야 합니다.

- 프로그램은 반드시 **영어** 위키피디아 URL에 request를 보내야 하며, 이는 브라우저에서의 표준 검색 형식과 동일하게 동작해야 합니다. 달리 말하면, 사이트 API를 **사용하지 마세요**.

- `html` 페이지를 `BeautifulSoup` 라이브러리를 이용하여 다음과 같이 파싱해야 합니다:

  - 최종적으로 리디렉션 되는 문서를 찾아 **roads to philosophy**를 시작하세요. URL 리디렉션이 아님에 주의하세요.

  - 페이지의 타이틀을 찾아서, **roads to philosophy**에 추가하세요.

  - (존재한다면) 페이지의 서문 문단에서, 다른 위키 문서로 연결되는 첫 번째 링크를 찾으세요. 이탤릭 처리된 링크나 괄호 안의 링크를 무시한다기보단, `위키피디아`의 help 섹션처럼 위키 문서가 아닌 곳으로 이동하는 링크를 세심히 **무시**하도록 프로그램을 설계하세요.

- 프로그램은 직전 문서에서 얻은 링크를 가지고 방금 전의 과정을 반복해야 합니다. 다음과 같은 조건을 맞닥트리기 전까지요 :

  - 얻은 링크가 `philosophy` 페이지를 가리킬 때. 이 때는, 지금까지 방문했던 문서들의 제목을, 거쳐간 문서의 개수와 함께 다음과 같은 포맷으로 표준 출력해야 합니다: `<number> roads from <request> to philosophy`

  - 얻은 링크의 문서 내부에 어떠한 다른 하위 링크도 없을 때. ([dead-end](https://en.wikipedia.org/wiki/Category:All_dead-end_pages)) 프로그램은 다음을 출력해야 합니다 : `It leads to a dead end !`

  - 이미 방문한 페이지를 또 방문하려 시도할 때. 이 경우는 프로그램이 무한 루프를 시도하므로, 프로그램은 다음을 출력해야 합니다: `It leads to an infinite loop !`

- 이 조건에 해당하면, 요구하는 출력문을 표준 출력으로 출력한 후, 프로그램이 정상적으로 종료되어야 합니다.
  ​

> ℹ️ <br>
> 프로그램 실행 시에는 연결 오류, 서버 오류, 패러미터 오류, 리퀘스트 오류 등 어떠한 오류 상황에서도, 각 상황별로 설정된 에러 메시지를 제대로 출력하고 정상적으로 종료되어야 합니다.

직전 과제처럼, 이 프로그램을 구동시키기 위한 라이브러리를 설치하는 `requirement.txt`를 제공하세요.

출력은 이렇게 생겨야 합니다:

```sh
$> python3 roads_to_philosophy.py "42 (number)"
42 (number)
Natural number
Mathematics
Ancient Greek
Greek language
Modern Greek
Colloquialism
Word
Linguistics
Science
Knowledge
Awareness
Conscious
Consciousness
Quality (philosophy)
Philosophy
17 roads from 42 (number) to philosophy !
$> python3 roads_to_philosophy.py Accuvio
It's a dead end !
$>
```

> ℹ️ <br>
> 위키피디아 커뮤니티는 문서를 자주 업데이트합니다. 이 pdf가 만들어진 시점과 여러분이 과제를 수행하는 시점 사이에 문서가 변경되었을 가능성이 높으며, philosophy로 향하는 길 또한 달리 출력될 가능성이 높고 accuvio 예시 또한 dead end가 아닐 수 있습니다.

<br>

# Chapter 8

## Exercise 04

​
<br>

| **Piscine**                         | Exercise 04                    |
| ----------------------------------- | ------------------------------ |
| Exercise 04 : 가상환경 (Virtualenv) |
| **제출할 폴더**                     | ex04/                          |
| **제출할 파일**                     | `requirement.txt my_script.sh` |
| **허용되는 함수**                   | `전부 다`                      |

<br>
​
내일부터는, 본격적인 `Django` 프레임워크 연습을 시작할 것입니다. 그 전에 간단한 설치와 함께 과제 수행을 준비해야겠죠?

이것을 위해, 여러분은 두 개의 파일을 만들어야 합니다:

- `Django` 와 `psycopg2`의 최신 안정 버전을 설치하는 `requirement.txt`

- 다음을 수행하는 쉘 스크립트:

  - `.sh` 확장자를 가져야 합니다.

  - `django_env` 라는 이름의 `python3 virtualenv (가상환경)` 을 생성해야 합니다.

  - `requirement.txt` 에 포함된 모든 파일을 `가상환경` 에 설치해야 합니다.

  - `가상환경`은 해당 스크립트가 종료될 시점에 **활성화 (activated)** 되어 있어야 합니다.

<br>

# Chapter 9

## Exercise 05

​
<br>

| **Piscine**              | Exercise 05          |
| ------------------------ | -------------------- |
| Exercise 05 : 안뇽, 세상 |
| **제출할 폴더**          | ex05/                |
| **제출할 파일**          | `필요한 모든 파일들` |
| **허용되는 함수**        | `전부 다`            |

<br>
​
`Django` 설치만 봐도 머리가 지끈지끈하죠? 이해합니다.

그렇기 때문에! 우리는 `Django`를 이용하여 `Hello World`를 출력함으로써 라이브러리에 관한 내용을 빵 하고 끝내 버려야 합니다.

이 마지막 과제에서는, 쟝고 공식 튜토리얼을 차근차근 따라하면서 `Hello World !` 라는 간단한 텍스트를 출력하는 페이지를 만들고, 브라우저에서 다음 링크에 접속하여 출력하여야 합니다 : [http://localhost:8000/helloworld](http://localhost:8000/helloworld)

여러분의 레포지토리에는 `Django` 프로젝트 폴더와 그 내용물을 전부 포함하여야 합니다.
