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
      ~List() {
    while (head != NULL) {
        node* curr = head;
        head = head->next;

        if (head == curr) {
           
            head = NULL;
        } else {
            
            node* tail = head;
            while (tail->next != curr) {
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
            head->prev = head;
            
        }

        else if(pos == 1)
        {
            n->next = head;
            if(head != NULL)
            {
                head->prev = n;
            }
              while(curr->next != head)
            {
                curr = curr->next;

            }
            curr->next = n;
            n->prev = curr;

            
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
            node* tail = head;
    if (pos == 1) {
        
        node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        if (head == head->next) {
            head = NULL;
        }
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
    node* curr = NULL;
  while(curr != head){
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
   
   void copy(List& l) {
    node* curr = l.head;
    do {
        if (curr == NULL) {
            curr = l.head;
        }
        insert(curr->data, length + 1); // Insert into the current object
        curr = curr->next;
    } while (curr != l.head);
}

    

      };

 int main()
 {
        List l;
        l.insert(30,1);
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
        l1.copy(l);
        l1.display();
        l.clear();
        l.display();
        l1.display();
        
        return 0;
 }