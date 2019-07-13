#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ;
typedef vector<int> vi ;

int v,e,t=0 ;
vi dfs_num ,dfs_low ,dfs_par,artic ;
  vector<vi> adj(100,vi()); ;
int root ,rchild;
void arti(int u){
dfs_low[u]=dfs_num[u]=++t ;
for(int i=0;i<(int)adj[u].size();i++){
    int x=adj[u][i];
if (root==u)
rchild++ ;    
if(dfs_num[x]==0){
        dfs_par[x]=u ;
        
        arti(x) ;
       if(dfs_low[x]>=dfs_num[u])
       artic[u]=1 ;
       if(dfs_low[x]>dfs_num[u])
          printf("Bridge : %d %d\n",x,u);       
dfs_low[u] = min(dfs_low[u],dfs_low[x]) ;


    }
    else if(x!=dfs_par[u])
    dfs_low[u] = min(dfs_low[u],dfs_num[x]) ;
}

}

int main(){
 printf("Enter number of Vertices and Edges : ") ;
 cin>>v>>e ;
 dfs_num.assign(v,0);dfs_low.assign(v,0) ;dfs_par.assign(v,0) ;artic.assign(v,0);
 printf("Enter the edges : ");
 int a,b;


 for(int i=0;i<e ; i++){
   cin>>a>>b ;
   adj[a].push_back(b) ;
   adj[b].push_back(a) ;
}
 for(int i = 0;i<v ; i++){
     if(dfs_num[i]==0)
root=i; rchild=0;        
arti(i) ;
 }
artic[root] = rchild>1 ;
for(int i=0 ; i<v ; i++)
  
  printf("%d ",artic[i]) ;

}
