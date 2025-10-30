// AMR(autonomous Mobile Robot): 자율주행 로봇 - 스스로 주변을 살피고 장애물을 감지하면서, 바퀴나 다리를 이용하여 장애물을 회피하며 목적지까지 최적의 경로를 따라 이동하는 로봇.
// MDH80 스펙 참고

// 구동바퀴와 캐스터 : 구동바퀴는 동력을 직접 전달받는 바퀴, 캐스터는 동력을 받지 않고 무게중심이나 하중분산을 위해 존재하는 바퀴
// 안전계수 : 외력에 저항하는 수준에 관련된 계수 (교량에서 보의 굽힘이나 최대 응력에 대한 마진 정도)
// 감속비 : (10: 1) -> 모터(1차축)가 10회 회전 시 바퀴(2차축)는 1회 회전. 보통 2차축은 1로 고정하고 1차축만 바꿔서 감속비를 표현함.
// 예를 들어 모터의 토크가 3이라면, 바퀴에서 측정되는 토크 값은 30이 됨. (이상상태 가정) 감속비가 올라가면 바퀴에서의 토크가 증가함.
// 주로 바퀴-감속기-모터 로 구성되며, 감속기로 원하는 속도 제어가능 
// encoder~ = ppr (purse per revolution)


// 기획 단계에서 선정하는 요소(목적성에 따른 스펙 설정) :
// 구동 바퀴 수(N = 2) / 총 하중(m= 200kg) / 안전계수(SF = 2.0) / 설계 마진(DM = 1.2)

// 모터 정보 : 
// 바퀴 반지름(R= 0.0535m) / 토크(T= 3Nm) / 감속비(G=1 ,inwheel모터에서는 감속비가 없음->기어박스가 없기 때문)

// 상수 및 환경 조건 : 
// 구름 저항 계수 (c= 0.018) / 중력 가속도 (g= 9.81N/m^2) / 중량 W= mg  N

// 필요한 최소 견인력(안전계수 포함) :
// F_min = c x W x SF x DM
// 모터가 낼 수 있는 견인력 :
// F_motor = (T x G)x N / R
//  모터 적정성 여부 판정 :
// F_min <= F_motor

#include<stdio.h>

int main(void)
{
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// {
//     double SF = 2.0, DM= 1.2,T=3;
//     double m,N,G,R,W,F_min, F_motor;
//     const double g = 9.81;
//     const double c = 0.018;

//     printf("총 하중(Kg): "); if (scanf("%lf", &m)!=1) return 1;
//     printf("구동 바퀴 수: "); if (scanf("%lf", &N)!=1) return 1;
//     printf("감속비: "); if (scanf("%lf", &G)!=1) return 1;
//     printf("바퀴 반지름(m): "); if (scanf("%lf", &R)!=1) return 1;

//     W = m*g;
//     F_min = c*W*SF*DM;
//     F_motor = (T*G)*N/R;

//     printf("\n필요한 최소 견인력 : %lf\n" ,F_min);
//     printf("모터가 낼 수 있는 견인력 : %lf\n" ,F_motor);

//     if(F_motor>=F_min){
//         printf("판정 : 만족 (모터 견인력이 충분합니다.)\n");
//     }
//     else{
//         printf("판정 : 불만족 (더 큰 모터나 감속비가 필요합니다)\n");
//     } 

//     if (m<= 0 || N <= 0 || G<=0 || R<0){
//         printf("입력값 범위를  확인하세요.\n");
//         return 1;
//         }
        

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//while 문 활용하여 모터 조건을 바꿔가면서 값이 출력되도록 하기.

    int i;
    double SF = 2.0, DM= 1.2;
    double T,m,N,G,R,W,F_min, F_motor;
    const double g = 9.81;
    const double c = 0.018;


    

    printf("총 하중(Kg): "); if (scanf("%lf", &m)!=1) return 1;
    printf("구동 바퀴 수: "); if (scanf("%lf", &N)!=1) return 1;

    for (i=0;i<=3;i++) {

        printf("모터 정격 토크(Nm): "); if (scanf("%lf", &T)!=1) return 1;
        printf("감속비: "); if (scanf("%lf", &G)!=1) return 1;
        printf("바퀴 반지름(m): "); if (scanf("%lf", &R)!=1) return 1;
        printf("\n필요한 최소 견인력 (N): %.2lf\n" ,F_min);
        printf("모터가 낼 수 있는 견인력 (N) : %.2lf\n" ,F_motor);
        
        W = m*g;       
        F_min = c*W*SF*DM;
        F_motor = ((T*G)/R)*N;        

        if(F_motor>=F_min){
            printf("판정 : 만족 (모터 견인력이 충분합니다.)\n");
        }
        else{
            printf("판정 : 불만족 (더 큰 모터나 감속비가 필요합니다)\n");
        } 

        if (m<= 0 || N <= 0 || G<=0 || R<=0 || T<=0){
            printf("입력값 범위를  확인하세요.\n");
            return 1;
            }
        }        
    return 0;
}