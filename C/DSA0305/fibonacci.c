#include <stdio.h>
void fibonacci_series(int n) {
    if (n <= 1) {
        printf("%d", n);
    }
    else {
        int a = 0, b = 1, next;
        printf("%d %d ", a, b);
        for (int i = 2; i < n; i++) {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
    }
    printf("\n");
}

int main() {

    int n;  
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    fibonacci_series(n);

    return 0;
}