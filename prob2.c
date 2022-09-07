#include <stdio.h>

int main(){

    int a; // 입력받을 정수의 개수
    int input; // 계속해서 입력받는 변수
    int list[100] = {};
    int temp = 0;

    scanf("%d", &a);

    for (int i = 0; i < a; i++){ // 계속 입력받은 수들을 배열안에 저장
        scanf("%d" , &input);
        list[i] = input;
    }

    for (int i = 0; i < a; i++){ // 배열을 오름차순으로 정렬
        for (int j = 0; j < a -i -1; j++){
            if(list[j] > list[j+1]) {
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
            }
        }
    }

    printf("%d %d", list[0], list[1]); // 정렬된 배열의 앞의 두 정수를 출력

    return 0;
}
