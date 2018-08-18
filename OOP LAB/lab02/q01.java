/* Author Abhyuday Tripathi 201752005 */


import java.util.*;
public class q01{
public static double[] normalize(double[] arr){
    double avg= 0.0;
    for(Double x: arr)
        avg+=x;
    avg=avg/(double)arr.length;
    double[] normal=new double[arr.length];
    double SD=0.0;
    for(int i=0;i<arr.length;i++)
    SD+=Math.pow(arr[i]-avg,2);
    SD=Math.sqrt(SD/arr.length-1);
    
    for(int i=0;i<normal.length;i++)
    normal[i]=(arr[i]-avg)/SD;
    return normal;
}
public static double[] stats(double[] arr){
    ArrayList<Double> n=new ArrayList<>();
    
    double avg=0.0;
    for(double x: arr)
    avg+=x;
    avg=avg/arr.length;
    double SD=0.0;
    for(int i=0;i<arr.length;i++)
    SD+=Math.pow(arr[i]-avg,2);
      Arrays.sort(arr);
    double median=0.0;
      if(arr.length%2==0)
      median=(arr[arr.length/2]+arr[arr.length/2]+1)/2;
      else
      median =arr[(arr.length+1)/2];
      double data[]={avg,SD,median};
      return data;      

}
public static void main(String[] args){
    Random rd=new Random();
    double[] arr=new double[10];
    for(int i=0;i<10;i++){
        arr[i]=(double)rd.nextInt(50);
    }
    System.out.println("Random double Array :  ");
    for(int i=0;i<10;i++)
    System.out.print(arr[i] + "  ");
    System.out.println("\nNormalised Array : ");
    for(int i=0;i<10;i++)
     System.out.print(normalize(arr)[i] + "  ");
    System.out.println();
    System.out.println("Average : " + stats(arr)[0]);
    System.out.println("SD : " + stats(arr)[1]);
    System.out.println("Median : " + stats(arr)[2]);
}
}