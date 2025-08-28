#include<stdio.h>

void swap(int *a1, int *a2) {
     int temp = *a1;
     *a1 = *a2;
     *a2 = temp;

}

int partition(int a[],int low,int high)
{
    int p,i,j;
    p=a[low];
    i=low+1;
    j=high;
    
    while(i<j)
    {
        while(a[i]<=p)
        {
            i++;
        }
        while(a[j]>p)
        {
            j--;
        }
        if(i<j){
        swap(&a[i],&a[j]);
        }
    }
   
    swap(&a[j],&a[low]);
    return(j);
}

void quicksort(int a[],int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int a[100],i;
    for(i=0;i<n;i++)
    {
        printf("Enter %dth element:",i);
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Elements after sorting are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
