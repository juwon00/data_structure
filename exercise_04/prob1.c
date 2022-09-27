#include <stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int num;
    int num_array[100]; // 정수를 저장할 배열
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        num_array[i] = num;
    }

    int count; // 역전된 쌍의 개수
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++) // i+1인 이유
        {                             // i번쨰 수보다 이후에 나온 수만 비교하기 위해
            if (num_array[i] > num_array[j])
            {
                count = count + 1;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}