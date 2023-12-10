#include<iostream>
using namespace std;

class Date
{
    int date;
    int month;
    int year;
public:
Date(int d = 1, int m = 1, int y = 1)
{
   if(d>0 && d<32)
   {
       date=d;
   }
   else
   {
       cout<<"Invalid Date"<<endl;
   }
   if(m>0 && m<13)
   {
       month=m;
   }
   else
   {
       cout<<"Invalid Month"<<endl;
   }

    if(y>0)
    {
         year=y;
    }
    else
    {
         cout<<"Invalid Year"<<endl;
    }
}

int getday()
{
    return date;
}
int getmonth()
{
    return month;
}
int getyear()
{
    return year;
}


};

class Book
{
int ISBN;
string title;
string author;
Date date;
string genre;
public:

Book(int i=0,string t="",string a="",string g="",int d= 1,int m = 1,int y= 1):date(d,m,y)
{
    ISBN=i;
    title=t;
    author=a;
    genre=g;

}

int getISBN()
{
    return ISBN;
}   
string gettitle()
{
    return title;
}
string getauthor()
{
    return author;
}
string getgenre()
{
    return genre;
}
Date getdate()
{
    return date;
}




};

class node
{
    public:
       
        Book data;
        node *next;
        node *prev;

       node(Book val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }


};


class List
{
    node* head;
    int length;
    public:
      List()
      {
          head = NULL;
          length = 0;
      }
      ~List()
      {
         node* curr = NULL;
         while(head != NULL)
         {  curr = head;
             head = head->next;
             delete curr;
            
         }
      }

bool comparedates(Book date1,Book date2)
{
      if(date1.getdate().getmonth() == date2.getdate().getmonth() && date1.getdate().getday() == date2.getdate().getday() && date1.getdate().getyear() == date2.getdate().getyear())
        {
             return true;
        }

    else  if (date1.getdate().getyear() > date2.getdate().getyear()) {
        return true;
    } else if (date1.getdate().getyear() == date2.getdate().getyear()) {
        if (date1.getdate().getmonth() > date2.getdate().getmonth()) {
            return true;
        } else if (date1.getdate().getmonth() == date2.getdate().getmonth()) {
            if (date1.getdate().getday()> date2.getdate().getday()) {
                return true;
            }
        }
        
    }
    return false;






}

void insert(Book val)
{
    node* n = new node(val);
    
    if (head == NULL) {
        n->next = head;
        if (head != NULL)
            head->prev = n;
        head = n;
    } else {
        node* curr = head;
        while (curr != NULL && comparedates(val, curr->data)) {
            curr = curr->next;
        }
        
        if (curr == NULL) {
           
            node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = n;
            n->prev = last;
        } else {
            
            n->next = curr;
            n->prev = curr->prev;
             if (curr->prev != NULL) {
                curr->prev->next = n;
             } 
             else {
                head = n;
            }
            curr->prev = n;
        }
    }
}

bool search(int isbn)
{  
    node *temp = head;
    while(temp!= NULL)
    { 
        if(temp->data.getISBN() == isbn)
        {   cout<<"Book found"<<endl;
            return true;
        }
        temp = temp->next;

    }
    return false;

}

void filter(string author)
{ 
    node* temp = head; 
     cout<<" *Books by the author* " <<author<<endl;
    while(temp != NULL)
    {  
        if(temp->data.getauthor() == author) 
        { 
            cout << temp->data.gettitle() << endl; 
           
        }
         temp = temp->next;
}
        
}
string getGenre(string bookName)
{
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data.gettitle() == bookName)
        {
            return temp->data.getgenre();
        }
        temp = temp->next;
    }
    return "";
}
void relatedbooks(string bookName)
{
    string genre = getGenre(bookName);
    if(genre == "")
    {
        cout << "Book not found." << endl;
        return;
    }

    node* temp = head; 
    int count = 0;
    cout<<"* Related books to "<<bookName <<"*"<< endl;
    while(temp != NULL && count < 3)
    {
        if(temp->data.getgenre() == genre && temp->data.gettitle() != bookName) 
        {   
            cout << temp->data.gettitle() << endl; 
            count++;
        }
        temp = temp->next;
    }
}

 void deleteBook(int isbn)
        {
            if(head == NULL)
            {
                cout << "List is empty." << endl;
                return;
            }

            if(head->data.getISBN() == isbn)
            {
                node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            node* temp = head;
            while(temp->next != NULL && temp->next->data.getISBN() != isbn)
            {
                temp = temp->next;
            }

            if(temp->next == NULL)
            {
                cout << "Book not found." << endl;
                return;
            }

            node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete ;
        }
void display()
{
    node* curr = head;
    while(curr != NULL)
    {   
        cout << "------------------------" << endl;
        cout << "Title: " << curr->data.gettitle() << endl;
        cout << "Author: " << curr->data.getauthor() << endl;
        cout << "Date: " << curr->data.getdate().getday()<<"/"  << curr->data.getdate().getmonth() <<"/"<< curr->data.getdate().getyear()<< endl;
        cout << "Genre: " << curr->data.getgenre() << endl;
        cout << "ISBN: " << curr->data.getISBN() << endl;
        cout << "------------------------" << endl;
        curr = curr->next;
    }
}
};

int main()
{
    List l1;
    int choice;
    while(1)
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Search Book"<<endl;
        cout<<"3. Filter Books by Author"<<endl;
        cout<<"4. Display Books"<<endl;
        cout<<"5. Delete Book"<<endl;
        cout<<"6. Recommend Related Books"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            int isbn;
            string title;
            string author;
            string genre;
            int day;
            int month;
            int year;
            cout<<"Enter ISBN"<<endl;
            cin>>isbn;
            cout<<"Enter Title"<<endl;
            cin>>title;
            cout<<"Enter Author"<<endl;
            cin>>author;
            cout<<"Enter Genre"<<endl;
            cin>>genre;
            cout<<"Enter Date"<<endl;
            cin>>day;
            cin>>month;
            cin>>year;
            Book b(isbn,title,author,genre,day,month,year);
            l1.insert(b);
        }
        else if(choice == 2)
        {
            int isbn;
            cout<<"Enter ISBN"<<endl;
            cin>>isbn;
            if(l1.search(isbn) == false)
            {
                cout<<"Book not found"<<endl;
            }
        }
        else if(choice == 3)
        {
            string author;
            cout<<"Enter Author"<<endl;
            cin>>author;
            l1.filter(author);
        }
        else if(choice == 4)
        {
            l1.display();
        }
        else if(choice == 5)
        {
            int isbn;
            cout<<"Enter ISBN"<<endl;
            cin>>isbn;
            l1.deleteBook(isbn);
        }
        else if(choice == 6)
        {
            string bookName;
            cout<<"Enter Book Name"<<endl;
            cin>>bookName;
            l1.relatedbooks(bookName);
        }
        else if(choice == 7)
        {
            break;
        }
    }

}