#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 4
int parent[V];

int find(int i) 
{ 
    while(parent[i]!= i) 
        i=parent[i]; 
    return i; 
} 
   
void un(int i, int j) 
{ 
    int a=find(i); 
    int b=find(j); 
    parent[b]=a; 
} 
  
void kruskal(int graph[][V]) 
{ 
    int mincost = 0;  
   
    for (int i=0;i<V;i++) 
        parent[i]=i; 
  
    int edge=0; 
    while(edge<V-1)
	{ 
        int min=INT_MAX,a=-1,b=-1; 
        for (int i=0;i<V;i++) 
		{ 
            for (int j=0;j<V;j++) 
			{ 
                if (find(i)!= find(j) && graph[i][j]<min) 
				{ 
                    min=graph[i][j]; 
                    a=i; 
                    b=j; 
                } 
            } 
        } 
  
        un(a,b); 
        edge++;
        printf("%d-->%d == %d \n",a+1,b+1,min); 
        mincost += min; 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 

int main()
{
	int graph[V][V] = { { INT_MAX, 1, 3, 4 }, 
						{ 1, INT_MAX, 2, INT_MAX }, 
						{ 3, 2, INT_MAX, 5 }, 
						{ 4, INT_MAX, 5, INT_MAX }}; 
						
	kruskal(graph);
	
	return 0;
	
}
