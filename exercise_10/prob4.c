// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>

#define MAX 1000

int floor(int data[], int start, int N, int K){

    if (data[0] > K) // K보다 작거나 같으면서 가장 큰 정수가 없는경우
        return -1;

    if (start < N) // 범위내에서
    {   
        if (data[start] <= K) // K보다 작거나 같은값이 있을 때
        {
            start++;
            return floor(data, start, N, K); // 재귀함수 진행
        }
        else // 그러다가 K보다 큰값을 만났을 때 
            return data[start-1]; // 그 이전값 반환
        
    }

    else // 범위 끝까지 갔는데 그 값이 가장 작은 값인 경우 (data[end]반환)
        return data[start-1];
}


int ceiling(int data[], int end, int N, int K){
    
    if (data[N-1] < K) // K보다 크거나 같으면서 가장 작은 정수가 없는경우
        return -1;
    
    if (end > 0) // 범위내에서
    {
        if (data[end] >= K) // K보다 크거나 같은값이 있을 때
        {
            end--;
            return ceiling(data, end, N, K); // 재귀함수 진행
        }
        else // 그러다가 K보다 작은값을 만났을 때 
            return data[end+1]; // 그 이전값 반환
    }

    else // 범위 끝까지 갔는데 그 값이 가장 큰 값인 경우 (data[start]반환)
        return data[end+1];
}   


int main(){

    int data[MAX];
    int N, K;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }
    scanf("%d", &K);

    int start = 0;
    int end = N - 1;

    printf("%d\n%d", floor(data, start, N, K), ceiling(data, end, N, K));
    
    return 0;
}