#include <iostream>
using namespace std;
class node
{
    public:
        char data;
        node *next;

        node(char val)
        {
            data = val;
            next = NULL;
        }
};

class Stack
{
    node* top;
    int length;
    public:
     Stack()
      {
          top = NULL;
          length = 0;
      }
      ~Stack()
      {
         node* curr = NULL;
         while(top != NULL)
         {  curr = top;
             top = top->next;
             delete curr;
            
         }
      }

        void push(char val)
        {
            node*  n = new node(val);
            n->next = top;
            top = n;
            length++;
        }

        int pop()
        {
            if(top == NULL)
            {
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            node* curr = top;
            char val = curr->data;
            top = top->next;
            delete curr;
            length--;
            return val;
        }
        int peak()
        {
            if(top == NULL)
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            return top->data;
        }

        void display()
        {
            node* curr = top;
            while(curr != NULL)
            {
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<endl;

        }


      bool isEmpty()
      {
          if(top == NULL)
          {
              cout<<"Stack is Empty"<<endl;
                return true;
          }
            return false;
      }
       

};

void r_display(Stack &s)
{
    if(s.isEmpty())
    {
        return;
    }
    char val = s.pop();
    r_display(s);
    cout<<val<<" ";
    s.push(val);
}
 
int main()
{
   Stack s;
   Stack s1;
   string str;
    cout<<"Enter a string: ";
    cin>>str;
     for(int i = 0 ; i < str.length() ; i++)
    {
        s.push(str[i]);
    }
  
   
  
   int choice;
   
     while(1)

     {  cout<<endl;
         cout<<"1. undo "<<endl;
         cout<<"2. Redo"<<endl;
         cout<<"3. Exit"<<endl;
         cout<<"Enter your choice: ";
            cin>>choice;

        if(choice == 1)
        {
            if(s.isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                s1.push(s.pop());
                cout<<"Undo"<<endl;
            }
        }
        else if(choice == 2)
        {
            if(s1.isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                s.push(s1.pop());
                cout<<"Redo"<<endl;
            }
        }
        else if(choice == 3)
        {
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }


        cout<<"Current String: ";
        r_display(s);
}

    return 0;
    }