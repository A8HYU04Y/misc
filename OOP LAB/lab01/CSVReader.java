package lab01;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
public class CSVReader{
    
        public void maxScore(File file)throws IOException{
            
            PrintStream print = new PrintStream(System.out);
            
            try{
            Scanner scan= new Scanner(file);}
            catch(FileNotFoundEcxeption){ System.out.println("File Not Found !!!! ");           }
        ArrayList<String> contents=new ArrayList<String>();
        int index=0;

        while(scan.hasNextLine()){
         String line = scan.nextLine();
         contents.add(index, line);
        // System.out.println(contents.get(index));        
         index++;}
            Double max=0.0;
            String name="";
            String ID="";

            for(String x : contents){
                if(Double.parseDouble(x.split(",")[2])>max){
                    name=x.split(",")[1];
                    ID=x.split(",")[0];
                    max=Double.parseDouble(x.split(",")[2]);
                }
                else
                continue;}
            print.println("----------------------------");
                print.println("ID : " + ID);
            print.println("Name : " + name);
            print.println("CPI : " + max);    
                
           
            }
            public double averageScore(File file)throws IOException{
                PrintStream print = new PrintStream(System.out);
                Scanner scan= new Scanner(file);
            ArrayList<String> contents=new ArrayList<String>();
            int index=0;
    
            while(scan.hasNextLine()){
             String line = scan.nextLine();
             contents.add(index, line);
            // System.out.println(contents.get(index));        
             index++;}
             Double score=0.0;
             for(String x:contents){
                 score+=Double.parseDouble(x.split(",")[2]);
             }
             return score/(double)contents.size();
            }

            public void aboveAverage(File file)throws IOException{
                PrintStream print = new PrintStream(System.out);
                Scanner scan= new Scanner(file);
            ArrayList<String> contents=new ArrayList<String>();
            int index=0;
            while(scan.hasNextLine()){
             String line = scan.nextLine();
             contents.add(index, line);
            // System.out.println(contents.get(index));        
             index++;}
             double avg=averageScore(file);
             for(String x: contents){
                 if(Double.parseDouble(x.split(",")[2])>avg){
                     print.println("ID : " + x.split(",")[0]);
                     print.println("Name : " + x.split(",")[1]);
                     print.println("CPI : " + x.split(",")[2]);
                     print.println("----------------------------------------");

                }
                else{
                    continue;
                }
             }

            }
        }
