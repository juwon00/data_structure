#include <stdio.h>

int main(){

    int n; // 입력받을 정수의 개수
    long front_num[100]; // 시작점의 정수를 저장할 배열
    long back_num[100]; // 끝점의 정수를 저장할 배열
                        // long을 쓴 이유는 두번째 입력 예의 200000을 저장하기 위해
    scanf("%d", &n);


    for (int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &front_num[i], &back_num[i]); 
    }



    long tempf;
    long tempb;

    for (int i = 0; i < n; i++) // 먼저 시작점이 빠른 순서로만 정렬
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (front_num[j] > front_num[j+1])
            {
                tempf = front_num[j];
                front_num[j] = front_num[j+1];
                front_num[j+1] = tempf;

                tempb = back_num[j];
                back_num[j] = back_num[j+1];
                back_num[j+1] = tempb;
            }
        }
    }


    
    long temp;

    for (int i = 0; i < n; i++) // 시작점이 같은 경우 끝점이 빠른 순서로 정렬
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (front_num[j] == front_num[j+1])
            {
                if (back_num[j] > back_num[j+1])
                {
                    temp = back_num[j];
                    back_num[j] = back_num[j+1];
                    back_num[j+1] = temp;
                } 
            }  
        }
    }
    
    
    for (int i = 0; i < n; i++) // 정렬된 배열을 출력
    {
        printf("%ld %ld\n", front_num[i], back_num[i]);
    }


    return 0;
}