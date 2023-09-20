
#include <iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;

        node(int val)
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

        void push(int val)
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
            int val = curr->data;
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

};

int main()
{
   Stack s;
   int a,b;
   cout<<"Enter two numbers"<<endl;
   cin>>a>>b;
   cout<<"Before swapping"<<endl;
   
   cout<<"a is "<<a<<"  b is "<<b<<endl;
   
   s.push(a);
   s.push(b);

   a = s.pop();
   b = s.pop();

   cout<<"After Swapping"<<endl;
   cout<<"a is "<<a<<"  b is "<<b<<endl;

  return 0;
    
}