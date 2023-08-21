// Write a program in which using a 2D array store the weekly temperatures of
// a month. Each row represents a week. A visual representation is given below.
// Week 1
// Week 2
// Week 3
// Week 4

// • Populate the array using a pointer variable with random numbers (make
// use of rand() function) between 10-30 degree Centigrade.
// • Display the temperature of the whole month using a pointer.
// • Find the hottest day of each week using a pointer, and also show the
// temperature on that day.

#include<iostream>
using namespace std;

int main()
{
    int arr[4][7];
    int *ptr = &arr[0][0];
    

    for(int i = 0 ; i < 4 ; i++)
    {   
         

        for(int j = 0 ; j < 7 ; j++)
        { 
           
            *ptr = rand() % (30 + 1 - 10) + 10;
            ptr++;
        
        }
    }
 
    ptr = &arr[0][0];
    for(int i = 0 ; i < 4 ; i++)
    {   
         

        for(int j = 0 ; j < 7 ; j++)
        { 
           
            cout<<*ptr<<" ";
            ptr++;
        
        }
        cout<<endl;
    }

    ptr = &arr[0][0];
   
   for(int i = 0 ; i < 4 ; i++)
    {  int max = 0;
        for(int j= 0 ; j < 7 ;j++)
        {
            if(*ptr > max)
            {
                max = *ptr;
            }
            ptr++;
        }
        cout<< " Maximum temperature of week "<<i+1<<" is "<<max<<endl;
        }

    return 0;
    }





