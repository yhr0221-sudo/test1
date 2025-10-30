// 입력 조건 : 스캔 데이터 개수 36개 , 각 원소는 0~500cm 사이의 실수형 거리값 , 0~360 까지 10도 간격으로 저장
// 입력 - 각도별 거리값 (배열 dist[360]) / 처리 - 배열을 순회하며 최솟값 탐색 / 출력 - 최솟값(거리)과 해당 각도(인덱스) / 조건 - for문과 if 문만 사용. 함수 사용금지
// 알고리즘 (텍스트 수식형 표현)

// #include<stdio.h>


// int main(void)
// {
//     double dist[360];
//     double min_v1=9999.0, min_v2=9999.0, min_v3 = 9999.0;
//     int count = 10;
//     int idx1=-1, idx2=-1, idx3=-1;
//     int i;
    
//     printf("360 라이다 거리값 입력:  (%d개만 가능)\n", count);
//     for (i=0;i<count;i++){
//         printf("%3d 거리 (cm) : ",i);
//         scanf("%lf", &dist[i]);
//     }

//     for(i = 0; i < count; i++){
        
//         if (dist[i] < min_v1) {
//             min_v3 = min_v2;
//             idx3 = idx2;
//             min_v2 = min_v1;
//             idx2 = idx1;
//             min_v1 = dist[i];
//             idx1 = i;

//         } else if (dist[i] < min_v2) {

//             min_v3 = min_v2;
//             idx3 = idx2;
//             min_v2 = dist[i];
//             idx2 = i;

//         } else if (dist[i] < min_v3) {

//             min_v3 = dist[i];
//             idx3 = i;
//         }
//     }

//     printf("\n[가까운 3개 탐색 결과]\n");
//     printf(" 1순위: %.1f cm (장애물 방향: %d 도)\n", min_v1, idx1 * 10);
//     printf(" 2순위: %.1f cm (장애물 방향: %d 도)\n", min_v2, idx2 * 10);
//     printf(" 3순위: %.1f cm (장애물 방향: %d 도)\n", min_v3, idx3 * 10);
    
//     return 0;
// }


// SLAM(Simultaneous Localization and Mapping) - 센서를 통해 주변 환경에 대한 지도를 작성하면서 동시에 로봇의 위치를 추정하는 기술
// SLAM의 기본 구조 Sensor(Lidar,camera,IMU,Odometry-모터에서 올라온 데이터를 가지고,...) -(data)> Map -(pose)> Localization  -(Map Update)
// SLAM의 종류 : Gmapping, HectorSLAM, Cartographer, Karto SLAM

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// //랜덤으로 받아보기
// int main(void)
// {
//     double dist[360];
//     double min_v1=9999.0, min_v2=9999.0, min_v3 = 9999.0;
//     int count = 36;
//     int idx1=-1, idx2=-1, idx3=-1;
//     int i;

//     srand(time(NULL)); // 프로그램 실행 시마다 다른 난수를 생성(난수 시드 초기화)

//     printf("랜덤 라이다 거리값 생성: (%d개)\n", count);
//     for (i=0;i<count;i++){
//         dist[i] = (double)(rand() % 500 + 1); //0~499까지 정수 생성 +1 (1~500)
//         printf("%3d도 거리 (cm) : %.1f\n", i * 10, dist[i]);
//     }

//     for(i = 0; i < count; i++){
        
//         if (dist[i] < min_v1) {
//             min_v3 = min_v2;
//             idx3 = idx2;
//             min_v2 = min_v1;
//             idx2 = idx1;
//             min_v1 = dist[i];
//             idx1 = i;

//         } else if (dist[i] < min_v2) {

//             min_v3 = min_v2;
//             idx3 = idx2;
//             min_v2 = dist[i];
//             idx2 = i;

//         } else if (dist[i] < min_v3) {

//             min_v3 = dist[i];
//             idx3 = i;
//         }
//     }

//     printf("\n[가까운 3개 탐색 결과]\n");
//     printf(" 1순위: %.1f cm (장애물 방향: %d 도)\n", min_v1, idx1 * 10);
//     printf(" 2순위: %.1f cm (장애물 방향: %d 도)\n", min_v2, idx2 * 10);
//     printf(" 3순위: %.1f cm (장애물 방향: %d 도)\n", min_v3, idx3 * 10);
    
//     return 0;
// }