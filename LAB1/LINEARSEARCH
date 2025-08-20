LINEAR SEARCH 


#include <stdio.h>

int main()
{
    int n, i, a[100], s;
    printf("Enter size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter required element: ");
    scanf("%d", &s);
    for (i = 0; i < n; i++)
    {
        if (a[i] == s)
        {
            printf("Element found at position %d\n", i + 1);
            return 0;  
        }
    }
    printf("Element not found\n");
    return 0;
}
