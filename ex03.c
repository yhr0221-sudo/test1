// 이동로봇의 최대 견인력과 등판 가능 경사각
// 입력 : 총 질랑(m), 모터 정격 토크 (T_m), 구동 모터 수 (N_m), 감속비(G), 구동 효율(eta), 바퀴 반지름(r), 구름계수 (c), 안전계수 (SF)
// 요구 사항 : 1. 총 가용 견인력 (F_avail)을 계산 2. 안전계수 적용 시 등판 가능 최대각(theta_max)과 등판율(grade)를 구하라 3. 마찰 한계는 무한다는 가정으로 계산
// T_tot = N_m * T_m * G * eta
// F_avail = T_tot / r
// F_need = mgsin(theta) + cmg
// sin() = clip((F_avail/SF -cmg)/mg,0,1) //clip(x,0,1)는 값을 0~1로 제한하는 함수.
// grade = tan(theta_max) * 100

// tan 45^deg = 1  
// 경사 80% -> 1: 0.8 -> 0.8 = arctan(theta) -> theta = 38.65980825^deg

#include <stdio.h>
#include <math.h> 

// clip 함수 (이전과 동일)
double clip(double value, double min, double max) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

int main(void)
{
    // 입력 변수
    double m, T_m, N_m, G, eta, r, c, SF;
    double F_avail, grade, T_tot;
    double sin_value, theta_max_rad, theta_max_deg; 

    const double g = 9.81;

    printf("m = ? kg \n"); if (scanf("%lf", &m) != 1) return 1;
    printf("T_m = ? Nm \n"); if (scanf("%lf", &T_m) != 1) return 1;
    printf("N_m = ? \n"); if (scanf("%lf", &N_m) != 1) return 1;
    printf("G = ? \n"); if (scanf("%lf", &G) != 1) return 1;
    printf("eta = ? \n"); if (scanf("%lf", &eta) != 1) return 1;
    printf("r = ? m \n"); if (scanf("%lf", &r) != 1) return 1;
    printf("c = ? \n"); if (scanf("%lf", &c) != 1) return 1;
    printf("SF = ? \n"); if (scanf("%lf", &SF) != 1) return 1;

    // --- 2. 계산 ---

    // 요구사항 1: 총 가용 견인력 (F_avail)
    T_tot = N_m * T_m * G * eta;
    F_avail = T_tot / r;
    double numerator = (F_avail / SF) - (c * m * g);
    double denominator = m * g;

    if (denominator == 0) {
        sin_value = 0;
    } else {
        sin_value = numerator / denominator;
    }

    // clip 로직 적용
    sin_value = clip(sin_value, 0.0, 1.0);

    // 라디안(radian) 단위의 각도 계산
    theta_max_rad = asin(sin_value);

    // 라디안을 각도(degree) 단위로 변환
    theta_max_deg = theta_max_rad * (180.0 / M_PI);

    // 등판율(grade) 계산
    grade = tan(theta_max_rad) * 100.0;

    printf("\n--- 계산 결과 ---\n");
    printf("총 구동 토크 T_tot : %.2lf Nm\n", T_tot);
    printf("가용 견인력 F_avail : %.2f N\n", F_avail);
    printf("등판 가능 최대 각 theta_max : %.2f degree\n", theta_max_deg); 
    printf("등판율 grade: %.2f %%\n", grade);

    return 0;
}