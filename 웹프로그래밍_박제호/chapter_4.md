# CSS3로 웹 페이지 꾸미기
## CSS3 스타일 시트 개요
- CSS는 HTML 문서에 색이나 모양, 출력 위치 등 외관을 꾸미는 언어이며, CSS로 작성된 코드를 스타일 시트라고 부른다.
- 셀렉터라는 개념이 있는데 스타일 시트 내 셀렉터에 설정한 속성값들이 그 셀렉터와 같은 이름의 태그에 모두 적용 됨
- 스타일 시트는 중괄호를 사용
- {프로퍼티 : 값; 프로퍼티 : 값;}과 같은 형식
- 마찬가지로 대소문자 구분 안해
- style 태그는 항상 헤드안에 작성, 여러 개 작성 가능
- 태그 안에도 스타일 시트 작성 가능 style 속성을 활용
- link 태그를 사용해 외부의 스타일 시트를 불러올 수 있다.
- CSS 파일은 html 파일이 아니라서 style 태그 필요없다
- style 태그 내부에서 @import를 활용해 .css파일을 불러올수있다
- css3 스타일은 부모태그로 부터 상속된다.(뭔말인지 알거야~)
- 스타일은 브라우저 디폴트 스타일, .css 스타일 시트 파일에 작성된 스타일, style태그 내 작성된 스타일, style 속성에 작성된 스타일이 합쳐서 적용된다.
- 그럼 문제 가 있지? 같은 스타일을 다르게 정의 하면 어쩌냐 이 말이야~ 그래서 우선순위가 결정되어있어 style 속성에 작성된 스타일이 최우선이야. 그리고 디폴트 스타일이 제일 미천한 놈이지
- 자세한건 구글에 '스타일 시트 우선순위'라고 검색 해
- 태그 이름 셀렉터는 콤마(,)로 구분이 가능해
- class 셀렉터는 .class{}같은 방식으로 작성해
- id 셀렉터는 #id{} 같은 방식으로 작성해
- div > strong{} 에서 > 는 부모 자식 관계임을 뜻해
- ul strong{}은 ul의 자손 즉 친자식이 아니더라도 strong에 스타일을 적용시킨다는 뜻이야
- *{} 은 전체 셀렉터 (전체야 말그대로 전체~!)
- 속성 셀렉터 특정 속성값을 갖는 놈들에게 적용하는 셀렉터 input[type=text]{}와 같은 형식이야
- 가상 클래스 셀렉터는 a:visited{} 와 같이 사용하는데 특정 상황이 이루어지면 스타일을 적용시키라는 뜻이야
- 나머지 세세한 값들은 176p부터 참고해~ㅋㅋ 참고하라고

## 박스 모델
- html에 각 요소는 사각형 박스로 다루어져 
- 그 박스는 콘텐츠(텍스트나 이미지), 패딩(테두리 안 내부 여백), 테두리(패딩 외부 외곽선), 여백으로 이루어져(박스의 맨 바깥 쪽, 테두리 바깥) 
- 나머지는 책봐 새기야~
