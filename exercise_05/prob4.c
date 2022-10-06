// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <stdbool.h> // bool을 쓰기 위해

int main(){

    FILE*fp = fopen("sample.html", "r");
    FILE* fp2 = fopen("sample.txt", "w");

    char buffer; // 하나의 문자를 저장하기 위해
    bool delete_tag = true; // true면 입력받고 false면 입력받지 않는다

    while (fscanf(fp, "%c", &buffer) != EOF)
    {
        if (buffer == '<') // '<'를 만나면 false로 바꿔서 이후 문자를 입력받지 않게 만듣다
        {
            delete_tag = false;
            continue;
        }
        if (buffer == '>') // '>'를 만나면 true로 바꿔서 다시 입력받게 해준다
        {
            delete_tag = true;
            continue;
        }
        if (delete_tag == false) // <>안에 있을때는 false로 입력받지 않는다
            continue;

        fprintf(fp2, "%c", buffer); 
    }

    fclose(fp);
    fclose(fp2);
    
    return 0;
}