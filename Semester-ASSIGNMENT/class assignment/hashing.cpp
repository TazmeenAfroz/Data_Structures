#include <iostream>
using namespace std;

void rehash();
class Hash {
private:
    int size;
    int num;

    struct node {
        int value;
    };
    node** hash;

    int hashFunction(int value) {
        return value % size;
    }
    
    void insertWithoutRehash(int value) {
        int index = hashFunction(value);

        while (hash[index] != NULL && hash[index]->value != -1) {
            index = (index + 1) % size;
        }

        hash[index] = new node{value};
        num++;
    }

public:
   Hash(int size) {
        this->size = size;
        this->num = 0;
        this->hash = new node*[size]();
    }

   
    ~Hash() {
        for (int i = 0; i < size; i++) {
            delete hash[i];
        }
        delete[] hash;
    }

    void insert(int value) {
        if ((float)num / size > 0.7) {
            rehash();
        }

        insertWithoutRehash(value);
    }
    void print() {
    for (int i = 0; i < size; i++) {
        if (hash[i] != NULL && hash[i]->value != -1) {
            cout << "Index: " << i << ", Value: " << hash[i]->value << endl;
        }
    }
}

void rehash() {
    cout << "Before rehashing:" << endl;
    print();

    int oldSize = size;
    size = 2 * size;

    node** prev = hash;
    hash = new node*[size]();

    for (int i = 0; i < oldSize; i++) {
        if (prev[i] != NULL && prev[i]->value != -1) {
            insertWithoutRehash(prev[i]->value);
        }
        delete prev[i];
    }

    delete[] prev;

    cout << "After rehashing:" << endl;
    cout<<"SIze becomes "<<size<<endl;
    print();
}


};

int main() {
    Hash h(10);
    cout<<"Table size is 10"<<endl;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(90);
    

    
  
}



