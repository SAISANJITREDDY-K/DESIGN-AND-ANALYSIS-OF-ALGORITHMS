#include<stdio.h>
void hanoi(int n,char source,char middle,char destination)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c",source,destination);
        return;
    }
    hanoi(n-1,source,destination,middle);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    hanoi(n-1,middle,source,destination);
}

int main()
{
    int n=3;
    hanoi(n,'A','B','C');
    return 0;
}
