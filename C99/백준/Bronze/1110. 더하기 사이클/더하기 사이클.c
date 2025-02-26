#include <stdio.h>

int main() {
    int cycle = 0, sum_result = -9999, original_num, A, A_1, A_10;

    scanf("%d", &original_num);
    
    A = original_num;

    while(sum_result != original_num){
        if(A >= 10){
            A_10 = (A % 100) / 10;
            A_1 = (A % 10) / 1;
        }

        else{
            A_10 = 0;
            A_1 = A;
        }

        sum_result = (A_1 * 10) + (((A_1 + A_10) % 10) / 1);

        A = sum_result;

        cycle ++;
    }

    printf("%d", cycle);

    return 0;
}
