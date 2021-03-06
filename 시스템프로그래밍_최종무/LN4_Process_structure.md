# Process Structure
- 프로세스의 정의
- 프로세스 구조
- 프로그램과 프로세스 구조와의 관계
- 스택의 디테일

## 프로세스 정의
- 실행중인 프로그램
- 자신의 메모리공간과 CPU 레지스터들을 가짐
- 프로세스는 자원을 두고 경쟁 관계야
- load : 데이터가 디스크에서 메모리로 올라오는 것, 파일 시스템이 디스크를 가상메모리가 메모리를 관리 한다, 결론적으로 OS가 load를 처리한다.
- fetch : 데이터가 메모리에서 CPU로 올라오는 것, 명령어 패치와 데이터 패치로 나뉨, 페치는 CPU가 처리해준다.

## 프로세스 구조
- user space
  - text : 가장 아래 size 일정, 프로그램 코드가 들어감(assembly) 코딩순서에따라 낮은주소에서 높은주소로 올라감
  - data : text 위 size 일정, 전역변수들이 들어감 초기화된것과 초기화 안된것을 나누어 관리
  - heap : 동적으로 위로 자라남, 지역변수, 인자. 복귀주소가있다.
  - stack : 동적으로 아래로 자라남,  런타임중 메모리를 동적할당 할때 사용됨
- kernel : 커널을 위한공간
- shaer region : 커널을 위한 공간


![process_structure](https://i.stack.imgur.com/kvqxs.jpg)

- tip. 함수이름은 그자체로 주소

## 스택 디테일
- 인텔 스텍 구조
  - 인자, 리턴주소, 지역변수가 들어감
  - LIFO 구조를 띄며 push, pop으로 관리한다.
  - ESP(Extended Stack Pointer) 스텍에 탑을 가리킨다. pop, push시 ESP를 움직인다.
  - 함수가 호출되면 stack에 push되고 끝나면 pop 된다
  - stack frame : 함수가 저장되는 단위로 argument(여러개일경우 뒷 인자부터), return address, saved ebp(6장에서 배움) local variables 순으로 push 된다.
  
