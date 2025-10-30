#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>   // time()
#include <math.h>   // asin(), tan()
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



// 1. 배터리 런타임 계산
void cal_battery(void);
// 2. 모터 견인력 계산
void cal_traction(void);
// 3. 등판 각도 계산
void cal_grade(void);
// 4. 라이다 최소 거리 탐색
void cal_lidar(void);
// 5. 급가속/급제동 횟수 카운트
void cal_accel(void);
// 6. 배터리 히스테리시스(이력) 경보
void cal_hysteresis(void);
// 7. IR 센서 라인 분류기
void cal_ir_sensor(void);
// 8. ADC 변환기
void cal_adc(void);

// 3, 7, 8번에서 사용하는 헬퍼(Helper) 함수 원형
double clip(double value, double min, double max);
void classify_by_threshold(const double value[], int label[], int N, int threshold);
int count_black(const int label[], int N);
double average_index_of_black(const int label[], int N);
void adc_to_voltage(double volt[], const int adc[], int N, double V_ref);
void voltage_to_distance(double dist[], const double volt[], int N, double k);


// --- 메인 함수 (메뉴) ---
int main(void)
{
    int choice = -1;
    srand(time(NULL));

    do
    {
        printf("\n\n--- 로봇 종합 계산기 --- \n");
        printf("1. 배터리 용량 및 주행 거리 계산\n");
        printf("2. 모터 견인력 적정성 판정\n");
        printf("3. 최대 등판 가능 경사각 계산\n");
        printf("4. 360도 라이다 최소 거리/방향 찾기\n");
        printf("5. 주행 로그 급가속/급제동 이벤트 카운트\n");
        printf("6. 배터리 잔량 히스테리시스 경보 시스템\n");
        printf("7. IR 센서 라인 탐지 분류기\n");
        printf("8. ADC 전압/거리 변환기\n");
        printf("0. 종료\n");
        printf("--------------------------------------\n");
        printf("원하는 기능의 번호를 입력하세요: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("잘못된 입력입니다. 숫자만 입력하세요.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice)
        {
        case 1: cal_battery(); break;
        case 2: cal_traction(); break;
        case 3: cal_grade(); break;
        case 4: cal_lidar(); break;
        case 5: cal_accel(); break;
        case 6: cal_hysteresis(); break;
        case 7: cal_ir_sensor(); break;
        case 8: cal_adc(); break;
        case 0: printf("프로그램을 종료합니다.\n"); break;
        default:
            printf("잘못된 선택입니다. 0~8 사이의 번호를 입력하세요.\n");
        }

    } while (choice != 0);

    return 0;
}


// --- 1. 배터리 런타임 계산 ---
void cal_battery(void)
{
    printf("\n--- 1. 배터리 용량 및 주행 거리 계산 ---\n");
    float I_load = 8, vel = 6.4, R = 0.1, V = 48, C = 80, eta = 0.95;
    float E_usable, P, t, d;
    int n;

    printf("모터 개수를 입력하세요 : ");
    if (scanf("%d", &n) != 1)
    {
        printf("입력 오류\n");
        return;
    }

    E_usable = V * C * eta * (1 - R);
    P = (V * I_load) * n / eta;
    t = E_usable / P;
    d = vel * t;

    printf("사용가능 에너지(Wh) :%.2f\n", E_usable);
    printf("소비 전력(W) :%.2f\n", P);
    printf("런타임(h) :%.2f\n", t);
    printf("주행 거리(km) :%.2f\n", d);
}

// --- 2. 모터 견인력 계산 ---
void cal_traction(void)
{
    printf("\n--- 2. 모터 견인력 적정성 판정 ---\n");
    int i;
    double SF = 2.0, DM = 1.2;
    double T, m, N, G, R, W, F_min, F_motor;
    const double g = 9.81;
    const double c = 0.018;

    printf("총 하중(Kg): "); if (scanf("%lf", &m) != 1) return;
    printf("구동 바퀴 수: "); if (scanf("%lf", &N) != 1) return;

    for (i = 0; i <= 3; i++)
    {
        printf("\n--- %d번째 모터/휠 테스트 ---\n", i + 1);
        printf("모터 정격 토크(Nm): "); if (scanf("%lf", &T) != 1) return;
        printf("감속비: "); if (scanf("%lf", &G) != 1) return;
        printf("바퀴 반지름(m): "); if (scanf("%lf", &R) != 1) return;

        W = m * g;
        F_min = c * W * SF * DM;
        F_motor = ((T * G) / R) * N;

        printf("필요한 최소 견인력 (N): %.2lf\n", F_min);
        printf("모터가 낼 수 있는 견인력 (N) : %.2lf\n", F_motor);

        if (F_motor >= F_min)
        {
            printf("판정 : 만족 (모터 견인력이 충분합니다.)\n");
        }
        else
        {
            printf("판정 : 불만족 (더 큰 모터나 감속비가 필요합니다)\n");
        }

        if (m <= 0 || N <= 0 || G <= 0 || R <= 0 || T <= 0)
        {
            printf("입력값 범위를 확인하세요.\n");
            return;
        }
    }
}

