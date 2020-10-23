# CSS3 고급 활용

## CSS3의 3가지 박스 유형
- html 태그는 블록태그와 인라인 태그로 나뉘어 저번에 설명한거니까 따로 설명은 안해~(꼬우면 잘 하셨어야죠!)
- 이 박스 유형을 display 속성으로 지정해 줄 수가 있어 
- 속성 값으로는 block, inline, inline-block 이 있어
- display:block
  - 항상 새 라인에서 시작(항상 한 단락을 혼자 차지)
  - 부모가 블록박스일때만 배치 가능
  - width, height으로 크기조절 가능
  - padding, margin, border 조절 가능
- display:inline
  - 새 라인에서 시작 불가(한 줄의 일부분이라 생각)
  - 모든 박스 내부에 배치 가능
  - width, height으로 크기조절 불가능
  - margin-top, margin-bottom 조절 불가능(어찌보면 당연 고작 한줄의 일부가 혼자만 위로 늘릴수는 없는 마당)
- display:inline-block
  - 새 라인에서 시작 불가(inline)
  - 모든 박스내 배치 가능(inline)
  - width, height으로 크기조절 가능(block)
  - padding, border, margin 조절 가능(block)
- block은 어떤 큰 세계관을 이루고 그 안의 생명체나 그새계를 이루는 개체가 inline 그 세계관의 주인공들인 inline-block같은 느낌이군... 크크킄

## 박스의 배치
- 브라우저는 웹 페이지에 나타난 html 태그 순서대로 배치해 이걸 normal flow라고 불러
- 하지만 이러면 내가 원하는 배치가 힘들 수있자나? 그래서 박스를 배치할수잇는 속성이있지 바로 position 이야!
- 정적 배치-position:static(디폴트) 
  - 정적 배치는 그냥 디폴트 대로 출력하는거야 나온 태그 순서대로 배치하는거
- 상대 배치-position:relative
  - normal flow대로 출력된 위치를 기본위치로 두고 그 기본위치에서 left,top,bottom,right 만큰 이동 한 상대 위치로 배치하는 방식이야
  - 상대배치로 배치된 태그는 다른 태그의 위치에 영향을 미치지 않아
  - 양수 값은 콘탠츠의 안쪽방향으로 이동 음수 값은 바깥쪽으로 이동해
- 절대 배치-position:absolute
  - 부모 태그를 기준으로 상대 좌표에서 어떤짓을 하더라도 변하지않는 배치야
- 고정 배치-position:fixed
  - 줮같은 광고가 여기 포함되는 듯해 아무리 스크롤을 내려도 따라오자나
  - 어떤 짓을 하더라도 브라우저를 닫지 않는한 항상 보이게 해주는 배치야
- 유동 배치-float
  - 다른놈들은 무시하고 일단 배치시킨 후 다른놈들이 이놈을 피해 배치되는 느낌
- 수직으로 쌓기-z-index
  - 겹쳐서 출력될 태그들의 순서를 정해준다.
  - nomal flow는 자동으로 결정되고 relative나 abslolute에 경우만 작동한다.
- 가시성-visibility
  - 보이냐 안보이냐 이건대 보이면 visible 안보이면 hidden
  - 대신 diplay:none과 다르게 자리는 차지한다.
- overflow
  - 블록 태그에만 적용되고 박스 크기보다 콘탠츠의 크기가 커서 넘 칠때 visible은 그냥 넘어가게 출력 hidden은 그냥 짤라버리고 scroll은 스크롤바를 항상 부착시키고 auto는 넘치면 스크롤바 부착 시킨다.

