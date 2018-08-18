package lab01;
import java.util.ArrayList;
import java.lang.*;
public class BubbleSortString{
    
    public void sort(String[] data){
        String tmp;
        
     for(int i=0;i<data.length-1;i++){
         for(int j=0;j<data.length-i-1;j++){
             if(data[j+1].compareToIgnoreCase(data[j])<0)
            { tmp=data[j];
            data[j]=data[j+1];
              data[j+1]=tmp; }
         }
     }
    }
}