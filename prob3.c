# include <stdio.h>
# include <stdbool.h>

int main(){

    int a; // 계속해서 입력받을 정수
    int i = 0; // 배열의 크기, 입력받을 떄 마다 증가함
    int list[100] = {};
    bool exitOut = false; // 중복된 정수가 입력받을 떄 while문을 빠져나오기 위한 값
    int temp = 0;

    while (1)
    {
        scanf("%d", &a);

        if (a == -1)
            break;
        
        for (int k = 0; k < sizeof(list)/sizeof(int); k++) // 중복 된 값 입력받을 때
        {
            if (a == list[k]){
                printf("duplicate\n");
                exitOut = true;
            }
        }

        if (exitOut == true)
        {
            exitOut = false;
            continue;
        }
        
        list[i] = a; // 중복되지 않은 값이면 배열에 저장
        i = i + 1;

        for (int m = 0; m < i; m++){ // 배열을 오름차순으로 정렬
            for (int n = 0; n < i -m -1; n++){
                if(list[n] > list[n+1]) {
                    temp = list[n];
                    list[n] = list[n+1];
                    list[n+1] = temp;
                }
            }
        }

        for (int j = 0; j < i; j++) // 배열을 출력
        {
            printf("%d ", list[j]);
        }
        printf("\n");
    }

    return 0;
}