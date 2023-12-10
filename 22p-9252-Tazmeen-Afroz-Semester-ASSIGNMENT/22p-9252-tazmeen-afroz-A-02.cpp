#include<iostream>
#include<math.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;
    public:
    Stack(int c)
    {
        arr = new int[c];
        top = -1;
        capacity = c;
    }
    bool isFull()
    {
        if(top+1 == capacity)
            return true;
        
        return false;
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        
        return false;
    }
    void push(int val)
    {
        if(isFull())
        {
         cout<<"StackOverflow";
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"StackUnderflow";
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    int peak()
    {
        if(isEmpty())
        {
            
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        for(int i = 0; i<=top; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};           

void moveDisks(Stack& src, Stack& dest)
{
    int disk1 = src.peak();
    int disk2 = dest.peak();

    if (disk1 == -1)
    {
        int p = dest.pop();
        src.push(p);
    }
    else if (disk2 == -1)
    {
        int p = src.pop();
        dest.push(p);
    }
    else if (disk1 > disk2)
    {
        int p = dest.pop();
        src.push(p);
    }
    else
    {
        int p = src.pop();
        dest.push(p);
    }
}

void harnoi(int n, Stack& s1, Stack& s2, Stack& s3)
{
    Stack *dest;
    Stack *aux;

    if(n % 2 == 0)
    {
        dest = &s2;
        aux = &s3;
    }
    else
    {
        dest = &s3;
        aux = &s2;
    }

    int totalMoves = pow(2, n) - 1;

    for(int i = n; i >= 1; i--)
    {
        s1.push(i);
    }

    for(int i = 1; i <= totalMoves; i++)
    {
        if(i % 3 == 1)
            moveDisks(s1, *dest);
        else if(i % 3 == 2)
            moveDisks(s1, *aux);
        else if(i % 3 == 0)
            moveDisks(*aux, *dest);
    }
}


int main()
{
    cout<<"Enter the number of disks "<<endl;
    int n;
    cin>>n;
    Stack s1(n);
    Stack s2(n);
    Stack s3(n);



    harnoi(n, s1, s2, s3);

   
    cout<<"Stack 3: ";
    s3.display();


    return 0;
}
