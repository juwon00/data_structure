// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h> // bool

bool is_palindrome(char *str1, char *str2, int word_len){
                        
    if (*str1 != *str2) // 양끝문자가 다른경우 false를 반환
        return false;
    
    else if (word_len > 0) // 문자열의 길이내에서 양끝문자가 같은경우 
    {   
        word_len--;
        return is_palindrome(str1+1, str2-1, word_len); // 재귀함수진행
    }

    return true; // 문자열의 길이내에서 양끝문자가 끝까지 같은경우 true를 반환
}

int main(){

    char word[100];
    int word_len;

    scanf("%s", word);

    word_len = strlen(word);

    if (word_len <= 1) // 길이가 1이하면 바로 회문이므로
        printf("Yes");
    
    else if (is_palindrome(&word[0], &word[word_len-1], word_len) == false) 
        printf("No"); // 회문 함수에서 false가 반환된 경우

    else
        printf("Yes"); // 나머지 경우 (길이가 1보다 큰 회문인 경우)

    return 0;
}