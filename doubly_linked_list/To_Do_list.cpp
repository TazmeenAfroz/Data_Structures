
#include <iostream>
using namespace std;
class node
{
    public:
        string data;
        node *next;
        node *prev;
        bool check;

        node(string val)
        {
            data = val;
            next = NULL;
            prev = NULL;
            check = false;
        }
};


class Todo
{
    node* head;
    int length;
    public:
      Todo()
      {
          head = NULL;
          length = 0;
          
      }
      ~Todo()
      {
         node* curr = NULL;
         while(head != NULL)
         {  curr = head;
             head = head->next;
             delete curr;
            
         }
      }
 void insert(string val,int pos)
      {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node*  n = new node(val);

        if(pos == 1)
        {
            n->next = head;
           if(head != NULL)
            
                head->prev = n;
            
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
            if(pos == 1)
            {
                head = head->next;
                if(head != NULL)
                {
                    head->prev = NULL;
                }
                delete curr;
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
    int find(string val)
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
    void rem_val(string val)
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
        cout<<"Choose your priority order (1 for top to bottom and 2 for bottom to top)"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1)
        {
        node* curr = head;
        int i =1;
        string comp = "Not Completed";
         
 
        while(curr != NULL)
        { 
        if(curr->check == true)
        {
            comp = "Completed";
            
        }
       
           
        
            cout<<i<<curr->data<<" - "<<comp<<endl;
            curr = curr->next;
            i++;
             comp = "Not Completed";
        }
        cout<<endl;
        }
        else
        {
            node* curr = head;
            int i = length;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            while(curr != NULL)
            {
                cout<<i<<curr->data<<" "<<endl;
                curr = curr->prev;
                i--;
            }
            cout<<endl;
        }
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
   
  
    void update(string val,int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node* curr = head;
        for(int i = 1 ; i < pos ; i++)
        {
            curr = curr->next;
        }
        curr->data = val;
    }
    void update_by_name(string val)
    {

        int pos = find(val);
        if(pos == -1)
        {
            cout<<"Value not found"<<endl;
            return;
        }
         cout<<"Enter the name of the Todo u want to add"<<endl;
            string val2;

            cin.ignore();
            getline(cin,val2);

           
         update(val2,pos);

    }

    void completed(string val)
    {
        int pos = find(val);
        if(pos == -1)
        {
            cout<<"Value not found"<<endl;
            return;
        }
        node* curr = head;
        for(int i = 1 ; i < pos ; i++)
        {
            curr = curr->next;
        }
        curr->check = true;


    }
    void rem_completed()
    {
         node* curr = head;
                while(curr != NULL)
                {
                    if(curr->check == true)
                    {
                       rem_val(curr->data);
                    }
                    curr = curr->next;
                }
    }


      };

 int main()
 {
        Todo s1;
        while(1)
        {   int choice;
            cout<<"YOur TO_DO LIST"<<endl;
            cout<<"Select an option"<<endl;
            cout<<"1. Add a Task"<<endl;
            cout<<"2. Remove completed tasks"<<endl;
            cout<<"3. Mark a Task as completed"<<endl;
            cout<<"4. Update a Task"<<endl;
            
            cout<<"5. Display list"<<endl;
            cout<<"6.Search a task"<<endl;
            cout<<"7. Exit"<<endl;
            cin>>choice;

            if(choice == 1)
            {
                cout<<"Enter the name of the Todo"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                cout<<"Enter the priority level?"<<endl;
                cout<<"1. Add to Top"<<endl;
                cout<<"2. Add to end"<<endl;
                cout<<"3. Somewhere between it. let me specify the number"<<endl;
                int pos;
                cin>>pos;

                if(pos == 3)
                {
                     cout<<"Valid positions are 2 to "<<s1.len()<<endl;
                    cin>>pos;

                }
                else if(pos == 2)
                {
                    pos = s1.len()+1;


                }
                cin.ignore();
                s1.insert(name,pos);


            }

            if(choice == 2)
            {
               
                s1.rem_completed();
            }

            if(choice == 3)
            {
                s1.display();
                cout<<"Enter the name of the Task you want to mark as completed"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                s1.completed(name);



            }
            
            

            if(choice == 4)
            {   string nam;
                cout<<"Enter the name of the Todo you want to update"<<endl;
                cin.ignore();
                getline(cin,nam);

                s1.update_by_name(nam);
            }

            if(choice == 5)
            {
                s1.display();
                
                 


                
            }

            if(choice == 6)
            {
                cout<<"Enter the name of the Todo you want to search"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                int pos = s1.find(name);
                if(pos == -1)
                {
                    cout<<"Todo not found"<<endl;
                }
                else
                {
                    cout<<"Todo found at position "<<pos<<endl;
                    
                }
            }

            if(choice == 7)
            {
                break;
            }

        }
        
        return 0;
 }