// --- 3. 등판 각도 계산 ---
double clip(double value, double min, double max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void cal_grade(void)
{
    printf("\n--- 3. 최대 등판 가능 경사각 계산 ---\n");
    double m, T_m, N_m, G, eta, r, c, SF;
    double F_avail, grade, T_tot;
    double sin_value, theta_max_rad, theta_max_deg;
    const double g = 9.81;

    printf("m = ? kg \n"); if (scanf("%lf", &m) != 1) return;
    printf("T_m = ? Nm \n"); if (scanf("%lf", &T_m) != 1) return;
    printf("N_m = ? \n"); if (scanf("%lf", &N_m) != 1) return;
    printf("G = ? \n"); if (scanf("%lf", &G) != 1) return;
    printf("eta = ? \n"); if (scanf("%lf", &eta) != 1) return;
    printf("r = ? m \n"); if (scanf("%lf", &r) != 1) return;
    printf("c = ? \n"); if (scanf("%lf", &c) != 1) return;
    printf("SF = ? \n"); if (scanf("%lf", &SF) != 1) return;

    T_tot = N_m * T_m * G * eta;
    F_avail = T_tot / r;
    double numerator = (F_avail / SF) - (c * m * g);
    double denominator = m * g;

    if (denominator == 0) sin_value = 0;
    else sin_value = numerator / denominator;

    sin_value = clip(sin_value, 0.0, 1.0);
    theta_max_rad = asin(sin_value);
    theta_max_deg = theta_max_rad * (180.0 / M_PI);
    grade = tan(theta_max_rad) * 100.0;

    printf("\n--- 계산 결과 ---\n");
    printf("총 구동 토크 T_tot : %.2lf Nm\n", T_tot);
    printf("가용 견인력 F_avail : %.2f N\n", F_avail);
    printf("등판 가능 최대 각 theta_max : %.2f degree\n", theta_max_deg);
    printf("등판율 grade: %.2f %%\n", grade);
}

// --- 4. 라이다 최소 거리 탐색 ---
void cal_lidar(void)
{
    printf("\n--- 4. 360도 라이다 최소 거리/방향 찾기 ---\n");
    double dist[360]; // 360개 전체 배열
    double min_v1 = 9999.0, min_v2 = 9999.0, min_v3 = 9999.0;
    int count = 36; // 실제 사용할 샘플 개수
    int idx1 = -1, idx2 = -1, idx3 = -1;
    int i;

    printf("랜덤 라이다 거리값 생성: (%d개)\n", count);
    for (i = 0; i < count; i++)
    {
        dist[i] = (double)(rand() % 500 + 1); // 1~500
        printf("%3d도 거리 (cm) : %.1f\n", i * 10, dist[i]);
    }

    for (i = 0; i < count; i++)
    {
        if (dist[i] < min_v1)
        {
            min_v3 = min_v2; idx3 = idx2;
            min_v2 = min_v1; idx2 = idx1;
            min_v1 = dist[i]; idx1 = i;
        }
        else if (dist[i] < min_v2)
        {
            min_v3 = min_v2; idx3 = idx2;
            min_v2 = dist[i]; idx2 = i;
        }
        else if (dist[i] < min_v3)
        {
            min_v3 = dist[i]; idx3 = i;
        }
    }

    printf("\n[가까운 3개 탐색 결과]\n");
    printf(" 1순위: %.1f cm (장애물 방향: %d 도)\n", min_v1, idx1 * 10);
    printf(" 2순위: %.1f cm (장애물 방향: %d 도)\n", min_v2, idx2 * 10);
    printf(" 3순위: %.1f cm (장애물 방향: %d 도)\n", min_v3, idx3 * 10);
}

// --- 5. 급가속/급제동 횟수 카운트 ---
void cal_accel(void)
{
    printf("\n--- 5. 주행 로그 급가속/급제동 이벤트 카운트 ---\n");
    int i;
    double speed[1000];
    int acc = 0, stp = 0;
    int N = 500;
    double delta;

    printf("랜덤 속도 데이터 생성: (%d개)\n", N);
    for (i = 0; i < N; i++)
    {
        speed[i] = (double)(rand() % 200 + 1); // 1~200
        printf("%3d번째 속도 (km/h) : %.1f\n", i + 1, speed[i]);
    }

    for (i = 1; i < N; i++)
    {
        delta = speed[i] - speed[i - 1];
        if (delta >= 10)
        {
            acc++;
        }
        else if (delta <= -10)
        {
            stp++;
        }
    }
    printf("급가속 횟수 : %d\n", acc);
    printf("급제동 횟수 : %d\n", stp);
}

// --- 6. 배터리 히스테리시스 경보 ---
void cal_hysteresis(void)
{
    printf("\n--- 6. 배터리 잔량 히스테리시스 경보 시스템 ---\n");
    int i;
    int N = 20;
    double battery_log[100];
    int alert = 0; // 0 = OFF, 1 = ON 

    printf("배터리 잔량 로그 생성 (%d개)\n", N);

    for (i = 0; i < N; i++)
    {
        battery_log[i] = (double)(rand() % 100 + 1);
        if (battery_log[i] <= 30)
        {
            alert = 1;
        }
        else if (alert == 1 && battery_log[i] >= 35)
        {
            alert = 0;
        }
        printf("%2d번째 -> 잔량 : %5.1f%% | 경고 상태 : %s\n", i + 1, battery_log[i], (alert == 1) ? "ON" : "OFF");
    }
}

// --- 7. IR 센서 라인 분류기 ---
void classify_by_threshold(const double value[], int label[], int N, int threshold)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (value[i] >= threshold) label[i] = 0; // 흰색
        else label[i] = 1; // 검정색
    }
}

