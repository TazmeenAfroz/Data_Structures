#include <iostream>
using namespace std;

class Student
{
string name;
int merit;

public:
Student(string s= "",int m = 0)
{
    name = s;
    merit = m;
}


int getmerit()
{
    return merit;
}
string getName()
{ 
    return name;
}

void display()
{
    cout<<"Name : "<<name<<endl;
    cout<<"Merit : "<<merit<<endl;
}

};

class node
{
    public:
       Student data;
        node *next;

     

        node(Student val)
        {
            data = val;
            next = NULL;
        }
};

class officer1
{
  node* head;
    int length;
    public:
      officer1()
      {
          head = NULL;
          length = 0;
      }
      ~officer1()
      {
         node* curr = NULL;
         while(head != NULL)
         {  curr = head;
             head = head->next;
             delete curr;
            
         }
      }
       void enqueue(Student val)
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
            int x = head->data.getmerit();
            node* temp = head;
            head = head->next;
            delete temp;
            length--;
            return x;
        }

   
        void print()
        {
            cout<<"Total Number of students under the officer  : "<<length<<endl;
           
            node* curr = head;
            while(curr != NULL)
            {
                cout<<curr->data.getName()<<" "<<endl;
                cout<<curr->data.getmerit()<<" "<<endl;
                
                curr = curr->next;
            }
            cout<<endl;
        }
        int getlength()
        {
            return length;
        }
         
        bool empty()
        {
            if(length == 0)
            return true;
            else 
            return false;
        }

        Student peek()
        {
        if(head == NULL)
        {
        cout<<"Queue is empty"<<endl;
        return Student(); 
        }
       return head->data; 
}

};

void marks(int n)
{
    if(n > 50)
    {
        cout<<"Student is selected for admission"<<endl;
    }
    else
    {
        cout<<"Student is not selected for admission"<<endl;
    }
    cout<<endl;

}


void dequeueFromShortestToLongest( officer1& q1, officer1& q2, officer1& q3) {
    Student s1;
    while (!q1.empty() || !q2.empty() || !q3.empty()) {
        if (!q1.empty() && (q2.empty() || q1.getlength() <= q2.getlength()) && (q3.empty() || q1.getlength() <= q3.getlength())) {
            
            s1 = q1.peek();
            int x = q1.dequeue();
            cout<<"Student Name : "<<s1.getName()<<endl;
            cout<<"Student Merit : "<<s1.getmerit()<<endl;

            marks(x);

        } else if (!q2.empty() && (q3.empty() || q2.getlength()<= q3.getlength())) {
           s1 = q2.peek();
            int x = q2.dequeue();
            cout<<"Student Name : "<<s1.getName()<<endl;
            cout<<"Student Merit : "<<s1.getmerit()<<endl;
            marks(x);
          
        } else if (!q3.empty()) {
            s1 = q3.peek();
            int x = q3.dequeue();
            cout<<"Student Name : "<<s1.getName()<<endl;
            cout<<"Student Merit : "<<s1.getmerit()<<endl;
            marks(x);
        }
    }

}


int main()
{
    officer1 o1;
    officer1 o2;
    officer1 o3;
    int choice;
    while(1)
    {
        cout<<"1. Add Student to Queue: "<<endl;
        cout<<"2.Process the admission: "<<endl;
        cout<<"3.Check Queue Status: "<<endl;
        cout<<"4. See who is next: "<<endl;
        cout<<"5.EXIT"<<endl;

        cin>>choice;

        if(choice == 1)
        {   string name;
            int merit;
            cout<<"Enter the name of the student "<<endl;
            cin.ignore();
            getline(cin,name);
            cout<<"Enter the merit of the student"<<endl;
            cin>>merit;
            Student s1(name,merit);

            int length1 = o1.getlength();
            int length2 = o2.getlength();
            int length3 = o3.getlength();

            if (length1 == length2 && length1 == length3) 
                  {o1.enqueue(s1); }
            else if (length1 <= length2 && length1 <= length3) 
                  {o1.enqueue(s1); } 
            else if (length2 <= length1 && length2 <= length3) 
                  {o2.enqueue(s1); }
            else 
                  {o3.enqueue(s1);}
        }


    if (choice == 2) {
 
        dequeueFromShortestToLongest(o1, o2, o3);
}



    if(choice == 3)
    {
        cout<<"Students under the officer 1 : "<<endl;
        o1.print();
        cout<<"Students under the officer 2 : "<<endl;
        o2.print();
        cout<<"Students under the officer 3 : "<<endl;
        o3.print();
    }
   if(choice == 4)
{
    int num;
    cout << "Enter the queue number (1, 2, or 3): ";
    cin >> num;
    

    if(num == 1)
    {
        Student next = o1.peek();
        cout << "Next student in queue 1: "  << endl;
        next.display();
    }
    
    else if(num == 2)
    {
      Student next = o2.peek();
        cout << "Next student in queue 2: "  << endl;
        next.display();
    }
    else if(num == 3)
    {
        Student next = o3.peek();
        cout << "Next student in queue 3: "  << endl;
        next.display();
    }
    else
    {
        cout << "Invalid queue number.";
    }
}
if(choice == 5)
{
    cout<<"Byee"<<endl;
    return 0;
}



}
}

 
