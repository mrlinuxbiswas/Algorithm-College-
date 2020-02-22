//Quick sort

#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[], int low, int up);
int partition(int a[], int low,int up);

void quicksort(int a[], int low, int up)
{
    int p;
    if(low>=up)
        return;
    
    p= partition(a,low,up);
    quicksort(a,low,p-1);
    quicksort(a,p+1,up);
}

int partition(int a[], int low,int up)
{
    int i,j,temp,pivot;
    
    pivot=a[low];
    i=low+1;
    j=up;
    
    while(i<=j)
    {
        while(a[i]<pivot && i<j)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        else
            break;
    }
    a[low]=a[j];
    a[j]=pivot;
    
    return j;
}

int main()
{
    int a[100],n,i;
    
    printf("Enter the size of the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    quicksort(a,0,n-1);
    
    printf("\n\n\n\n----Array after sorting:\n");
     for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}