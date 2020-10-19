# LN1 What is System Programming 학습 목표
- 시스템 프로그래밍의 정의를 이해
- 시스템 프로그래밍의 3가지 타입에 대한 설명
- Hardware consideration
- 추상화에대한 개념 이해

## 시스템 프로그래밍의 정의
- 응용 프로그램들이 수행될 수 있는 컴퓨팅 환경을 제공하는 프로그램
  - 응용 프로그램은 특정한 목표를 달성하기 위해 만들어지는 프로그램
- 따라서 하드웨어와 연관이 깊음
- 컴퓨터를 도구로 사용하는 프로그램이기 보다 컴퓨터를 만드는 프로그램이라 생각하고 있자!

## 시스템 프로그래밍의 타입
- Compilation system
  - 컴퓨터 언어는 다음과 같은 세가지 계층으로 나뉜다.
    - High-lever Laguage(고급 언어) : 인간이 더 효율적으로 프로그래밍 하기위해  만든 언어
    - Assembly Language(어셈블리어) : 고급 언어와 기계어 사이에 중간 정도의 언어이다.
    - Machine Language(기계어,binary) : 기계가 이해할 수 있는 언어로 이진수로 표현된다.
  - 고급언어로 작성한 언어를 컴퓨터가 이해할 수 있는 기계어로 만들어 주기위해 필요한 것이 Compilation system 이다.(고급 언어 -> 어셈블리어 -> 기계어)
  ![Compilation system](https://miro.medium.com/max/3628/1*hQDhA0nO8ZvmXDpg-GJNVw.png)
- Operating system
  - 다름이 아닌 그 유명한 OS, 운영체제가 바로 이 녀석이다.
  ![OS](https://w.namu.la/s/714c0e6deee4500d49151cfdb943fe1590236291f619ca7cc91e15b159db517b71a2c4f9e9338b74bddec3ec95c809820e8ba7813b8e0eff59a4267058c002f5a965d549cf74e4683265d223b78fdb0f2475537605f8a97ff9c829f1642e4c6d)
  - Kernel(커널) : 운영체제의 심장이자 그 OS의 정체성을 규정짓는 친구 하드웨어의 자원을 자원이 필요한 프로세스에 나눠주고, 덩달아 프로세스 제어(태스크 매니저), 메모리 제어, 프로그램이 운영체제에 요구하는 시스템 콜 등을 수행하는 부분으로 운영체제 맨 하부에서 돌아간다. OS의 심장 같은 존재(심장이 맛 가면... RIP)
  유닉스 계통은 모두 단일형 커널이기 때문에 커널이하는 일이 엄청 많다.(커널의 인권을 보장하라!)
    - Process manager : process manipulation, schedule, IPC, signal, cotext switch
    - Virtual Memory : page, segment, address traslation, buddy, LRU
    - File system : file, directory, disk scheduling, FAT
    - Dvice driver : IO port management, interrupt, DMA
    - Network protocol : connection, routing, fragmentation
    (겁 먹지마 나중에 다 할꺼야 ㅋㅋ)
  - Runtime system
   - 런타임 시스템의 개념을 이해한대로 작성하자면 음... 프로그램이 실행되는 환경? 공간?을 뜻하는 것 같다.
   - 런타임 시스템의 종류
    - Commend
    - Shell
    - Library
    - Framework
    - Vitual machine and Docker
    - Key-Value Store
## Hardware consideration
 - 이 파트는 도대체 뭘 말하고자 한참을 고민했다... 일단 시스템 프로그래밍의 목적 중 더 효율적인 응용 프로그램 작성이 있는데 이를 위한 하드웨어 고려를 설명하려는 것 같다.
 - 예를 두가지 정도 드는데 하나는 메모리 하나는 CPU이다. 이 둘 모두 프로그램이 하드웨어적 구조로 인해 비효율적인 프로그램이 되는 것을 예시로 들고있다. 대표적인 것이 2차원 배열의 행 or 열 우선 access에 메모리 효율 차이이다.
## 추상화
- 엄청 중요하다.똑바로 이해해라 간다잇!
- 추상화라는 어떤 대상들에 대해 그것이 꼭 가져야할 핵심적인 특징 즉 프로그래머가 그 대상에 기대하고 필요한 특징을 가지는 모델을 만드는것이다. 여기서 중요한것은 그 핵심적인 특징을 제외한 나머지는 프로그래머에게 제공하지 않는데 있다.
- ㅋㅋ 질문 많은거 알아 왜 이렇게 하냐 이 말이지 근데 사실 추상화는 너가 굉장히 애용하는 개념이야 한번 볼까? 너가 c언어로 프로그래밍할때 printf("아 줜나 어렵다~"); 라는 코드를 짰을때 너는 진정 이 코드를 정확히 알까? 안다는놈들은 이거 보고있음 안되징 딴대로 가 printf라는 함수가 호출되고 이것이 컴퓨터 내부에서 어찌 작동되는지 너는 상관 안하자나 그저 "아 줜나 어렵다~"가 화면에 출력되기만 하면 그만이지 이게 바로 추상화야
- 어려운건 몰라도 돼 너는 필요한것만 알고 사용해! 짧게 말하자면 빡대가리 인간들을 위한 친절한 개념이 추상화다 이 말이야
- 멋있는 말로 써보자면 '컴퓨터 과학에서 추상화(abstraction)는 복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념 또는 기능을 간추려 내는 것을 말한다.' 라고하네
- 이 추상화가 계층적인 구조를 이루어 추상화의 정도가 다른거지 깊이 들어갈수록 더 정확한 대상을 가리키게 되지(설명이 부실하네...) 
