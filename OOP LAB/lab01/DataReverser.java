package lab01;

import java.util.ArrayList;

public class DataReverser{
    
    public void reverse(int[] arr){
        for(int i=0; i<arr.length/2; i++){
            int tmp = arr[i];
            arr[i] = arr[arr.length -i-1];
            arr[arr.length-i-1] = tmp;
        
        }
        System.out.print("Reversed Array : ");
          for(int x : arr){
            System.out.print(x + " ");
        }  
        System.out.println();
          
        
          
        
        
    }
}