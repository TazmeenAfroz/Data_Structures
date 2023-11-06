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
        node *left;
        node *right;
        int height;
        
    node(int val)
    {
        info = val;
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

node* insert(node* curr,int val)
{
 if(curr == NULL)
   {
    return new node(val);
   }

 if(val < curr->info)
   {
    curr->left = insert(curr->left,val);
    
   }
 else if(val > curr->info)
   {
    curr->right = insert(curr->right,val);
    
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
 
    cout<<n->info<<"\t";
   
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;
    
    inOrder(n->left);
    
    cout<<n->info<<"\t";
   
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
     
    cout<<n->info<<"\t";
   
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


void updateValue(int val1,int val2)
{
   root =  deleteNode(val1,root);
   insert(root,val2);

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

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


int main()
{
  
    Tree t;
    //    t.root = t.insert(t.root, 14);
    // t.root = t.insert(t.root, 11);
    // t.root = t.insert(t.root, 19);
    // t.root = t.insert(t.root, 7);
    // t.root = t.insert(t.root, 12);
    // t.root = t.insert(t.root, 17);
    // t.root = t.insert(t.root, 53);
    // t.root = t.insert(t.root, 20);
    // t.root = t.insert(t.root, 15);
    // t.root = t.insert(t.root, 25);
    // t.root = t.insert(t.root, 10);
    // t.root = t.insert(t.root, 17);
    // t.root = t.insert(t.root, 16);
    // t.root = t.insert(t.root, 30);
    // t.root = t.insert(t.root, 28);
   
    for(int i = 1; i <= 10; i++)
    {
        int num = rand()%100;
        t.root = t.insert(t.root, num);
    }
printTree(t.root, NULL, false);
cout<<endl;
cout<<"Inorder"<<endl;
t.inOrder(t.root);
cout<<endl;
cout<<"GOing to delete 92 "<<endl;
t.root = t.deleteNode(92,t.root);
cout<<"GOing to delete 93 "<<endl;
t.root = t.deleteNode(93,t.root);

printTree(t.root, NULL, false);
cout<<endl;
cout<<"GOing to delete 15 "<<endl;
t.root = t.deleteNode(15,t.root);
printTree(t.root, NULL, false);
cout<<endl;
cout<<"GOing to delete 77 "<<endl;
t.root = t.deleteNode(77,t.root);
printTree(t.root, NULL, false);
cout<<endl;
cout<<"GOing to delete 83 "<<endl;
t.root = t.deleteNode(83,t.root);
printTree(t.root, NULL, false);
cout<<endl;
// t.root = t.deleteNode(86,t.root);
// printTree(t.root, NULL, false);
cout<<"INSERTING NEW VALUES"<<endl;

    t.root = t.insert(t.root, 43);
     t.root = t.insert(t.root, 32);
         t.root = t.insert(t.root, 12);
           t.root = t.insert(t.root, 2);
             t.root = t.insert(t.root, 3);
               t.root = t.insert(t.root, 0);
                 t.root = t.insert(t.root, 1);
                   t.root = t.insert(t.root, 5);
                   t.root = t.insert(t.root, 4);
                     t.root = t.insert(t.root, 13);
                       t.root = t.insert(t.root, 14);
 printTree(t.root, NULL, false);
 cout<<endl;
 cout<<"GOing to delete 35 "<<endl;
t.root = t.deleteNode(35,t.root);
 printTree(t.root, NULL, false);
     cout<<endl;

 cout<<endl;
 cout<<"GOing to delete 86"<<endl;

t.root = t.deleteNode(86,t.root);
 printTree(t.root, NULL, false);

    
}