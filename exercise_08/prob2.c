#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc()

#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100

typedef char Item; // char을 Item으로 바꿔 씀 -> 코드의 재사용률을 높이기 위해
typedef struct stack_type *Stack;

char *stack_array[INIT_CAPACITY]; // Stack들의 위치를 저장할 배열
int stack_index = 0; // 그 배열들의 위치조정 정수

struct node { // 추가되고 삭제될 연결리스트
    Item *data;
    struct node *next; 
};

struct stack_type { // 연결리스트 중의 대표? 
    Item *name;
    struct node *top;
};

void create(Item *i){ // 새로운 Stack을 만듬
    Stack s = malloc(sizeof(struct stack_type));
    s -> top = NULL;
    s -> name = i;

    stack_array[stack_index] = strdup(s->name); // 만든 스택의 이름을 stack_array에 저장해둠
    stack_index++; // stack_array의 다음공간을 가르킴
}

void push(Stack s, Item *i){ // 새로운 node를 만들고 add_first하는것
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> data = strdup(i);
    new_node -> next = s -> top;
    s -> top = new_node;
}

void list(Stack s){ // node연결리스트를 전부 보여줌
    Stack p = s;
    struct node *q = p -> top;
    while (q != NULL)
    {
        printf("%s\n", q->data);
        q = q ->next;
    }   
}

void pop(Stack s){ // node에 대해 remove_first하는것
    struct node *old_top;
    Item *i;

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    printf("%s\n", i);
}



int read_line(FILE *fp, char str[], int n){ // 한줄씩 읽는 함수
    int ch, i = 0;
    while ((ch=fgetc(fp))  != '\n' && ch != EOF)
        if(i < n-1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}


int main(){

    char command_line[BUFFER_LENGTH];
    char *command;

    while (1) // infinite loop
    {
        printf("$ "); // prompt

        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)  // get a line
            continue;

        command = strtok(command_line, " "); // 처음 커맨드(create, push등)을 구분

        if(strcmp(command, "create") == 0){
            char *tmp0 = strtok(NULL, " ");
            create(tmp0);
        }

        else if(strcmp(command, "push") == 0){
            char *tmp1 = strtok(NULL, " ");
            char *tmp2 = strtok(NULL, " ");

            for (int i = 0; i < stack_index; i++) {
                if (strcmp(tmp1, stack_array[i]) == 0) {
                    push(stack_array[i], tmp2);
                    break;
                }
            }
        }

        else if(strcmp(command, "list") == 0){
            char *tmp3 = strtok(NULL, " ");

            for (int i = 0; i < stack_index; i++) {
                if (strcmp(tmp3, stack_array[i]) == 0) {
                    list(stack_array[i]);
                    break;
                }
            }
        }
            

        else if(strcmp(command, "pop") == 0){
            char *tmp4 = strtok(NULL, " ");

            for (int i = 0; i < stack_index; i++) {
                if (strcmp(tmp4, stack_array[i]) == 0) {
                    pop(stack_array[i]);
                    break;
                }
            }
        }

        else if(strcmp(command, "exit") == 0)
            break;

    }

}