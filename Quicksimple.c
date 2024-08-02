#include <stdio.h>

void quicksort(int *arr, int left, int right) {
    int i = left, j = right, pivot = arr[(left + right) / 2], temp;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++; j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
