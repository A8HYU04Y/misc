#include <algorithm>
#include <iostream>
#include <list>
#include<vector>
#define INF 10e5
#define ii pair<int,int>
using namespace std ; 

int bellmanFord(list<ii>* adj , int v,int e,int from ,int to){
vector<int> dist ; 
dist.assign(v+1,INF) ; 
dist[from] = 0 ; 
for(int i = 1;i<v;i++)
	//for(int j = 1 ; j<v+1 ; j++)
		for(list<ii>::iterator it = adj[from].begin();it!=adj[from].end();it++){
			ii x = *it ; 
			dist[x.first] =min(dist[x.first],dist[from]+x.second);
		}
return dist[to] ; 		

}

int main()

{   
	int v,e,deg,tmp,w; 
	printf("Enter Number of Vertices and Edges : \n");
	scanf("%d %d",&v,&e) ; 
	list<ii> adj[v+1] ; 
	for(int  i=1 ;i<v+1 ; i++){
		printf("Degree of vertex %d\n",i);
		scanf("%d",&deg) ; 
		printf("Enter the neighbours and respective weights : ");
		for(int j =0;j<deg ; j++){
            scanf("%d %d",&tmp,&w) ; 
			adj[i].push_back(make_pair(tmp,w)) ; 
		}
	}
	cout<<bellmanFord(adj,v,e,3,1);
;}
