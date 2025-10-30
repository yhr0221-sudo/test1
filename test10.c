#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

// 5장

// 16. 메모리 동적 할당

// RAM - stack(지역변수, 매개변수 - {}가 끝나면 사라진다) / heap(동적 메모리 - 개발자가 컨트롤하는 영역, 썼다가 지웠다를 직접 해야함) / data (전역변수, static변수 - 프로그램 실행부터 종료까지)
// stack 과 data는 시스템이 관리. heap는 개발자가 관리함.

// malloc(Memory AlloCation - 메모리 할당), free 함수
// 메모리를 할당 했으면 지우는 것도 스스로 해야함 (free 이용)

// int main(void){
//     int *pi;
//     double *pd;

//     pi = (int *)malloc(sizeof(int));        
//     // sizeof(int) 저장공간을 할당하고 (void)형으로 변환 ->(*int)반환되는 주소를 int으로 형 변환 ->> int형을 가리키는 포인터(pi)에 저장.
//     // heap영역 어디에 생겼는지 모르니까 pi로 주소값을 받아오도록 하는 것.

//     if (pi == NULL){
//         printf(" # 메모리가 부족합니다. \n");
//         exit(1);    //프로그램 종료 함수
//     }
//     pd = (double*)malloc(sizeof(double));

//     *pi = 10;       //포인터로 할당된 영역을 사용 (10으로 채움)
//     *pd = 3.4;

//     printf(" 정수형으로 사용 : %d\n",*pi);      // 동적 할당 영역에 저장된 값 출력
//     printf(" 실수형으로 사용 : %.1lf\n",*pd);

//     free(pi);
//     free(pd);       // 다 썼으면 메모리 지우기

//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // // 동적 할당 영역을 배열처럼 쓰기 
// // **이것만 알고 가기

// int main(void)
// {
//     int *pi;
//     int i , sum = 0;
//     pi = (int *) malloc(5*sizeof(int));       // 저장 공간 20바이트 할당  ( 5 * 4 = 20) // 젤 중요한 한 줄 (할당 영역의 크기 설졍 + 할당된 영역의 주소를 pi에 저장)

//     if (pi ==NULL)
//     {
//         printf("메모리가 부족합니다.\n");
//         exit(1);
//     }// 메모리가 부족할 떄의 예외 처리 구문 (습관화 필요함)


//     printf("다섯 명의 나이를 입력하세요 :");

//     for (i=0;i<5;i++){
//         scanf("%d",&pi[i]);
//         sum += pi[i];
//     }
//     printf("다섯 명의 평균 나이 : %.1lf\n",(sum/5.0));
//     free(pi);
    
//     return 0;
// }
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 기타 동적 할당 함수 (realloc - 할당한 공간의 크기를 늘이거나 줄인다./ calloc - 할당한 공간을 0 으로 초기화 한다.)

// 원하는 크기의 영역을 할당할 수 없을 수도 있다.
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 17 사용자 정의 자료형 (구조체)


// // 구조체 선언과 멤버 사용
// struct student      // 예약어 구조체 이름
// {
//     int num;        // 구조체 멤버
//     double grade;
// };

// int main (void){
//     struct student s1;

//     s1.num = 2;     //구조체 변수명(s1) 멤버 접근 연산자(.) 멤버명(num)
//     s1.grade = 2.7;
//     printf(" 학번 :%d\n", s1.num);
//     printf(" 학점 :%.1lf\n",s1.grade);

//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 구조체 변수의 크기 - 구조체는 실행 효율을 위해 패딩 바이트를 넣어 바이트를 정렬한다. 
// ㅁㅁㅁㅁ     oooo            int 4 + double 8 = 12 (X) -> int 4 + double 8 + 패딩 4 = 16  
//  int형4   패딩바이트          실제 sizeof를 해보면 16바이트가 나옴.
// ㅁㅁㅁㅁ     ㅁㅁㅁㅁ
//     double형 8

// 제일 긴 자료형에 크기를 맞추고 나머지는 패딩 바이트를 채움 

// 패딩 바이트를 줄이기 - 선언된 순서대로 저장되는데, 크기에 맞게 순서를 조절하면 구조체의 크기를 줄일 수 있음.

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 다양한 구조체 멤버

