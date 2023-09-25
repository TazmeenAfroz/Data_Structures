//merge two sorted list in sorted form

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
    
    void sorted_merge(List& l1,List& l2)
    {
        node* curr1 = l1.head;
        node* curr2 = l2.head;
        while(curr1 != NULL && curr2 != NULL)
        {
            if(curr1->data < curr2->data)
            {
                insert(curr1->data,length+1);
                curr1 = curr1->next;
            }
            else
            {
                insert(curr2->data,length+1);
                curr2 = curr2->next;
            }
        }
        while(curr1 != NULL)
        {
            insert(curr1->data,length+1);
            curr1 = curr1->next;
        }
        while(curr2 != NULL)
        {
            insert(curr2->data,length+1);
            curr2 = curr2->next;
        }
    }

      };
    
   

 int main()
 {
        List l;
        List l2;
        List l3;
        l.insert(1,1);
        l.insert(3,2);
        l.insert(5,3);
        
        l2.insert(2,1);
        l2.insert(4,2);
        l2.insert(6,3);
        l.display();
        l2.display();
        l3.sorted_merge(l,l2);
        l3.display();
        return 0;
 }

