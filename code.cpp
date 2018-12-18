#include<stdio.h>
#include<iostream>
using namespace std ;
int c =0 ;

void func(int n){
    //printf("%d ",n) ;
    c++;
    if(n==1){
        return ;
    }
    else if(n%2){n= 3*n+1;}
    else{
        n=n/2 ;

    }
    func(n) ;
}
int main(){
freopen("myfile.txt","w",stdout);     

int L,r;
while(scanf("%d %d",&L,&r)!=EOF){
        int res =0;
        int a=L,b=r;
        if(a>b)swap(a,b);

int i=a ;
while(i<=b){
    func(i);
    res =max(res,c) ;
    c=0;
i++ ;
}
printf("%d %d %d\n",L,r,res) ;
res=0;}
fclose (stdout);
}