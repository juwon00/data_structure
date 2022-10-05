#include <stdio.h>
#include <string.h>

int main(){

    char x[100];
    int start = 0; // 가장 긴 자음이 시작 할 위치
    int max_length = 0; // 가장 긴 자음의 길이
    int length = 0; // 각각 자음들의 길이를 알아낼 때 쓰이는 변수

    scanf("%s", x);

    for (int i = 0; i < strlen(x); i++)
    {                                          // 모음이 아니면
        if (x[i] != 'a' && x[i] != 'e' && x[i] != 'i' && x[i] != 'o' && x[i] != 'u')
        {
            length = length + 1;  // 길이를 계속해서 더해준다
            if (max_length < length)  // 최대길이가 나올때 마다 최대길이를 갱신해준다
            {
                max_length = length;
                start = i - max_length + 1; // start의 위치도 갱신해준다
            }
        }
        else // 모음이 나오면 길이를 0으로 초기화시킨다
        {
            length = 0;
        }
    }
    
    for (int i = start; i < start+max_length; i++) // start부터 최대 길이까지 출력한다
        printf("%c", x[i]);
    
    
    return 0;
}