#include <stdio.h>

int main(){

    int n;
    int k = 1;
    int count = 1;
    int input;
    int temp;
    int list[100] = {};
    int resultList[100] = {};

    scanf("%d", &n); // 입력받을 정수의 개수 

    for (int i = 0; i < n; i++) // 계속 입력받은 수들을 배열안에 저장
    {
        scanf("%d" , &input);
        list[i] = input;
    }
    
    for (int i = 0; i < n; i++){  // 배열을 오름차순으로 정렬
        for (int j = 0; j < n -i -1; j++){
            if(list[j] > list[j+1]) {
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
            }
        }
    }

    resultList[0] = list[0];

    for (int i = 1; i < n; i++) // 배열안에 중복 된 수를 제거
    {
        if (list[i] != resultList[k - 1])
        {
            resultList[k++] = list[i];
            count = count + 1;
        }
        
    }
    
    printf("%d:", count); // 배열 안 남은 정수의 개수

    for (int i = 0; i < count; i++) 
    {
            printf(" %d", resultList[i]);
    }

    return 0;
}