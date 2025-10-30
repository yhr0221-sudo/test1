//랜덤 난수 예제

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// int main(void)
// {
//     srand(time(NULL));
//     int r1 = rand() % 10;
//     int r2 = rand() % 100 + 1;
//     int r3 = rand() % 21 -10;  // -10 ~ 10

//     printf("0~9 랜덤 : %d\n", r1);
//     printf("1~100 랜덤 : %d\n", r2);
//     printf("-10~10 랜덤 : %d\n", r3);
    
//     return 0;
// }

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 로그에서 급가속/급제동 이벤트 카운트
// 1. 주제 : 로봇(또는 자율주행 차량) 의 속도 로그데이터를 배열로 입력받아, 이웃한 시점 간의 속도 변화량을 계산하여 급가속(delta_v >=10) 또는 급제동(delta_v <= -10)횟수를 계산한다.
// 2. 베경 : 실제 이동로봇이나 차량에서는 속도 센서 로그를 분석하여 운행 안정성을 평가한다. 이 예제는 배열을 이용해 주행 데이터를 저장하고, 반복문으로 이웃한 값의 차이를 계산하며, 조건문으로 급가속,급제동 이벤트를 카운트한다.
// 3. 입력 조건 : 주행 로그 개수 (N), 각 값은 단위 시간당 속도 (km/h 또는 m/s)


//1) N = 500개 랜덤 받기 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int main(void)
// {
//     int i;
//     double speed[1000];
//     int N = 500;
//     double delta;

//     srand(time(NULL));

//     printf("랜덤 속도 데이터 생성: (%d개)\n", N);
//     for (i=0;i<N;i++){
//         speed[i] = (double)(rand() % 200 + 1); 
//         printf("속도 (km/h) : %.1f\n", i * 10, speed[i]);
//     }

//     for(i=1;i<N;i++){
//         delta = speed[i] - speed[i-1];
//         if(delta >= 10){
//             acc ++;
//         }
//         else if (delta <= -10)
//         {
//             stp ++;
//         }
//     }
//     printf("급가속 횟수 : %d\n",acc);
//     printf("급제동 횟수 : %d\n",stp);

//     return 0;
// }

//2) 변화량이 10이상이 되지 않도록 rand범위 제한


//  2-1)speed 앞의 값을 확인하고 그 값의 차이가 10이상이 나면 배열에 넣지 않도록 하는 방법? >방법 사용
//  2-2)speed 이전의 값에 -9~9까지 난수를 더해서 차이가 10이 안되도록 수정 + 200km/h가 넘지 않도록 범위 조절

// int main(void)
// {
//     int i;
//     int acc = 0,stp = 0;
//     double speed[1000];
//     int N = 10;
//     double prev_speed;
//     double new_speed;
//     int tries =0 ;
    

//     srand(time(NULL));

//     speed[0] = (double)(rand() % 200 + 1); 
//     printf("처음 속도 (km/h) : %.1f\n", i * 10, speed[0]);
    

//     for(i=1;i<N;i++){
//         prev_speed = speed[i-1];

//         do {
//             new_speed = (double)(rand() % 200 + 1);
//             tries++;
//         } while (labs(new_speed - prev_speed) >= 10); 
    
//     speed[i] = new_speed;
//     printf("속도(km/h): %.1f (시도: %d)\n",speed[i], tries);
//     }

//     return 0;
// }

//3) 변화량이 연속된 10개 값 이상이 증가 또는 감소만 하도록 rand값 제한
//  3-1) 계속 증가하다가 200(max_speed)을 만나면 감소하는 경향을 띄도록
//// 다시 해보기

// int main(void)
// {
//     int i;
//     int max_speed = 200;
//     int acc = 0,stp = 0;
//     double speed[1000];
//     int N = 50;
//     double prev_speed,next_speed;
//     double ctl_speed;
    

//     srand(time(NULL));

//     speed[0] = (double)(rand() % max_speed + 1); 
//     printf("처음 속도 (km/h) : %.1f\n", speed[0]);

