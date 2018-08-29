
/*Author Abhyuday Tripathi 201752005 */

import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.LinkedList;
public class Linked_List_Demo{
    public static void main(String[] args){
      Scanner sc=new Scanner(System.in);
        LinkedList<Book> Book_List=new LinkedList<>();
       // inserting books to the linkedList 
       Book_List.add(new Book("HPEQ123","Harry Potter : And The Philosopher's Stone",345.0));
       Book_List.add(new Book("HPEQ111","Harry Potter : And The Chamber Of Secrets",375.25));
       Book_List.add(new Book("HPEQ112","Harry Potter : And THe Prisoner of Azkaban",408.50));
       Book_List.add(new Book("HPEQ132","Harry Potter : And The Goblet Of Fire",425.75));
       Book_List.add(new Book("HPEQ222","Harry Potter : And The Order Of Pheonix",520.0));
       Book_List.add(new Book("HPEQ333","Harry Potter : And The Half Blood Prince",610.5));
       Book_List.add(new Book("HPEQ321","Harry Potter : The Deathly Hallows Part 1",745.0));
       Book_List.add(new Book("HPEQ213","Harry Potter : The Deathly Hallows Part 2",850.75));
       Book_List.add(new Book("abcd123","RAW",45));
       
       while(true){
       System.out.println("////////// Book List //////////");
       System.out.println("1. Insert Book ");
       System.out.println("2. Remove Book From List ");
       System.out.println("3. Search for Book ");
       System.out.println("4. Check all Books");
       System.out.print("Enter your choice : ");
       int response=0;
        try{
       	 response=sc.nextInt();
        }
       	 
        catch(InputMismatchException e){
       	 System.out.println("(Wrong Choice) Closing !!!");
         System.exit(1);
        }
    switch(response){
        case 1:  String title="";
                 String ISBN="";
                 double price=0.0;
                 sc.nextLine();
                 System.out.print("Enter the title : ");
                 title=sc.nextLine();
                 System.out.print("Enter ISBN : ");
                 ISBN=sc.nextLine();
                 System.out.print("Enter Price : ");
                 try{
                 price=sc.nextDouble();
                 Book_List.add(new Book(ISBN,title,price));
                 System.out.println("Added "+ title);
                 sc.nextLine();
                 break;}
                 catch(InputMismatchException e){
                 	System.out.println("(Invailid Price) :: Book can't be added ");
                    sc.nextLine();
                 	break;
                 }
        case 2: System.out.println("Enter ISBN : ");
                
                 sc.nextLine(); // clearing Scanner Buffer
                   Book target=new Book();
                   String is=sc.nextLine();
                for(Book x: Book_List){
                    if(x.ISBN.equalsIgnoreCase(is)){
                    target=x;
                    break;    
                }}
                
                if(target.ISBN!=null){ 
                Book_List.removeFirstOccurrence(target);
                System.out.println("Removed " +target.ISBN);
                 break;}
                else{
                 	System.out.println("Error :: Book Not Found !!!");
                 	break;
                }

        case 3: System.out.print("Enter Title : ");
                 sc.nextLine();      // clearing Scanner Buffer  
                 Book targetT=new Book();
                 String titl = sc.nextLine();
                for(Book x : Book_List){
                    if(x.title.equalsIgnoreCase(titl)){
                        targetT=x;
                        break;
                    }
                    else
                    continue;
                    }
                if(targetT.title!=null){
                   System.out.println("Found : "+ targetT.title + " ISBN : "+targetT.ISBN + " Price :  "+ targetT.price);
                   break;}
                System.out.println("Not found !!!");
                break;
        case 4: 
            for(Book x: Book_List){
            System.out.println("Title : "+x.title + " ISBN : "+x.ISBN + " Price : "+x.price);
                           }
            sc.nextLine();
            break;
        default : System.out.println("(Wrong Choice) Try Again !!! ");
                  sc.nextLine();
                  break;            
    
    }
System.out.println("------------------------------------------------------------");    
System.out.println("Do you want to continue ??");
System.out.println("------------------------------------------------------------");    

if(sc.nextLine().equalsIgnoreCase("y")){
	System.out.println("------------------------------------------------------------");    
	continue;}
else
break;
}
sc.close();
    }
   
}

