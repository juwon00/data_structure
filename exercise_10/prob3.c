// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>

#define MAX 1000

int count = 0;

void sum_recursion(int data[], int start, int end, int K){

    int sum = data[start] + data[end];

    if (start < end) // 범위 내에서
    {
        if (sum > K) // 원하는 값(K)보다 큰 경우 뒤쪽을 줄인다
        {
            end--;
            sum_recursion(data, start, end, K);
        }
        else if (sum < K) // 원하는 값(K)보다 작은 경우 앞쪽을 줄인다
        {
            start++;
            sum_recursion(data, start, end, K);
        }
        else // 원하는 값(K)과 같은경우 앞뒤 다 줄인다
        {
            count++; 
            start++;
            end--;
            sum_recursion(data, start, end, K);
        }
    }
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

    sum_recursion(data, start, end, K);
    
    printf("%d", count);

    return 0;
}