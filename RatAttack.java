import java.util.*;
class coord
{
    int x;
    int y;
    coord(int x,int y){
    	this.x=x;
    	this.y=y;
    }

}

class RatAttack{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int t=in.nextInt();
		while(t-->0){
			int[][] a=new int[1025][1025];
		int[][] killed =new int[1025][1025];
			int d= in.nextInt();
			int n = in.nextInt();
			coord maxC=null;
			int maxi=-1;
			ArrayList<coord> c=new ArrayList<>();
			while(n-->0){
				int r=in.nextInt();
				int col= in.nextInt();
				c.add(new coord(r,col));
				int p = in.nextInt();
				a[r][col]=p;}
				int s=0;
			for(int i=0;i<c.size();i++){
				for(int j= c.get(i).x-d;j<=c.get(i).x+d && j>=0 && j<1024;j++ ){
					for(int k= c.get(i).y-d;k<=c.get(i).y+d && k>=0 && k<1024;k++ ){
						killed[j][k]+=a[c.get(i).x][c.get(i).y];
					    if(killed[j][k]>maxi){
					    	maxi =killed[j][k];
					    	maxC=new coord(j,k);
					    }
					    else if(killed[j][k]==maxi){
					    	if(j<maxC.x && k<maxC.y){
					    		maxC=new coord(j,k);
					    		maxi=killed[j][k];
					    	}
					    }
					}
				}
			}	
	
        System.out.println(maxC.x+" "+maxC.y+" "+maxi);

		
		}
	}
}