int count_black(const int label[], int N)
{
    int i;
    int count = 0;
    for (i = 0; i < N; i++)
    {
        if (label[i] == 1) count++;
    }
    return count;
}

double average_index_of_black(const int label[], int N)
{
    int i;
    double sum_index = 0.0;
    int black_count = 0;

    for (i = 0; i < N; i++)
    {
        sum_index += (i * label[i]);
        black_count += label[i];
    }

    if (black_count == 0) return -1.0; 
    
    return sum_index / black_count;
}

void cal_ir_sensor(void)
{
    printf("\n--- 7. IR 센서 라인 탐지 분류기 ---\n");
    double value[100];
    int label[100];
    double index_avg = 0.0;
    int N, i, threshold;
    int black_count = 0;

    printf("센서 개수 입력 : "); scanf("%d", &N);
    printf("임계값 입력(0~1023): "); scanf("%d", &threshold);

    printf("%d개의 value 값을 입력하세요:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("%d번째 값: ", i + 1);
        scanf("%lf", &value[i]);
    }
    classify_by_threshold(value, label, N, threshold);
    black_count = count_black(label, N);

    if (black_count == 0)
    {
        printf("라인 없음 (모두 흰색)\n");
        index_avg = -1.0; // 라인 없음 표시
    }
    else
    {
        index_avg = average_index_of_black(label, N);
    }

    printf("Label (0=흰색, 1=검정): ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", label[i]);
    }
    printf("\n");
    printf("검출된 라인 개수 (black_count) : %d\n", black_count);
    printf("라인 중심 인덱스 (index_avg) : %.2f\n", index_avg);
}


// --- 8. ADC 전압/거리 변환기 ---
#define MAX_N 10
void adc_to_voltage(double volt[], const int adc[], int N, double V_ref)
{
    int i;
    for (i = 0; i < N; i++)
    {
        volt[i] = (adc[i] / 1023.0) * V_ref;
    }
}
void voltage_to_distance(double dist[], const double volt[], int N, double k)
{
    int i;
    double v;
    for (i = 0; i < N; i++)
    {
        v = volt[i];
        if (v < 0.01) v = 0.01; // 0으로 나누기 방지
        dist[i] = k / v;
    }
}

void cal_adc(void)
{
    printf("\n--- 8. ADC 전압/거리 변환기 ---\n");
    int i, N = 0;
    int adc[MAX_N];
    double V_ref = 0.0, k = 0.0;
    double volt[MAX_N], dist[MAX_N];

    printf("ADC 데이터 개수 입력 (최대 %d) : ", MAX_N); scanf("%d", &N);
    if (N > MAX_N) N = MAX_N; 
    printf("기준 전압 입력 (예: 5.0): "); scanf("%lf", &V_ref);
    printf("거리 변환 상수 입력 (예: 20.0): "); scanf("%lf", &k);

    printf("ADC 값 %d개를 입력하세요:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("%d번째 ADC 값 (0~1023): ", i + 1);
        scanf("%d", &adc[i]);
    }

    adc_to_voltage(volt, adc, N, V_ref);
    voltage_to_distance(dist, volt, N, k);

    // 3. 결과 출력
    printf("\n--- 변환 결과 ---\n");
    printf("ADC :\t");
    for (i = 0; i < N; i++) printf("%8d", adc[i]);
    printf("\n");
    
    printf("전압(V) :\t");
    for (i = 0; i < N; i++) printf("%8.2lf", volt[i]);
    printf("\n");
    
    printf("거리(cm) :\t");
    for (i = 0; i < N; i++) printf("%8.2lf", dist[i]);
    printf("\n");
}