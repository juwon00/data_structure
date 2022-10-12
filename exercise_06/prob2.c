// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char* data;
    int count;
    struct node* next;
};
typedef struct node Node;
Node* head = NULL;

void add_first(char* item){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = item;
    temp -> count ++;
    temp -> next = head;
    head = temp;
}

int add_after(Node* prev, char* item){
    if (prev == NULL)
        return 0;
    
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = item;
    temp -> count ++;
    temp -> next = prev -> next;
    prev -> next = temp;

    return 1;
}

void add_ordered_list(char* item){
    Node *p = head;
    Node *q = NULL;

    while (p != NULL && strcmp(p -> data, item) <= 0)
    {
        q = p;
        p = p -> next;
    }
    if (q == NULL)
        add_first(item);
    else
        add_after(q, item);
    
}

Node * remove_first () { //* 맨 앞자리의 node를 제거해야 할 때
    if (head == NULL)
       return NULL;
    
    else 
    {
        Node *tmp = head;
        head = head->next; 
        return tmp;
    }
}

Node * remove_after (Node *prev) { //* 맨 처음자리가 아닌 다른자리에 node를 제거해야 할 때
    Node *tmp = prev->next;
    if (tmp == NULL) 
        return NULL; 

    else 
    {
    prev->next = tmp->next; 
    return tmp;
    } 
}

void remove_list(char *item){ //* node를 제거하는 함수
    Node *p = head;
    Node *q = NULL;
    while (p!=NULL && strcmp(p->data, item)!=0) 
    {
        q = p;
        p=p->next; 
    }
    if (q == NULL)
        remove_first();
    else
        remove_after(q);
    
}





int main(){

    FILE* fp = fopen("harry.txt", "r");

    char buffer[30];
    int all_cnt = 0;

    while (fscanf(fp, "%s", buffer) != EOF)
    {
        Node *p = head;
        while (p != NULL && strcmp(p -> data, buffer) != 0)
            p = p -> next;

        if (p != NULL)
            p -> count ++;
        
        else
        {
            all_cnt += 1;
            add_ordered_list(strdup(buffer));
        } 
    }

    int remove_cnt = 0; // 제거된 node의 개수
    Node *delete = head;
    while (delete != NULL) // Node를 끝까지 돌면서
    {
        if (delete -> count <= 10) // count가 10이하면
        {
            remove_list(delete -> data); // 제가하고
            remove_cnt += 1; // 제거된 노드의 개수에 1을 더한다
        }
        delete = delete -> next;
    }
    


    int result_cnt; // 총 남은 node의 개수
    result_cnt = all_cnt - remove_cnt;


    
    Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%s: %d\n", tmp -> data, tmp -> count);
        tmp = tmp -> next;
    }
    
    printf("%d", result_cnt);

    fclose(fp);

    return 0;
}