#include <stdio.h>

float arr[2][10];
int n,w;

float knapsack(int w,int n, float arr[][10])
{
	float cur_w=0.0,profit=0.0,temp1=0.0,temp2=0.0;
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			if((arr[0][j]/arr[1][j]) < (arr[0][j+1]/arr[1][j+1]))
			{
				temp1=arr[0][j]; temp2=arr[1][j];
				arr[0][j]=arr[0][j+1]; arr[1][j]=arr[1][j+1];
				arr[0][j+1]=temp1; arr[1][j+1]=temp2;
			}
		}
	}
			
	for(int i=0;i<n;i++)
	{
		if (cur_w+arr[1][i]<=w) 
		{ 
			cur_w +=arr[1][i]; 
			profit +=arr[0][i]; 
		} 
		else 
		{
			int remain=w-cur_w;
			profit +=arr[0][i]*(remain/arr[1][i]);
			break; 
		}
	}
	
	return profit;
}

int main()
{
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		printf("Enter obj %d-th profit & weight:\n",i+1);
		scanf("%f %f",&arr[0][i],&arr[1][i]);
	}
	
	printf("\nEnter the Maximum Weight: ");
	scanf("%d",&w);
	
	printf("Maximum profit: %f",knapsack(w,n,arr));
}
