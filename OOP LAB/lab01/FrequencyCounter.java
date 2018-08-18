package lab01;
import java.util.ArrayList;
import java.util.HashMap;

public class FrequencyCounter{
    public void countElements(ArrayList<Integer> arr){
    HashMap<Integer,Integer> dict = new HashMap<Integer,Integer>();    
    for(Integer x:arr){
        if(dict.containsKey(x)){
            int pre= dict.get(x);
            dict.put(x,pre+1);
        }
        else{
            dict.put(x,1);
        }
}
    for(int i=0;i<11;i++){
        System.out.println("Count for " +i+ " = " +dict.get(i));
    }

}
} 