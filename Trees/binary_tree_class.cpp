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
{ 
    int length;
    node *root;
    public:
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
     
        node *getRoot()
        {
            return root;
        }
       
  void insertroot(int val)
  {
      if(root == NULL)
      {
          root = new node(val);
          length++;
      }
      else
      {
          cout<<"Root already exists"<<endl;
      }
  }

 void insertleft(node *n, int val)
 {
     if(n == NULL)
     {
         cout<<"Parent does not exist"<<endl;
     }
     else
     {
         if(n->left == NULL)
         {
             n->left = new node(val);
             length++;
         }
         else
         {
             cout<<"Left child already exists"<<endl;
         }
     }
 }

    void insertright(node *n, int val)
    {
        if(n == NULL)
        {
            cout<<"Parent does not exist"<<endl;
        }
        else
        {
            if(n->right == NULL)
            {
                n->right = new node(val);
                length++;
            }
            else
            {
                cout<<"Right child already exists"<<endl;
            }
        }
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

node* sibling(node* p)
{
    node* par = parent(root, p, root);

    if (par->left == p)
        return par->right;
    else 
        return par->left;
    


}

       
int maxDepth(node* n)  
{  
    if (n == NULL)  
        return -1;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}



int getLevel(node *ptr, node* n,int level) 
{
    if (ptr == NULL)
        return 0;
    if (ptr == n)
        return level;

    int l = getLevel(ptr->left, n, level+1); 
    int r = getLevel(ptr->right, n, level+1);

    if(l == 0)
        return r;
    else if(r == 0)
        return l;
    else
        return 0;
    // return l | r;
    // return getLevel(ptr->left, val, level+1) | 
            // getLevel(ptr->right, val, level+1);
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

void checkDuplicates(node** n, int val)
{
    if(*n == NULL)
    {
        *n = new node(val);
        return;
    }
    

    if(val > (*n)->info)
    {
        if ((*n)->right != NULL)
            checkDuplicates(&(*n)->right, val);
        else
        {
            (*n)->right = new node(val);
            return;
        }
        
    }
    else if(val < (*n)->info)
    {
        if((*n)->left != NULL)
            checkDuplicates(&(*n)->left, val);
        else
        {
            (*n)->left = new node(val);
            return;
        }
    }
    else if(val == (*n)->info)
        cout<<val<<" is repeated..."<<endl;
}

int main()
{
    Tree t;
    t.insertroot(5);
    node *root = t.getRoot();
    t.insertleft(root, 2);
     t.insertright(root, 7);
    // t.insertleft(root->left, 2);
    t.insertright(root->left, 3);
    t.insertright(root->right, 9);
    t.insertright(root->right->right, 10);
    t.insertleft(root->left, 6);
    t.insertleft(root->left->right, 1);
    printTree(root, NULL, false);

    cout<<"Preorder: "<<endl;
    t.preOrder(root);
    cout<<endl;

    cout<<"Inorder: "<<endl;
    t.inOrder(root);
    cout<<endl;

    cout<<"Postorder: "<<endl;
    t.postOrder(root);
    cout<<endl;

    cout<<"Max Depth: "<<t.maxDepth(root)<<endl;

    cout<<"Level of 7: "<<t.getLevel(root, root->right, 1)<<endl;


    node* par = t.parent(root, root->right->right->right, root);
    cout<<"Parent of 10: "<<par->info<<endl;

    node* sib = t.sibling(root->left->right);
    cout<<"Sibling of 3: "<<sib->info<<endl;

    // Find Duplicates [Start]
    
      node *r = NULL;
    int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    int sz = sizeof(arr)/sizeof(int);
    
    for (int i = 0; i < sz; i++)
        checkDuplicates(&r, arr[i]);
    

    return 0;

}
           