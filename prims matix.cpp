#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 4

int minKey(int key[],bool myset[])
{
	int min=INT_MAX, min_index;  
  
    for (int v=0; v<V;v++)  
        if (myset[v]==false && key[v]<min)  
            min=key[v], min_index=v;  
  
    return min_index;  
}

void prims(int graph[][V])
{
	int parent[V],key[V];
	bool myset[V];
	
	for(int i=0;i<V;i++)
		key[i]=INT_MAX, myset[i]=false;
		
	key[0]=0; parent[0]=-1;
	
	for(int i=0;i<V-1;i++)
	{
		int u=minKey(key,myset);
		
		myset[u]=true;
		
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && myset==false && graph[u][v]<key[v])
				parent[v]=u, key[v]=graph[u][v];
		}
	}
	
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++) 
		printf("%d - %d \t%d \n", parent[i]+1, i+1, graph[i][parent[i]]);
}

int main()
{
	int graph[V][V] = { { 0, 1, 3, 4 }, 
						{ 1, 0, 2, 0 }, 
						{ 3, 2, 0, 5 }, 
						{ 4, 0, 5, 0 }}; 
						
	prims(graph);
	
	return 0;
}
