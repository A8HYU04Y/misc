package lab01;
import java.util.ArrayList;
import java.util.Arrays;
import java.lang.Double;

public class CSVExtractor{
    
    public void extract(String data){
        ArrayList<String> df= new ArrayList<String>(Arrays.asList(data.split(",")));
        ArrayList<Double> s = new ArrayList<Double>();//ArrayList Used
       for(int i=0;i<df.size();i++){
           s.add(i,Double.parseDouble(df.get(i)));
       } 
       System.out.print("Double Array : ");
       for(Double x:s)
       System.out.print(x +" ");
       System.out.println();
    }
}