#include<iostream>

using namespace std;
// 2.Merge 
void merge(int* a,int left,int mid,int right){
  int part1=mid-left+1; // size of left partition
  int part2=right-mid;  // size of right partition
  int L1[part1],L2[part2]; // partitioned arrays
  int i,j,k;
  for(i=0;i<part1;i++)
    L1[i]=a[left+i];  // copying Array Left
  for(j=0;j<part2;j++)
    L2[j]=a[mid+1+j]; // copying Array Right
  i=0,j=0,k=left;   // partitioned Arrays Created now Comparing data and adding to main Array 
  while(i<part1 && j<part2){
    if(L1[i]<=L2[j])//Left 
        a[k++]=L1[i++];
        
    else
        a[k++]=L2[j++]; //Right
        
  }
  // if L1 is still not Empty
  while(i<part1)
    a[k++]=L1[i++];
  // If L2 is still not Empty  
  while(j<part2)
    a[k++]=L2[j++];
    
}

// 1. Dividing Array into smaller ones
void partition(int* a ,int left,int right){
    if(left>=right)
        return;
    else{
        int mid=left+(right-left)/2; // mid required to prevent stack overflow
        partition(a,left,mid); // partitioning Left
        partition(a,mid+1,right); // partitioning Right
        merge(a,left,mid,right); // Merging Both Partitions
    }
}
// Caller Function
void MergeSort(int* a,int size){
    partition(a,0,size-1);
}
// Driver Function
int main(){
    int n;
    printf(">>> Enter the Size of the Array :  ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  // Sorting
    MergeSort(a,n);
    printf("Sorted Array : \n");
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
