#include <stdio.h>

int main(){

    int n; // 입력받을 정수의 개수
    int data_num[100]; // 입력받은 정수들을 저장할 배열

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
       scanf("%d", &data_num[i]);
    }


    int k;
    int max;
    int temp;

    for (int i = 0; i < n - 1; i++) //조건대로 정렬한다
    {
        max = data_num[0];
        k = 0;

        for (int j = 0; j < n - i; j++)
        {
            if (data_num[j] > max)
            {
                max = data_num[j];
                k = j;
            }
        }
        
        
        temp = data_num[n-1-i];
        data_num[n-1-i] = data_num[k];
        data_num[k] = temp;
    }
    

    for (int i = 0; i < n; i++) // 정렬된 배열을 출력한다
    {
        printf("%d\n", data_num[i]);
    }

    return 0;
}


