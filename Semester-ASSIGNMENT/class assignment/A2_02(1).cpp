#include <iostream>
#include <math.h>
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
    node *top;
    int length;

public:
    List()
    {
        top = NULL;
        length = 0;
    }
    ~List()
    {
        node *curr = NULL;
        while (top != NULL)
        {
            curr = top;
            top = top->next;
            delete curr;
        }
    }

    void push(int val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
        length++;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        node *curr = top;
        int val = curr->data;
        top = top->next;
        delete curr;
        length--;
        return val;
    }

    int peak()
    {
        if (top == NULL)
        {
         
            return -1;
        }
        return top->data;
    }

    void display()
    {
        node *curr = top;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

bool parthesisMatch(string p)
{
    List l;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(' || p[i] == '[' || p[i] == '{' || p[i] == '<')
        {
            l.push(p[i]);
        }
        else if (p[i] == ')' || p[i] == ']' || p[i] == '}' || p[i] == '>')
        {
            if (l.peak() == -1)
            {
                return false; 
                
            }


            if (p[i] == ')' && l.peak() == '(')
            {
                l.pop();
            }
            else if (p[i] == ']' && l.peak() == '[')
            {
                l.pop();
            }
            else if (p[i] == '}' && l.peak() == '{')
            {
                l.pop();
            }
            else if (p[i] == '>' && l.peak() == '<')
            {
                l.pop();
            }

            else
            {
                return false; 
                
            }
        }
    }


    if(l.peak() == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}




int main()
{ 
    string p = "(){()}[{}[]{}({{{()}()}})]";
   
    string p1 = "({)}";
    string p2 = " {()}{[[<{}>]]}[[]]";
    string p3 = "<{()}>";
 

    cout<<parthesisMatch(p)<<endl;
    cout<<parthesisMatch(p1)<<endl;
    cout<<parthesisMatch(p2)<<endl;
    cout<<parthesisMatch(p3)<<endl;
    
    
    return 0;
}
