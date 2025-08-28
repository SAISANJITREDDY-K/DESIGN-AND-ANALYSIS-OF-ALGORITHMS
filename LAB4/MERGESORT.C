#include<stdio.h>


void merge(int *a,int l,int mid,int r)
{
    int i=l,j=mid+1,k=0;
    int temp[r-l+1];
    while(i<=mid && j<=r)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=l,k=0;i<=r;i++,k++)
    {
        a[i]=temp[k];
    }

}

void mergesort(int *a,int l,int r)
{
    if(l<r)
    {   
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void main()
{
    int n,i,a[100];
    printf("enter n value:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %dth element:",i);
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("Elements after merge sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
