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

      void insert(int val,int pos)
      {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node*  n = new node(val);

        if(pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node* curr = head;
            for(int i = 1 ; i < pos - 1 ; i++)
             {
                  curr = curr->next;
             }
             n->next = curr->next;
                curr->next = n;
        }
        length++;
        }
        void remove(int pos)
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(pos < 1 || pos > length)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            node* curr = head;
            if(pos == 1)
            {
                head = head->next;
                delete curr;
            }
            else
            {
                node* slow = NULL;
                for(int i = 1 ; i < pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                delete curr;

            }
            length--;
        }
    int find(int val)
        {
            node* curr = head;
            for(int i = 1 ; i <= length ; i++)
             {
                    if(curr->data == val)
                    {
                        return  i;
                    }
                    curr = curr->next;


             }
                return -1;
        }
    void rem_val(int val)
    { 
        int pos = find(val);
        if(pos == -1)
        {
            cout<<"Value not found"<<endl;
            return;
        }
        remove(pos);
    }

    void display()
    {
        node* curr = head;
        while(curr != NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    void clear()
    {
        while(head != NULL)
        {
           remove(1);

        }
    }
    int len()
    {
        return length;
    }
   
    void copy(List& l)
    {
        node* curr = l.head;
        while(curr != NULL)
        {
            insert(curr->data,length+1);
            curr = curr->next;
        }
    }
    int get(int pos)
    {
        if(1 > pos || pos > length){
            cout<<"INVALID";
            return -1;
        }
        node* curr = head;
        for(int i = 1 ; i < pos ; i++)
        {
            curr = curr->next;
        }
        return curr->data;

    }
    
     bool isEmpty()
        {
            if(len() == 0)
                return true;
            
            return false;
        }
        

      };
    
    class Stack : public List
    {
        public:
        Stack()
        {
            List();
        }
        void push(int val)
        {
            insert(val,1);
        }
        int pop()
        {
            if(isEmpty())
            {
                cout<<"StackUnderflow";
                return -1;
            }
            int val = get(1);
            remove(1);
            return val;
        }
        int peak()
        {
            return get(1);
        }
        void display()
        {
            List::display();
        }
       
    };
 int main()
 {
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.display();
        cout<<s.pop()<<endl;
        s.display();
        cout<<s.peak()<<endl;
        

      
        
        return 0;
 }