#include <stdio.h>

typedef struct {
    int min;
    int max;
} Pair;

Pair findMinMax(int arr[], int low, int high) {
    Pair minmax, leftMinMax, rightMinMax;
    int mid;
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    } 
    else if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minmax.min = arr[low];
            minmax.max = arr[high];
        } else {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    } 
    else {
        mid = (low + high) / 2;
        leftMinMax = findMinMax(arr, low, mid);
        rightMinMax = findMinMax(arr, mid + 1, high);
        minmax.min = (leftMinMax.min < rightMinMax.min) ? leftMinMax.min : rightMinMax.min;
        minmax.max = (leftMinMax.max > rightMinMax.max) ? leftMinMax.max : rightMinMax.max;
        return minmax;
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Pair minmax = findMinMax(arr, 0, n - 1);
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
