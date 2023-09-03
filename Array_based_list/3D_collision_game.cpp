
#include <iostream>
using namespace std;

void print(char *ptr) 
    {    
        ptr = ptr - 4;
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<*ptr<<" ";
                ptr++;
            }
            cout<<endl;
        }
    }
 void top(char *ptr)
 {
       ptr = ptr - 3;

    if(*ptr == 'x')
    {
        cout<<"You lost, it was a collision object"<<endl;
        ptr = ptr + 3;
        print(ptr);
        exit(0);
    }

   else if(*ptr == '-')
   {
    cout<<"You are safe"<<endl;
     ptr = ptr + 3;
    print(ptr);
    exit(0);
   }
   

 }


 void bottom(char *ptr)
    {
        ptr = ptr + 3;
    
        if(*ptr == 'x')
        {
            cout<<"You lost, it was a collision object"<<endl;
            ptr = ptr - 3;
            print(ptr);
            exit(0);
        }
    
    else if(*ptr == '-')
    {
        cout<<"You are safe"<<endl;
        ptr = ptr - 3;
        print(ptr);
        exit(0);
    }
  
    
    }

    void left(char *ptr)
    {
        ptr = ptr - 1;
    
        if(*ptr == 'x')
        {
            cout<<"You lost, it was a collision object"<<endl;
            ptr = ptr + 1;
            print(ptr);
            exit(0);
        }
    
    else if(*ptr == '-')
    {
        cout<<"You are safe"<<endl;
         ptr = ptr + 1;
        print(ptr);
        exit(0);
    }
    
    
    }


    void right(char *ptr)
    {
        ptr = ptr + 1;
    
        if(*ptr == 'x')
        {
            cout<<"You lost, it was a collision object"<<endl;
            ptr = ptr - 1;
            print(ptr);
            exit(0);
        }
    
    else if(*ptr == '-')
    {
        cout<<"You are safe"<<endl;
           ptr = ptr - 1;
        print(ptr);
        exit(0);
    }
    
    }

    
int main()
{

  char arr[3][3];
    char *ptr;
  
    ptr = &arr[0][0];
   
    
 

  for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
              *ptr = rand()%10 + '0';
               if(*ptr == '1' || *ptr == '2' || *ptr == '3' || *ptr == '9')
               {
                   *ptr = 'x';
               }
               else
                {
                     *ptr = '-';
                }
              ptr++;    

            
            
        }

    }

    ptr = &arr[0][0];
    ptr = ptr + 4;
    *ptr = 'o';

  
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"1. Top"<<endl;
    cout<<"2. Bottom"<<endl;
    cout<<"3. Left"<<endl;
    cout<<"4. Right"<<endl;
    cin>>choice;

  
    if(choice == 1) 
    {
        top(ptr);
        print(ptr);
    }
    else if(choice == 2)
    {
        bottom(ptr);
        print(ptr);
    }

    else if(choice == 3)
    {
        left(ptr);
        print(ptr);
    }

    else if(choice == 4)
    {
        right(ptr);
        print(ptr);
    }


        return 0;
    }