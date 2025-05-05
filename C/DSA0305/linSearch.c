#include<stdio.h>

void Search(int *arr, int value) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == value) {
            printf("\nValue %d found at index %d\n", value, i);
            return;
        }
    }
    printf("\nValue %d not found in the array\n", value);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value;
    printf("\nEnter the value to search for: ");
    scanf("%d", &value);
    Search(arr, value);
}