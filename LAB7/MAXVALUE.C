#include <stdio.h>

typedef struct {
    int value;
    int weight;
    int taken;
} Item;

int maxValueIndex(Item arr[], int n) {
    int maxIdx = -1;
    int maxVal = -1;
    for (int i = 0; i < n; i++) {
        if (!arr[i].taken && arr[i].value > maxVal) {
            maxVal = arr[i].value;
            maxIdx = i;
        }
    }
    return maxIdx;
}

double fractionalKnapsackValue(Item arr[], int n, int capacity) {
    double totalValue = 0.0;
    int curWeight = 0;

    while (curWeight < capacity) {
        int idx = maxValueIndex(arr, n);
        if (idx == -1) break;

        if (curWeight + arr[idx].weight <= capacity) {
            curWeight += arr[idx].weight;
            totalValue += arr[idx].value;
            arr[idx].taken = 1;
        } else {
            int remain = capacity - curWeight;
            double fraction = (double)remain / arr[idx].weight;
            totalValue += arr[idx].value * fraction;
            break;
        }
    }
    return totalValue;
}

int main() {
    Item arr[] = { {60, 10, 0}, {100, 20, 0}, {120, 30, 0} };
    int capacity = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsackValue(arr, n, capacity);
    printf("Maximum value by Value method = %.2f\n", maxValue);
    return 0;
}
