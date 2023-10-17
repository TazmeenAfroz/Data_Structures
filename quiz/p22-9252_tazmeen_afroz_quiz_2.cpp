/*As a cave explorer you are going to enter in a dark cave, design a stack-based escape
plan for an adventurer. The adventurer enters the cave and moves forward. He uses
a stack to mark his path as he explores the cave. He must push the current location
in the stack before moving forward, so that when he sees a ghost, he can go back to
these points so that he does not get lost and find their way back to the exit. Implement
stack using linked list.*/
#include<iostream>
using namespace std;

class node
{
    public:
    char data;
    node *next;
    node(char d)
    {
        data=d;
        next=NULL;
    }

};

class Stack
{
    node* head;
    int length;
    public:
    Stack()
    {
        head=NULL;
        length=0;
    }
    ~Stack()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            node *temp1=temp;
            temp=temp->next;
            delete temp1;
        }
    }

    void insert(char d)
    {
       node *n=new node(d);
       if(head == NULL)
       {
         head = n;
         head->next = NULL;

       }
         else
         {
            n->next = head;
            head = n;
         }
            length++;
    }

    char pop()
    {
        if(length == 0)
        {
            cout<<"Stack underflow"<<endl;
            return -1;

        }
        char val = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        length--;
        return val;


    }

    char top()
    {
        if(length == 0)
        {
            cout<<"empty"<<endl;
            return -1;
        }
        else

        return head->data;
    }

  void clear()
   {
    while(length != 0)
    {
       cout<<"you are now at  "<< pop()<<"    "<<endl;
    }
   }

};

int main()
{
    Stack s;
    cout<<"Welcome to the cave"<<endl;

    int choice;
    while(1)
    {
        cout<<"Choose"<<endl;
        cout<<"1.move forward"<<endl;
        cout<<"2.Go Back"<<endl;
        cout<<"3.Run i saw a ghost"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Mark your location"<<endl;
            char data;
            cin>>data;
            s.insert(data);

        }

        if(choice == 2)
        {
            cout<<"You are going back"<<endl;
            cout<<"you are at "<<s.pop()<<endl;
          
            

        }
        if(choice == 3)
        {
            
            s.clear();
            cout<<"You successfully ran out of the cave"<<endl;
            break;

        }

    }

}
