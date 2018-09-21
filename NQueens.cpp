#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
bool Safe(bool board[12][12] ,int r,int c ,int n){
   // column check
   for(int row=0;row<r;row++){
   	if(board[row][c])
   		return false;}
   // left diagonal check
   	int x=r,y=c;
   	while(x>=0 && y>=0){
   		if(board[x][y])
   			return false;
   		x--;
   		y--;
   	}
  // right diagonal check 	
   	x=r;
   	y=c;
while(x>=0 && y<n){
   		if(board[x][y])
   			return false;
   		x--;
   		y++;
   	}
   	return true;
}
bool Solve(bool board[12][12],int i,int n){
	if(i==n){
        for(int g=0;g<n;g++){
        	for(int h=0;h<n;h++){
        		if(board[g][h])
        			cout<<"Q ";
        		else
        			cout<<"_ ";
        	}
        cout<<"\n";
        }
        cout<<"\n";
		// false is returned to view all possible configs.
		return false;
	}
    for(int j=0;j<n;j++){
    	if(Safe(board,i,j,n)){
    		board[i][j]=true;
    		bool nextQueen = Solve(board,i+1,n); // can next Queen be placed for this position

    		if(nextQueen)
    			return true;
    	}
    	board[i][j]=false; //BackTrack
    
    }
return false;

}
int main()
{   int n;
	printf("Enter the size of board : ");
	scanf("%d",&n);
	bool board[12][12] ={false};
     Solve(board,0,n);

	return 0;
}