// struct profile
// {
//     char name[20];
//     int age;
//     double height;
//     char *intro;
// };

// int main(void){
//     struct profile yuni;
//     strcpy(yuni.name, "서하윤");
//     yuni.age = 17;
//     yuni.height = 164.5;

//     yuni.intro = (char*)malloc(80);
//     printf("자기소개 : ");
//     gets(yuni.intro);

//     printf("이름 : %s\n",yuni.name);
//     printf("나이 : %d\n",yuni.age);
//     printf("키 : %.1lf\n",yuni.height);
//     printf("자기 소개 : %s\n",yuni.intro);
//     free(yuni.intro);
//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 구조체 맴버로 다른 구조체 사용하기

// struct profile
// {
//     int age;
//     double height;
// };

// struct student
// {
//     struct profile pf;
//     int id;
//     double grade;
// };

// int main(void)
// {
//     struct student yuni;

//     yuni.pf.age = 17;           //yuni구조체 변수의 pf 멤버 접근, pf 구조체 변수의 age멤버 접근
//     yuni.pf.height = 164.5;
//     yuni.id = 315;
//     yuni.grade = 4.3;
//     printf(" 나이 : %d\n", yuni.pf.age);
//     printf(" 키 : %.1lf\n", yuni.pf.height);
//     printf(" 학번: %d\n", yuni.id);
//     printf(" 학점 : %.1lf\n", yuni.grade);

//     return 0;
   
// }
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 구조체 변수의 초기화와 대입 연산
// struct student
// {
//     int id;
//     char name[20];
//     double grade;
// };

// int main(void)
// {
//     struct student s1 = {315, "홍길동", 2.4},
//                    s2 = {316, "이순신", 3.7},
//                    s3 = {317, "세종대왕", 4.4};

//     struct student max;

//     max = s1;   // max.id = s1.id /strcpy(max.name , s1.name)/ max.grade = s1.grade (s1을 max에 복사하는 과정)

//     if (s2.grade > max.grade) max = s2;
//     if (s3.grade > max.grade) max = s3;

//     printf(" 학번 : %d\n", max.id);
//     printf(" 이름 : %s\n", max.name);
//     printf(" 학점 : %.1lf\n", max.grade);
//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 구조체 변수를 함수의 매개변수에 사용하기

// struct vision
// {
//     double left;
//     double right;
// };

// struct vision exchange (struct vision robot); // 함수로 매개변수와 반환형 모두 구조체임

// int main(void){
//     struct vision robot;
//     printf("시력 입력 : ");
//     scanf("%lf%lf",&(robot.left),&(robot.right));
//     robot = exchange(robot);
//     printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

//     return 0;
// }
// struct vision exchange (struct vision robot)
// {   
//     double temp;
//     temp = robot.left;
//     robot.left = robot.right;
//     robot.right = temp;

//     return robot; // 구조체 자체를 리턴
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 구조체 포인터와 (->)연산자

// struct score
// {
//     int kor;
//     int eng;
//     int math;
// };
// int main(void)
// {
//     struct score yuni = {90,80,70};
//     struct score *ps = &yuni;           // 가리키는 것은 struct score 구조체, ps는 포인터

//     printf(" 국어 : %d\n", (*ps).kor);
//     printf(" 영어 : %d\n", ps -> eng);
//     printf(" 수학 : %d\n", ps -> math);
//     return 0;
// }

// head->num은 (*head).num 과 같다.
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 구조체 배열
// struct address
// {
//     char name[20];
//     int age;
//     char tel[20];
//     char addr[80];
// };
// void print_list(struct address *lp);

// int main(void){

//     struct address list[5] = {{"홍길동", 23 , "111-1111","울릉도 독도"},{"이순신", 35 , "222-2222","서울 건천동"},
//                               {"장보고", 19 , "333-3333","완도 청해진"},{"유관순", 15 , "444-4444","충남 천안"},{"안중근", 45 , "555-5555","황해도 해주"}};
//     print_list(list);
//     // int i;

