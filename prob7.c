#include <stdio.h>
#include <string.h>

void sortString(const char list[100][20], const int n){

    char temp[20]; //임시로 저장할 때 쓰는 배열

    for (int i = 0; i < n - 1; i++)
    {
       for (int j = 0; j < n - i - 1; j++)
       {
            if (strlen(list[j]) > strlen(list[j+1])) // 문자의 길이 순서대로 정렬
            {
                strcpy(temp,list[j]);
                strcpy(list[j],list[j+1]);
                strcpy(list[j+1],temp);
            }

            if (strlen(list[j]) == strlen(list[j+1])) // 문자의 길이가 같을 때 사전순으로 정렬
            {
                if (strcmp(list[j], list[j+1]) > 0) 
                {	
				    strcpy(temp, list[j]);	
				    strcpy(list[j], list[j+1]);
				    strcpy(list[j+1], temp);
			    }
            }
       }
    }
}

int main(){

    int n; 
    char list[100][20] = {};

    scanf("%d", &n); // 입력받을 문자의 개수 n
  
    for (int i = 0; i < n; i++) //입력받은 문자를 배열에 저장
    {
        scanf("%s",list[i]);
    }
 
    sortString(list, n); // 정렬하는 함수

    for (int i = 0; i < n; i++) // 배열을 출력
    {
        printf("%s ", list[i]);
    }

    return 0;
}


