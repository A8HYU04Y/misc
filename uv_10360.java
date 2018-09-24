import java.util.*;
class box
{
    int x;
    int y;
    box(int x,int y){
    	this.x=x;
    	this.y=y;
    }

}

class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int t=in.nextInt();
		while(t-->0){
			int[][] a=new int[1025][1025];
		int[][] killed =new int[1025][1025];
			int d= in.nextInt();
			int n = in.nextInt();
			box maxC=null;
			int maxi=-1;
			
			while(n-->0){
				int r=in.nextInt();
				int col= in.nextInt();
				int p = in.nextInt();
				a[r][col]=p;
			for(int j= r-d;j<=r+d && j>=0 && j<1025;j++ ){
					for(int k= col-d;k<=col+d && k>=0 && k<1025;k++ ){
						killed[j][k]+=a[r][col];
					    if(killed[j][k]>maxi){
					    	maxi =killed[j][k];
					    	maxC=new box(j,k);
					    }
					    else if(killed[j][k]==maxi){
					    	if(j<maxC.x && k<maxC.y){
					    		maxC=new box(j,k);
					    		maxi=killed[j][k];
					    	}
					    }}
				
				}
			}	
	
        System.out.println(maxC.x+" "+maxC.y+" "+maxi);

		
		}
	}}
