#include<stdio.h>
#include <stdbool.h> 
#define n 4

void DFS(int,int);                                  //n is no of vertices and graph is sorted in array G[10][10]
 
void DFS(int G[][n],int visited[],int i)
{
    int j;
    
	printf("%d\t",i);
    visited[i]=1;
	
	for(j=0;j<n;j++)
       if(!visited[j] && G[i][j]==1)
            DFS(G,visited,j);
} 

int main()
{
    int i,j,visited[n];
    
    int G[n][n]={ { 0, 1, 1, 1 }, 
				  { 1, 0, 1, 0 }, 
			      { 1, 1, 0, 1 }, 
				  { 1, 0, 1, 0 }}; 
			
	for(i=0;i<n;i++)
        visited[i]=0;
 	
 	printf("DFS:\n");
    DFS(G,visited,0);
}
