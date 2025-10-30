// 이동로봇의 배터리 용량 선정
// 5000mah * 1ea = 18.5[Wh]
// 3500mah * 4ea = 51.8[Wh]
// 5000mah * 35ea = 647.5[Wh]
// 에너지와 와트시
// 전력 [와트](power) : 특정 순간에 에너지가 소비되는 순간 비율 
// 에너지 (energy) : 일정 시간동안 소비된 전력 

// 배터리에서 예비율 R (배터리 용량이 너무 낮아지게 되면 전압이 낮아지면서 전류가 반비례하게 발생, 일반적인 배터리의 경우 10-20%정도 예비율을 두고 사용 -> 배터리의 총량 중 80~90%정도만 실사용함)

// 사전 선정 정보 
// 평균 전류 I_load[A] : 8 [A]
// 평균 속도 vel [km/h] : 6.4 [km/h]
// 예비율 R [0~1] : 0.1

// 배터리 정보
// 공칭전압 V[V] : 48V
// 용량 (Capacity) C[Ah] : 80A
// 시스템 효율 eta [0~1] : 0.95

// **조건 : 전압 강하, 온도 영향 무시, 평균 전류 일정**

// 사용 가능 에너지 (Wh): E_usable = V * C * eta * (1-R)
// 소비 전력 (W): P = (V*I_load) / eta
// 런타임 (h): t = E_usable / P 
// 주행거리 (km): d = vel * t 

 #include <stdio.h>
 
 int main(void)
 {
   float I_load = 8, vel =  6.4, R = 0.1, V = 48, C = 80, eta = 0.95;
   float E_usable, P, t, d;
   int n ;

   printf("모터 개수를 입력하세요 : \n");
   if (scanf("%d", &n)!=1) {
      return 1;
   }
   
   E_usable = V * C * eta * (1-R);
   P = (V*I_load)* n / eta;
   t = E_usable / P;
   d = vel * t;

   printf("사용가능 에너지(Wh) :%.2lf\n",E_usable);
   printf("소비 전력(W) :%.2lf\n",P);
   printf("런타임(h) :%.2lf\n",t);
   printf("주행 거리(km) :%.2lf\n",d);
   return 0 ;
 }
// int main (void) 
// int ? : 정수형태의 어떤 값을 반환받는 그런 함수 
// return이 1을 반환하면 오류가 생김. 0이 정상상태. 

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 교수님은 double로 변수를 선언했고, scanf로 사용자에게 직접 값을 받음.
// ex) printf("평균 전류 I_load: "); if (scanf("%lf", &I_load)!=1) return 1;
// 해석 >> scanf 가 참이면 -> scanf로 받은 무언가가 double형태여야함 .(문자나 다른형태 즉, 거짓일 경우 return 1 -> 오류를 발생시킴.

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 입력 범위 검증 : 내가 입력 받은 데이터들 중 하나라도 잘못된 값이 있다면 오류를 출력
// if (V<= 0 || C <= 0 || I_load<=0 || vel<0 || R<0 || R>=0 || eta <= 0 || eta>100) {printf("입력값 범위를  확인하세요.\n"); return 1;}