//     // for(i=0;i<5;i++){
//     //     printf("%10s%5d%15s%20s\n",
//     //     list[i].name,list[i].age,list[i].tel,list[i].addr);
//     // }
//     return 0;
// }
// void print_list(struct address *lp)
// {
//     int i;
//     for(i=0;i<5;i++){
//         printf("%10s%5d%15s%20s\n", (lp+i)->name, (lp+i)->age, (lp+i)->tel, (lp+i)->addr);
//     }
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 자기 참조 구조체로 list 만들기

// struct list
// {
//     int num;
//     struct list *next;
// };

// int main(void)
// {
//     struct list a = {10,0}, b = {20,0}, c = {30,0};
//     struct list *head = &a , *current;
//     //struct list *head = &a; struct list *current; 를 한 줄로 쓴 것과 같음.

//     a.next = &b;
//     b.next = &c;

//     printf(" head -> num : %d\n", head -> num);
//     printf(" head -> next -> num : %d\n", head->next->num);
//     printf(" list all : ");
//     current = head;
//     while (current != NULL)
//     {
//         printf("%d ", current -> num);
//         current = current -> next;
//     }
//     printf("\n");
//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 공용체(union)

// union student
// {
//     int num;
//     double grade;
// };
// int main (void)
// {
//     union student s1 = {315};
//     printf("학번 : %d\n",s1.num);
//     s1.grade = 4.4;
//     printf("학점 : %.1lf\n",s1.grade);
//     printf("학번 : %d\n",s1.num);

//     return 0;
// }
// // 출력 
// // 학번 : 315
// // 학점 : 4.4
// // 학번 : -1717986918 -> 메모리에 4.4를 넣어서 학번 315가 사라졌음

// // 공용체(union) 는 구조체처럼 쓰이며, 큰 자료형 기준으로 공간을 하나 마련함(위 경우에는 double1개 8바이트만)
// // 공용체의 모든 멤버가 하나의 저장공간을 사용하기 때문에, 앞에 num=315를 쓴 뒤에 grade에 4.4를 넣을 때 315는 사라지고 그 자리에 4.4가 들어감
// // 동시에 무언가를 할 수 없다는 단점이 있지만, 극한으로 메모리를 아낄 수 있다는 장점이 있다. 
// // 임베디드 같은 경우 메모리가 부족할 때 활용가능성이 큼. 일반 컴퓨터에서는 잘 쓰이지 않음.

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 열거형
// enum season {SPRING, SUMMER, FALL, WINTER};

// int main (void){
//     enum season ss;
//     char *pc = NULL;

//     ss = SPRING;

//     switch (ss)
//     {
//         case SPRING:
//         pc = "inline"; break;
//         case SUMMER:
//         pc = "swimming"; break;
//         case FALL:
//         pc = "trip"; break;
//         case WINTER:
//         pc = "skiing"; break;
//     }
//     printf("나의 레저 활동 => %s\n",pc);
//     return 0;
// }

// // 열거형은 멤버에 의미없는 숫자대신 문자를 넣을 수 있음. -> 코드의 가독성 증가

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // typedef를 사용한 형의 재정의 

// // struct student
// // {
// //     int num;
// //     double grade;
// // };
// // typedef struct student Student; // typedef 구조체 이름 - 새 자료형 이름 -> 짧게 코드를 간결하게 쓰는데 용이함.

// typedef struct {     // 다시 정의 될 거라 이름 생략해도 됨
//     int num;
//     double grade;
// } Student;      // 와 같은 형식으로 자주쓰임

// void print_data(Student *ps);

// int main(void){
//     Student s1 = {315, 4.2};
//     print_data(&s1);
//     return 0;
// }
// void print_data(Student *ps)
// {
//     printf("학번 : %d\n",ps->num);
//     printf("학점 : %.1lf\n",ps->grade);
// }


// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡtypedef 연습해보기ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ // 

// 다양한 구조체 멤버 ...

// typedef struct 
// {
//     char name[20];
//     int age;
//     double height;
//     char *intro;
// }pf;
// int main(void){
//     pf yuni;

// // 구조체 맴버로 다른 구조체 사용하기 ...

// typedef struct 
// {
//     int age;
//     double height;
// }Profile;

// typedef struct 
// {
//     Profile pf;
//     int id;
//     double grade;
// }Student;

// int main(void)
// {
//     Student s1;

