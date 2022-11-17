#include <stdio.h>
#include <stdlib.h> // malloc
#include <stdbool.h> // bool

#define MAX 100
#define PATH 1

typedef struct pos { // 위치를 나타내는 구조체
int x, y; 
} Position;

struct node { // Queue에 연결된 노드들
    Position data;
    struct node *next;
};

struct queue_type { // Queue의 정보를 담고있는? 시작점?
    struct node *front;
    struct node *rear;
    int size;
};
typedef struct queue_type *Queue;

int offset[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
                    //* 순서대로 북, 북동, 동, 동남, 남, 남서, 서, 서북 방향으로 이동할 수 있게하는 방향인덱스


int T; //* 테스트 케이스
int n; //* 지도의 크기
int maze[MAX][MAX];

void read_maze(FILE *fp);
void print_maze();
void maze_start();


int main(){

    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);

    for (int i = 0; i < T; i++){
        
        read_maze(fp); // 테스트 마다 지도를 읽어오고

        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (maze[x][y] == PATH){ // 안가본 길이 있으면 미로찾기시작
                    maze_start(x, y);
                }
            }
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}



Queue create(){ //* 새로운 큐 만들기
    Queue q = malloc(sizeof(struct queue_type));
    q -> front = NULL;
    q ->rear = NULL;
    q ->size = 0;
    return q;
}
bool is_empty(Queue q){ //* 큐가 비어있는지 확인
    return q -> front == NULL;
}
void enqueue(Queue q, Position i){ //* 큐에 넣기
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> data = i;
    new_node -> next = NULL;

    if (q->front == NULL){ //큐가 비어있다면 처음으로 연결
        q -> front = new_node;
        q -> rear = new_node;
    }
    else{ // 아니라면 연결되어 있는 노드들 끝에다 연결
        q -> rear -> next = new_node;
        q -> rear = new_node;
    }
    q -> size ++;
}
Position dequeue(Queue q){ //* 큐에서 빼기
    struct node *old_front;
    Position i;

    old_front = q -> front; // 가장 앞 노드를 뺀다
    i = old_front -> data;
    q -> front = old_front -> next;

    if (q->front == NULL)
        q -> rear = NULL;
    free(old_front);
    q -> size--;
    return i;
}



void read_maze(FILE *fp){ //* 지도를 읽어오는 함수
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
            fscanf(fp, "%d", &maze[i][j]);
       }
    }
}

void print_maze(){ //* 지도를 출력하는 함수
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int moveable(Position pos, int dir){ //* dir방향으로 이동가능한지 확인하는 함수
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];

    if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < n){ // 다음 위치가 지도를 벗어나지 않고
        if (maze[next.x][next.y] == PATH) // 다음 위치가 1일때만 true반환 = 움직일 방향이 있음(dir방향)
            return true;
        else
            return false;    
    }    // 나머지는 false반환 = 움직일 방향이 없음
    else
        return false;
}

Position move_to(Position pos, int dir){ //* dir방향으로 이동하는 함수
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}


void maze_start(int x, int y){

    Queue queue = create();
    Position cur;
    cur.x = x;
    cur.y = y;
    int count = 1; //* enqueue할때마다 count값을 1 증가시킬건데 처음 미로찾기를 시작하면
                   //* 아래줄에서 enqueue를 항상 하니까 1로 시작한다
    enqueue(queue, cur);

    maze[x][y] = 2; //! 1로 시작하면 앞으로 한칸 갔다가 다시 출발지점으로 돌아오기때문에 2로 시작
    bool found = false;

    while (!is_empty(queue))
    {
        Position cur = dequeue(queue);

        for (int dir = 0; dir < 8; dir++){ 
            if (moveable(cur, dir)){ // 8방향중 한방향으로 움직일 수 있으면

                Position p = move_to(cur, dir);
                // printf("p.x  p.y: %d %d\n", p.x, p.y);
                maze[p.x][p.y] = maze[cur.x][cur.y] + 1; //! 2로 시작하고 가능한 방향 1씩증가
                count += 1; //* enqueue할때마다 +1하면 총 컴포넌트의 개수를 구할 수 있다
                enqueue(queue, p);
            }   
        }
    }
    printf("%d ", count);
}