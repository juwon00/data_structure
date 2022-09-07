#include <stdio.h>

int main(){
    
    int a; // 처음 입력받을 양의 정수
    scanf("%d", &a);
    
    while (1)
    {
        a = a / 2; // 계속해서 2로 나눈다

        printf("%d ", a);

        if(a > 0){
            continue;
        }else{
            break;
        }
    }
    return 0;
}
