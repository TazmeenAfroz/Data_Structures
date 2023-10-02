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

class Queue
{
 node* head;
    int length;
    public:
      Queue()
      {
          head = NULL;
          length = 0;
      }
      ~Queue()
      {
         node* curr = NULL;
         while(head != NULL)
         {  curr = head;
             head = head->next;
             delete curr;
            
         }
      }
       void enqueue(int val)
{ 
    node* n = new node(val);
    if (head == NULL) {
        head = n;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    length++;
}


        int dequeue()
        {
            if(head == NULL)
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int x = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            length--;
            return x;
        }
   
        void print()
        {
            node* curr = head;
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
        Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.print();
        
        return 0;
 }
