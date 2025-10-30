#include<stdio.h>
#include<string.h>  // string.h 헤더 파일 추가 (문자열을 다룰 수 있는 헤더 파일 strcpy에 씀)

int main(void)
{
    unsigned int a;     // unsigned자료형은 항상 양수만 저장,%u 로 출력함.

    a = 4294967295;
    printf("%d\n", a); // -1 이 출력되는 이유 4294967295는 담을 수 있는 가장 큰 수 (이진수로 변환한 결과 11~~11) >> %d는 111..111을 -1로 인식하기 때문에 -1로 출력함.
    // 맨 앞 비트가 1 이면 음수로 판단 이외 모든 비트가 1이면 %d는 1로 판단 >> -1
    a = -1;
    printf("%u\n",a); //%u는 맨 앞 비트가 1임일 신경쓰지않음 >> 양수만 저장하고 출력할 수 있음 >> 따라서 4294967295와 -1의 비트 형태가 같으므로
    // 11..1111을 그 값 그대로 출력할 수 있음 

    float ft = 1.234567890123456789; //유효 숫자가 많은 값으로 초기화 (소수점이하 7자리)
    double db = 1.234567890123456789; // 소수점 이하 15자리 까지 출력 >> 소수점 아래의 숫자가 유의미하거나 지키고 싶을 때 사용. (소수점이하 15자리 이상은 long double 사용)
    printf("float형 변수의 값 : %.20f\n",ft);
    printf("double 변수의 값 : %.20lf\n",db);

    char fruit[20] = "strawberry";          // char 배열 선언과 문자열 초기화  fruit[20]에서 fruit:배열명, [n]: n = 문자열의 길이
                                           // 문자열의 길이는 저장할 문자열의 길이 +1 (\n이 들어갈 공간이 필요하기 때문.) 
    printf("딸기 : %s\n", fruit);           // 배열 명으로 저장된 문자열 출력
    printf("딸기쨈 : %s %s\n", fruit, "jam"); // 문자열 상수를 직접 %s로 출력
    printf("%s\n",fruit);
    strcpy(fruit,"banana");     //fruit 에 BANANA를 복사함 (string copy)
    printf("%s\n",fruit);

        
    //const
    int income = 0;
    double tax;
    const double tax_rate = 0.12;       // const를 사용한 변수는 초기값 수정 불가능.
    income = 456;
    // double tax_rate = 0.1;  바꾸려고 해도 const 때문에 변경 불가능
    tax = income * tax_rate;
    printf("세금은 : %.1lf입니다.\n",tax);


    //식별자는 사용자가 만든 단어 , 예약어는 컴파일러와 약속된 단어임. 대문자와 소문자는 서로 다른 식별자
    // 숫자로 시작하거나 특수문자, 띄어쓰기, 예약어 등은 식별자로 사용할 수 없음.(3times, behappy~, apple tree는 사용 불가능)

    return 0;
}