# **D07 - Piscine Python-Django**

## 쟝고 - 심화

_요약: 오늘은 쟝고의 어려운 기능들을 살펴볼게요._

##### _번역 오류 및 오역 제보는 42seoul_club_translate 채널 또는 @jiychoi 로 연락주세요._

<br>

# Contents

| Chapter | Contents                                 | page |
| :-----: | :--------------------------------------- | :--: |
|    1    | [**Preamble**](#Chapter-1)               |  2   |
|    2    | [**Instructions**](#Chapter-1)           |  5   |
|    3    | [**Today's specific rules**](#Chapter-2) |  6   |
|    4    | [**Exercise 00**](#Chapter-3)            |  7   |
|    5    | [**Exercise 01**](#Chapter-4)            |  9   |
|    6    | [**Exercise 02**](#Chapter-5)            |  11  |
|    7    | [**Exercise 03**](#Chapter-6)            |  13  |
|    8    | [**Exercise 04**](#Chapter-7)            |  15  |
|    9    | [**Exercise 05**](#Chapter-8)            |  16  |
|   10    | [**Exercise 06**](#Chapter-9)            |  17  |

<br>

# **Chapter 1**

## Preamble

<br>
나는 내 조미료들을 편리하게 보관할 수 있는 작은 찬장을 만들고 싶어.

목공에 익숙하기 때문에, 무슨 재료가 필요한지는 이미 알고 있지: 원목, 기본적인 툴들. 자, 톱, 수평 공구와 망치.

만약에 내가 집을 지어야 했다면, 해당 재료들이 전부 다 필요했을 거야. 그래서 도구상에 가서 망치를 사고 싶다고 점원한테 물어봤어.

- "망치요?" 그가 대답했어. "요즘 누가 망치를 사요. 망치는 한 물 갔지."

내가 놀라서 왜냐고 물었어.

- "뭐, 망치는 아시다시피 종류가 정말 다양하잖아요? 아메리카 망치, 유럽 망치.. 만약에 이 중 한 개라도 샀다가 나중에 다른 종류의 망치가 필요하게 되면 다시 사러 와야 하잖아요? 요즘 사람들은 그런 걸 원하지 않아요. 한 번 사면 어디든 써먹을 수 있는 보편적인 도구를 원하지."

- "그럴듯한 말이네요. 그럼 어디에서나 사용가능한 보편적인 망치를 보여주실 수 있나요?"

- "이제 그런 건 팔지 않아요. 쓸모가 없어졌거든."

- "진짜요? 방금 보편적인 망치가 대세라고 말씀해주셨잖아요.."

- "아시다시피, 뭐든 할 수 있는 보편적인 망치는 특정한 일을 수행할 때 도움이 안 될 수 있어요. 예를 들면 오함마로 못을 두들기는 건 비효율적이죠. 그리고 만약 사람을 죽이고 싶을 땐, 아메리칸 망치만한 게 없고요."

- "그렇네요! 그래서.. 아무도 보편적인 망치를 사지 않고, 특정한 종류의 망치를 팔지 않으면, 이 가게에서는 어떤 종류의 망치를 파나요?"

- "네, 망치 안 팔아요."

- "그렇다면..."

- "연구에 따르면, 사람들은 보편적인 망치를 딱히 원하지 않는다고 해요. 매번 특정 용도에 맞는 적절한 망치를 사용하는 게 효율적이니까요. 그래서, 여러분이 그때그때 원하는 망치를 바로 만들 수 있도록 망치 공장을 판매하고 있습니다. 내부에 노동자들을 적절히 배치하고, 기계를 동작시키고, 간단한 재료를 수급하고, 세금만 제대로 낸다면 여러분이 원하는 바로 그 망치를 눈 깜짝할 새에 손에 넣을 수 있지요."

- "근데 저는 딱히 망치 공장을 사고 싶지 않은데요..."

- "다행이네요. 저흰 이제 망치 공장을 팔지 않거든요."

- "아니 방금 분명히..."

- "대부분의 사람들은 모든 요소가 갖춰진 뼈대를 원하지 않아요. 예를 들면, 몇몇 사람들은 평생 동안에 아메리칸 망치는 필요로 하지 않을 수도 있겠지요. (죽이고 싶은 원수가 없거나, 고드름으로 죽일 수도 있으니까요) 그래서 우리는 적절한 판단 하에, 모든 종류의 망치를 제작할 수 있는 망치 공장을 판매할 이유가 없다고 결정하였습니다."

- "예"

- "그래서, 대신 망치의 설계도와 제작 방법을 판매하는 것으로 손님들의 입맛에 맞는 망치를 제작할 수 있도록 도와드렸답니다. 이제 손님들이 원하는 완벽한 도구를 만들 수 있게 말이죠."

- "네, 제가 한번 맞춰볼게요.. 이것도 이제는 안 팔잖아요?"

- "당연하죠! 사람들은 그깟 망치 한 두개 만들자고 온갖 설비를 들이고 싶지 않아하니까요! 이미 망치 제작 전문가들이 지천에 널려있는데 뭐하러 굳이 설비를 들여 망치를 손수 제작하나요? 제가 항상 손님들에게 해드리는 이야기에요!!"

- "그렇다면 당신이.. "

- "그렇습니다. 그래서 설계도 판매는 그만두고 대신 망치를 만드는 기계를 만드는 기계를 팔기 시작했어요. 전문가가 제작한 기계니까 완성도에 대해서는 신경쓸 필요가 없으니까요. 이제 여러분이 직접 설계한 망치를 만드는 기계를 만드는 기계를 가질 수 있게 되었지요."

- "그건 너무 비효율적인.."

- "무슨 말 하려는지 알지요!! 당연히 그것도 이제 안 팔아요. 왜냐면 망치를 만드는 기계를 만드는 기계를 찾는 사람들은 너무 적었으니까요. 그래서 새로운 해결책을 들고 왔습니다."

- "예."

- "시간을 들여 저희의 기술 인프라를 평가해본 결과, 사람들은 망치 만드는 기계를 만드는 기계를 다뤄야 한다는 사실만으로 절망감을 느끼더라구요. 해머 만드는 기계를 만드는 기계 다루는 법은 자 만드는 기계 만드는 기계를 다룰 때와 수평 공구 만드는 기계 만드는 기계를 다룰 때는 쓸모가 없으니까요. 공구를 만드는 동안 낭비되는 나무의 양은 말할 것도 없지요. 간단한 찬장 하나 만들자는 사람한테 너무 복잡했던 거에요."

- "이런 젠장..."

- "그래서 이번 주부터, 도구를 만드는 기계를 만드는 기계를 만드는 기계를 판매하기로 했습니다. 이거 하나만으로 모든 종류의 도구를 만드는 기계를 만드는 기계를 제작할 수 있답니다. 이거 하나만으로 여러분은 여러분이 필요로 하는 하나의 특징적인 도구를 만들 수 있는 기계를 만들 수 있는 기계만을 제작할 수 있답니다. 이제 이 기계만 있으면 단 한번의 동작으로 여러분이 원하는 완벽한 망치와 자를 가질 수 있어요. (물론 제대로 동작하기 위해선 조금의 환경 설정이 필요하긴 하지만요.)

- "아니 그래서 망치는 아예 안 팝니까?"

- "네. 만약 당신이 당신의 조미료를 위한, 정말 고퀄리티의, 산업 표준이 되는 그야말로 완벽한 찬장을 원하신다면, 동네 도구상에서 파는 망치보다 훨씬 정교하고 고급진 것이 필요합니다."

- "아 예... 뭐 좋은 게 좋은거니까요. 만약 그게 요즘 트렌드라면 좀 배워두긴 해야겠네요."

- "훌륭합니다!"

- "그래서, 사용 방법도 함께 알려주나요?"

출처: Joel Spolsky의 "내가 프레임워크를 싫어하는 이유" 에서 간단히 발췌

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

- 오늘은 단독 사이트 하나를 개발할 것입니다. 해당 사이트는 유저와 상호작용할 수 있는 게시글들을 담습니다. 로그인한 유저들은 새로운 게시글을 작성하거나, 게시글을 즐겨찾기에 넣어둘 수 있습니다.

- 사이트 이름은 원하는 걸로 정하시고, 주제도 마음껏 결정하세요. (뉴스, 팬픽, 에로소설 등...)

##### _역주: 본문에도 에로소설이라고 되어있습니다 (erotic novellas)_

- 데이터베이스 또한 `Django`의 기본 `ORM`과 호환되는 한 마음껏 선택하셔도 됩니다.

- 레포는 단 하나의 `Django` 프로젝트로 이루어져야 합니다. 평소처럼 ex 단위로 찢어놓지 않으셔도 됩니다. 각 과제는 프로젝트에 새로운 기능을 추가할 것이고, 해당 기능이 제대로 동작하면 점수를 받을 수 있습니다.

- 'hard' url을 사용하시는 것은 절대 금지입니다. 뷰든 템플릿든간에, URL의 이름을 참고하여야 합니다.

- 뷰를 함수 형태로 구성하시는 것 또한 절대 금지입니다. `generic view`를 사용하세요.

- pdf에 명시된 순서대로 평가될 것이라는 사실을 기억하세요.

- 영어가 사이트의 기본 언어가 되어야 합니다. 다만 데이터베이스의 내용물은 뭐가 되든 상관 없습니다. 본인이 고대 그리스어를 잘 하신다면, 알아서 작성해 보세요.

- 기본 관리 어플리케이션을 남기셔야 합니다. (You must leave the default administration application)

> 💡 <br>
> 요구하지 않은 것들을 만드느라 시간을 낭비하지 마세요!

<br>

# Chapter 4

## Exercise 00

<br>

| **Piscine**                             | Exercise 00 |
| --------------------------------------- | ----------- |
| Exercise 00 : 모델 만들기 - 일반 클래스 |
| **제출할 폴더**                         | ex00/       |
| **제출할 파일**                         |             |
| **허용되는 함수**                       |             |

<br>

새로운 프로젝트를 생성하세요. 어플리케이션 구조 설정이나 이름짓기는 마음껏 하시되 논리적인 구조를 짤 수 있게 생각해 보세요. 이해가 쉬운 구조일 수록 평가도 쉬워집니다.

다음 모델을 작성하세요:

- `Article`: 게시글의 내용과 메타데이터. 다음 필드를 포함해야 합니다:

  - `Title`: 게시글의 제목. Character chain 64 max size, Non null.

  - `Author`: 게시글의 작성자. 사용자 모델 레코드를 참조합니다. Non null.

  - `Created`: 게시글이 생성된 날짜와 시간. 생성될 때 자동으로 작성되어야 합니다. Non null.

  - `Synopsis`: 게시글의 개요. Character chain max size 312. Non null.

  - `Content`: 게시글 내용물. 텍스트 타입입니다. Non null.

\_\_str()\_\_ 메소드는 title을 전송하도록 오버로드되어야 합니다.

- `UserFavouriteArticle`: 유저가 좋아요 누른 게시물들. 다음과 같은 필드를 포함해야 합니다 :

  - `user`: 유저 모델의 레코드를 참조합니다. Non null.

  - `article`: 게시글 모델의 레코드를 참조합니다. Non null.

\_\_str()\_\_ 메소드는 article 모델에 포함된 title을 전송하도록 오버로드되어야 합니다.

이 작업들이 끝나면, 이 과제의 진짜 내용에 대해 살펴보아야 합니다.

Generic view만 사용하여 (상속을 바로 받지 못하는 `View`는 괜찮습니다) 다음과 같은 기능들을 사이트에 구현해야 합니다. 각 기능들은 각자의 독자적인 URL 링크가 있어야 하구요.

`Articles`: `Article` 테이블에 기록된 모든 article의 필드들 (Contents 제외) 을 `HTML` 표 (table) 형식으로 보여주는 HTML 페이지.

표는 각 행의 제목을 알려주는 `header`를 포함해야 합니다.

`Home`: 필수 URL `127.0.0.1:8000`. `Articles`로 리디렉션됩니다.

`Login`: `POST` 타입의 폼을 보여주는 `HTML` 페이지. 유저명과 비밀번호를 이용하여 로그인 기능을 구현하세요. 에러가 발생했을 경우엔, 에러 메시지를 표시해야 합니다. 로그인 성공 시에는, `Home`으로 리디렉션되어야 합니다.

또한 최소한 3명의 서로 다른 유저들이 작성한 5개의 서로 다른 게시물을 제출해야 합니다. 필요한 경우 fixture를 제공해도 괜찮습니다. 게시물의 내용은 뭐든 상관 없습니다. 간단하게 Lorem Ipsum 같은 걸로 채워놓아도 괜찮아요.

> ℹ️ <br>
> css 포매팅은 이 과제에서 필요하지 않습니다.

<br>

# Chapter 5

## Exercise 01

<br>

| **Piscine**                  | Exercise 01 |
| ---------------------------- | ----------- |
| Exercise 01 : 또 일반 클래스 |
| **제출할 폴더**              | ex01/       |
| **제출할 파일**              |             |
| **허용되는 함수**            |             |

<br>

Generic view만 사용하여 (상속을 바로 받지 못하는 `View`는 괜찮습니다) 다음과 같은 기능들을 사이트에 구현해야 합니다. 각 기능들은 각자의 독자적인 URL 링크가 있어야 해요.

`Publications`: 현재 로그인한 유저의 `Article` 테이블에 기록된 `title`, `synopsis`, `created` 필드를 `HTML` 표 (table) 형식으로 보여주는 HTML 페이지.

각 게시물마다, 밑의 `Detail` 부분으로 연결되는 링크 URL을 구현하여야 합니다.

표는 각 행의 제목을 알려주는 `header`를 포함해야 합니다.

`Detail`: 데이터베이스에 있는 게시물 중 선택한 게시물의 모든 필드를 `HTML` 형식으로 보여주는 기능. 각 URL은 게시물의 식별자 (Identification) 을 포함해야 합니다.

필드의 배치 방법은 자유입니다.

`Articles` 페이지에서의 각 게시물별로 `Detail` 페이지로 이동하는 링크를 추가하여야 합니다.

`Logout`: 현재 로그인한 유저를 로그아웃시켜주는 링크. 이 링크는 사이트에서 잘 보이고 접근가능한 어떤 곳에든 배치해도 괜찮습니다. 로그아웃에 성공하면, `Home`으로 리디렉션됩니다.

`Favourites`: 현재 로그인한 유저가 좋아하는 게시물들의 제목을 링크를 포함한 리스트로 보여주는 `HTML` 페이지.

각 링크 - 게시물의 식별자를 포함한 URL - 을 누르면 각 게시물의 `Details` 페이지로 이동해야 합니다.

최소한 한 명의 유저와 그가 좋아하는 게시물 2개를 제출하세요.

<br>

# Chapter 6

## Exercise 02

<br>

| **Piscine**                            | Exercise 02 |
| -------------------------------------- | ----------- |
| Exercise 02 : 일반 클래스 - CreateView |
| **제출할 폴더**                        | ex02/       |
| **제출할 파일**                        |             |
| **허용되는 함수**                      |             |

<br>

`CreateView` 만을 사용해서 다음 기능을 구현하세요. 어김없이, 각 기능들은 각자의 독자적인 URL 링크가 있어야 합니다!

`Register`: POST 타입의 폼을 포함한 `HTML` 페이지, 로그아웃이 되지 않은 상태에서 신규 계정을 로그인할 수 있는 페이지입니다.

폼은 최소한 아이디, 비밀번호, 비밀번호 확인 란이 필요합니다. 이 폼은 해당 폼에만 독점적으로 사용되는 URL과 연결되어 접근가능해야 하며, `register`로 끝나야 합니다.

`Publish`: POST 타입의 폼을 포함한 `HTML` 페이지. 로그인한 유저가 새로운 게시물을 작성할 수 있는 페이지입니다. 작성자 필드는 표시되어서는 안됩니다. 검증 과정 중에 뷰에서 모든 값 생성이 완료되어야 합니다. 뷰에서 생성한 `form` 객체를 사용하여 폼을 만들어야 합니다. (\<input\> 태그를 이용하여 직접 폼을 만들지 마세요!!!)

`Publications` 기능에 해당 기능 (`Publish`) 에 접근가능한 링크를 추가하세요.

`Add to Favourite`: 각 게시물의 detail 페이지에 연결된, POST 타입의 폼을 포함한 `HTML` 페이지. 어떠한 폼도 눈에 띄면 (visible) 안 됩니다. `article` 필드는 현재 보고 있는 게시물의 ID로 채워져 있어야 하고, 검증 단계에서 `user` 필드는 현재 로그인된 유저 아이디로 채워져야 합니다. 이 기능은 로그인한 유저가 게시물을 좋아하는 게시물 리스트에 추가할 수 있도록 해요.

> ℹ️ <br>
> css 포매팅은 이 과제에서 필요하지 않습니다.

> 💡 <br>
> 쟝고의 내부에 이미 선언된 (ready-made) 폼을 알고 계신가요?

<br>

# Chapter 7

## Exercise 03

​
<br>

| **Piscine**                      | Exercise 03 |
| -------------------------------- | ----------- |
| Exercise 03 : 템플릿 태그와 필터 |
| **제출할 폴더**                  | ex03/       |
| **제출할 파일**                  |             |
| **허용되는 함수**                |             |

<br>

**모든** 페이지에서 접근가능한 (보이는) 메뉴 섹션을 만들어야 합니다.

메뉴에 포함된 모든 링크들은 **여러분이 아까까지 만든 기능들**에 접근해야 합니다. 뭔가 빠진 것 같다면, 눈을 감고 되짚어 보세요.

이 메뉴는 다음과 같은 요소를 포함해야 합니다:

- `Home`: `Home` 으로 돌아가는 기능 (`Articles`로 리디렉션되는 거, 잊지 않으셨죠?)

- `Last Articles`: `Articles` 기능으로 이동하는 링크. 이 링크의 이름은 여러분의 사이트 테마에 따라 입맛대로 정하셔도 됩니다. (다만 반드시 영어로 지으세요!)

- 유저가 로그인 하지 않았다면:

  - `Register`: `Register` 창으로 이동하는 링크.

  - `Login`: `Login` 기능. 약간 다른 점은, 다른 항목과는 다르게 링크를 포함하는 것이 아니라 메뉴에서 로그인이 바로 가능하도록 메뉴 **안에** 폼을 보여야 합니다.

  이 말인 즉슨, 로그인 전용 페이지 뿐만이 아닌 모든 페이지에서 해당 폼이 접근가능해야 한다는 의미입니다.

  다만, 폼이 부적합할 경우 (invalid) 에러 메시지를 항상 띄워야 합니다.

- 유저가 로그인했다면:

  - `Favourites`: `Favourites` 항목으로 가는 링크

  - `Publications`: `Publications` 항목으로 가는 링크

  - `Logged as <유저명>`: 유저가 로그인했다는 것을 알려주는 간단한 텍스트. 당연히, \<유저명\> 부분은 지금 로그인된 유저의 유저명으로 교체되어야 합니다.

  - `Logout`: `Logout` 기능. 드디어 이 링크를 넣어둘 수 있는 적합한 장소를 찾았네요.

태그와 필터를 이용해서, 모든 게시물을 다음과 같이 정렬할 수 있도록 템플릿을 수정하세요:

- 문자열은 최대 20글자 길이로 줄어들어 (abstract) 표현되어야 합니다. 생략된 글자들은 말줄임표 (...) 로 교체되어야 합니다. 이를 보여줄 수 있는 예시를 준비하세요.

- 게시글의 리스트는 최근 것부터 예전 것 순으로 정렬되어 표시되어야 합니다.

- 이 게시글이 등록된 지 얼마나 긴 시간이 지났는지 알려주는 새로운 행을 추가하세요.

> ℹ️ <br>
> css 포매팅은 이 과제에서 필요하지 않습니다.

<br>

# Chapter 8

## Exercise 04

​
<br>

| **Piscine**              | Exercise 04 |
| ------------------------ | ----------- |
| Exercise 04 : 부트스트랩 |
| **제출할 폴더**          | ex04/       |
| **제출할 파일**          |             |
| **허용되는 함수**        |             |

<br>

부트스트랩을 이용해서, 오늘의 과제 자료로 주어진 이미지와 똑같은 CSS 포맷을 가지도록 메뉴를 꾸며보세요.

<br>

# Chapter 9

## Exercise 05

​
<br>

| **Piscine**          | Exercise 05 |
| -------------------- | ----------- |
| Exercise 05 : 국제화 |
| **제출할 폴더**      | ex05/       |
| **제출할 파일**      |             |
| **허용되는 함수**    |             |

<br>

해당 사이트의 `Articles` 기능을 (Articles 기능에서 접근가능한 `메뉴` 또한 당연히 과제 요건에 포함됩니다.) URL의 접두사 (prefix) 에 따라 번역하여 표시해야 합니다.

예를 들면:

- URL이 `127.0.0.1:8000/en/articles` 일 경우, 모든 컨텐츠는 영어여야 합니다.

- URL이 `127.0.0.1:8000/<언어명>/articles` 일 경우, <언어명\> 여기에 적힌 언어로 번역되어 표시되어야 합니다.

사이트명이나 데이터베이스 내용들은 번역할 필요 없습니다.

사이트의 기본 언어는 영어여야 합니다.

해당 페이지에 언어를 바꿀 수 있는 링크를 추가하세요.

<br>

# Chapter 10

## Exercise 06

​
<br>

| **Piscine**          | Exercise 06 |
| -------------------- | ----------- |
| Exercise 06 : 테스팅 |
| **제출할 폴더**      | ex06/       |
| **제출할 파일**      |             |
| **허용되는 함수**    |             |

<br>

`Django`의 내장 프레임워크를 사용하여, 테스터를 제작하여 사이트의 다음 기능들이 잘 동작하는지 테스트할 수 있도록 해 보세요:

- `favourites`, `publications`, `publish`와 그 템플릿들은 로그인한 상태에서만 접근가능하여야 합니다.

- 로그인한 유저는 회원가입창에 접근할 수 없습니다.

- 유저는 같은 게시물을 두 번 이상 '좋아요 리스트' 에 추가할 수 없습니다.

각 테스트들은 명시적으로 이름붙여져 있어야 하고, 어떤 동작을 하는지 제대로 보여야 합니다.

테스터가 띄우는 에러를 전부 수정해 보세요.