#include<iostream>
using namespace std;

class List
{
    int *arr;
    int *curr;
    int capacity;
    int length;
    public:
    List(int c);
    ~List();
    void next();
    void back();
    void start();
    void tail();
    void insert(int val,int pos);
    void remove(int pos);
    void print();
    int find(int val);
    int get(int pos);
    void update(int val, int pos);
    void copy(List &l);
    void clear();
    bool isEmpty();
    bool isFull();

};

List::List(int c)
{
  capacity = c;
  arr = new int[c];
  curr = arr;
  length = 0;
}
List::~List()
{
    delete []arr;
}

void List::next()
{
    curr++;
}

void List::back()
{
    curr--;
}

void List::start()
{
    curr = arr;
}

void List::tail(){
    curr = arr + length-1;
}

void List::insert(int val, int pos)
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
void List:: remove(int pos)
{
    if(length == 0)
    {
        cout<<"EMPTY";
        return;
    }

    if(1 > pos || pos > length){
        cout<<"INVALID";
        return;
    }
    start();
    for(int i = 1; i < pos; i++)
    {
        next();
    }
        for(int i = pos; i < length; i++)
        {
            *curr = *(curr+1);
            curr++;
        }
        length--;
    

}

int List::find(int val)
{
    start();
    for(int i = 1; i <= length; i++)
    {
        if(*curr == val)
        {
            return i;
        }
        next();
    }
    return -1;
}

void List::print()
{
    start();
    for(int i = 1; i <= length; i++)
    {
        cout<<*curr<<" ";
        next();
    }
    cout<<endl;
}

void List::update(int val, int pos)
{
    if(1 > pos || pos > length){
        cout<<"INVALID";
        return;
    }
    start();
    curr += pos - 1;    
    *curr = val;
}
int List::get(int pos)
{
    if(1 > pos || pos > length){
        cout<<"INVALID";
        return -1;
    }
    start();
    curr += pos - 1;    
    return *curr;
}

void List::copy(List &l)
{   
    start();
  
    length = l.length;
    for(int i = 1; i <= length; i++)
    {
        *curr = l.get(i);
        next();
        
    }
    
}

void List::clear()
{
    length = 0;
}

bool List::isEmpty()
{
    return length == 0;
}

bool List::isFull()
{
    return length == capacity;
}

class Stack : public List
{
    int top;
    public:
    Stack(int c):List(c)
    {
        top = 0;
    }
    
    void push(int val)
    {
        if(isFull())
        {
            cout<<"StackOverflow";
            return;
        }

        top++;
        insert(val, top);

    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout<<"StackUnderflow";
            return -1;
        }
        int val = get(top);
        remove(top);
        top--;
        return val;
    }
    
    int peak()
    {
        if(isEmpty())
        {
            cout<<"List is empty";
            return -1;
        }
        return get(top);
    }

    void print()
    {
        List::print();
    }

};
int main()
{
  
   Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.print();
    cout<<s.peak();
    return 0;


    

}