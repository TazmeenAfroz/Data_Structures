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
            cout << "Stack is Empty" << endl;
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

bool digit(char c)
{
   if(c >= '0' && c <= '9')
   {
       return true;
   }
    return false;
}

int evaluatePostfix(string p)
{
    List s;
    int i = 0;
    while (i < p.length()) {
        if (digit(p[i]) || (p[i] == '-' && i + 1 < p.length() && digit(p[i + 1]))) {
          
            int sign = 1;
            if (p[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            while (i < p.length() && digit(p[i])) {
                num = num * 10 + (p[i] - '0');
                i++;
            }
            s.push(sign * num);
        } else if (p[i] != ' ') {
            
            int op1 = s.pop();
            int op2 = s.pop();
            switch(p[i])
            {
                case '+':
                    s.push(op2 + op1);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                case '*':
                    s.push(op2 * op1);
                    break;
                case '/':
                    if (op1 == 0) {
                        cout << "Division by zero" << endl;
                        return 0; 
                    }
                    s.push(op2 / op1);
                    break;
                case '^':
                    if (op2 == 0 && op1 == 0) {
                        cout << "0 ^ 0 is undefined" << endl;
                        return 0; 
                    }
                    s.push(pow(op2, op1));
                    break;
                case '%':
                    if (op1 == 0) {
                        cout << "Modulo by zero" << endl;
                        return 0; 
                    }
                    s.push(op2 % op1);
                    break;
                
            }
            i++;
        } else {
         
            i++;
        }
    }
    return s.pop();
}



int main()
{
    string p = "25 4 -2 * + 7 -"; // here -2 is a negative number
    string q = "100 200 + 2 / -5 * 7 +"; // here -5 is a negative number
    string r = "2 3 ^ 4 + ";
    string s = "9 4 % 5 +";
    string t = "6 2 3 + - 3 8 2 / + * 2 ^ 3 +";
    string u = "10 0 / 10 0 % 10 0 ^ 10 0 * 10 0 + 10 0 -";
    cout << evaluatePostfix(p) << endl;
    cout << evaluatePostfix(q) << endl;
    cout << evaluatePostfix(r) << endl;
    cout << evaluatePostfix(s) << endl;
    cout<<  evaluatePostfix(t) << endl;
    cout << evaluatePostfix(u) << endl;
    return 0;
}
