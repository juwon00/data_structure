#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 20
#define MAX 100000

int main()
{

    FILE* fp = fopen("harry.txt", "r"); // harry.txt 파일은 오픈

    char* p_word_list[MAX]; // 초기 단어 단위로 저장할 배열
    char buffer[BUFFER_SIZE];
    int n = 0; // 총 단어의 개수 n
    while(fscanf(fp, "%s", buffer) != EOF){ // 파일안에 있는 데이터를 단어단위로 저장
        p_word_list[n] = strdup(buffer);
        n += 1;
    }



    char temp[BUFFER_SIZE]; // 임시로 저장할 때 쓰는 배열

    for (int i = 0; i < n - 1; i++) // 배열을 오름차순 순서로 정렬
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(p_word_list[j], p_word_list[j+1]) > 0)
            {
                strcpy(temp, p_word_list[j]);
                strcpy(p_word_list[j], p_word_list[j+1]);
                strcpy(p_word_list[j+1], temp);
            }
        }
    }



    char* result_list[MAX]; // 중복없이 오름차순으로 정렬된 배열
    int k = 0; // result_list의 크기

    for (int i = 0; i < n - 1; i++) // 배열에서 중복된 값을 제거
    {
        if (strcmp(p_word_list[i], p_word_list[i+1]) < 0) // 두 단어가 같으면 0
        {                                                 // 왼쪽 단어가 크면 양수
            result_list[k] = p_word_list[i];              // 오른쪽 단어가 크면 음수
            k = k + 1;
        }
    }
    result_list[k] = p_word_list[n-1]; // 마지막값은 비교 할 대상이 없으니 바로 넣어준다



    char prefix[BUFFER_SIZE]; // 입력받을 접두어
    int count; // 같은 접두어를 가진 단어의 개수

    scanf("%s", prefix);

    for (int i = 0; i < k+1; i++) // 같은 접두어를 찾아내는 for문
    {
        if (strncmp(prefix, result_list[i], strlen(prefix)) == 0) // 위의 strcmp와 유사하지만
        {                                                         // 3번째 인자에 비교할 길이가 필요
            printf("%s\n", result_list[i]); 
            count = count + 1;
        }
    }
    printf("%d\n", count); 

   

    fclose(fp); // 파일을 닫는다

    return 0;
}
