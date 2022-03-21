# ft_printf


### 1. 프로젝트 소개
표준 라이브러리의 printf 함수를 재구현한다. (단, 실제 printf처럼 버퍼 매니지먼트를 해선 안됨다.)
이 프로젝트를 통해서 다음을 배웠다. 
* 가변함수


### 2. 실행
```shell
git clone https://github.com/jikwon101/42/ jikwon_42
cd jikwon_42/ft_printf

# 라이브러리 생성
make

# 오브젝트 파일 삭제
make clean

# 오트젝트 파일 및 라이브러이 파일 삭제
make fclean

# 라이브러리 파일 재생성
make re
```
 
### 3. 함수 소개
```c
int ft_printf(const char*, ...);
```

*conversion*

c, s, p, d, i, u, x, X, %

*flag*

'-', '*', '0', '.', 'minimun filed width'


### 4. 프로젝트 규칙

- 프로젝트는 Norm 규칙에 맞춰 작성되어야 한다.
- 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단 되어서는 안 된다. (segmentation fault, bus error, double free 등. )
- 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 한다. 메모리 누수가 발생해서는 안된다. 
- 이 라이브러리는 GCC로 `-Wall -Wextra -Werror` 플래그를 지정하여 컴파일 된다. 
- Makefile은 relink 되어서는 안된다. 
- 전역 변수는 사용할 수 없다.
- 복잡한 함수를 작성하기 위해 하위 함수가 필요한 경우에는, 이러한 하위 함수를 라이브러리와 함께 publishing 하지 않도록 static(정적)으로 정의해야 한다.
