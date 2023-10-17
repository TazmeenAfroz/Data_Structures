/*When you were a kid, you are might have played a game of musical chairs, where
there are let’s say 5 children and 4 seats. The game involves children walking around
the seats while music plays and trying to find a seat when the music stops. The child
who fails to occupy a chair when the music stops is eliminated from the game, and
then one seat is removed. This process continues until only one child remains as the
winner.
• You will simulate this game using a single circular linked list data structure in
C++. Each child participating in the game will be represented as a node in the
single circular linked list. The linked list will be circular to simulate the
continuous movement of children around the seats.
• Now actually you have to simulate this by creating 5 nodes initializing the list
with the names of the players (hard coded using call to insert method).
• In the main menu you have two choices. Traverse the players one by one, and
start game.
• Traverse the players one by one: Straight forwardly display the names in the
list one by one, according to the user choice. See sample output.
• Start game: Start the game, and hen in each round you will generate a random
no between 1 to current length of the list, and the node (player) at the position
will be removed from the list. Note in each round, display the random no
generated, player who is removed, and also display the current players in the
game. In the end show the winner.*/
#include<iostream>
using namespace std;

class node
{
    public:
    char data;
    node *next;
    node(char d)
    {
        data=d;
        next=NULL;
    }

};

class circularList
{
    node *head;
    int length;
    public:
    circularList()
    {
        head=NULL;
        length=0;
    }
    ~circularList()
    {
        node *temp=head;
        while(temp->next!=head)
        {
            node *temp1=temp;
            temp=temp->next;
            delete temp1;
        }
        delete temp;
    }
   
    void insert(char d,int pos)
    {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node*  n = new node(d);
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
    void display()
    {
         if(length == 0)
        {
            cout<<"empty";
        }
        node *temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }

    void deleteNode(int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node* curr = head;
        if(pos == 1)
        {
            while(curr->next != head)
            {
                curr = curr->next;
            }
            node* temp = head;
            head = head->next;
            curr->next = head;
            delete temp;
        }
        else
        {
            for(int i = 1 ; i < pos - 1 ; i++)
            {
                curr = curr->next;
            }
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        length--;
    }
   
   int findValue(char value)
   { 
     node* curr = head;
     for(int i = 1 ; i <= length ; i++)
     {
         if(curr->data == value)
         {
             return i;
         }
         curr = curr->next;
     }
        return -1;
   }

 void rem_value(char d)
 {
    int pos = findValue(d);
    if(pos == -1)
    {
        cout<<"Value not found"<<endl;
        return;
    }
    deleteNode(pos);

 }
  
void round(int N,int K)
{
    node* curr = head;
    
    for (int i = 1; i < K; i++)
        {
            curr = curr->next;
        }

        node* nextNode = curr->next;
        char val = curr->data;
        curr = nextNode;
        rem_value(val);
      
        cout << val << " is out" << endl;
        cout<<endl;
        display();

}


void startGame()
{
    
    while(length > 1)
    {
        int n = rand() % length + 1;
        cout<<"Random number is "<<n<<endl;
        round(length,n);
    }
    cout<<"The winner is "<<head->data<<endl;
}

void transverselist()
{
    node* curr = head;
    cout<<curr->data<<" ";
    int choice;
    cout<<"1.Next"<<endl;
    cout<<"2.exit"<<endl;
    cin>>choice;
    while(choice != 2)
    {
        curr = curr->next;
        cout<<curr->data<<" ";
        cout<<"1.Next"<<endl;
        cout<<"2.exit"<<endl;
        cin>>choice;
    }
}

};

int main()
{   
    circularList c;
    int N;
    c.insert('A',1);
    c.insert('B',2);
    c.insert('C',3);
    c.insert('D',4);
    c.insert('E',5);
    c.insert('F',6);
    c.insert('G',7);

int choice;
while(1)
{
  cout<<"1.Transverse the list"<<endl;  
  cout<<"2.Start the game"<<endl;
    cout<<"3.Exit"<<endl;
cin>>choice;
if(choice == 1)
{
    c.transverselist();
}
else if(choice == 2)
{
    c.startGame();
}
else if(choice == 3)
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

  
