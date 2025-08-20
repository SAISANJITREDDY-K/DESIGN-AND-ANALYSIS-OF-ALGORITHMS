BINARY SEARCH


#include <stdio.h>

int binsearch(int a[], int l, int h, int s)
{
    if (l > h) 
        return -1;

    int mid = (l + h) / 2;

    if (a[mid] == s)
        return mid;
    else if (a[mid] > s)
        return binsearch(a, l, mid - 1, s);
    else
        return binsearch(a, mid + 1, h, s);
}

int main()
{
    int a[100], i, n, s;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter array elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Elements in the array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &s);

    int pos = binsearch(a, 0, n - 1, s);

    if (pos != -1)
        printf("\nElement found at position %d\n", pos + 1);
    else
        printf("\nElement not found\n");

    return 0;
}
