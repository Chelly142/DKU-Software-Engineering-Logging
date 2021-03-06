# Process Programming
- 프로세스와 관련된 시스템 콜 
- 새로운 프로세스 생성 방법
- 새로운 프로그램 실행 방법
- 쉘에대한 이해
- 멀티테스킹 시스템 이해

## 프로세스 관련 시스템 콜
- fork(),clone() : 프로세스 생성, task_struct 생성(inode와 비슷 pid와 메모리 정보를 저장)
- execve() : 새로운 프로그래 실행(binary loader)
- exit() :  프로세스 종료
- wait(), waitpid() : 프로세스를 잠시 멈춤(자식 프로세스 종료 대기)
- getpid() : 프로세스 id를 얻음

### fork()
- 세로운 프로세스를 만든다 기존의 프로세스를 메모리에서 그대로 복사 가져옴
- 기존의 프로세스는 부모 프로세스 새로 만들어진 프로세스를 자식 프로세스라고함
- 리턴 값이 2개이다. 부모의 리턴값(자식 pid 항상 0보다큼)과 자식의 리턴값(0)
- fork()를 만난순간부터 그 이후의 제어흐름이 2개로 나뉜다.
- fork() 수행 시 메모리에 text는 읽을 수만 있으므로 부모와 자식이 공유하고 stack과 data는 복사해서 새로 만들어진다.
- 따라서 부모와 자식은 서로 독립되어있어 서로 영향을 끼치거나 변화를 알거나 할 수 없다.

### execve()
- 새로운 프로그램을 수행 시키는 시스템 콜
- exec이 성공하면 기존의 프로세스에서 새로 실행된 프로그램 프로세스로 대체되어 다음 코드는 실행되지 않는다.
- execve() 실행시 대상 프로그램을 디스크로부터 메모리로 올린 후 process의 메모리 이미지를 교체한다.
- 메인 함수는 최대 3개의 인자를 받는데 인자수, 인자값들, 환경변수 가있다.
- 환경변수는 터미널 정보를 결정
- 인자를 따로 나열하면 list, 배열로 묶어 전달하면 vector이다
- 리눅스에서 오브젝트 파일은 elf 구조를 따르기 떄문에 프로세스 구조와 비슷하고 관련이 되어있다.

### Shell
- 커멘드 해석기
- 기본 동작 구조 
  - prompt를 띄우고 입력을 parsing 한다
  - 외부 명령어의 경우 fork()하고 자식 프로세스에서 execve()을 해준다.
  - 내부 명령어의 경우 그냥 처리
- Shell 고급기능
  - background processing : &, wait()를 사용 안하면 됨
  - rediraction : >, execve()전에 dup2()를 사용해 원하는 파일디스크립터로 바꿔준다.
  - pipe : |, 프로세스간의 커뮤니케이션
  - Shell script

### 프로세스 프로그램 심화
- signal() : 프로세스 수행중 시그널을 받으면 프로세스를 멈추고 프로세스 헨들러를 처리하고 다시 수행하는데 이때 시그널 핸들러를 등록하기위해 쓰이는 시스텤 몰
- kill() : 시그널을 보냄
- alarm() : 몇초 이후에 시그널을 보냄
- sleep() : 몇초동한 프로세스 멈춤
- pause() : 시그널을 받을때까지 프로세스 멈춤
- nice(), getpriority(), setpriority() : 프로세스 우선순위 결정
- scheduler : 프로세스 스케줄링 정책 결정
- time(), gettimeofday() : 프로세스 수행 시간 구할떄 사용
- ptrace() : 한 프로세스가 다른 프로세스를 제어할때 사용
- 경쟁 상태 : fork()시 부모,자식 프로세스는 공유자원에 동시에 access 함으로 서로 순서관계를 주지 않으면 서로 번갈아 가면 access 하게된다. 따라서 wait()등을 이용해 순서관계를 주어야한다. 이를 동기화라고한다.
- 가상 메모리에서의 주소와 실제 메모리 주소는 서로 다르다 이를 연결해주는게 sagment table, paging이다.
- 쓰레드
  - 프로세스 모델은 각 프로세스 마다 독립적이고 디버그가 쉽다 하지만 느리고 IPC(pipe)가 필요하다
  - 쓰리데 모델은 메모리를 적게 사용하고 전역변수를 사용해 데이터를 공유한다. 한쓰레드가 죽으면 나머지도 다죽는다 또한 디버그가 힘들다.
  -pthread_creat()으로 쓰레드 생성함, pthread_join()으로 프로세스에 넣어줌
