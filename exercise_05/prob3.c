// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <stdlib.h> // exit()를 사용하기 위해

// 바둑돌 주변 8군데를 확인하기 위해 선언한 배열
int move[8][2] = { {-1,-1}, {-1,0}, {-1,+1}, {0,-1}, {0,+1}, {+1,-1}, {+1,0}, {+1,+1} };
int n;
int board[20][20]; 


void white_win(int x, int y); // 흰돌이 이겼는지 확인하는 함수
void black_win(int x, int y); // 검은돌이 이겼는지 확인하는 함수

int main(){

    FILE* fp = fopen("board.txt", "r");
    
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &board[i][j]); // 2차원 배열에 파일에 값이 저장된다
    }



    for (int i = 0; i < n; i++) // 2차원 배열을 돌면서
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1) // 겅은돌을 만났을때 이겼나 확인하고
            {
                black_win(i, j);
            }
            else if (board[i][j] == 2) // 흰돌을 만났을때 이겼나 확인한다
            {
                white_win(i, j);
            }
        }
    }
                            // 이기는 돌이 있다면 바로 끝나도록 설정해 놨기 때문에
    printf("Not Finished"); // 들다 이기지 않았다면 출력한다

    fclose(fp);

    return 0;
}



void black_win(int x, int y){

    int move_x, move_y;

    for (int i = 0; i < 8; i++) // 주변의 8군데 중 어디를 확인할지 i로 정한다
    {
        move_x = x + move[i][0];
        move_y = y + move[i][1];

        int k = 4; // 중심에 검은돌 주변에 연속으로 4개의 검은돌이 있으면 이기기 때문에 while문을 컨트롤 하기위해 4로 선언했다
        int count = 0; // 주변에 검은돌 개수, 새로운 검은돌을 만날때마다 0으로 초기화
       
        while (k > 0)
        {
            if (board[move_x][move_y] == 1) // 한칸 움직였는데도 검정돌이면
            {
                move_x = move_x + move[i][0]; // 한칸 더 움직이고
                move_y = move_y + move[i][1];
                count = count + 1; // 주변돌 개수에 +1을 한다
            }
            k = k - 1;

            if (count == 4) // 주변에 검은돌이 4개있으면
            {
                printf("Black\n"); // 출력하고
                exit(0); // 바로 끝낸다
            }
        }
    }
}





void white_win(int x, int y){ // 검정돌이랑 논리가 똑같다

    int move_x, move_y;
    for (int i = 0; i < 8; i++)
    {
        move_x = x + move[i][0];
        move_y = y + move[i][1];

        int k = 4;
        int count = 0;
       
        while (k > 0)
        {
            if (board[move_x][move_y] == 2)
            {
                move_x = move_x + move[i][0];
                move_y = move_y + move[i][1];
                count = count + 1;
            }
            k = k - 1;

            if (count == 4)
            {
                printf("White\n");
                exit(0);
            }
        }
    }
}



