#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<map>

using namespace std ; 
int count =1 ;
void bfs(map<int,list<int>> adj,int start,int ttl){
    queue<int> q ; 
    map<int,int> vis ; 
    q.push(start) ; 
    vis[start] = 0 ;
    while(!q.empty()){
        int x = q.front() ; q.pop() ; 
        for(list<int>::iterator i = adj[x].begin() ; i!=adj[x].end() ; i++){
            if(!vis.count(*i)){
                vis[*i] = vis[x] + 1 ;
                q.push(*i) ; 
            }
        }
    }
    int res=0; 
 for(map<int,int>::iterator i = vis.begin() ; i!=vis.end() ; i++){
     if((*i).second>ttl)
        res++ ; 
 }
 res+= adj.size()-vis.size() ; 
 printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",count,res,start,ttl);
 count++ ; 
}
int main(){
    int nc ; 
    while(scanf("%d",&nc) && nc){
        map<int,list<int>> adj ; 
        int f,s ; 
        for(int i = 0 ;i<nc ; i++){
            scanf("%d %d",&f,&s) ; 
            adj[f].push_back(s) ; 
            adj[s].push_back(f) ; 
        }
        int start,ttl ;
        while(scanf("%d %d",&start,&ttl) && (start!=0 || ttl!=0)){
            bfs(adj,start,ttl) ; 
        }  
    }
}