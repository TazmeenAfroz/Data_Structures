
#include <iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
        node *prev;

        node(int val)
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
           if(head != NULL)
            
                head->prev = n;
            
            head = n;
        }
        else
        {
            node* curr = head;

            for(int i = 1 ; i < pos - 1 ; i++)
             {
                curr = curr->next;
             }
             n->prev = curr;
             n->next = curr->next;
                if(curr->next != NULL)
                {
                    curr->next->prev = n;
                }
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
                if(head != NULL)
                {
                    head->prev = NULL;
                }
                delete curr;
            }
            else
            {
                for(int i = 1 ; i < pos ; i++)
                {
                    curr = curr->next;
                }
                curr->prev->next = curr->next;
                if(curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
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
        node* curr = head;
        while(curr != NULL)
        {
            l.insert(curr->data,l.len()+1);
            curr = curr->next;
        }
    }
    

      };

 int main()
 {
        List l;
        l.insert(10,1);
        l.insert(20,2);
        l.insert(30,3);
        l.insert(40,4);
        l.insert(50,5);
        l.remove(1);
        l.rem_val(40);
        l.display();
        cout<<l.find(30)<<endl;
        cout<<l.len()<<endl;
        List l1;
        l.copy(l1);
        l1.display();
        l.clear();
        l.display();
        l1.display();
        
        return 0;
 }