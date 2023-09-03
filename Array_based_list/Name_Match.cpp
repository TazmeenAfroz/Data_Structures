

#include<iostream>
#include<string>
using namespace std;

class Name
{
    char *arr;
    char *curr;
    int capacity;
    int length;
    public:
    Name(int c);
    ~Name();
    void next();
    void back();
    void start();
    void tail();
    void insert(char val,int pos);
    void remove(int pos);
    void print();
    int check();
    int match();


};
int Name::check()
{ int flag;
    if(capacity == length)
    {
        cout<<"FULL";
        
        flag = 1;
    }
    return flag;
}


Name::Name(int c)
{
  capacity = c;
  arr = new char[c];
  curr = arr;
  length = 0;
}
Name::~Name()
{
    delete []arr;
}

void Name::next()
{
    curr++;
}

void Name::back()
{
    curr--;
}

void Name::start()
{
    curr = arr;
}

void Name::tail(){
    curr = arr + length-1;
}

void Name::insert(char val, int pos)
{
    if(capacity == length)
    {
        cout<<"FULL";
        return;
    }
    
    if(1 > pos || pos > length + 1){
        cout<<"INVALID";
        return;
    }
    tail();
    
    for(int i = length; i >= pos ; i--){
        *(curr + 1) = *curr;
         back();

    }
    *(curr+1)= val;
    length++;

}
void Name::remove(int pos)
{
    
    
    if(1 > pos || pos > length) {
        cout<<"INVALID";
        return;
    }
    
    start();
    curr = arr + pos -1;
    for(int i = pos;i < length ; i++)
    {
        *curr = *(curr+1);
        next();

    }
    length--;

}

int Name::match()
{
    string s;
    int flag = 0; 
    start();
    
    for (int i = 0; i < length; i++)
    {
      
        s += *curr; 
        next();
    }
    
    if (s == "fariba") 
    {
        flag = 1;
    }
    
    return flag;
}

void Name::print()
{  
    start();
    
    for (int i = 1; i <= length; i++)
    {
        cout << *curr;
        
        if (i != length)
        {
            next(); 
        }
    }
    
    cout << endl; 
}


int main()
{
    Name l1(6);
    l1.insert('e',1);
    l1.insert('f',2);
    l1.insert('a',3);
    l1.insert('b',4);
    l1.insert('i',5);
    l1.insert('r',6);
   while(1)
   { 
    
     l1.print();
      if(l1.match() == 1)
      { cout<<"Congrats"<<endl;
      return 0;

      }
    int choice;
    cout<<"Enter an option:"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Remove"<<endl;

    cin>>choice;
    if(choice == 1 && l1.check() != 1)
    {   
        cout<<"Enter the position on which u want to insert"<<endl;
        int pos; 
        cin>>pos;
        cout<<"Enter the char u want to insert"<<endl;
        char c;
        cin>>c;
        l1.insert(c,pos);

    }
    else if(choice == 2)
    {
        cout<<"Enter the position u want to remove"<<endl;
        int pos;
        cin >>pos;
        l1.remove(pos);
    }

    

}
}
