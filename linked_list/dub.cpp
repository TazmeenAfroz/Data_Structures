/*Q6: Given a linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
from the original list*/



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
    
    void dub()
     {
            node* curr = head;
            node* temp = NULL;
            node* prev = NULL;
            while(curr != NULL)
            {
                temp = curr->next;
                prev = curr;
                while(temp != NULL)
                {
                    if(curr->data == temp->data)
                    {
                        prev->next = temp->next;
                        delete temp;
                        temp = prev->next;
                        length--;
                    }
                    else
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                }
                curr = curr->next;
            }
     }

      };
    
   

 int main()
 {
        List l;
        
        l.insert(1,1);
        l.insert(3,2);
        l.insert(5,3);
        l.insert(3,4);
        l.insert(3,5);
        l.insert(5,6);
        l.insert(7,7);
        l.insert(7,8);
        l.insert(7,9);
        l.dub();
       
        l.display();
      
        return 0;
 }

