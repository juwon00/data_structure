#include <stdio.h>
#include <string.h>
#define MAX 100000
#define BUFFER_SIZE 20

int main(){

    FILE* fp = fopen("harry.txt", "r");

    char* word_list[MAX]; // 초기 단어 단위로 저장할 배열
    char buffer[BUFFER_SIZE];
    int n = 0; //word_list의 크기
    while(fscanf(fp, "%s", buffer) != EOF){ // 파일안에 있는 데이터를 단어단위로 저장
        if (strlen(buffer) >= 6) // 단어의 길이가 6 이상인 단어만 배열에 저장
        {
            word_list[n] = strdup(buffer);
            n += 1;
        }
    }



    char temp[BUFFER_SIZE]; // 임시로 저장할 때 쓰는 배열

    for (int i = 0; i < n - 1; i++) // 배열을 오름차순 순서로 정렬
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(word_list[j], word_list[j+1]) > 0)
            {
                strcpy(temp, word_list[j]);
                strcpy(word_list[j], word_list[j+1]);
                strcpy(word_list[j+1], temp);
            }
        }
    }



    int num_list[MAX]; // 단어가 중복된 수를 저장하는 배열
    int num; // 횟수 카운터
    int m; // num_list의 크기
    for (int i = 0; i < n; i++) // 단어마다 중복 된 수를 세는 방법
    {
        num = 0;

        for (int j = i; j < n; j++) 
        {
            if (strcmp(word_list[i], word_list[j]) == 0)
            {
                num = num + 1;
            }
            
        }

        num_list[m] = num;
        i = i + num - 1; // 중복된 단어의 개수만큼 뛰어넘는다
        m = m + 1;
    }
    
    
    
    char* result_list[MAX]; // 중복없이 오름차순으로 정렬된 배열
    int k = 0; // result_list의 크기

    for (int i = 0; i < n - 1; i++) // 배열에서 중복된 값을 제거
    {
        if (strcmp(word_list[i], word_list[i+1]) < 0) // 두 단어가 같으면 0
        {                                                 // 왼쪽 단어가 크면 양수
            result_list[k] = word_list[i];              // 오른쪽 단어가 크면 음수
            k = k + 1;
        }
    }
    result_list[k] = word_list[n-1]; // 마지막값은 비교 할 대상이 없으니 바로 넣어준다



    for (int i = 0; i < m; i++) 
    {
        printf("%s: %d\n", result_list[i], num_list[i]);
    }
    printf("%d\n", m); 


    fclose(fp); // 파일은 닫는다
    

    return 0;
}