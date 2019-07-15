#include<iostream>
#include<vector>
#include<stdio.h>
#include<numeric>
#include<algorithm>
using namespace std ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ;
typedef vector<int> vi ;

int t=0,n ;
vi dfs_num ,dfs_low ,artic,dfs_par ;
  vector<vi> adj(100,vi());
int root,rchild ;


void arti(int u){
dfs_low[u] = dfs_num[u] = ++t ;
for(int i = 0 ; i < (int)adj[u].size() ; i++){
       int x = adj[u][i] ;
       if(dfs_num[x]==0){
         if(u==root)
         ++rchild ;
         dfs_par[x] = u ;

         arti(x) ;

         if(dfs_low[x] >= dfs_num[u])
         artic[u] = 1 ;

         dfs_low[u] = min(dfs_low[u] , dfs_low[x]) ;

       }
       else if (x !=dfs_par[u])
              dfs_low[u] = min(dfs_low[u] , dfs_num[x] ) ;
}



}

int main(){
 
 //freopen("file.txt","w",stdout);
 int u,f,res ;
 while(1){
 
 scanf("%d",&n) ;
  int a = n ;
  for (int i=0;i<adj.size();i++)
 adj[i].clear();
 //artic.clear(); dfs_num.clear() ;dfs_low.clear() ;
 t=0 ;
  dfs_num.assign(100,0);dfs_low.assign(100,0) ;artic.assign(100,0); dfs_par.assign(100,0);

 if(!n)
 break;
 while(n+1){
     cin>>u ;
     if(u!=0)
     while(fgetc(stdin)!=10){cin>>f; adj[u].push_back(f) ;adj[f].push_back(u) ;}
     else{break ;}
     n--;
 }
 for(int i=1 ; i<=a;i++)
  if(dfs_num[i]==0)
 {
     root =i ;rchild = 0 ;arti(i) ;artic[root]= rchild>1 ;
 } 
 res = count(artic.begin(),artic.end(),1) ;
 printf("%d\n",res ) ;
 

 
 
 }


}