#include <stdio.h>

int main() {
    int n, i, j, count = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count duplicates
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;  // Avoid counting the same duplicate multiple times
            }
        }
    }

    printf("Total number of duplicate elements = %d\n", count);

    return 0;
}