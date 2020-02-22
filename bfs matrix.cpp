#include<stdio.h>
#define n 4

void bfs(int a[][n],int q[],int visited[],int v) 
{
	int i,j,f=0,r=-1;
	for(i=1; i <= n; i++)
		if(a[v][i] && !visited[i])
			q[++r] = i;
			
	if(f<=r) 
	{
		visited[q[f]] = 1;
		bfs(a,q,visited,q[f++]);
	}
}

int main()
{
	int q[n],visited[n];
	int a[n][n]={ { 0, 1, 1, 1 }, 
			      { 1, 0, 1, 0 }, 
			      { 1, 1, 0, 1 }, 
			      { 1, 0, 1, 0 }};
	
	for(int i=1;i<= n;i++) 
	{
		q[i]=0;
		visited[i]=0;
	}
	
	bfs(a,q,visited,0);
	printf("\n The node which are reachable are:\n");
	
	for(int i=1;i<=n;i++) 
	{
		if(visited[i])
			printf("%d\t", i);
		else 
		{
			printf("\n Bfs is not possible. Not all nodes are reachable");
			break;
		}
	}
}
