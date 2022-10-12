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

Node * remove_first () {
    if (head == NULL)
       return NULL;
    
    else 
    {
        Node *tmp = head;
        head = head->next; 
        return tmp;
    }
}

Node * remove_after (Node *prev) {
    Node *tmp = prev->next;
    if (tmp == NULL) 
        return NULL; 

    else 
    {
    prev->next = tmp->next; 
    return tmp;
    } 
}

void remove_list(char *item){
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






struct sort_node //* 새롭게 만든 연결리스트 node를 더하는 방법은 위의 방법과 동일하다
{
    char* sort_data;
    int sort_count;
    struct sort_node* sort_next;
};
typedef struct sort_node sort_Node;
sort_Node* sort_head = NULL;

void sort_add_first(char* item, int count_max){
    sort_Node* temp = (sort_Node*)malloc(sizeof(sort_Node));
    temp -> sort_data = item;
    temp -> sort_count = count_max;
    temp -> sort_next = sort_head;
    sort_head = temp;
}

int sort_add_after(sort_Node* prev, char* item, int count_max){
    if (prev == NULL)
        return 0;
    
    sort_Node* temp = (sort_Node*)malloc(sizeof(sort_Node));
    temp -> sort_data = item;
    temp -> sort_count = count_max;
    temp -> sort_next = prev -> sort_next;
    prev -> sort_next = temp;

    return 1;
}

void sort_add_ordered_list(char* item, int count_max){
    sort_Node *p = sort_head;
    sort_Node *q = NULL;

    while (p != NULL)
    {
        q = p;
        p = p -> sort_next;
    }
    if (q == NULL)
        sort_add_first(item, count_max);
    else
        sort_add_after(q, item, count_max);
    
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



    int remove_cnt = 0;
    Node *delete = head;
    while (delete != NULL)
    {
        if (delete -> count <= 10)
        {
            remove_list(delete -> data);
            remove_cnt += 1;
        }
        delete = delete -> next;
    }
    
    int result_cnt;
    result_cnt = all_cnt - remove_cnt;




    for (int i = 0; i < result_cnt; i++) // * 빈도의 내림차순으로 정렬하는 방법
    {
        Node *p = head; 
        Node *p_max = NULL;
        sort_Node *q = sort_head;
        int count_max = 0;

        for (int j = 0; j < result_cnt - i ; j++) // Node에서 count가 가장 큰 곳을 찾고
        {
            if (count_max == 0 || count_max < p -> count)
            {
                count_max = p -> count; 
                p_max = p; // 그곳읠 p_max라고 저장해 놓는다
                q = p; // 그때의 p를 sort_Node q에 저장해놓는다
            }

            p = p -> next;
        }
        remove_list(p_max -> data); // Node에서 가장 큰 count를 가진 node를 제거하고
        sort_add_ordered_list(q -> sort_data, count_max); // sort_Node에 Node에서 count가 가장 큰 값을 추가한다
    } 
    
    


    

    sort_Node *tmp = sort_head;
    while (tmp != NULL)
    {
        printf("%s: %d\n", tmp -> sort_data, tmp -> sort_count);
        tmp = tmp -> sort_next;
    }
    printf("%d", result_cnt);

    fclose(fp);

    return 0;
}