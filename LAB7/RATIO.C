#include <stdio.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

void sortByRatio(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j+1].ratio) {
                Item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double fractionalKnapsackRatio(Item arr[], int n, int capacity) {
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }

    sortByRatio(arr, n);

    double totalValue = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= capacity) {
            curWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            int remain = capacity - curWeight;
            totalValue += arr[i].ratio * remain;
            break;
        }
    }
    return totalValue;
}

int main() {
    Item arr[] = { {60, 10, 0.0}, {100, 20, 0.0}, {120, 30, 0.0} };
    int capacity = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsackRatio(arr, n, capacity);
    printf("Maximum value by Ratio method = %.2f\n", maxValue);
    return 0;
}

