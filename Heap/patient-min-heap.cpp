#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    string name;
    int urgency;

    Patient(string name, int urgency) {
        this->name=name;
        this->urgency=urgency;
    }
};

class Heap {
public:
    vector<Patient> htree;

    int getParent(int child) 
    {
        if(child == 0)
        {
            return -1;
        }
    
        return (child-1)/2;

    }

    int getLeft(int parent) {

       if((2*parent)+1 >= htree.size())
         {
              return -1;
            }

        return (2*parent)+1;

        

        
    }

    int getRight(int parent) {
        if((2*parent)+2 >=htree.size())
         {
              return -1;
            }


        return (2*parent)+2;
        
    }

    void swap(Patient *a, Patient *b) {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        if (node == 0) {
            return;
        }
      
        int parent = getParent(node);
     
        if (parent!=-1 && htree[node].urgency < htree[parent].urgency) {
            swap(&htree[node], &htree[parent]);
            heapifyUp(parent);
        }



    }
    

   
    void heapifyDown(int node) {
        
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;
        if(left != -1 && htree[left].urgency < htree[smallest].urgency)
        {
            smallest = left;
        }
        if(right != -1 && htree[right].urgency < htree[smallest].urgency)
        {
            smallest = right;
        }
        if(smallest != node)
        {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }

    
}


    void insert(Patient patient) 
    {
        htree.push_back(patient);
        heapifyUp(htree.size()-1);

    }

    void del() {
        if (htree.empty()) {
            cout << "No appointments to delete." << endl;
            return;
        }
        swap(&htree[0], &htree[htree.size()-1]);
        htree.pop_back();
        heapifyDown(0);

        
    }
    void del(int node)
    {
       
        swap(&htree[node], &htree[htree.size()-1]);
        htree.pop_back();
        heapifyDown(node);
        
    }

   void updateUrgency(string patientName, int newUrgency) 
   {
    for(int i = 0 ; i < htree.size(); i++)
    {
        if(htree[i].name == patientName)
        {
           del(i);
           insert(Patient(patientName,newUrgency));
           return ;
        }
       
       
    }
   cout<<"Patient not found";
      
    
}
    void display() {
        if (htree.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main() {
    Heap priorityQueue;
   int choice;
    string name;
    int urgency;

    while (true) {
        cout << "1. Add a patient" << endl;
        cout << "2. Delete a patient" << endl;
        cout << "3. Update urgency of a patient" << endl;
        cout << "4. Display all patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter urgency: ";
                cin >> urgency;
                priorityQueue.insert(Patient(name, urgency));
                break;
            case 2:
                priorityQueue.del();
                break;
            case 3:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter new urgency: ";
                cin >> urgency;
                priorityQueue.updateUrgency(name, urgency);
                break;
            case 4:
                priorityQueue.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
