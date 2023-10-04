#include <iostream>
using namespace std;

class Queue
{
    int front, rear, length;
    int capacity;
    string* arr;

public:
Queue(int s)
{
    capacity = s;
    front = 0;
    rear = -1;
    arr = new string[s];
    length = 0;
}
~Queue()
{
    delete[] arr;
}
void enqueue(string x)
{
    if(length == capacity)
    {
        cout<<"Can't take more patients"<<endl;
        return;
    }
    if(rear == capacity-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    arr[rear] = x;
    length++;
}

string dequeue()
{
    if(length == 0)
    {
        cout<<"No patients in the waiting list"<<endl;
        return "";
    }
    string x = arr[front];
    if(front == capacity-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    length--;

    return x;
}

void print()
{
    if(length == 0)
    {
        cout<<"No more patients"<<endl;
        return;
    }
    int index = front;
    for(int i = 0 ; i < length ; i++)
    {
        cout<<arr[index]<<" ";
        if(index == capacity-1)
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }
    cout<<endl;

}

string peek()
{
    if(length == 0)
    {
        cout<<"No more patients"<<endl;
        return "";
    }
    return arr[front];

}

};

int main()
{
   cout<<"Enter the available number of seats: ";
    int n;
    cin>>n;
    Queue q(n);
  
    while(1)
    {   cout<<endl;
        cout<<"1. Add a patient to the queue"<<endl;
        cout<<"2.Send next patient to doctor"<<endl;
        cout<<"3. See who is next"<<endl;
        cout<<"4. Display all patients"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice == 1)
        {
           cout<<"Enter the name of the patient:";
           string name;
           cin.ignore();
           getline(cin,name);
           q.enqueue(name);
           cout<<name<<" is now waiting in the queue"<<endl;

        }
        else if(choice == 2)
        {
            string name = q.dequeue();
            if(name != "")
            {
                cout<<name<<" is sent to the doctor"<<endl;
            }


        }

        else if(choice == 3)
        {
            string name = q.peek();
            if(name != "")
            {
                cout<<name<<" is next in the queue"<<endl;
            }
        }
        else if(choice == 4)
        {
            q.print();
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }

    }
}

