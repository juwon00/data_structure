// 테스트 데이터 모두 통과했습니다.

#include <stdio.h>
#include <stdbool.h> // bool()
#include <stdlib.h> // malloc()
#include <time.h>

typedef int Item; // int를 Item으로 바꿔 씀 -> 코드의 재사용률을 높이기 위해

struct stack_type { // 배열로 스택만들기
    Item *num;
    int top;
    int size;
};
typedef struct stack_type *Stack;

Stack create(){
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    s -> num = (Item *)malloc(1000000 * sizeof(Item));

    s -> top = -1;
    s -> size = 1000000;
    return s;
}

void push(Stack s, Item i){
    s -> top++;
    s -> num[s->top] = i;
}

Item pop(Stack s){
    s -> top--;
    return s->num[s->top+1];
}

bool is_empty(Stack s) {
    return s->top == -1; 
}



int main(){

    FILE *fp = fopen("input.txt", "r");

    int T, N; // T: 테스트 케이스 개수  N: 정수의 개수
    int array[1000000]; // N개의 정수를 저장할 배열
    fscanf(fp, "%d", &T);

    for (int i = 0; i < T; i++) {

        fscanf(fp, "%d", &N);
        for (int i = 0; i < N; i++)
            fscanf(fp, "%d", &array[i]);

        Stack s1 = create();

        push(s1, 0); // h(0)는 항상 0이니까 0번 index를 push해준다

        int stack_pop; // pop을 int 함수로 만들어서 return값을 단순히 받기 위해 (안쓰는 변수)
        long long int result = 0; // 결과값 출력

        for (int i = 1; i < N; i++)
        {
            for (int j = s1->top; j > -1; j--) // 스택에 top에서부터 내려오면서 비교
            {
                if (array[i] >= array[s1->num[j]]) 
                    stack_pop = pop(s1); // 앞의 수보다 크면 앞의 계속해서 stack을 pop한다

                else {
                    result += i - s1->num[s1->top] - 1;  // (아래의 push하기전 결과값 계산해주고)
                    push(s1, i); // 처음으로 앞에 수보다 작으면 그때의 index를 push한다
                    break;
                }
            }

            if (is_empty(s1)) { // 가장 큰 수가 나와 전부다 pop했을 때 예외처리
                result += i;
                push(s1, i);
            }
        }

        printf("%lld\n", result % 1000000);
    }

    // 실행 시간을 출력하기 위해 가져온 코드
    clock_t start = clock();
    
    int sum = 0;
    for (int i = 0; i < 10000; ++i)
        for(int j = 0; j < 10000; ++j)
            sum += 1;
    clock_t end = clock();
    printf("Elapsed Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}







