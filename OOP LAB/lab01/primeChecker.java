package lab01;
//import java.util.*;

public class primeChecker{
    private boolean IsPrime(int data){
        if(data==0 || data==1)
        return false;
        for(int i=2;i<data;i++){
            if(data%i==0)
            return false;
        }
    return true;}
    public void primeCheck(int data){
        if(IsPrime(data))
        System.out.println(data +" is Prime.");
        else
        System.out.println(data +" is NOT Prime.");
    }
}
