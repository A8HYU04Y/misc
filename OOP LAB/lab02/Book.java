public class Book{
    String ISBN;
    double price;
    String title;
    Book(){}
    Book(String isbn,String title,double price){
        this.ISBN=isbn;
        this.title=title;
        this.price=price;
    }
    public String getIsbn(){
        return this.ISBN;
    }
    public double getPrice(){
        return this.price;
    }
    public void setIsbn(String isbn){
        this.ISBN=isbn;
    }
    public void setPrice(double price){
        this.price=price;
    }
    public void setTitle(String title){
        this.title=title;
    }
    public boolean equals(Book bk){
        if(this.ISBN==bk.ISBN && this.title==bk.title && this.price==bk.price )
        return true;
        return false;
    }
    
    
    }
