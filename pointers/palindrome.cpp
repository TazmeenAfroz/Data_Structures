/*Write a menu driven program in which you should input a string without space
from the user, and the program should perform the following operations using
pointers:
• Check if the string is palindrome.
• Count the frequency of a certain character.*/

#include<iostream>
using namespace std;

int main()
{
    
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    int choice;
   while(choice != 3)

  { 
    cout<<"Enter 1 to check if string is palindrome"<<endl;
    cout<<"Enter 2 to count the frequency of a certain character"<<endl;
    cout<<"Enter  3 to exit "<<endl;
    cin>>choice;

       if(choice == 1)
       {
      

         char *ptr = &str[0];

         int size = str.size();

         char *ptr2 = &str[size-1];

         int flag = 0;
     
           while(ptr < ptr2)
           {
            if(*ptr != *ptr2)
             {
              flag = 1;
              break;
              }
             ptr++;
            ptr2--;

           }
    
          if(flag == 0)
           {
              cout<<"String is palindrome"<<endl;
           }
          else
          {
            cout<<"String is not palindrome"<<endl;
          }


        }


        if(choice == 2)
        { 
            char ch;
            cout<<"Enter a character: ";
            cin>>ch;
            char *ptr = &str[0];
            int count = 0;
            for(int i = 0; i < str.size(); i++)
            {
                if(*ptr == ch)
                {
                    count++;
                }
                ptr++;
          

         
          }
          cout<<"Frequency of "<<ch<<" is "<<count<<endl;

        if(choice == 3)
        {
            break;
        }
       

    
  }
}
return 0;
}