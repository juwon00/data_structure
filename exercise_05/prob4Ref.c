// 처음에 생각했던 코드
// '<'를 만나면 그안에 글자와 '>'까지 '|'로 바꾸고
// '|'가 아닌 문자들을 temp에 저장했다가 다시 line에 저장해 불러오는 구조였다 
// 이상한 문자가 자꾸 나와서 해결하지 못했다

#include <stdio.h>
#include <string.h>

void remove_tag(char *line);
void remove_space(char *line);

int main(){

    FILE*fp = fopen("sample.html", "r");
    

    char buffer[200]; 
    char* str[200]; 
    int n = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        remove_tag(buffer);
        remove_space(buffer);
        str[n++] = strdup(buffer); 
    }
    fclose(fp);

    FILE* fp2 = fopen("sample.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fputs(str[i], fp2);
    }
    
    fclose(fp2);
    
    return 0;
}



void remove_tag(char *line){
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '<')
        {
            line[i] = '|';
            for (int j = i; j < strlen(line); j++)
            {
                if (line[j] != '>')
                    line[j] = '|';
                
                else{
                    line[j] ='|';
                    break;
                }
            }
        }
    }
}



void remove_space(char *line){
    char temp[200];
    int index = 0;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] != '|')
        {
            temp[index] = line[i];
            index++;
        }
    }
    
    index = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        line[index] = temp[i];
        index++;
    }

    if (strlen(line) == 2) // 일때 sample.txt에 이상한 문자가 들어가는데 해결하지 못했다.
    {
        *line = ' ';
    }
    
    line[strlen(line)] = *"\0";
        
}

