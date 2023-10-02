#include <iostream>
using namespace std;

class Queue
{
    int front, rear, length;
    int capacity;
    int* arr;

public:
Queue(int s)
{
    capacity = s;
    front = 0;
    rear = -1;
    arr = new int[s];
    length = 0;
}
~Queue()
{
    delete[] arr;
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
    if(length == 0)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int x = arr[front];
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
        cout<<"Queue is empty"<<endl;
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



};

int main()
{
    Queue q(5);
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