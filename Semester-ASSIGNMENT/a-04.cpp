#include<iostream>
#include<string>

using namespace std;
struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}
class node
{
    public:
        int info;
        string name;
        string designation;
        node *left;
        node *right;
        int height;
        
    node(int val,string n,string d)
    {
        info = val;
        name = n;
        designation = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
   
};

class Tree
{  public:
    int length;
    node *root;
   
        Tree()
        {
            length = 0;
            root = NULL;
        }
        
        ~Tree()
        {
            deleteTree(root);
        }

int getbalance(node *n)
{
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

void deleteTree(node* leaf)
{
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}



int max(int a, int b)
{
    return (a > b)? a : b;
}
node *leftRotate(node *x)
{
    node *y = x->right;
    node *t = y->left;
 
    y->left = x;
    x->right = t;
 
   
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    return y;

}
node *rightRotate(node *y)
{
    node *x = y->left;
    node *t = x->right;
 
    x->right = y;
    y->left = t;
 
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    return x;
}

node* insert(node* curr,int val,string n,string d)
{
 if(curr == NULL)
   {
    return new node(val,n,d);
   }

 if(val < curr->info)
   {
    curr->left = insert(curr->left,val,n,d);
    
   }
 else if(val > curr->info)
   {
    curr->right = insert(curr->right,val,n,d);
    
   }
    else
    return curr;

    curr->height = 1 + max(height(curr->left),
                           height(curr->right));
    int balance = getbalance(curr);

    if(balance < -1 && val > curr->right->info)
    {   
        return leftRotate(curr);
    }
    if(balance > 1 && val < curr->left->info)
    {
        return rightRotate(curr);
     }
     if(balance < -1 && val < curr->right->info)
     {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
     if(balance > 1 && val > curr->left->info)
    {
       curr->left = leftRotate(curr->left);
         return rightRotate(curr);
     }

    return curr;
}

 
void preOrder(node *n)
{
    if(n == NULL)
        return;
 
   cout<<"Employee ID\t";
    cout<<n->info<<"\t";
    cout<<endl;
    cout<<"Employee Name\t";
    cout<<n->name<<"\t";
    cout<<endl;
    cout<<n->designation<<"\t";
    cout<<endl;
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;
    
    inOrder(n->left);
    cout<<"Employee ID\t";
    cout<<n->info<<"\t";
    cout<<endl;
    cout<<"Employee Name\t";
    cout<<n->name<<"\t";
    cout<<endl;
    cout<<n->designation<<"\t";
    cout<<endl;

   
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
     
     cout<<"Employee ID\t";
    cout<<n->info<<"\t";
    cout<<endl;
    cout<<"Employee Name\t";
    cout<<n->name<<"\t";
    cout<<endl;
    cout<<n->designation<<"\t";
    cout<<endl;
   
}

node* search(node * curr,int val)
{
    if(curr == NULL)
        return NULL;
    if(curr->info == val)
        return curr;
    else if(val < curr->info)
        return search(curr->left,val);
    else
        return search(curr->right,val);

}
node* find(node *n, int val)
{
    if(n == NULL)
        return NULL;
    if(n->info == val)
        return n;
    else
    {
        node *t = NULL;
        t = find(n->left, val);
        if(t!= NULL)
            return t;
        else
        {
            t = find(n->right, val);
            if(t!= NULL)
            return t;
        }
    }
    return NULL;


}


node * findMax(node *n)
{
    if(n == NULL)
        return NULL;
    if(n->right == NULL)
        return n;
    else
        return findMax(n->right);
}

node * findMin(node *n)
{
    if(n == NULL)
        return NULL;
    if(n->left == NULL)
        return n;
    else
        return findMin(n->left);
}

node* deleteNode(int val,node *root)
{
    if(root == NULL)
        return NULL;
    if(val < root->info)
        root->left = deleteNode(val,root->left);
    else if(val > root->info)
        root->right = deleteNode(val,root->right);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            node *t = root;
            root = root->right;
            delete t;
        }
        else if(root->right == NULL)
        {
            node *t = root;
            root = root->left;
            delete t;
        }
        else
        {
            node *t = findMin(root->right);
            root->info = t->info;
            root->right = deleteNode(t->info,root->right);
        }
    }
    if(root == NULL)
        return root;
    
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getbalance(root);
//case1
    if(balance < -1 && getbalance(root->right) <= 0)
    {   
        return leftRotate(root);
    }
    //case2
    if(balance > 1 && getbalance(root->left) >= 0)
    {
        return rightRotate(root);
     }
     //case3
     if(balance < -1 && getbalance(root->right) > 0)
     {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    //case4
     if(balance > 1 && getbalance(root->left) < 0)
    {
       root->left = leftRotate(root->left);
         return rightRotate(root);
     }

    return root;
}


void updateValue(int val,string n,string des)
{

    node *t = find(root,val);
    if(t == NULL)
        cout<<"Value not found"<<endl;
    else
    {
        t->name = n;
        t->designation = des;
    }

}



};


void printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;
    cout<<"  "<<endl;
    cout<<root->name<<endl;
    cout<<root->designation<<endl;
    cout<<"  "<<endl;
    


    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


int main()
{
  
    Tree t;
    int choice;

    while(1)
    {
        cout<<"1.Add Employee"<<endl;
        cout<<"2.Search Employee"<<endl;
        cout<<"3.Update Employee Info"<<endl;
        cout<<"4.Remove an Employee"<<endl;
        cout<<"5. Print Hirechal Tree"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            int val;
            string n;
            string d;
            cout<<"Enter Employee ID"<<endl;
            cin>>val;
            cout<<"Enter Employee Name"<<endl;
            cin>>n;
            cout<<"Enter Employee Designation"<<endl;
            cin>>d;
            t.root = t.insert(t.root,val,n,d);
        }
        else if(choice == 2)
        {
            int val;
            cout<<"Enter Employee ID"<<endl;
            cin>>val;
            node *t1 = t.search(t.root,val);
            if(t1 == NULL)
                cout<<"Employee not found"<<endl;
            else
            {
                cout<<"Employee found"<<endl;
                cout<<"Employee ID\t";
                cout<<t1->info<<"\t";
                cout<<endl;
                cout<<"Employee Name\t";
                cout<<t1->name<<"\t";
                cout<<endl;
                cout<<t1->designation<<"\t";
                cout<<endl;
            }
        }
        else if(choice == 3)
        {
            int val;
            string n;
            string d;
            cout<<"Enter Employee ID to update the value"<<endl;
            cin>>val;
            cout<<"Enter Employee Name"<<endl;
            cin>>n;
            cout<<"Enter Employee Designation"<<endl;
            cin>>d;
            t.updateValue(val,n,d);
        }
        else if(choice == 4)
        {
            int val;
            cout<<"Enter Employee ID"<<endl;
            cin>>val;
            t.root = t.deleteNode(val,t.root);
        }
        else if(choice == 5)
        {
            printTree(t.root, NULL, false);
        }
        else if(choice == 6)
        {
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }


    }
    return 0;
    
}