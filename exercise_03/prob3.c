// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <string.h>
#define MAX 1000000  
#define BUFFER_SIZE 500 

int main(){

    FILE* fp = fopen("shuffled_dict.txt", "r"); // shuffled된 파일을 연다
    char buffer[BUFFER_SIZE];
    char* word_explain[MAX]; // 줄 단위로 저장할 배열
    int n = 0; // 총 줄의 개수

    while (fgets(buffer, sizeof(buffer), fp) != NULL) // 파일안에 있는 데이터를 줄 단위로 저장
    {
        word_explain[n] = strdup(buffer);
        n++;
    }


    char* temp[n]; // 임시로 저장할 배열

    for (int i = 0; i < n - 1; i++) // 오름차순으로 정렬한다.
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(word_explain[j], word_explain[j+1]) > 0)
            {
                temp[j] = &word_explain[j][0]; // 각 줄의 크기가 다르기 때문에 시작하는 줄의 주소를 활용해 정렬한다
                word_explain[j] = &word_explain[j+1][0];
                word_explain[j+1] = &temp[j][0];
            }
        }
    }
    fclose(fp); // 파일을 닫는다.



    FILE* fp2 = fopen("sorted_dict.txt", "w"); // sorted된 파일을 연다

    for (int i = 0; i < n; i++) // 줄 단위로 정렬된 배열을 sorted파일에 저장한다
    {
        fputs(word_explain[i], fp2);
    }

    fclose(fp2); // 파일을 닫는다
    

    return 0;
}