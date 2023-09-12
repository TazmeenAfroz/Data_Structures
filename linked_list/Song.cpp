/*Create a menu-driven music playlist manager program using a singly linked list to manage your
favorite songs. Each song in the playlist will have a name.
The program should offer the following options:
• Add a Song: When the user adds a song, the program should ask the name of the song,
after that the user will be prompted to specify its "favorite level." They can choose from
the following options:
1. (Top Favorite): The song will be inserted at the beginning of the playlist.
2. (Lease Favorite): The song will be inserted at the end of the playlist.
3. Somewhere between (let me specify the number): If the user selects a custom
favorite level (e.g., 2 to 4), the program will display valid priority levels based
on the current number of songs in the playlist (e.g., 2 to 5 for a playlist of 5
songs). The song will be inserted at the specified custom priority position.
• Delete a Song: Users can remove a song from the playlist by entering its name/ position
(depends on you).
• Search for a Song: Users can search for a song by its name and display the name and
level of how much favorite it is.
• Update a song name: Thie function will take the song number, and the new name, and
update the song name on that position.
• Print Playlist: This option will display the entire playlist with song names.
• Play Song: Users can start playing songs from the beginning of the playlist. When the
user clicks on Play Song, play the first song in the list. After that the user can select the
option of play next song, so the program will play the next song from the list (just a
simulation by displaying the song name.
• Exit: Exit the program.
Note: After each insertion, update, or removal operation, print the playlist. Your program
should have all the checks for invalid input. The update song option is not showed in the
sample output, but you must implement it in your code, and display the menu accordingly.*/
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
                cout<<"Song list is empty"<<endl;
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
        node* curr = head;
        int i =1;
        while(curr != NULL)
        { 
            cout<<i<<curr->data<<" "<<endl;
            curr = curr->next;
            i++;
        }
        cout<<endl;
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
