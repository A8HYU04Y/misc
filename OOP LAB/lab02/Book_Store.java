/* author Abhyuday Tripathi 201752005 */
import java.util.HashMap;
public class Book_Store{
    public static void main(String[] args){
     HashMap<String,Book> book_store=new HashMap<>();
     //putting books in book_store
     book_store.put("HPEQ123",new Book("HPEQ123","Harry Potter : And The Philosopher's Stone",345.0));
     book_store.put("HPEQ111",new Book("HPEQ111","Harry Potter : And The Chamber Of Secrets",375.25));
     book_store.put("HPEQ112",new Book("HPEQ112","Harry Potter : And THe Prisoner of Azkaban",408.50));
     book_store.put("HPEQ132",new Book("HPEQ132","Harry Potter : And The Goblet Of Fire",425.75));
     book_store.put("HPEQ222",new Book("HPEQ222","Harry Potter : And The Order Of Pheonix",520.0));
     book_store.put("HPEQ333",new Book("HPEQ333","Harry Potter : And The Half Blood Prince",610.5));
     book_store.put("HPEQ321",new Book("HPEQ321","Harry Potter : The Deathly Hallows Part 1",745.0));
     book_store.put("HPEQ213",new Book("HPEQ213","Harry Potter : The Deathly Hallows Part 2",850.75));
     book_store.put("WERT34",new Book("WERT34","The Alchemist",166.5));
     book_store.put("TAGR1CH",new Book("TAGR1CH","Think And Grow Rich",75.0));
     //searching books
     System.out.println(book_store.get("HPEQ123").title)  ; //Harry Potter : And Philosopher's Stone
     System.out.println(book_store.get("HPEQ111").title); //Harry Potter : And The Chamber Of Secrets
    //removing books
    book_store.remove("HPEQ111");//Removes Harry Potter : And The Chamber Of Secrets
    book_store.remove("HPEQ123"); // Removes Harry Potter : And Philosopher's Stone
    
    //using printAll Books
    printAllBooks(book_store);
    }
public static void printAllBooks(HashMap<String,Book> bk){
    for(String x : bk.keySet()){
        System.out.println("ISBN : "+bk.get(x).getIsbn()+ " | Title : "+bk.get(x).title + " | Price : "+bk.get(x).getPrice() );
    }
}

}
