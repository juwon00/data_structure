#include <stdio.h>
#include <string.h> 
#include <ctype.h> // isspace함수를 쓰기 위해
#define BUFFER_SIZE 500


char* ltrim(char *s) { //* 문자열 좌측의 공백문자를 없애는 함수
    char* begin;
    begin = s;
    while (*begin != '\0') 
    {
        if (isspace(*begin))
            begin++;
        else 
        {
            s = begin;
            break;
        }
    }
    return s;
}

char* rtrim(char* s) { //* 문자열 우측의 공백문자를 없애는 함수
    char t[4000];
    char *end;

    strcpy(t, s); 
 
    end = t + strlen(t) - 1;
    while (end != t && isspace(*end)) 
        end--;
    *(end + 1) = '\0';
    s = t;

    return s;
}

char* trim(char *s) { //* 문자열 앞뒤 공백문자 모두 없애는 함수
    return rtrim(ltrim(s));
}



int main(){

    FILE*fp = fopen("table.txt", "r");

    int n,m;
    fscanf(fp, "%d", &m); // 행
    fscanf(fp, "%d", &n); // 열

    char buffer[BUFFER_SIZE];
    char* line[m];
    int x = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) //* table.txt 에서 문자열들을 가져오는 부분
    {
        buffer[strlen(buffer) - 1] = *"\0"; // 각 라인의 "\n"문자를 "\0"문자로 바꾼다 
        line[x++] = strdup(buffer); // 한 줄씩 끊어서 line배열에 저장한다
    }   
    
    



    char* delim = "&"; // 구분문자를 이용해 문자열을 나눈다
    char* token;

    char* clean_words[n*m];

    for (int i = 1; i < m+1; i++) //* 문자열을 나누는 부분
    {
        token = strtok(line[i], delim); // line에 저장된 문자열을 &를 기준으로 나눈다

        for (int j = 0; j < n; j++)
        {   
            clean_words[j+ n*i-n] = strdup(token); // 나눠진 문자열들을 clean_words에 저장한다
            token = strtok(NULL, delim); 
        }
    }
    
    
    for (int i = 0; i < n*m; i++) //* 문자열 앞뒤 공백을 없애는 부분
        clean_words[i] = strdup(trim(clean_words[i]));
       

    int length_max;
    int length_max_array[n]; // 각 열에서 길이가 가장 긴 수를 저장할 배열

    for (int i = 0; i < n; i++) //* 각각의 열에서 가장 긴 단어를 찾는 부분
    {
       length_max = 0; // 최대값을 초기화해준다

        for (int j = 0; j < m; j++) 
        {
            if (strlen(clean_words[n*j +i]) > length_max) 
                length_max = strlen(clean_words[n*j +i]);
        }
        length_max_array[i] = length_max;   // 가장 긴 수를 저장한다
    }
    
   
    int spacing[n*m]; // 각 문자열 뒤 알마나 띄어쓰기를 할지 저장하는 배열
    int spacing_num; 

    for (int i = 0; i < n; i++) //* 깔끔히 보이기 위해 각 문자열뒤에 얼마만큼 띄어쓰기를 할지 구하는 부분
    {
        for (int j = 0; j < m; j++)
        {
            spacing_num = length_max_array[j] - strlen(clean_words[j+ n*i]);
            spacing[j+ n*i] = spacing_num;
        }
    }
    
    fclose(fp);



    FILE* fp2 = fopen("output.txt", "w");

    for (int i = 0; i < n*m; i++) //* output.txt 파일에 깔끔히 정리된 문자열들을 저장하는 부분
    {
        fputs(clean_words[i], fp2); // 단어를 출력하고

        for (int j = 0; j < spacing[i]; j++) // 띄어쓰기를 하고
            fputs(" ", fp2);
        
        fputs(" ", fp2); // 깔끔히 보이기 위해 단어와 단어 사이를 한칸 띄우고

        if ((i+1) % n == 0) // 각 행이 마지막 문자열에 도착하면 줄을 바꾼다
            fputs("\n", fp2);
    }

    fclose(fp2);


    return 0;
}