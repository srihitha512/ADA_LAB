#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quicksort(int a[],int i,int j)
{
    if(i>=j)
        return;
    int low=i;
    int high=j;
    int pivot=a[low];
    while(i<j){
        while((a[i]<=pivot) && (i<high))
            i++;
        while((a[j]>pivot) && (j>low))
            j--;
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int t1=a[low];
    a[low]=a[j];
    a[j]=t1;

    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
}
void generateRandomArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
}
int main()
{
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    srand(time(0));  // seed
    generateRandomArray(a, n);
    printf("Generated Array: [ ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("]");

    clock_t start, end;
    start = clock();

    quicksort(a, 0, n-1);

    end = clock();

    printf("\nSorted Array: [ ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("]");
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to Execute: %f seconds\n", time_taken);

    return 0;

}
