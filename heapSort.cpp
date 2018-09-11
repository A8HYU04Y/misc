#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapify(int* a ,int index,int heapSize){
    int left =2*index+1;
    int right =2*index+2;
    int largest=index;
    if(left<heapSize && a[index]<a[left])
        largest=left;
    if(right<heapSize && a[right]>a[largest])
        largest = right;
    if(largest!=index){
          swap(a[index],a[largest]);
          heapify(a,largest,heapSize);
    }        
}
void buildHeap(int* a,int size){
  for(int i=(size/2)-1;i>=0;i--){
        heapify(a,i,size);
    }
}
void heapSort(int * a,int size){
    buildHeap(a,size);
    for(int i=size-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}
int main(){
     srand(time(0));
     int random ;
     int a[1000];
     int size = 1000;
     for(int j=0;j<size;j++){
         a[j]=rand()%1000 + 1;
     }
     int t1=time(0);
     heapSort(a,size);
     int t2=time(0);
     for(int i=0;i<sizeof(a)/sizeof(int);i++)
        cout<<a[i]<<endl;
     cout<< t2-t1;
         return 0;
}