#include <stdio.h>
#include <bits/stdc++.h> 
  
void BellmanFord(int graph[][3], int V, int E, int src) 
{  
	int dis[V]; 
	for (int i=0;i<V;i++) 
		dis[i]=INT_MAX; 

	dis[src]=0; 
 
	for (int i=0;i<V-1;i++)                                             // Relax all edges |V|-1 times.  
	{ 
		for (int j=0;j<E;j++) 
		{ 
			if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) 
				dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2]; 
		} 
	} 

	// check for negative-weight cycles. 
	// The above step guarantees shortest 
	// distances if graph doesn't contain 
	// negative weight cycle. If we get a 
	// shorter path, then there is a cycle. 
	for (int i=0;i<E;i++) 
	{ 
		int x=graph[i][0]; 
		int y=graph[i][1]; 
		int weight = graph[i][2]; 
		if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) 
			printf("Graph contains negative weight cycle"); 
	} 

	printf("Vertex \t Distance from Source\n"); 
	for (int i=0;i<V;i++) 
		printf("%d \t %d\n",i,dis[i]); 
} 
 
int main() 
{ 
	int V=5;  
	int E=8; 

	// Every edge has three values (u, v, w) where  
	int graph[][3] = { { 0, 1, -1 }, 
						{ 0, 2, 4 }, 
					    { 1, 2, 3 }, 
						{ 1, 3, 2 }, 
					    { 1, 4, 2 }, 
						{ 3, 2, 5 }, 
					    { 3, 1, 1 }, 
						{ 4, 3, -3 } }; 

	BellmanFord(graph, V, E, 0); 
	return 0; 
} 

