
/*Author Abhyuday Tripathi 201752005 */

import java.util.Scanner;
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
       System.out.println("////////// Book List (q02) //////////");
       System.out.println("1. Insert Book ");
       System.out.println("2. Remove Book From List ");
       System.out.println("3. Search for Book ");
       System.out.println("4. Check all Books");
       System.out.print("Enter your choice : ");
       int response=sc.nextInt();
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
                 price=sc.nextDouble();
                 Book_List.add(new Book(ISBN,title,price));
                 System.out.println("Added "+ title);
                 break;
        case 2: System.out.println("Enter ISBN : ");
                
                 sc.nextLine(); // clearing Scanner Buffer
                   String is=sc.nextLine();
                for(Book x: Book_List){
                    if(x.ISBN.equalsIgnoreCase(is)){
                    Book_List.removeFirstOccurrence(x);
                    System.out.println("Removed " +is);
                    break;    
                }}
                //System.out.println("Not Found !!!");
                break;

        case 3: System.out.print("Enter Title : ");
                 sc.nextLine();      // clearing Scanner Buffer  
                 String titl = sc.nextLine();
                for(Book x : Book_List){
                    if(x.title.equalsIgnoreCase(titl)){
                        System.out.println("Found : "+ x.title + " ISBN : "+x.ISBN + " Price :  "+ x.price);
                        break;
                    }
                    else
                    continue;
                    
                }
                //System.out.println("Not found !!!");
                break;
        case 4: 
            for(Book x: Book_List){
            System.out.println("Title : "+x.title + " ISBN : "+x.ISBN + " Price : "+x.price);
                           }
            break;
                
    

    }
    sc.close();
}
}
