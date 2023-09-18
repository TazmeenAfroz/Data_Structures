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

class Song
{
    node* head;
    int length;
    public:
      Song()
      {
          head = NULL;
          length = 0;
      }
      ~Song()
      {
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

      void insert(string val,int pos)
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
            
        }

        else if(pos == 1)
        {
            n->next = head;
            while(curr->next != head)
            {
                curr = curr->next;

            }
            curr->next = n;
            head = n;
        }
        else
        {
            node* curr = head;
            for(int i = 1 ; i < pos - 1 ; i++)
             {
                  curr = curr->next;
             }
             n->next = curr->next;
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
            if(pos == 1)
            {
                while(tail->next != head)
                {
                    tail = tail->next;
                }
                head = head->next;
                tail->next = head;
                if(head == head->next)
                {
                    head = NULL;
                }
                delete curr;
            }
            else
            {
                node* slow = NULL;
                for(int i = 1 ; i < pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
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
         cout<<"Enter the name of the song u want to add"<<endl;
            string val2;

            cin.ignore();
            getline(cin,val2);

           
         update(val2,pos);

    }

 void playlist()
 {
        node* curr = head;
        while(curr != NULL)
        {
            cout<<"Now playing "<<curr->data<<endl;
            cout<<"Wanna  play  the next song "<<endl;
            cout<<"1. Yes"<<endl;
            cout<<"2. No"<<endl;

            int choice;
            cin>>choice;
            if(choice == 1)
            {
                curr = curr->next;
            }
            else
            {
                cout<<"Your playlist is over"<<endl;
                break;
            }
            
        }
 }


      };

 int main()
 {
        Song s1;
        while(1)
        {   int choice;
            cout<<"YOur favourite Playlist"<<endl;
            cout<<"Select an option"<<endl;
            cout<<"1. Add a song"<<endl;
            cout<<"2. Delete a song"<<endl;
            cout<<"3. Display all songs"<<endl;
            cout<<"4.Search a song"<<endl;
            cout<<"5. Update a song"<<endl;
            cout<<"6. Start playlist"<<endl;
            cout<<"7. Exit"<<endl;
            cin>>choice;

            if(choice == 1)
            {
                cout<<"Enter the name of the song"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                cout<<"How much favourite it is?"<<endl;
                cout<<"1. Top Fav"<<endl;
                cout<<"2. least Fav"<<endl;
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
                cout<<"Enter the name of the song you want to delete"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                s1.rem_val(name);
            }

            if(choice == 3)
            {
                s1.display();

            }
            
            if(choice == 4)
            {
                cout<<"Enter the name of the song you want to search"<<endl;
                string name;
                cin.ignore();
                getline(cin,name);
                int pos = s1.find(name);
                if(pos == -1)
                {
                    cout<<"Song not found"<<endl;
                }
                else
                {
                    cout<<"Song found at position "<<pos<<endl;
                    
                }
            }

            if(choice == 5)
            {   string nam;
                cout<<"Enter the name of the song you want to update"<<endl;
                cin.ignore();
                getline(cin,nam);

                s1.update_by_name(nam);
            }

            if(choice == 6)
            {
                cout<<"Your playlist is ready"<<endl;
                
                cout<<"Now playing........"<<endl;

                s1.playlist();
                 


                
            }

            if(choice == 7)
            {
                break;
            }

        }
        
        return 0;
 }