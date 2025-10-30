#include <stdio.h>
#include <string.h>
//define 대문자 값 
// #define EARNED_INCOME_TAX_RATE 4
// #define LOCAL_INCOME_TAX_RATE 10
// #define NATIONAL_PENSION_RATE 4.5
// #define EMPLOYMENT_INSURANCE_RATE 0.8
// #define HEALTH_INSURANCE_RATE 3.38

int main(void)
{
    //교재 예제 p54
    // double salary;
    // double earn_it =4.0 , loac_it= 10.0, n_pension= 4.5, employ_i = 0.8, health_i= 3.38;
    // double eit, lit, np, ei, hi,total;

    // printf("This program calculates social insurance tax.\n");
    // printf("Please enter your salary(month) :");
    // scanf("%lf",&salary);

    // eit = salary * (earn_it / 100.0);
    // lit = eit * (loac_it / 100.0);
    // np = salary * (n_pension / 100.0);
    // ei = salary * (employ_i/100.0);
    // hi = salary * (health_i/ 100.0);
    // total = eit + lit + np + ei + hi ;

    // printf("\nEarne income tax: %10d won \n", (int)eit);
    // printf("Local income tax : %10d won \n", (int)lit);
    // printf("Nationa pension : %10d won  \n", (int)np);
    // printf("Employment insurance : %10d won \n", (int)ei);
    // printf("Health insurance : %10d won \n", (int)hi);
    // printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    // printf("Total :                   %10d won \n", (int)total);

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 매개변수가 없는 함수 
// 괄호 안에 매개변수 대신엔 void를 쓰거나 비워둔다. 반환값은 return 문과 함께 반환.
// ex) int get_num(void){... return num;}

// int get_num(void);
// int main(void)
// {
//     int result ;
//     result = get_num();
//     printf("반환값 : %d\n",result);
//     return 0;
// }
// int get_num(void)
// {
//     int num;
//     printf("양수 입력 :");
//     scanf("%d\n",&num);
//     return num;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 반환값이 없는 함수 
// // return 문이 없음
// void print_char(char ch, int count);

// int main(void)
// {
//     print_char('@',5);
//     printf("\n");
//     return 0;
// }
// void print_char(char ch, int count)
// {
//     int i;
//     for(i=0;i<count;i++){
//         printf("%C",ch);
//     }
//     return ;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 매개변수와 반환값이 모두 없는 함수

// void print_line(void);
// int main(void)
// {
//     print_line();
//     printf("학번        이름        전공        학점        \n");
//     print_line();
//     return 0;
// }
// void print_line(void) //void -> 매개변수 없음
// {
//     int i;
//     for(i=0;i<30;i++){
//         printf("ㅡ");
//         //return 이 없음
//     }
//     printf("\n");
// }
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 재귀 호출 함수 : 함수를 불렀는데, 안에서 또 부름

// void fruit (void);
// int main (void)
// {
//     fruit();
//     return 0;
// }
// void fruit(void)
// {
//     printf("apple \n");
//     fruit(); //자신을 다시 호출
// }
// //apple이 계속 출력되는 결과

// void fruit (int count); //count 라는 매개변수를 받음
// int main(void)
// {
//     fruit(1); // 처음 호출하므로 1을 인수로 준다.
//     return 0;
// }
// void fruit(int count)
// {
//     printf("apple\n");
//     if (count == 3) return ; //호출 횟수가 3이면 반환하고 끝낸다.
//     fruit(count + 1); //재호출 할 때 카운트가 1증가 
// }
// // apple가 3번 출력되는 결과

// // return은 위 코드의 실행이 끝났음을 의미함.
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 재귀호출과 반복문의 차이점
// 반복문은 바로 끝나지만 재귀호출은 부른곳으로 다시 올라가서 코드실행 > 다시 올라가서 코드실행 --> jam이 2번 출력되는 이유임. (7.2)

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 재귀호출을 이용해 1~10까지 합

// int sum(int count);
// int main (void)
// {
//     int result = sum(10);
//     printf("result : %d\n",result);
//     return 0;
// }
// int sum(int count)
// {
//     if (count==0) return 0;
//     return count + sum(count -1);
// }
// // sum(count -1)이 계속 int sum()함수를 반복
// // 1회 count(10) + sum(count -1) -> 2회 count(9) + sum(count -1) -> ... -> count(1) + sum(count -1) -> count가 0이 되면서 종료.

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 배열
// // int a[5] 이라면 ㅁㅁㅁㅁㅁ 5개 칸 생성(a[0]~a[4] 총 5개) 각각의 칸이 int. 즉, a = 4x5 = 20byte.
//     int ary[5];

//     ary[0] = 10;
//     ary[1] = 20;
//     ary[2] = ary[0] + ary[1];
//     scanf("%d",&ary[3]);      

//     printf("%d\n",ary[2]);
//     printf("%d\n",ary[3]);
//     printf("%d\n",ary[4]); //입력하지 않은 값에는 무작위한 쓰레기 값이 있음

// // 배열 초기화 : 중괄호 안에 초깃값을 나열하면 앞에서부터 차례로 초기화됨. int ary[5] = {1,2,3,4,5}; ->ary[0] = 1 , ... , ary[4] = 5
// // 요소의 수보다 초깃값이 적으면 남는 요소는 0으로 초기화됨 int ary[5] = {1,2,3}; -> ary[0] = 1 , ... , ary[3],ary[4] = 0
// // 초기화하면 배열 요소의 수를 생략할 수 있음. int ary[] = {1,2,3};
// // 각 자료형에 맞는 값으로 초기화 필요 doube = {문자불가능}, char = {'a','b','c','d'}문자 가능
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 배열과 반복문
    // int score[5];
    // int i;
    // int total = 0;
    // double avg;

    // for(i=0;i<5;i++)
    // {
    //     scanf("%d",&score[i]);
    // }
    // for (i=0;i<5;i++)
    // {
    //     total += score[i];
    // }
    // avg = total / 5.0;    
    // for(i=0;i<5;i++)
    // {
    //     printf("%5d",score[i]); //5d의 의미 : 5자리 출력 -> ()()()90

    // }
    // printf("\n");
    // printf("평균 : %.1lf\n",avg);

// //sizeof 연산자를 사용한 배열 
//     int score[5]; // [n] n값만 바꾸면 개수 바꿀 수 있음.
//     int i;
//     int total = 0;
//     double avg;
//     int count;

//     count = sizeof(score)/ sizeof(score[0]); //sizeof 로 count의 개수 결정 (전체 크기 / 하나의 크기 = 몇 칸)
    
//     for(i=0;i<count;i++)
//     {
//         scanf("%d",&score[i]);
//     }
//     for (i=0;i<count;i++)
//     {
//         total += score[i];
//     }
//     avg = total / count; 
//     for(i=0;i<count;i++)
//     {
//         printf("%5d",score[i]);

//     }
//     printf("\n");
//     printf("평균 : %.1lf\n",avg);

// // At Python, a={1,2,3,4,5} b= sizeof(a) , b=5
// // At C, int a={1,2,3,4,5} b = sizeof(a) , b=20 -> 20byte 크기가 나옴
// 배열을 선언하면 많은 변수를 한 번에 선언가능. 주로 반복문으로 처리. 크기는 sizeof 연산자 사용.
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // char형 배열의 선언과 초기화
//     char str[80] = "appejam";
//     printf("최초 문자열 : %s\n",str);
//     printf("문자열 입력 : ");
//     scanf("%s",str); //문자열은 scanf 할 때 &을 넣지 않음 (문자는 해야됨)
//     printf("입력 후 문자열 : %s\n",str);
//     // char형 배열의 초기화는 문자상수로 하나씩 {'a','p','p',...}으로 하나씩 초기화 하거나, "applejam"으로 한 번에 초기화함.
//     // 널문자가 들어갈 공간이 필요함(\0) : 배열의 남는 요소는 모두 널문자로 채워짐.
//     // 초기화하지 않는 경우 널문자 저장 str[0] = 'a'; str[1] = 'p';... str[5] = '\0'; 마지막에 넣어줘야함.
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 문자열을 대입하는 strcpy 함수
// //#include<string.h> //문자열 관련 함수 원형을 모아놓은 헤더파일

//     char str1[80] = "cat";
//     char str2[80];

//     strcpy(str1, "tiger");      //str1배열에 "tiger" 복사 strcpy("lion","tiger") (X)
//     strcpy(str2, str1);     //str2배열에 str1 배열의 문자열 복사
//     printf("%s, %s\n",str1,str2);strcpy
    
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 문자열 전용 입출력 함수 : gets, puts
//     char str[80];
//     printf("문자열 입력 : ");
//     gets(str);      //빈칸을 포함한 문자열 입력 (사용법이 매우 간단함.)
//     puts("입력된 문자열 : ");
//     puts(str);


// 2장끝

    return 0;
}