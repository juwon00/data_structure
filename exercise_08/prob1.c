#include <stdio.h>
#include <string.h> // strlen()

#define MAX_LENGTH 100

char stack[MAX_LENGTH]; // 배열로 스택만들기
int top = -1;

void push(int i){ 
    top++;
    stack[top] = i;
}

int pop(){
    int tmp = stack[top];
    top--;

    return tmp;
}

int main(){

    char expr[MAX_LENGTH];
    scanf("%s", expr);

    int index = 0; // 문자들을 하나씩 확인함
    int count = 0; // 스택안에 넣을 정수 (괄호를 push하는 것보다 출력할 숫자를 바로 push)

    while (index < strlen(expr)) { // 입력받은 길이보다 짧을 때
        char ch = expr[index]; // 문자열을 문자단위로 쪼갬

        if (ch == *"(") { // '(' 발견하면 push
            count += 1; 
            printf("%d ", count); 
            push(count); 
        }
        else if(ch == *")") { // ')' 발견하면 pop
            int x = pop(); 
            printf("%d ", x); 
        }

        index++; // 다음 문자로 이동
    }
}