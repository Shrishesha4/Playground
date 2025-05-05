#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result == -1)
        printf("Element not found in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}