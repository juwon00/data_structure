#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

int main(){

    int n = 1;
    int m = 1;
    int lengthA, lengthB;
    int ret; 
    char a[MAX_LENGTH];
    char b[MAX_LENGTH];
    char com;
    char resultA[MAX_LENGTH];
    char resultB[MAX_LENGTH];

    scanf("%s", a); // 두 문자열를 입력한다
    scanf("%s", b); 

    lengthA = strlen(a); // 두 문자열의 길이를 정의한다
    lengthB = strlen(b);
 
    for (int i = 0; i < lengthA; i++) // 처음 문자열을 오름차순으로 정렬한다
    {
        for (int j = 0; j < lengthA-i-1; j++)
        {
            if (a[j] > a[j+1]){
                com = a[j];
                a[j] = a[j+1];
                a[j+1] = com;
            }               
        }
    }

    for (int i = 0; i < lengthB; i++) // 두번째 문자열을 오름차순으로 정렬한다
    {
        for (int j = 0; j < lengthB-i-1; j++)
        {
            if (b[j] > b[j+1]){
                com = b[j];
                b[j] = b[j+1];
                b[j+1] = com;
            }             
        }
    }
    

    resultA[0] = a[0]; 
    for (int i = 1; i < lengthA; i++) // 처음 문자열의 중복된 문자를 제거한다
    {
        if (a[i] != resultA[n-1]){
            resultA[n++] = a[i];
        }
    }

    resultB[0] = b[0];
    for (int i = 1; i < lengthB; i++) // 두번째 문자열의 중복된 문자를 제가한다
    {
        if (b[i] != resultB[m-1]){
            resultB[m++] = b[i];
        }
    }

    
    ret = strcmp(resultA, resultB); // 두 문자열을 비교한다 (같으면 0이 나오고 다르면 1이 나온다)
    if (ret == 0){
        printf("yes\n"); // 같으면 yes출력
    }else{
        printf("no\n"); // 다르면 no출력
    }

    return 0;
}