//     for(i=1;i<N;i++){
//         prev_speed = speed[i-1];
//         ctl_speed = (double)(rand() % 10);
//         next_speed = ctl_speed + prev_speed;       

//         if (next_speed >= prev_speed) {
//             do {
//                 ctl_speed = (double)(rand() % 10); 
//                 next_speed = ctl_speed + prev_speed;
//             } while (prev_speed > next_speed);

//             if(next_speed >= 200){
//                 next_speed = 200;
//                 do {
//                 ctl_speed = (double)(rand() % 10) -19;
//                 next_speed = ctl_speed + prev_speed;
//             } while (next_speed > prev_speed); //다시 뽑는 조건
//         }
            
//         } else if (next_speed <= prev_speed) {
//             next_speed = 1;
//             do {
//                 ctl_speed = (double)(rand() % 10);
//                 next_speed = ctl_speed + prev_speed;
//             } while (next_speed < prev_speed);
//             if(next_speed <= 1){
//                 next_speed = 1;
//                 do {
//                 ctl_speed = (double)(rand() % 10);
//                 next_speed = ctl_speed + prev_speed;
//             } while (next_speed < prev_speed); //다시 뽑는 조건
//         }
//         }
    
//     speed[i] = next_speed;
//     printf("속도(km/h): %.1f\n",speed[i]);
//     }
//     return 0;
// }
    
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 배터리 잔량 히스테리시스 경보 시스템
// 1. 주제 : 배터리 잔량(%) 로그를 배열로 입력받아, 잔량이 특정 임계값 이하로 떨어지면 경고를 발생시키고, 다시 일정 수준 이상으로 회복될 때까지 경고를 유지하여 불필요한 경고 깜빡임을 억제한다.
// 2. 배경 : 로봇의 배터리 잔량은 센서 노이즈나 순간 부하로 인해 50% 근처에서 상승,하락이 반복되면 경고등이 깜빡이는 현상이 생긴다. 이 문제를 해결하기 위해 히스테리시스 (Hysteresis) 개념을 적용한다
//          경고 시작 임계값 30%이하 / 경고 해제 임계값 35% 이상 으로 설정하여 경고상태가 한 번 켜지면 35% 이상으로 회복될 때까지 유지되도록 한다.
// 3. 입력 조건 : 입력 - 배터리 잔량 로그 (%), 데이터 개수 N , 각 값 범위 0~100 (%)


// /// 이전 상태의 경고 유무만 비교
// int main (void)
// {
//     int i;
//     int N =20;
//     double battery_log[100];
//     int alert = 0 ; // 0 = OFF, 1 = ON 

//     srand(time(NULL));

//     printf("배터리 잔량 로그 생성 (%d개)\n", N);
//     // battery_log[0] = (double)(rand() % 100); 
//     // alert = 0;

//     for (i=0;i<N;i++){
//         battery_log[i] = (double)(rand() % 100 + 1);
//         if(battery_log[i] <= 30){
//             alert = 1;
//         }
//         else if (alert == 1 && battery_log[i]>=35){
//             alert = 0;
//         }

//         // // printf("배터리 잔량 (%%) : %.1f\t", battery_log[i]); 
            
//         // if (alert == 1) {
//         //     printf("경고 ON \n");
//         // } else {
//         //     printf("경고 OFF \n");
//         // }
//         printf("%2d번째 -> 잔량  : %5.1f%% | 경고 상태 : %s\n", i+1, battery_log[i],(alert ==1)? "ON" : "OFF");  //배운거 써먹기  
//     }
 
//     return 0;
// }
    
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// IR 센서 반사값 임계치 분류기

