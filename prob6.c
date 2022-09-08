#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // pow를 쓰기 위해

int combination(int n, int r){ //조합의 계산을 구현하는 함수

	if(n==r || r==0){
		return 1;
	}
	// nCr = (n-1)C(r-1) + (n-1)C(r)
	return combination(n-1,r-1) + combination(n-1, r);
}


int main(){

    double sum = 0;
    double perc;
    double a = 1;
    double b = 5;
    double c = 6;
    double frac1; // 주사위에서 1이 나올 확률 (1/6)
    double frac2; // 주사위에서 1이 나오지 않을 확률 (5/6)
    int comb;

    frac1 = a / c;
    frac2 = b / c;

    srand((unsigned int) time(NULL)); // 랜덤으로 1~6 사이값을 구하는 식
    int r = rand() % 6 + 1;

    printf("k의 값: %d\n", r);

    for (int i = 0; i < r; i++) // (1이 k번 이상 나올 확률) =  1 - (1이 k번 미만 나올 확률) 
    {                           // 1이 k번 미만 나올 확률 'sum'을 구하는 식
        comb = combination(6*r,i);
        sum = sum + (comb * pow(frac1, i) * pow(frac2, 6*r-i) ); 
    }
    perc = 1 - sum;

    printf("확률: %f", perc); // 최종 확률

    return 0;
}  
