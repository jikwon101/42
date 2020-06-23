#include <math.h>
#include <stdio.h>
//sqrt 컴파일시 -lm옵션 추가해줘야함
int main()
{
	double a = 9.0;
	double result1 = sqrt(a);
	printf("sqrt : %f\n", result1);
/*
	double b = -9;
	double result2=fabs(b);
	printf("fabs : %f\n", result2);
	
	double c = 2;
	double d = 3;
	double result3 = pow(2, 3);
	printf("pow : %f\n", result3);
	printf("sin(pie/2) : %f\n", sin(M_PI_2));
*/
	return 0;

}
