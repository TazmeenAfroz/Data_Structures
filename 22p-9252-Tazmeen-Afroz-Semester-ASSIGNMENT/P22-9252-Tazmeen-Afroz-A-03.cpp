#include<iostream>
using namespace std;

class node
{
    public:
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
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



void deleteTree(node* leaf)
{
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
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
    return curr;
   }
 else if(val > curr->info)
   {
    curr->right = insert(curr->right,val);
    return curr;
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

node* parent(node* curr, node* p, node* par)
{
    if(curr == NULL)
        return NULL;

    if (curr == p)
    {
        return par;
    }
    else
    {
        node *t = NULL;
        t = parent(curr->left, p, curr);
        if(t!= NULL)
            return t;
        else
        {
            t = parent(curr->right, p, curr);
            return t;
        }

    }
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

node* inorderPredecessor(node* root, node* n) {

    if (n->left != NULL) {
      
        node* current = n->left;
        while (current->right != NULL) {
            current = current->right;
        }
        return current;
    } else {
    
        node* current = n;
        node* par = parent(root, current, NULL);
        while (par != NULL && par->left == current) {
            current = par;
        }
        return par;
    }
}

node* inorderSuccessor(node* root, node* n) {
    if (n->right != NULL) {
        
        node* current = n->right;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    } else {
        
        node* current = n;
        node* par = parent(root, current, NULL);
        while (par != NULL && par->right == current) {
            current = par;
        }
        return par;
    }
}


node* deleteNode(int val)
{
    node *curr = find(root, val);
    node *par = parent(root, curr, NULL);

    if (curr->left == NULL && curr->right == NULL)
    {
        if (par->left == curr)
            par->left = NULL;
        else
            par->right = NULL;
        delete curr;
        return root;
    }
    else if (curr->left == NULL && curr->right != NULL)
    {    if(par == NULL)
        {
            root = curr->right;
            delete curr;
            return root;
        }
        else
        {
        if (par->left == curr)
            par->left = curr->right;
        else
            par->right = curr->right;
        delete curr;
        return root;
        }
    }
    else if (curr->left != NULL && curr->right == NULL)
    {   if(par == NULL)
        {
            root = curr->left;
            delete curr;
            return root;
        }
        else
        {
        if (par->left == curr)
            par->left = curr->left;
        else
            par->right = curr->left;
        delete curr;
        return root;
        }
    }
    else if (curr->left != NULL && curr->right != NULL)
    {
        node *pre = inorderPredecessor(root, curr);
        node *succ = inorderSuccessor(root, curr);
       
        //code for predecessor deletion
        
        // node *prepar = parent(root, pre, NULL);
        // curr->info = pre->info;
        // if (prepar->left == pre)
        //    prepar->left = pre->left;
        //  else
        //     prepar->right = pre->left;
        // delete pre;
        //  return root;
       
       //code for successor deletion
        node *succpar = parent(root, succ, NULL);
           
        curr->info = succ->info;
        if (succpar->left == succ)
        succpar->left = NULL;
        else
            succpar->right = NULL;
        delete succ;
        return root;

        }

    return root;
}

bool search(node * curr,int val)
{
    if(curr == NULL)
        return false;
    if(curr->info == val)
        return true;
    else if(val < curr->info)
        return search(curr->left,val);
    else if(val > curr->info)
        return search(curr->right,val);
    else
        return false;  

}
bool isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
}

};


int main()
{
    Tree t;
  
    bool check,find;
    check = t.isEmpty();
     
    if(check)
        cout<<"Tree is empty"<<endl;
    else
        cout<<"Tree is not empty"<<endl;
    
    cout<<endl;
    int val = 10;

    find = t.search(t.root, 10);
    if(find)
        cout<<val<<" is found"<<endl;
    else
        cout<<val<<" is not found"<<endl;
    
    cout<<endl;

    cout<<"Inserting elements"<<endl;

    cout<<endl;
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 60);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 9);
    t.root = t.insert(t.root, 70);
    t.root = t.insert(t.root, 55);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 5);
    
    cout<<"Preorder traversal"<<endl;
    t.preOrder(t.root);

    cout<<endl;
    cout<<"Inorder traversal"<<endl;
    t.inOrder(t.root);

    cout<<endl;
    cout<<"Postorder traversal"<<endl;
    t.postOrder(t.root);

    cout<<endl;
   
    find = t.search(t.root, val);
    if(find)
        cout<<val<<" is found"<<endl;
    else
        cout<<val<<" is not found"<<endl;

    
    cout<<endl;

    cout<<endl;
    int del1,del2,del3;
    del1 = 50;
    t.root = t.deleteNode(del1);
    cout<<del1<<" is deleted"<<endl;
       cout<<endl;
    
    cout<<"Inorder traversal"<<endl;
    t.inOrder(t.root);

    cout<<endl;
   
    del2 = 30;
    t.root = t.deleteNode(del2);
    cout<<del2<<" is deleted"<<endl;
    cout<<endl;
    
    
    cout<<"Inorder traversal"<<endl;
    t.inOrder(t.root);
    
    cout<<endl;
    del3 = 5;
    t.root = t.deleteNode(del3);
    cout<<del3<<" is deleted"<<endl;
    cout<<endl;
   

      cout<<"Inorder traversal"<<endl;
    t.inOrder(t.root);

 
    return 0;

}
           