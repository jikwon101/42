# Libft

> 자주 사용하는 C언어 함수들을 재구현 하여 나만의 C라이브러리 만들기.


### 1. 프로젝트 소개

42Seoul에서는 명시적으로 허가된 함수들을 제외하고는 표준 함수들을 사용하는 것이 금지되어 있다. 필요한 함수는 직접 구현해 사용해야 한다. 
이 프로젝트를 통해서 다음을 배웠다. 
* 함수 정의와 호출 방법
* C 포인터 사용
* 메모리 할당 및 해제 등 메모리 관리
* 라이브러리 사용 방법
* 자료 구조 : 연결리스트 
* static 키워드


### 2. 실행
```shell
git clone https://github.com/jikwon101/42/ jikwon_42
cd jikwon_42/libft

# 기본 함수 라이브러리
make

# 기본 함수 + 리스트 함수 라이브러기
make bonus

# 오브젝트 파일 삭제
make clean

# 오트젝트 파일 및 라이브러이 파일 삭제
make fclean

# 라이브러리 파일 재생성
make re
```

### 3. 프로젝트 규칙

- 프로젝트는 Norm 규칙에 맞춰 작성되어야 한다.
- 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단 되어서는 안 된다. (segmentation fault, bus error, double free 등. )
- 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 한다. 메모리 누수가 발생해서는 안된다. 
- 이 라이브러리는 GCC로 `-Wall -Wextra -Werror` 플래그를 지정하여 컴파일 된다. 
- Makefile은 relink 되어서는 안된다. 
- 전역 변수는 사용할 수 없다.
- 복잡한 함수를 작성하기 위해 하위 함수가 필요한 경우에는, 이러한 하위 함수를 라이브러리와 함께 publishing 하지 않도록 static(정적)으로 정의해야 한다.

  

### 4. 함수 리스트

이 라이브러리의 함수들은 크게 세 가지 파트로 나눌 수 있다. 


#### Part 1. Libc functions

man에 정의된 프로토타입의 함수들 재구현 한다. 
함수의 이름 앞에는 'ft_' 을 붙여 표준 라이브러리 함수와 구분한다. 

다음의 함수들을 구현했다. 

> memset • bzero • memcpy • memccpy • memmove • memchr • memcmp • strlen • strlcpy • strlcat • strchr • strrchr • strnstr • strncmp • atoi • isalpha • isdigit • isalnum • isascii • isprint • toupper • tolower

그리고 아래의 함수들은 `malloc`함수를 사용하여 재구현 했다.

> calloc • strdup


#### Part 2. Additional functions

다음의 함수들을 구현했다.

> substr • strjoin • strtrim • split • itoa • strmapi • putchar_fd • putstr_fd • putendl_fd • putnbr_fd



#### Part 3. List functions

리스트의 구조는 다음과 같다.
```c
typedef struct    s_list 
{ 
    void          *content; 
    struct s_list *next; 
}                 t_list;
```

아래의 함수들을 구현했다.

> ft_lstnew • ft_lstadd_front • ft_lstsize • ft_lstlast • ft_lstadd_back • ft_lstdelone • ft_lstclear • ft_lstiter • ft_lstmap