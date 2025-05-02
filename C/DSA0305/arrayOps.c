#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
void Insert(int *arr, int *size, int value, int pos) {
    if (*size >= 100) {
        printf("\nArray is full\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("\nIndex out of bounds\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}
void Delete(int *arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("\nIndex out of bounds\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void Search(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("\nValue %d found at index %d\n", value, i);
            return;
        }
    }
    printf("\nValue %d not found in the array\n", value);
}

int main() {
    int arr[100];
    int size = 0;
    int choice;
    while(1) {
        switch (choice) {
            case 1:
                printf("\nEnter the size of the array: ");
                scanf("%d", &size);
                printf("Enter %d elements:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("\n");
                printArray(arr, size);
                break;
            case 2:
                reverseArray(arr, size);
                printf("\nReversed array: ");
                printArray(arr, size);
                break;
            case 3:
                printf("\nEnter the value to insert: ");
                int value;
                int position;
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                Insert(arr, &size, value, position);
                printf("\nArray after insertion: ");
                printArray(arr, size);
                break;
            case 4:
                printf("\nEnter the index to delete: \n");
                printf(" ");
                printArray(arr, size);
                printf("[ ");
                for (int i = 0; i < size; i++) {
                    printf("%d  ", i);
                }
                printf("]\n");
                int index;
                scanf("%d", &index);
                if (size == 0) {
                    printf("\nArray is empty\n");
                    break;
                }
                for (int i = 0; i < size; i++) {
                    if (i == index) {
                        printf("Deleting %d\n", arr[i]);
                    }
                }
                if (index < 0 || index >= size) {
                    printf("\nIndex out of bounds\n");
                    break;
                }
                Delete(arr, &size, index);
                printf("\nArray after deletion: ");
                printArray(arr, size);
                break;
            case 5:
                printf("\nEnter the value to search for: ");
                scanf("%d", &value);
                Search(arr, size, value);
                break;
        }
        printf("\nChoose an operation:\n");
        printf("1. Create an array\n");
        printf("2. Reverse the array\n");
        printf("3. Insert an element\n");
        printf("4. Delete an element\n");
        printf("5. Search for an element\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }
}