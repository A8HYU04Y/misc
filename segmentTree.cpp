#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
//#define vector<int> vector<int>

class segTree{
    private :
	vector<int> st,arr;  // st will store indexes and arr is actual array
	int s; // size variable
	// left index
	int left(int p){
		return p<<1;
	}
	//right index
	int right(int p){
		return (p<<1)+1;
	}
    // building the tree O(n)
	void build(int p, int l,int r){
		// leaf
		if(l==r)
			st[p]=l;
		else{
			//build left subtree
			build(left(p),l,(l+r)/2);
			// build right subtree
			build(right(p),(l+r)/2 +1,r);
			// left min 
			int p1 = st[left(p)];
			// right min
			int p2 = st[right(p)];
			// min of left min && right min
			st[p] = (arr[p1]<=arr[p2])?p1:p2;
		}
	}
	// RangeMinimumQuery
   int rmq(int p,int l,int r,int i,int j){
   	// no overlap
   	if(i>r || j<l )
   		return -1;
   	// perfect overlap
   	else if(i<=l && j>=r)
   		return st[p];
    // partial overlap
    int p1 = rmq(left(p),l,(l+r)/2,i,j);
    int p2 = rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1)
    	return p2;
    if(p2==-1)
    	return p1;
    return (arr[p1]<=arr[p2])?p1:p2;
   }
    public:
    // Constructor
   segTree(const vector<int> &_arr){
   	arr = _arr;
   	s = (int)arr.size();
   	// creating large enough array with 0(s)
   	st.assign(4*s,0);
   	// build
   	build(1,0,s-1);
   }
   // wrapper for RMQ
   int rmq(int i,int j){
   	return rmq(1,0,s-1,i,j);
   }
	};

int main()
{
	int arr[] = {18,17,13,19,15,11,20};
	vector<int> _arr(arr,arr+7);
	segTree  st(_arr);
	printf("RMQ(1,3) = %d\n",st.rmq(1,3));
} 
		
