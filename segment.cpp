#include<iostream>
#include<string.h>
#define loop(i,l,r) for(int i=l ; i<r ; i++)
using namespace std; 
int n ;

// rsqbuild  
void rsqbuild(int* tree ,int idx,int l,int r,int* a){
    if(l==r)
    tree[idx]=a[l] ;
    else{
        build(tree,2*idx+1,l,(l+r)/2,a) ;
        build(tree,2*idx+2,(l+r)/2 + 1,r,a) ;
        tree[idx] = tree[2*idx+1]+tree[2*idx+2] ;
    }
}
//rmqBuild

void rmqbuild(int * tree ,int idx,int l,int r,int* a){
    if(l==r)
        tree[idx]=a[l] ;
    else{
        rmqbuild(tree,2*idx+1,l,(l+r)/2,a) ;
        rmqbuild(tree,2*idx+2,(l+r)/2+1,r,a) ;
        tree[idx] = min(tree[2*idx+1],tree[2*idx+2]) ;
    }
}

//RMQ
int rmq(int* tree ,int idx , int l,int r,int nodeL,int nodeR){
    // Outside the Range
    if(r<nodeL || l>nodeR)
        return INT32_MAX ;
    // inside the range
    if(l<=nodeL && r>=nodeR)
        return tree[idx] ;
    // Partial Overlap
    int p1 = rmq(tree,2*idx+1,l,r,nodeL,(nodeL+nodeR)/2) ;
    int p2 = rmq(tree,2*idx+2,l,r,(nodeL+nodeR)/2+1,nodeR) ;
    return min(p1,p2) ;

}
// RSQ

int rsq(int* tree ,int idx , int l,int r,int nodeL,int nodeR){
    // Outside the Range
    if(r<nodeL || l>nodeR)
        return 0;
    // inside the range
    if(l<=nodeL && r>=nodeR)
        return tree[idx] ;
    // Partial Overlap
    int p1 = rsq(tree,2*idx+1,l,r,nodeL,(nodeL+nodeR)/2) ;
    int p2 = rsq(tree,2*idx+2,l,r,(nodeL+nodeR)/2+1,nodeR) ;
    return p1+p2 ;

}

int main(int argc ,char* argv[]){

scanf("%d",&n) ;
int arr[n],tree[4*n+1] ;
memset(tree,0,sizeof tree) ;
loop(i,0,n) scanf("%d",&arr[i]) ;
build(tree,0,0,n-1,arr) ;
int l,r ;
scanf("%d %d",&l,&r) ;
printf("%d",rsq(tree,0,l,r,0,n-1)) ;
}