//     s1.pf.age = 17;           
//     s1.pf.height = 164.5;
//     s1.id = 315;
//     s1.grade = 4.3;
//     printf(" 나이 : %d\n", s1.pf.age);
//     printf(" 키 : %.1lf\n", s1.pf.height);
//     printf(" 학번: %d\n", s1.id);
//     printf(" 학점 : %.1lf\n", s1.grade);

//     return 0;
// }


/// 정리 
/// 구조체 변수의 주소를 포인터에 저장하면 포인터로 멤버를 사용할 수 있다 (-> 사용)
/// 구조체도 자료형이 같으면 배열을 선언할 수 있다.
/// 자기 참조 구조체는 연결 리스트를 만들 때 사용한다.
/// 공용체 변수의 크기는 멤버의 수에 비례하지 않는다. (공용체는 제일 큰 자료형 하나의 크기를 가짐)
/// 열거형의 멤버는 열거형 변수에 저장될 값들을 나열한다.

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // **************************다시보기********************************

// // 예제 1) 학생 5명의 국어,영어,수학 점수를 입력해 총점, 평균, 학점을 구하고 총점 순으로 정렬을 출력합니다.
// //        학점은 평균이 90점 이상이면 A, 80점 이상이면 B, 70점 이상이면 C, 그 외에는 F 로 평가합니다.

// // 입력 : 학번/ 이름/ 국어,영어,수학 점수/ 총 5번을 받음
// // 출력 : 정렬 전 데이터 (입력 받은 순서대로) -> 정렬 후 데이터 (총점 순으로 정렬하여 출력)

// typedef struct
// {
//     int id;
//     char name[20];
//     int kor;
//     int eng;
//     int math;
//     int sum;
//     double avg;
//     char grade;
// } student;

// void sort_students(student s_arr[], int size);

// int main(void)
// {
//     student s[5];
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         printf("학번 : ");scanf("%d", &s[i].id);        
//         printf("이름 : ");scanf("%s", s[i].name);         //배열은 &로 받지 않음
//         printf("국어, 영어, 수학 점수 : ");scanf("%d %d %d", &s[i].kor, &s[i].eng, &s[i].math);

//         s[i].sum = s[i].kor + s[i].eng + s[i].math;        
//         s[i].avg = (double)s[i].sum / 3.0; 

//         if (s[i].avg >= 90.0) {
//             s[i].grade = 'A';
//         } else if (s[i].avg >= 80.0) {
//             s[i].grade = 'B';
//         } else if (s[i].avg >= 70.0) {
//             s[i].grade = 'C';
//         } else {
//             s[i].grade = 'F';
//         }
//     }
//     printf("\n--- 정렬 전 데이터 ---\n");
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d  %s  %d  %d  %d  %d  %.1lf   %c\n",s[i].id, s[i].name, s[i].kor, s[i].eng, s[i].math,
//                                                      s[i].sum, s[i].avg, s[i].grade);
//     }

//     sort_students(s, 5);

//     printf("\n--- 정렬 후 데이터 (총점 순) ---\n");
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d  %s  %d  %d  %d  %d  %.1lf   %c\n",s[i].id, s[i].name, s[i].kor, s[i].eng, s[i].math,
//                                                      s[i].sum, s[i].avg, s[i].grade);
//     }
//     return 0;
// }
// void sort_students(student s_arr[], int size)
// {
//     int i, j;
//     student temp;  
    
//     for (i=0;i<size-1;i++){

//         for(j=0;j<size-1-i;j++){

//             if (s_arr[j].sum < s_arr[j+1].sum){     // 총점만 비교하고
//                 temp = s_arr[j];                    // 비교한 총점을 바탕으로 해당 student 전체를 바꿔줌
//                 s_arr[j] = s_arr[j+1];
//                 s_arr[j+1] = temp;
//             }            
//         }
//     }   
// }
// // (At, Python - 버블정렬)
// // for j in range(5):
// //     for i in range(5 - j):  # 5>4>3>2>1 순서로 쭉 진행 -> array[5] 자리부터 값이 채워짐 > 오름차순
// //         if array[i] > array[i + 1]:
// //             temp = array[i]
// //             array[i] = array[i + 1]
// //             array[i + 1] = temp
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

//  18 파일 입출력      

