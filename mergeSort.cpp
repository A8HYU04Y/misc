#include<iostream>

using namespace std;
void merge(int* a,int left,int mid,int right){
  int part1=mid-left+1;
  int part2=right-mid;
  int L1[part1],L2[part2];
  int i,j,k;
  for(i=0;i<part1;i++)
    L1[i]=a[left+i];
  for(j=0;j<part2;j++)
    L2[j]=a[mid+1+j];
  i=0,j=0,k=left;
  while(i<part1 && j<part2){
    if(L1[i]<=L2[j])
        a[k++]=L1[i++];
        
    else
        a[k++]=L2[j++];
        
  }
  while(i<part1)
    a[k++]=L1[i++];
    
  while(j<part2)
    a[k++]=L2[j++];
    
}
void partition(int* a ,int left,int right){
    if(left>=right)
        return;
    else{
        int mid=left+(right-left)/2; // required to prevent stack overflow
        partition(a,left,mid);
        partition(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
void MergeSort(int* a,int size){
    partition(a,0,size-1);
}

int main(){
    int n;
    printf(">>> Enter the Size of the Array :  ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MergeSort(a,n);
    printf("Sorted Array : \n");
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}