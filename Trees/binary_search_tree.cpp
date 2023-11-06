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
    {
        if (par->left == curr)
            par->left = curr->right;
        else
            par->right = curr->right;
        delete curr;
        return root;
    }
    else if (curr->left != NULL && curr->right == NULL)
    {
        if (par->left == curr)
            par->left = curr->left;
        else
            par->right = curr->left;
        delete curr;
        return root;
    }
    else if (curr->left != NULL && curr->right != NULL)
    {
        node *pre = inorderPredecessor(root, curr);
        node *succ = inorderSuccessor(root, curr);
        cout<<succ->info<<endl;
        cout<<pre->info<<endl;

        if(pre != NULL)
        {
        node *prepar = parent(root, pre, NULL);
        curr->info = pre->info;
        if (prepar->left == pre)
           prepar->left = pre->left;
         else
            prepar->right = pre->left;
        delete pre;
         return root;
        }
        else 
        {
        node *succpar = parent(root, succ, NULL);
           
        curr->info = succ->info;
        if (succpar->left == succ)
        succpar->left = NULL;
        else
            succpar->right = NULL;
        delete succ;
        return root;

        }


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

};

void printTree(node *root, Trunk *prev, bool isRight)
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
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 60);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 9);
    t.root = t.insert(t.root, 70);
    t.root = t.insert(t.root, 55);
    // t.root = t.insert(t.root, 20);
    // t.root = t.insert(t.root, 10);
    // t.root = t.insert(t.root, 5);

  
    printTree(t.root, NULL, false);

    cout<<"Preorder: "<<endl;
    t.preOrder(t.root);
    cout<<endl;

    
     cout<<"Inorder: "<<endl;
     t.inOrder(t.root);
    
    cout<<endl;

    cout<<"Postorder: "<<endl;
    t.postOrder(t.root);

 
 t.deleteNode(50);
 

    cout<<endl;
    cout<<"After deletion: "<<endl;



   
     cout<<"Inorder: "<<endl;
    t.inOrder(t.root);

    cout<<endl;
    cout<<endl;

    printTree(t.root, NULL, false);

 t.deleteNode(30);
 

    cout<<endl;
    cout<<"After deletion: "<<endl;



   
     cout<<"Inorder: "<<endl;
    t.inOrder(t.root);

    cout<<endl;
    cout<<endl;

    printTree(t.root, NULL, false);



    return 0;

}
           