//   모드,         설 명,                 파일이 없을 때,     파일이 있을 때 (내용)
// """r""",     읽기 전용,               오류 (NULL 반환),     내용 유지
// """w""",     쓰기 전용,               새 파일 생성,         내용 모두 삭제
// """a""",     이어쓰기 전용 (Append),   새 파일 생성,         내용 유지 (맨 뒤에 추가)
// """r+""",    읽기/쓰기 (Update),      오류 (NULL 반환),     내용 유지 (덮어쓰기)
// """w+""",    읽기/쓰기 (Erase),       새 파일 생성,         내용 모두 삭제
// """a+""",    읽기/이어쓰기 (Append),   새 파일 생성,         내용 유지 (맨 뒤에 추가)

// // 파일 개방과 폐쇄 - 파일을 열고 닫는 프로그램

// // 파일을 읽기 - 1.열기 2.읽기 3.닫기 / 쓰기는 2.쓰기
// // python 에서는 withopen으로 자동으로 닫기가 가능했었음.


// int main(void)
// {
//     FILE *fp;                           // 파일 포인터(FILE - 자료형(int,double,...) 자리에 들어가며, 파일에 접근한다고 알려줌)

//     fp = fopen("a.txt","r");        // "파일명", "개방모드"
//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     printf("파일이 열렸습니다 .\n");
//     fclose(fp);

//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 문자 입력 함수 fgetc - 파일 내용 출력하기
// // 기존에 배운건 fget's' ('s' = str, 'c' = char)

// int main (void)
// {
//     FILE *fp;
//     int ch;

//     fp = fopen("a.txt","r");
//     if(fp ==NULL)
//     {
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     while(1)
//     {
//         ch = fgetc(fp);
//         if(ch == EOF)           ///EOF == End Of File
//         {
//             break;
//         }
//         putchar(ch);
//     }
//     fclose(fp);
//     return 0;
// }
// // 파일 개방 후 내용을 버퍼에 저장
// // 버퍼의 내용을 모두 읽으면 EOF(-1)를 반환함

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// // 문자 출력 함수 fputc - 문자열을 한 문자씩 파일로 출력

// int main(void)
// {
//     FILE *fp;
//     char str[] = "Banana";
//     int i;

//     fp = fopen("b.txt","a");        // 'w' 쓰기 모드로 열기 (쓰기 모드는 파일이 알아서 만들어짐. 있으면 그냥 열고)
//     if(fp == NULL)
//     {
//         printf("파일이 만들지 못했습니다.\n");
//         return 1;
//     }
//     i=0;
//     while (str[i]!= '\0')
//     {
//         fputc(str[i],fp);       // 파일에 banana 를 쓰기
//         i++;
//     }
//     fputc('\n',fp);
//     fclose(fp);

//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 기본적으로 개방되는 표준 입출력 스트림 파일 (stdin, stdout을 사용한 문자 입출력)

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 예제 2) 문자열 내에서 특정 문자열 찾기 (strstr)
// #include<stdio.h>
// #include<string.h>
// int main(){
//     char text[] = "Power Source : Battery";

//     if(strstr(text, "Battery")){
//         printf("배터리 전원입니다.\n");
//     }else{
//         printf("AC전원 입니다.\n");
//     }
//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 예제 3) log.txt에 저장된 로그들을 보고 에러가 몇 번 발생했는지 ? (파일 분석 해보기)
// strstr 함수는 문자열(char *) 안에서 다른 문자열을 찾는 함수.
// 파일의 내용을 검색하려면, fgets 같은 함수로 파일의 내용을 한 줄씩 읽어와서, 그 읽어온 문자열(버퍼)을 strstr 로 검사해야 합니다.

// int main(void)
// {
//     FILE *fp;
//     int count = 0;
//     char E_log[1024];

//     fp = fopen("log.txt","r");       
//     if(fp == NULL)
//     {
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     // while 반복문으로 파일 끝(NULL)까지 한 줄씩 읽음
//     // fgets(저장할곳, 저장 공간의 크기, 어떻게 입력 받을지) -> test8.c에 fgets부분에서 나옴
//     while (fgets(E_log, sizeof(E_log), fp) != NULL)
//     if (strstr(E_log,"ERROR")){
//         count ++;
//     }
//     fclose(fp);
//     printf("에러가 %d 번 발생했습니다.\n",count);

