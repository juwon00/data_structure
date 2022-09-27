#include <stdio.h>
#include <math.h> // sqrt함수를 쓰기 위해

int main(){

    FILE*fp = fopen("input.txt", "r");
    
    int num_array[100][100];
    int n;
    fscanf(fp, "%d", &n); // 행랼의 크기를 먼저 입력받고
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &num_array[i][j]); // 2차원 배열로 나머지 수를 저장한다
        }
    }
    

    double aver_stDeviation[40][2]; // [(평균, 표본편차), (평균, 표본편차) .. ] 형식으로 저장

    for (int i = 0; i < n; i++) // 평균을 계산
    {
       double sum_row = 0; // 한 행의 수들을 저장
       double aver_row; // 한 행의 평균을 저장

       double sum_column = 0; // 한 열의 수들을 저장
       double aver_column; // 한 열의 수들을 저장

        for (int j = 0; j < n; j++)
        {
            sum_row = sum_row + num_array[i][j];
            sum_column = sum_column + num_array[j][i];
        }
        aver_row = sum_row / n;
        aver_stDeviation[i][0] = aver_row;

        aver_column = sum_column / n;
        aver_stDeviation[i+n][0] = aver_column; // 열의 평균은 행의 평균을 다 저장한 이후 공간에 저장한다
    }

    


    for (int i = 0; i < n; i++) // 표본편차를 계산
    {
        double x = 0; // 각 행의 편차의 제곱을 저장
        double x_devi = 0; // 각 행의 표본 편차를 저장

        double y = 0; // 각 열의 편차의 제곱을 저장
        double y_devi = 0; // 각 열의 표본 편차를 저장

        for (int j = 0; j < n; j++)
        {
            x = num_array[i][j] - aver_stDeviation[i][0]; // 각 수에서 평균을 빼고
            x = x * x; // 제곱한 수들을 
            x_devi = x_devi + x; // x_devi에 먼저 저장한다

            y = num_array[j][i] - aver_stDeviation[i+n][0];
            y = y * y;
            y_devi = y_devi + y;
        }
        x_devi = x_devi / n; // 편차의 제곱들의 합을 수의 개수로 나눈 후
        x_devi = sqrt(x_devi); // 루트를 씌운것이 표본편차이다
        aver_stDeviation[i][1] = x_devi;

        y_devi = y_devi / n;
        y_devi = sqrt(y_devi);
        aver_stDeviation[i+n][1] = y_devi;
    }




    for (int i = 0; i < n; i++) // 출력방식을 맞춰서 출력한다
    {
        for (int j = 0; j < n; j++)
        {
             printf("%d ", num_array[i][j]); // 기본 행렬을 출력하고
        }
        printf("%.2f ", aver_stDeviation[i][0]); // 행의 평균과
        printf("%.2f", aver_stDeviation[i][1]); // 행의 표준편차는 각 행의 뒤에 출력
        printf("\n");
    }

    for (int i = n; i < n*2; i++)
        printf("%.2f ", aver_stDeviation[i][0]); // 열의 평균과
    printf("\n");
    for (int i = n; i < n*2; i++)
        printf("%.2f ", aver_stDeviation[i][1]); // 열의 표본편차는 각 열에 밑에 출력

    fclose(fp);
    

    return 0;
}