#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++)
    {
        l[i]=a[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=a[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=l[i];
        i++;
    }
    while(j<n2)
    {
        a[k]=r[j];
        j++;
    }
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int low,high,mid,n,m;
    printf("Enter no of elements u wish to enter: ");
    scanf("%d",&n);
    int a[n];
    // Seed random generator
    srand(time(NULL));

    // Fill array with random numbers (range 0–999)
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
    }

    printf("Unsorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    int start=clock();
    mergesort(a,0,n-1);
    int end=clock();
    printf("\n");
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute: %f seconds\n", time_taken);

    return 0;


}

