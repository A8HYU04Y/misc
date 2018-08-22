/* Created by Abhyuday Tripathi

    06.08.2018
*/
package lab01;
import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;
import lab01.primeChecker;
import java.util.Random;
import lab01.BubbleSortString;
import lab01.CSVExtractor;
import java.io.File;
import java.io.IOException;
//import java.lang.*;
public class Main  {
    public static void main(String[] args)throws IOException{
     Scanner scn = new Scanner(System.in);
     int choice=0;
     System.out.println("////////////////////////////////////////////");
     System.out.println("                                           /");
     System.out.println(" 1. primeChecker (Q01)                     /");
     System.out.println(" 2. CSVExtractor (Q02)                     /");
     System.out.println(" 3. DataReverser (Q03)                     /");
     System.out.println(" 4. FrequecyCounter (Q04)                  /");
     System.out.println(" 5. BubbleSortString (Q05)                 /");
     System.out.println(" 6. CSVReader (Q06)                        /");
     System.out.println("                                           /");
     System.out.println("////////////////////////////////////////////");
     System.out.print("Enter Your Choice : ");
     choice =scn.nextInt();
     switch(choice){
         case 1: System.out.println("\n//////// PrimeChecker (q01) ////////");
                primeChecker p = new primeChecker();
                System.out.print("\nEnter The Number : ");
                int data=scn.nextInt();
                p.primeCheck(data);
                break;
         case 2:System.out.println("\n//////// CSVExtractor (q02) ////////");
                CSVExtractor csv = new CSVExtractor();
                System.out.print("\nEnter the comma seperated double string : ");
                scn.nextLine();//clearing buffer 
                String ds=scn.nextLine();
                csv.extract(ds);
                break;
         
         case 3:System.out.println("\n//////// DataReverser (q03) ////////");
                DataReverser dR = new DataReverser();
                int length=0;
                System.out.println("\nEnter length of array :  ");
                length=scn.nextInt();
                System.out.println("Provide Elements one by one (INTEGER) : ");
                int[] arr= new int[length];
                for(int i=0;i<length;i++){
                    arr[i]=scn.nextInt();
                }
                dR.reverse(arr);
        
                break;
         case 4:
                System.out.println("//////// FrequencyCounter ////////");
                FrequencyCounter counter=new FrequencyCounter();
                Random rand=new Random();
                ArrayList<Integer> sample= new ArrayList<Integer>();
                for(int m=0;m<100;m++){
                    sample.add(m,rand.nextInt(11));
                }
                System.out.println("Random Array : ");
                System.out.println("---------------------------------------");

                for(int x: sample){
                    System.out.print(x+ "  ");
                }
                System.out.println();
                System.out.println("---------------------------------------");

                System.out.println("Counter : ");
                System.out.println("---------------------------------------");
                 counter.countElements(sample);     
                 break;
               
         case 5:
                System.out.println("//////// BubbleSortString ////////");
                scn.nextLine();
                System.out.println("Enter the Unsorted String Array (Space Seperated):");
                String[] daa=scn.nextLine().split(" ");
                BubbleSortString sorter = new BubbleSortString();
                sorter.sort(daa);
                System.out.println("Sorted Array : ");
                for(String x: daa){
                    System.out.print(x + " ");
                }
                      break;    
         case 6: System.out.println("\n//////// CSVReader (q06) ////////");
                 System.out.print("\n Provide CSV File Path (cpi.csv):");
                 scn.nextLine();
                 String path=scn.nextLine();
                 File file = new File(path);
                 CSVReader reader = new CSVReader();
                 System.out.println("1. To Check Student with maximum CPI");
                 System.out.println("2. To Check Average CPI");
                 System.out.println("3. To Check Students above Average CPI");
                 System.out.println("Choose Option : ");
                 int response=scn.nextInt();
                 switch(response){
                     case 1: reader.maxScore(file);
                     break;
                     case 2: System.out.println("Average CPI :  " +new DecimalFormat("#0.00").format(reader.averageScore(file))); //decimal precision
                     break;
                     case 3: reader.aboveAverage(file);
                     break;
                     default :
                     break;
                 }
                 break;
                 
                default:

                      break;                        
     }
           scn.close();
    }
}
