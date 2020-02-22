#include <stdio.h>

main()
{
	int a[100],n,num;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter the elements in sorted order:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("\nEnter the element u want to search: ");
	scanf("%d",&num);
	
	int low=0,high=n-1,mid,k=0;
	
	while(low<=high)
	{
		mid=(high+low)/2;
		if(a[mid]>num)
		{
			low=mid+1;
		}
		if(a[mid]<num)
		{
			high=mid-1;
		}
		if(a[mid]==num)
		{
			k++;
			break;
		}
			
	}
	
	if(k==1)
	{
		printf("the number is in index %d",mid);
	}
	else
	{
		printf("element not found");
	}
}
