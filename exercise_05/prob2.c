#include <stdio.h>
#include <string.h>

int n;
int num[100][100];

void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice();

int main(){
   
    FILE* fp = fopen("data.mat", "r");
    
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &num[i][j]); // 2차원 배열에 정수들을 저장한다
    }
    
    

    while (1)
    {
        char command[100];

        printf("$ ");
        scanf("%s", command); // 각각의 command에 맞춰서 함수를 실행시킨다


        if (strcmp(command, "show") == 0)
        {
            show();
        }
        else if (strcmp(command, "colmax") == 0)
        {
            colmax();
        }
        else if (strcmp(command, "colmin") == 0)
        {
            colmin();
        }
        else if (strcmp(command, "rowmax") == 0)
        {
            rowmax();
        }
        else if (strcmp(command, "rowmin") == 0)
        {
            rowmin();
        }
        else if (strcmp(command, "slice") == 0)
        {
            slice();
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
           
    }
    
    return 0;
}


void show(){ // 전체 행렬을 출력하는 함수

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", num[i][j]);
        printf("\n");
    }
    printf("\n");
}


void colmax(){ // 각 열의 최대값을 출력하는 함수

    for (int i = 0; i < n; i++)
    {
        int max = num[0][i];
       
        for (int j = 0; j < n; j++)
        {
            if (max < num[j][i])
                max = num[j][i];
        }        
       printf("%d ", max);
    }
    printf("\n\n");
}


void colmin(){  // 각 열의 최소값을 출력하는 함수

    for (int i = 0; i < n; i++)
    {
        int min = num[0][i];

        for (int j = 0; j < n; j++)
        {
            if (min > num[j][i]) 
                min = num[j][i];  
        }
        printf("%d ", min);
    }
    printf("\n\n");
}


void rowmax(){  // 각 행의 최대값을 출력하는 함수

    for (int i = 0; i < n; i++)
    {
        int max = num[i][0];

        for (int j = 0; j < n; j++)
        {
            if(max < num[i][j])
                max = num[i][j];
        }
        printf("%d ", max);
    }
    printf("\n\n");
}


void rowmin(){  // 각 행의 최소값을 출력하는 함수

    for (int i = 0; i < n; i++)
    {
        int min = num[i][0];

        for (int j = 0; j < n; j++)
        {
            if (min > num[i][j]) 
                min = num[i][j];  
        }
        printf("%d ", min);
    }
    printf("\n\n");
}

void slice(){  // x번 행부터 p행씩 건너띄고 y번 열부터 q열씩 건너띄면서 출력하는 함수

    int x, p, y, q;

    scanf("%d %d %d %d", &x, &p, &y, &q);

    printf("\n");
    for (int i = x; i < n; i = i + p)
    {
       for (int j = y; j < n; j = j + q)
            printf("%d ", num[i][j]);

       printf("\n");
    }
    printf("\n");
}
