#include<iostream>
#include<list>
#include<math.h>
#include<string.h>
int x[9],a,b,counter=0;

bool safe(int r,int c){
	for(int i=1;i<c ;i++){
		if(x[i]==r || (abs(r-x[i])==abs(c - i)))
			return false;
	}
	return true;
}
void place(int col){
	for(int i=1 ; i<=8;i++)
	{
		if(safe(i,col)){
			x[col]=i;
			if(col==8 && x[b]==a){
				// do something here
				printf("%2d      %d",++counter,x[1]);
				for(int j=2;j<=8;j++)
					printf(" %d",x[j]);
				
				printf("\n");

			}
		   else
			place(col+1);
		}
		
	}
}

int main(){

  int t;
  scanf("%d",&t);
  while(t--){
  	counter=0;
  	memset(x , 0 , sizeof x);
  	scanf("%d %d",&a,&b);
  	printf("SOLN       COLUMN\n");
  	printf(" #      1 2 3 4 5 6 7 8\n\n");
  	place(1);
  	printf("\n");
  }
  return 0;

}