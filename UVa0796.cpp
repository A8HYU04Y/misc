#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;
vector<vector<int>> adj ;
int tmp,t ;
vector<int> dfs_num,dfs_par,dfs_low ;
vector<pair<int,int>> bridge ;

void artic(int u){
    dfs_low[u]=dfs_num[u]=++t ;
    for(int i=0;i<adj[u].size();i++){
        int x = adj[u][i] ;
        if(dfs_num[x]==0){
            dfs_par[x]=u ;
            artic(x) ;
            if(dfs_low[x]>dfs_num[u])
            bridge.push_back(make_pair(min(u,x),max(u,x))) ;

            dfs_low[u] = min(dfs_low[u],dfs_low[x]) ;
        }
        else if(x!=dfs_par[u])
            dfs_low[u] = min(dfs_num[x],dfs_low[u]) ;
    }
}

int main()
{ 
   freopen("file.txt","w",stdout) ;
   int n ;
    
    while(scanf("%d", &n) == 1){
   
   string str ;
   int u,v ;
   
   adj.assign(n+1,vector<int>()) ; dfs_num.assign(n+1,0) ;dfs_par.assign(n+1,0);dfs_low.assign(n+1,0) ;
    
   fflush(stdin) ;
   for(int i=0;i<n;i++){
   
   getline(cin,str,')') ;
   u = stoi(str.substr(0,str.find('(')-1 ) ) ;
   v = stoi(str.substr(str.find('(')+1,str.find('(')-1)) ;
   while(v)
   {cin>>tmp ;
   adj[u].push_back(tmp) ;
   v-- ;}}
   
/* for(int j=0;j<n;j++){
    cout<<j<<" : ";
    for(int k=0;k<adj[j].size();k++){
        cout<<adj[j][k]<<" ";
    }
    printf("\n") ;
}*/
if(!n){
    printf("0 critical links\n\n");
}
else{
for(int i = 0;i<n;i++) if(dfs_num[i]==0) artic(i) ;
sort(bridge.begin(),bridge.end()) ;
printf("%d critical links\n",(int)bridge.size()) ;
for(int i = 0;i<(int)bridge.size() ;i++)
printf("%d - %d\n",bridge[i].first,bridge[i].second) ;
printf("\n") ;
bridge.clear() ;
}

fflush(stdout);








}
}
