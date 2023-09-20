#include<iostream>
using namespace std;

class Stack
{
    char *arr;
    int top;
    int capacity;
    public:
    Stack(int c = 0)
    {
        arr = new char[c];
        top = -1;
        capacity = c;
    }
    ~Stack()
    {
        delete [] arr;
    }
    bool isFull()
    {
        if(top+1 == capacity)
            return true;
        
        return false;
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        
        return false;
    }
    void push(char val)
    {
        if(isFull())
        {
         cout<<"StackOverflow";
            return;
        }
        top++;
        arr[top] = val;
    }

    char pop()
    {
        if(isEmpty())
        {
            cout<<"StackUnderflow";
            return -1;
        }
        char val = arr[top];
        top--;
        return val;
    }

    int peak()
    {
        if(isEmpty())
        {
            cout<<"List is Empty";
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        for(int i = 0; i<=top; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

int main()
{
   
   string s = "Tazmeen Afroz";
   
    Stack st(s.length());

    for(int i = 0 ; i < s.length() ; i++)
    {
        st.push(s[i]);
    }

       for(int i = 0 ; i < s.length() ; i++)
    {
        s[i] = st.pop();
    }

    cout<<s<<endl;


    

  return 0;
    
}