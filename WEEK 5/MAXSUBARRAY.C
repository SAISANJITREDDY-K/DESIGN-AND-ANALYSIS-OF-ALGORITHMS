#include <stdio.h>

int max(int a, int b, int c) {
    int max_ab = (a > b) ? a : b;
    return (max_ab > c) ? max_ab : c;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = arr[mid];
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = arr[mid + 1];
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int left_max = maxSubArraySum(arr, low, mid);
    int right_max = maxSubArraySum(arr, mid + 1, high);
    int cross_max = maxCrossingSum(arr, low, mid, high);

    return max(left_max, right_max, cross_max);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum subarray sum is %d\n", max_sum);

    return 0;
}
