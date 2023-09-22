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

class Cir_list
{
    node* head;
    int length;
    public:

    Cir_list()
        {
          head = NULL;
          length = 0;
        }
    ~Cir_list() 
       {
        while (head != NULL)
        {
          node* curr = head;
          head = head->next;

        if (head == curr) 
          {
           head = NULL;
          } 
        else 
          {
           node* tail = head;
        while (tail->next != curr) 
           {
             tail = tail->next;
           }
             tail->next = head;
          }

          delete curr;
          length--;
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
        node* curr = head;
        if(head == NULL)
        {
            head = n;
            head->next = head;
            
        }

        else if(pos == 1)
        {
            n->next = head;
            while(curr->next != head)
            {
                curr = curr->next;

            }
            curr->next = n;
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
            node* tail = head;
            if(pos == 1)
            {
                while(tail->next != head)
                {
                    tail = tail->next;
                }
                head = head->next;
                tail->next = head;
                if(head == head->next)
                {
                    head = NULL;
                }
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
    node* curr = NULL;
    while(curr != head)
    {
     if(curr == NULL)
     {
        curr = head;
     }
     cout << curr->data << " ";
     curr = curr->next;
    }
    cout << endl;
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





};



 int main()
 {  
  Cir_list c;
     c.insert(1,1);
       c.insert(2,2);
  c.insert(3,3);
        c.display();
    return 0;
 }
