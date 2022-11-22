// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <string.h> // strlen()

int compare(char *str1, char *str2, int min_len){

    if (*str1 == *str2 && min_len > 0) // 범위 내에서 비교할 문자가 같다면
    {
        min_len--;
        return compare(str1+1, str2+1, min_len); // 재귀함수진행
    }
    else if (*str1 > *str2) // 앞이 늦은경우
        return 1;

    else if (*str1 < *str2) // 앞이 빠른경우
        return -1;

    else // 같은경우
        return 0;
}


int main(){

    char str1[100];
    char str2[100];
    int len1;
    int len2;
    int min_len;

    scanf("%s", str1);
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 > len2) // 두 문자열중 짧은 문자열의 길이가 최대한 재귀함수를 반복할 수 있기에
        min_len = len2;
    else
        min_len = len1;
    

    if (compare(&str1[0], &str2[0], min_len) == 1) // 처음 문자열이 늦으면 (1을 반환하면)
        printf("%s \n%s", str2, str1); // 두문자열 순서를 바꿔서 출력
    
    else // 처음 문자열이 빠르거나 두번째 문자열이랑 같다면 (-1 또는 0을 반환했다면)
        printf("%s \n%s", str1, str2); // 두문자열 순서 그대로 출력
    
    return 0;
}