// 1. 주제 : IR 적외선 반사 센서를 이용하여 바닥에 있는 라인(검정색) 을 감지하고, 라인이 어느 방향에 위치해 있는지 판단하는 프로그램을 작성하시오.
// 2. 배경 : 라인 트레이싱 로봇은 바닥에 있는 검정색 라인을 따라 움직인다. IR반사 센서는 물체나 바닥의 밝기 차이를 감지하며, 센서 값은 0~1023 사이의 숫자로 표현된다. 
//          여러 개의 IR 센서를 일렬로 배열하면 라인이 어느 방향에 있는 지 확인 할 수 있다. 센서 값과 임게값(threshold)을 비교하여 라인인지 아닌지(0/1)로 구분한다.
//          검정색 - 빛 반사가 약함 (숫자가 작음), 흰 색 - 빛 반사가 강함(숫자가 큼)
// 3. 입력 조건 : 센서 개수 N (1 <= N <= 16) / 센서로부터 입력되는 값 value[i](i는 0 부터 N-1) / 비교 기준이 되는 임계값 (threshold : 0 ~ 1023) 



//입력 N개와 threshold 값을 받으면 N개의 value를 random으로 뱉음 > 그 값이 threshold보다 큰지 작은지 확인하여 label 0 or 1을 판단 + black_count = 몇개인지 ?
// index_avg > 중심에서 얼마나 벗어나 있는지를 확인하는 값 : N 의 분포를 확인하여 중심값에서 1의 분포가 얼마나 멀리 있는지 확인하는 것 ?
// sum_index = (i*label[i]) / index_avg = sum_index / black_count (black_count = 0이면 예외처리)


// ******사용자 지정 함수 쓰는 법 다시 공부하기 (특히 average_index_of_black 부분)

// void classify_by_threshold(const double value[],int label[], int N, int threshold);
// int count_black(const int label[], int N);
// double average_index_of_black(const int label[],int N);

// int main (void)
// {
//     double value[100];
//     int label[100];
//     double index_avg = 0;
//     double sum_index;
//     int N, i,threshold;
//     int black_count =0;

//     printf("센서 개수 입력 : \t"); scanf("%d",&N);
//     printf("임계값 입력(0~1023): \t"); scanf("%d",&threshold);

//     for (i=0;i<N;i++){
//         printf("%d번째 value 값 입력: \t",i+1); scanf("%lf",&value[i]);

//     classify_by_threshold(value, label, N, threshold);
//         // if(value[i] >= threshold){
//         //     label[i] = 0;
//         // } else {            
//         //     label[i] = 1;
//         // }

//     black_count = count_black(label, N);
//         // black_count += label[i]; 

//         // sum_index += (i * label[i]);
//     } 
//     if(black_count == 0){
//     printf("라인 없음 \n");
//     }
//     else{
//         index_avg = average_index_of_black(label,N);
//     }    
    
    
//     printf("label : ");
//     for(i=0;i<N;i++){
//         printf("%d ",label[i]);
//     }
//     printf("\n");
//     printf("black_count : %d\n",black_count);
//     printf("index_avg : %f\n",index_avg);

//     return 0;
// }

// void classify_by_threshold(const double value[],int label[], int N, int threshold)
// {
//     int i; //main 에서 쓰이는 i 와는 별개임. 지역변수
//     for (i=0;i<N;i++){

//         if(value[i]>=threshold){
//         label[i] = 0;       //임계값보다 센서가 인식한 값이 크다 > 빛 반사가 많다 > 흰색임 > 0
//     } else if (value[i]<threshold){
//         label[i] = 1;       //임계값보다 센서가 인식한 값이 작다 > 빛 반사가 작다 > 검정색 > 1
//     }
//     }

// }
// int count_black(const int label[], int N)
// {
//     int i;
//     int count = 0;
//     for(i=0; i<N; i++){
//         if(label[i] == 1){
//             count++;        // count+= label[i];로 써도 됨
//         }
//     }
//     return count;
// }
// double average_index_of_black(const int label[], int N){
//     int i;
//     double sum_index = 0.0;
//     int black_count = 0; // 이 함수 내에서 다시 계산해야 함

//     for(i=0; i<N; i++){
//         sum_index += (i * label[i]); // label[i]가 0이면 0이, 1이면 i가 더해짐
//         black_count += label[i];     // label[i]가 1일 때만 count가 증가
//     }

