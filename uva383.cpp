#include<iostream>
#include<map>
#include<list>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
using namespace std ; 
int query ;

 
  
void bfs(map<string,list<string>> adj ,int size , string from , string to){
    queue<string> q ; 
    map<string,int> dist ; 
    q.push(from) ; 
    dist[from] = 0 ; 
    while(!q.empty()){
        string x =q.front() ; q.pop() ; 
        for(list<string>::iterator i = adj[x].begin() ; i!=adj[x].end() ; i++){
            if(!dist.count(*i)){
                dist[*i] = dist[x] + 1 ; 
                q.push(*i) ; 
            }
        }
    }
if(!dist.count(to))
    printf("NO SHIPMENT POSSIBLE\n") ; 
else
    printf("$%d\n",dist[to]*size*100) ; 
 
}
int main(){
   // freopen("myfile.txt","w",stdout);
    scanf("%d",&query) ; 
    int dataSet =1 ;  
       printf("SHIPPING ROUTES OUTPUT\n\n") ; 
    while(query--){
      
    printf("DATA SET  %d\n\n",dataSet) ;
    dataSet++ ;
    int m,n,p ;
    scanf("%d %d %d",&m,&n,&p) ; 
    map<string,list<string>> adj ;
    //list<string> l ;  
    while(m--){
        char st[2] ; 
        scanf("%s",st) ;
        adj[st] = list<string>() ;
   //     cout<<"done";
    }
    n+=1 ; 
    while(n--){
        string loc[2] ; 
        string from,to ; 
        getline(cin,from) ;
        istringstream ss(from);
        int i = 0 ;
        while(getline(ss, to, ' ') ) {
            loc[i] = to ; 
            i++ ; 
          }  
        adj[loc[0]].push_back(loc[1]) ;
        adj[loc[1]].push_back(loc[0])  ;
          }
       while(p--){
        int size;
        string from ,to ; 
        cin>>size>>from>>to ;
        bfs(adj,size,from,to) ;
       }
  printf("\n");
    }
printf("END OF OUTPUT\n") ;
//fclose (stdout); 
}