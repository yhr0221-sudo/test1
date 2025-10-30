// 3장 변수 선언 방법

#include <stdio.h>

int main(void)

{
    int a; 
    int b, c;
    double da;
    char ch;

    a = 10;
    b = a;
    c = a+ 20;
    da = 3.5;
    ch = 'A';

    printf("변수 a의 값 : %d\n", a);
    printf("변수 b의 값 : %d\n", b);
    printf("변수 c의 값 : %d\n", c);
    printf("변수 da의 값 : %.1lf\n", da);
    printf("변수 ch의 값 : %c\n", ch);

    
// 정수 자료형 (정수를 저장하는 자료형의 종류)
// char : 1,  short: 2, int: 4, long: 4, longlong: 8 (단위: 바이트)

    char ch1 = 'A';
    char ch2 = 65;
    printf("문자 %c의 아스키 코드 값 : %d\n", ch1,ch1);
    printf("아스키 코드 값이 %d인 문자: %c\n", ch2,ch2);



// short , int , long, longlong 형의 최댓값 
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647;
    long long lln = 123451234512345;

    printf("short 형 변수 출력 :%d\n",sh);
    printf("int 형 변수 출력 :%d\n",in);
    printf("long 형 변수 출력 :%ld\n",ln);  //long 는 system 마다 다른 경우가 있음 여기선 4바이트.
    printf("long long 형 변수 출력 :%lld\n",lln);


    return 0;

}