//     // 0으로 나누기 방지 (main에서도 했지만, 함수 자체로도 안전해야 함)
//     if(black_count == 0) return 0.0;  //return -1.0; 으로도 쓰는듯 ?
//                                         //return -1.0;**은 "평균 인덱스를 찾지 못했다"는 사실을 명확하게 전달합니다.
//                                         //return 0.0;**은 "평균 인덱스가 0이다"라고 말하는 것과 같아서, "찾지 못했다"는 본래의 의도와 다르게 해석될 수 있습니다.

//     return sum_index / black_count;
// }



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// ADC(Analog to Digital Converter)
// 분해능 : ADC의 정밀함 정도를 알 수 있는 변수
// 1.주제 : 아날로그 센서(예:거리센서)에서 읽은 ADCrkqt (0~1023)을 전압(V)과 거리(cm)으로 변환하는 프로그램을 작성하시오.
// 2.배경 : 로봇에 사용되는 많은 센서(예: 적외선거리센서,아날로그초음파센서등)는 시제 물리량을 바로 출력하지 않고 전압 값을 출력한다. 하지만 마이크로컨트롤러(Arduino,STM32등)는 전압을 직접 읽지 못하고 ADC를 이용해 0~1023 사이의 디지털 값으로 변환하여 읽는다.
// ex) 0 -> 0 , 2.5V -> 512, 5V -> 1023 
// 3.입력 조건 : N(ADC값의 개수 1~10) / adc[i] (센서로부터 읽은 ADC값) / V_ref (기준 전압- 5V) / k (거리 변환 상수 - 모델에 따라 다름)
// 전압이 증가하면 물체와의 거리는 줄어드는 형태, 거리변환 상수 k를 이용 : 거리 = k / 전압  (단, 전압 = 0 이면 연산 불가능하므로 최소 전압값을 0.01로 제한)

// 입력 N, adc, V_ref, k를 받아 adc에 따른 전압값과 거리를 출력하는 코드

#define MAX_N 10
double adc_to_voltage(double volt[],const int adc[], int N,double V_ref);
double voltage_to_distance(double dist[], const double volt[], int N, double k);

int main(void)
{
    int i, N=0;
    int adc[MAX_N];
    double V_ref=0.0, k=0.0;
    double volt[MAX_N], dist[MAX_N];

    printf("ADC 데이터 개수 입력 : \t");scanf("%d",&N);
    printf("기준 전압 입력 : \t");scanf("%lf",&V_ref);
    printf("거리 변환 상수 입력 : \t");scanf("%lf",&k);
    for (i=0;i<N;i++){
        printf("ADC 값 %d개 입력 : \t",N);scanf("%d",&adc[i]);

        adc_to_voltage(volt, adc, N, V_ref);

        voltage_to_distance(dist, volt, N, k);

    }
    printf("ADC : ");
    for (i=0;i<N;i++){
        printf("%8d",adc[i]);
    } 
    printf("\n");
    printf("전압(V) : ");
    for (i=0;i<N;i++){

        printf("%8.2lf",volt[i]);
    }
    printf("\n");
    printf("거리(cm) : ");
    for (i=0;i<N;i++){
        printf("%8.2lf",dist[i]);
    }
    printf("\n");

    return 0;
}
double adc_to_voltage(double volt[],const int adc[], int N,double V_ref)
{
    int i;
    for (i=0;i<N;i++){
    volt[i] = (adc[i]/1023.0) * V_ref;

 }
}
double voltage_to_distance(double dist[], const double volt[], int N, double k)
{
    int i;
    double v;
    // const를 사용한 이유 ? 원본 volt 배열의 값이 영구적으로 훼손될 가능성이 있음. >> const는 읽기만 가능하므로, 읽고 쓰기가 가능한 복사본(v)을 만들어서 수정하는 방법
    for (i=0;i<N;i++){
        v = volt[i];
        if(v < 0.00) v ==0.01;
        dist[i] = k/v;
    }

}