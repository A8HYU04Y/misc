#include<iostream>
#include<vector>
using namespace std;

int killed[1025][1025];
int a[1025][1025];
class coord{
	public:
    int x;
	int y;
    coord(){}
	 coord(int X,int Y){
		x=X;
		y=Y;
	}
	
};

int main()
{   
	int t;
    
    cin>>t;
    while(t--){
        int n,d,maxi=-1;
        vector<vector<int> > killed( 1025 , vector<int>(1025,0));
        vector<vector<int> > a( 1025 , vector<int>(1025,0));

        coord maxC(-1,-1);
        cin>>d;
        cin>>n;
        
        
        while(n--){
            int x,y,p;
            cin>>x>>y>>p;
            a[x][y]=p;
            for(int i=x-d ;i<=x+d && i<1025 && i>=0;i++){
                 for(int j=y-d ;j<=y+d && j<1025 && j>=0;j++){
                       killed[i][j]+=a[x][y];
                       if(killed[i][j]>maxi){
                          maxi=killed[i][j];
                          maxC.x=i;
                          maxC.y=j;
        }
          else if(killed[i][j]==maxi){
              if(maxC.x>i && maxC.y>j){
                 maxi= killed[i][j];
                 maxC.x=i;
                 maxC.y=j;
            }
        }


  }

        }}
        
       cout<<maxC.x<<" "<<maxC.y<<" "<<maxi<<endl; 
     




    }
    return 0;
}
