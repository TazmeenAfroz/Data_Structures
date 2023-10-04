#include <iostream>
using namespace std;
class node
{
    public:
        string data;
        node *next;

        node(string val)
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
       void enqueue(string val)
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


        string dequeue()
        {
            if(head == NULL)
            {
                cout<<"No more pending sales"<<endl;
                return "";
            }
            string x = head->data;
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

 bool isempty()
 {
     if(head == NULL)
     {
         return true;
     }
     else
     {
         return false;
     }
 }

};
 int main()
 { 
     Queue ticket;
     Queue Roller;
     Queue MotionRide;
     Queue RoundWheel;

     while(true)
     {
        cout<<endl;
        int choice;
        cout<<"1.Enter a visitor in the waiting list queue"<<endl;
        cout<<"2. Sell a ticket to the next visitor in the waiting list queue"<<endl;
        cout<<"3.Process all queues"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1)
        {
            string name;
            cout<<"Enter the name of the visitor: ";
            cin.ignore();
            getline(cin,name);
            ticket.enqueue(name);
            cout<<name<<" is now waiting in the waiting list queue"<<endl;

        }
        else if(choice == 2)
        {
            string name = ticket.dequeue();
            if(name != "")
            {
                cout<<name<<" is sent to the ticket counter"<<endl;
            

            int choice2;
            cout<<"Which ticket do " <<name<<" want to buy?"<<endl;
            cout<<"1. Roller Coaster"<<endl;
            cout<<"2. Motion Ride"<<endl;
            cout<<"3. Round Wheel"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice2;
            if(choice2 == 1)
            {
                Roller.enqueue(name);
                cout<<name<<" is now waiting in the Roller Coaster queue"<<endl;

            }
            else if(choice2 == 2)
            {
                MotionRide.enqueue(name);
                cout<<name<<" is now waiting in the Motion Ride queue"<<endl;

            }
            else if(choice2 == 3)
            {
                RoundWheel.enqueue(name);
                cout<<name<<" is now waiting in the Round Wheel queue"<<endl;

            }
            else
            {
                cout<<"Invalid choice"<<endl;
            }
            }

     }
      else if(choice == 3)
        {   
           while(Roller.isempty() == false)
           {
               string name = Roller.dequeue();
               cout<<name<<" is now enjoying the Roller Coaster"<<endl;
           }
              while(MotionRide.isempty() == false)
              {
                string name = MotionRide.dequeue();
                cout<<name<<" is now enjoying the Motion Ride"<<endl;
              }
                while(RoundWheel.isempty() == false)
                {
                    string name = RoundWheel.dequeue();
                    cout<<name<<" is now enjoying the Round Wheel"<<endl;
                }
                
          
        }
    
        else if(choice == 4)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
        }
        
        return 0;
 }
