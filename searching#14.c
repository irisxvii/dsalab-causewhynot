#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, key, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int linearResult = linearSearch(arr, n, key);
            if (linearResult != -1) {
                printf("Element found at index %d using Linear Search.\n", linearResult);
            } else {
                printf("Element not found using Linear Search.\n");
            }
            break;

        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Sorted array: ");
            printArray(arr, n);
            int binaryResult = binarySearch(arr, n, key);
            if (binaryResult != -1) {
                printf("Element found at index %d using Binary Search.\n", binaryResult);
            } else {
                printf("Element not found using Binary Search.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