//     return 0;
// }

// ///// 배터리 로그 확인

// int main(void)
// {
//     FILE *fp;
//     int count = 0;
//     char B_log[1024];

//     fp = fopen("battery_log.txt","r");       
//     if(fp == NULL)
//     {
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     while(fgets(B_log,sizeof(B_log),fp)!=NULL)
//     {
//         if(strstr(B_log,"Active")) count ++;
//     }
//     fclose(fp);
//     printf("STATE가 Active 횟수는 %d 회 입니다.\n",count);

//     return 0;
// }

//// 핑 확인 - 1) 핑이 몇 번 들어왔는지. 

// int main(void){

//     FILE *fp;
//     fp = fopen("fast.txt","r");
//     char log[1024];
//     int count;


//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     while(fgets(log, sizeof(log),fp)!= NULL)
//     {
//         if(strstr(log,"Ping")) count++;
//     }
//     printf("핑이 들어온 횟수 : %d\n",count);
//     }

//// 핑 확인 - 2) v4가 들어온 횟수 
// int main(void){

//     FILE *fp;
//     fp = fopen("fast.txt","r");
//     char log[1024];
//     int count = 0;


//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     while(fgets(log, sizeof(log),fp)!= NULL)
//     {
//         if(strstr(log,"192")) count++;
//     }
//     printf("핑이 들어온 횟수 : %d\n",count);
//     }

// // 핑 확인 - 3)어떤 주소에서 가장 많이 들어왔는지, 그 횟수까지
// fe80:0000:0000:0000:020c:29ff:feb7:6481 
int main(void){

    char log[1024];
    int count_list [200] = {0};
    char ip_list[200][100];
    char current_ip[200];
    int unique_ip_count = 0;

    int max_count = 0; // 가장 많이 나온 ip가 몇 번인지?
    int max_index = 0; // 가장 많이 나온 ip 주소의 idx?
    int i;

    FILE *fp;
    fp = fopen("fast.txt","r");
    if (fp == NULL){
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    //핵심 코드
    while(fgets(log, sizeof(log),fp)!= NULL)
    {
        char *p_ip = strstr(log,"fe80:");
        if(p_ip){
            sscanf(p_ip, "fe80:%s", current_ip);        //fe80:~~~~ 의 ~~~~부분이 변하므로 이 값들을 current_ip에 넣어둠

            int found_index = -1; // -1이면 못 찾았다는 뜻
            for (i = 0; i < unique_ip_count; i++) 
            {
                if (strcmp(ip_list[i], current_ip) == 0) // 0이면 두 ip가 같다
                {
                    found_index = i;
                    break;
                }
            }

            if (found_index != -1) {
                count_list[found_index]++;

            } else {
                strcpy(ip_list[unique_ip_count], current_ip);
                count_list[unique_ip_count] = 1;                 
                unique_ip_count++;             
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < unique_ip_count; i++) {
        if (count_list[i] > max_count) {
            max_count = count_list[i];
            max_index = i;
        }
    }
    printf("\n--- 전체 IP 주소 집계 ---\n");
    for (i = 0; i < unique_ip_count; i++) 
    {
        printf("주소: fe80:%s  |  횟수: %d\n", ip_list[i], count_list[i]);
    }
    printf("가장 많이 나온 IP -> fe80:%s\n", ip_list[max_index]);
    printf("등장 횟수: %d회\n", max_count);

    return 0;
    }

//핑 확인 - 4) 어떤 주소에서 몇 번 들어왔는지 (주소와 횟수 출력)
// int main(void){

//     char log[1024];
//     int count_list [200] = {0};
//     char ip_list[200][100];
//     char current_ip[200];
//     int unique_ip_count = 0;

//     int max_count = 0; // 가장 많이 나온 ip가 몇 번인지?
//     int max_index = 0; // 가장 많이 나온 ip 주소의 idx?
//     int i;

//     FILE *fp;
//     fp = fopen("fast.txt","r");
//     if (fp == NULL){
//         printf("파일이 열리지 않았습니다.\n");
//         return 1;
//     }
//     while(fgets(log,sizeof(log),fp) != NULL)
//     {
        
//     }
// }
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