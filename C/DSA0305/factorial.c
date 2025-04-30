#include<stdio.h>

int calculateFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        for (int i = n - 1; i > 1; i--) {
            n *= i;
        }
    }  
    return n;
}

int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = calculateFactorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }
    
    return 0;
}