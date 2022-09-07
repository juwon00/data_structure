#include <stdio.h>
#include <limits.h> // INT_MAX값을 쓰기 위해
#include <stdlib.h> // 절대값인 abs를 쓰기 위해

int main(){
    int n, k;
    int input;
    int list[100] = {};

    int dif = 0; // 차이값
    int difMin = INT_MAX; // 최소차이값
    int near = 0; // 근사값

    scanf("%d", &n); // 입력받을 정수의 개수 

    for (int i = 0; i < n; i++){ // 계속 입력받은 수들을 배열안에 저장
        scanf("%d" , &input);
        list[i] = input;
    }

    scanf("%d", &k); // k값과 근접한 값을 위해 k값 입력

    

    for (int j = 0; j < n; j++) // 절대값의 차이를 이용해 근사값을 찾음
    {
        dif = list[j] - k;
        if(abs(difMin) > abs(dif))
        {
            difMin = dif;
            near = list[j];
        }
    }

    printf("%d", near); // 가장 가까운 값을 출력함
    
    return 0;
}