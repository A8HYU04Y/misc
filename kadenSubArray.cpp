#include<iostream>
using namespace std;

int main()
{
  printf(">>> Enter the size of the Array : ");
  int size,sum=0,best=0; // instantial sum (sum) =0 , maximum sum =0 initially
  scanf("%d",&size);
  int a[size];
  printf(">>> Enter the Elements : ");
  for(int i=0;i<size;i++)
  	cin>>a[i];
  for(int j=0;j<size;j++)
  {  // checking current level sum 
  	sum=max(a[j],sum+a[j]);//maximum from current element and previous sum+current element 
  	best=max(best,sum);//maximum between previous max and current max
  }
printf(">>> Maximun SubArray Sum : ");
printf("%d",best);
}
