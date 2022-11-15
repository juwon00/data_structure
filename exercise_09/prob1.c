#include <stdio.h>
#include <stdlib.h> //  malloc()
#include <stdbool.h> //  true/false

#define INIT_CAPACITY 100
#define MAX 100
#define WALL 0 /* 지나갈 수 없는 위치 */ 
#define PATH 1 /* 지나갈 수 있는 위치 */
#define VISITED 2 /* 이미 방문한 위치 */
#define BACKTRACKED 3 /* 방문했다가 되돌아 나온 위치 */

typedef struct pos {
int x, y; 
} Position;

struct stack_type {
    Position *contents;
    int top;
    int size; 
};
typedef struct stack_type *Stack;

int offset[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
                    //* 순서대로 북, 북동, 동, 동남, 남, 남서, 서, 서북 방향으로 이동할 수 있게하는 방향인덱스

int maze[MAX][MAX]; // 지도 초기화
int T; //* 테스트 케이스 개수
int n; //* 지도의 크기

Stack create();
void push(Stack s, Position i);
Position pop(Stack s);
bool is_empty(Stack s);
void read_maze();
int moveable(Position cur, int dir);
Position move_to(Position pos, int dir);
void print_maze();
void maze_start(int x, int y);


int main(){

    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    // printf("%d", T);
    for (int i = 0; i < T; i++)
    {        
        read_maze(fp);
        // printf("n: %d\n", n);
        // print_maze();
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){ //* 지도의 특정부분이 1일때 미로찾기 시작
                if (maze[x][y] == 1){
                    // printf("start: %d %d\n", x, y);
                    maze_start(x, y);
                }
            }
        }
        printf("\n");
    }
    fclose(fp);

    return 0;
}


Stack create() {
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    s->contents = (Position *)malloc(INIT_CAPACITY * sizeof(Position)); 

    s->top = -1;
    s->size = INIT_CAPACITY; 
    return s;
} 
void push(Stack s, Position i) {
    s->top++;
    s->contents[s->top] = i;
}
Position pop(Stack s) {
    s->top--;
    return s->contents[s->top+1];
}
bool is_empty(Stack s) {
    return s->top == -1; 
}

void read_maze(FILE *fp){ //* 지도를 읽어오는 함수
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
            fscanf(fp, "%d", &maze[i][j]);
       }
    }
}

int moveable(Position pos, int dir){ //* dir방향으로 이동가능한지 확인하는 함수
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    // printf("next: %d %d maze[next]: %d\n", next.x, next.y, maze[next.x][next.y]);
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

void print_maze(){ //* 지도를 출력하는 함수
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void maze_start(int x, int y){ //* 미로찾기를 시작하는 함수

    Stack s = create();
    Position cur;
    cur.x = x;
    cur.y = y;
    // printf("%d %d\n", cur.x, cur.y);
    int num = 0;

    while (1)
    {
        maze[cur.x][cur.y] = VISITED;

        bool forwarded = false;
        for (int dir = 0; dir < 8; dir++){
            // printf("dir: %d\n", dir);
            if (moveable(cur, dir) == true){ //* 앞으로 갈 수 있다면
                // printf("moveable\n");
                // printf("move_to before: %d %d\n", cur.x, cur.y);
                num += 1; //! 갈 수 있는 방향이 있을 때 마다 num+1
                push(s, cur);
                cur = move_to(cur, dir);
                // printf("move_to after: %d %d\n", cur.x, cur.y);
                forwarded = true;
                break;
            }
        }

        if (!forwarded){ //* 앞으로 갈 수 없다면
            maze[cur.x][cur.y] = BACKTRACKED;

            if (is_empty(s)){ //! 미로찾기가 끝날 때 while문 break
                num += 1; //! 처음위치에서의 +1을 안해줬으니 여기서 해준다
                // printf("num = %d, No path exists\n\n", num);
                break;
            }
            cur = pop(s);
        }
        // printf("!!cur: %d %d\n", cur.x, cur.y);
    }
    printf("%d ", num);
    // print_maze();
    // printf("\n\n");
}