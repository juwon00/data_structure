// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node //* 연결리스트
{
    char* data; // 단어
    int count; // 단어가 나온 횟수
    struct node* next;
};
typedef struct node Node;
Node* head = NULL;

void add_first(char* item){ //* 만약 맨 처음 자리에 node를 추가해야 할 때
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = item;
    temp -> count ++; // 처음 단어가 추가된것이므로 1개부터 시작한다
    temp -> next = head;
    head = temp;
}

int add_after(Node* prev, char* item){ //* 맨 처음자리가 아닌 자리에 node를 추가해야 할 때
    if (prev == NULL)
        return 0;
    
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = item;
    temp -> count ++;
    temp -> next = prev -> next;
    prev -> next = temp;

    return 1;
}

void add_ordered_list(char* item){ //* node를 추가하는 함수
    Node *p = head; 
    Node *q = NULL; 

    while (p != NULL && strcmp(p -> data, item) <= 0) // 단어순서대로 정렬시키기 위해
    {
        q = p; // 이전의 node의 위치를 알기위해
        p = p -> next; // 
    }
    if (q == NULL)
        add_first(item);
    else
        add_after(q, item);
    
}




int main(){

    FILE* fp = fopen("harry.txt", "r");

    char buffer[30]; 
    int cnt = 0; // 총 단어의 개수를 저장하는 변수

    while (fscanf(fp, "%s", buffer) != EOF)
    {
        Node *p = head;
        while (p != NULL && strcmp(p -> data, buffer) != 0) // 중복된 단어를 제거하기 위해
        {
            p = p -> next; // p를 같은 단어를 만날 때 까지 이동시킨다.
        }


        if (p != NULL) // 중복된 단어이면 그 node의 count에 +1 해준다
        {
            p -> count += 1;
        }
        else // 중복된 단어가 없다면 (p가 끝까지 도달해 NULL을 만난다면) 전체단어의 개수에 +1 해주고 새로운 node를 만든다
        {
            cnt += 1;
            add_ordered_list(strdup(buffer));
        }
       
    }



    
    Node *tmp = head;
    while (tmp != NULL) // 연결리스트의 처음(head)부터 끝(NULL)까지 출력한다.
    {
        printf("%s: %d\n", tmp -> data, tmp -> count);
        tmp = tmp -> next;
    }
    
    printf("%d", cnt); //전체 단어의 개수도 출력한다.

    fclose(fp);

    return 0;
}