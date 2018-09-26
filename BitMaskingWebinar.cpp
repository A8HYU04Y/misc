#include<iostream>
#include<string.h>
using namespace std;
// Brian Kernighan’s Algorithm O(logn)
int CountSetBits(int n){
	int c=0;
	while(n){
		n=n&(n-1);
		c++;
		}
	return c;
}
// O(n)
int CountSetBits2(int n){
	int c=0;
	while(n){
		c+=n&1; // add count with leat bit AND that should be 1
		n>>=1; // right shifting for next bit
	}
	return c;
}
// say a=5, b=6 
void XORSwapping(int a,int b){
	a=a^b; // 1. a=a^b => a=5^6 
	b=b^a; //2. b=b^a => b=6^5^6=5 
	a=a^b; //3. a=a^b =>5^6^5 => a=6
}
// checking ith Bit
int ExtractIthBit(int n,int i){
     // say n=9 and i=3 then mask =1<<3=1000
	//n & mask  ==> 1001 &1000 ===> 1
     int mask=1<<i; // building Mask
     if(n&mask)
     	return 1;
     return 0;
}
void filter(char* a,int i){
	int j=0;
	while(i!=0){
		i&1?cout<<a[j]:cout<<"";
		j++;
		i>>=1;
	}
	cout<<endl;
}
void SubSequences(char* a){
	int range=(1<<strlen(a))-1;
	int i=0;
	for(i=1;i<=range;i++){
		filter(a,i);
	}
}

int main()
{ int n,i;
	char s[100];
	cin>>s;
	//cin>>n>>i;
	SubSequences(s)
	;
	return 0;
}
