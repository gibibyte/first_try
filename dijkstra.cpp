// Dijkstra's single source shortest path algorithm for Directed and Undirected connnected graphs. Time compexity: O(n^2)  
#include<bits/stdc++.h>
using namespace std;
#define V 10
int graph[V][V]; // adjacency matrix

int mindist(vector<int> dist,vector<bool> sptset,int n)
{
	int i,minval=INT_MAX,minindex;
	for(i=0;i<n;i++)
	{
		if(sptset[i]==false && dist[i]<minval)
		minval=dist[i],minindex=i;
	}
	return minindex;
}
void dijkstra(int n,int src)
{
	int v,i,min;
	vector<bool> sptset(n,false);					    // Shortest path tree set
	vector<int> dist(n,INT_MAX);						// The output array- minimum distance of each vertex from the source
	
	dist[src]=0;
	for(i=0;i<n-1;i++)
	{
		min=mindist(dist,sptset,n);
		
		sptset[min]=true;
		
		for(v=0;v<n;v++)
		{
			if(sptset[v]==false && graph[min][v] && dist[min]!=INT_MAX && (graph[min][v] + dist[min] < dist[v]))
			{
				dist[v]=dist[min]+graph[min][v];
			}
		}
		
	}

	cout<<endl<<"Distance of every vertex from source: "<<src<<" is as follows:\n"; 
	for(i=0;i<n;i++)
	{
		if(dist[i]==INT_MAX)cout<<-1<<" ";
		else cout<<dist[i]<<" ";
	}
}
int main()
{
	int i,j,n,src;
	cout<<"\nEnter the number of vertices: ";
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&graph[i][j]);
	}
	
	cout<<"\nEnter the source vertex: ";
	scanf("%d",&src);
	dijkstra(n,src);
	
	return 0;
}

