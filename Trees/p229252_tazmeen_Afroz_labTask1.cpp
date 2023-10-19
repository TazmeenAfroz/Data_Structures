/*Make a menu driven program with the following functions:
1. Insert in the tree: Take a value from the user, and ask where to insert. The user will specify the
node and also specify whether to make the new node the left/right child of the given node. Furthe
clean the code by making the setLeft(), and setRight() method.
2. Traverse the tree: Further ask the user whether to do Preorder, Inorder, or Postorder traversal.
Traverse and display the tree accordingly.
3. Find depth of the tree:
4. Find the level of a specific node: Enter the node’s value to find it’s level.
5. Search a value: Enter a value and check whether it exist in the tree or not.
6. Delete tree: Delete the entire tree.
Note: Make all the methods in the tree class.*/
#include<iostream>
#include<string>

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
            if(t!= NULL)
            return t;
        }
    }
    return NULL;
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
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        
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


};

int main()
{
    Tree t;

    // t.insertroot(5);
    // node *root = t.getRoot();
    // t.insertleft(root, 2);
    // t.insertright(root, 7);
    // t.insertright(root->left, 3);
    // t.insertright(root->right, 9);
    // t.insertleft(root->right, 6);
    // t.insertleft(root->left, 10);
    // t.insertleft(root->left->right, 1);
    /*Insert in the tree: Take a value from the user, and ask where to insert. The user will specify the
node and also specify whether to make the new node the left/right child of the given node. Furthe
clean the code by making the setLeft(), and setRight() method.*/
    int choice;
   while(1)
   {
   
    cout<<"1. Insert"<<endl;
   
    cout<<"2. Preorder"<<endl;
    cout<<"3. Inorder"<<endl;
    cout<<"4. Postorder"<<endl;
    cout<<"5. Max Depth"<<endl;
    cout<<"6. Level"<<endl;
    cout<<"7. Parent"<<endl;
    cout<<"8. Sibling"<<endl;
    cout<<"9. Check"<<endl;
    cout<<"10. Delete"<<endl;
    cout<<"11. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
   
     node *root = t.getRoot();
    if(choice == 1)
    {
        cout<<"Enter value: ";
        int val;
        cin>>val;
       
        int choice2;
        cout<<"1. Insert root"<<endl;
        cout<<"2. Insert left"<<endl;
        cout<<"3. Insert right"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice2;

        if(choice2 == 1)
        {
            t.insertroot(val);
        }
        else if(choice2 == 2)
        {
            if(root == NULL)
            {
                cout<<"Root does not exist"<<endl;
            }
            else
            {
                cout<<"1.Enter node to insert left: "<<endl;
                int val2;
                cin>>val2;
                node* n2 = t.find(root, val2);
                if(n2 == NULL)
                {
                    cout<<"Node does not exist"<<endl;
                }
                else
                {
                    t.insertleft(n2, val);
                }

            }

        }
        else if(choice2 == 3)
        {
           
            if(root == NULL)
            {
                cout<<"Root does not exist"<<endl;
            }
            else
            {
                cout<<"1.Enter node to insert right: "<<endl;
                int val2;
                cin>>val2;
                node* n2 = t.find(root, val2);
                if(n2 == NULL)
                {
                    cout<<"Node does not exist"<<endl;
                }
                else
                {
                    t.insertright(n2, val);
                }
            }
        }



    }
    
    else if(choice == 2)
    {
    cout<<"Preorder: "<<endl;
    t.preOrder(root);
    cout<<endl;

    }
    
   else if(choice == 3)
   {
   
     cout<<"Inorder: "<<endl;
    t.inOrder(root);
    cout<<endl;

   }

   else if(choice == 4)
   {
    
     cout<<"Postorder: "<<endl;
    t.postOrder(root);
    cout<<endl;
   }

   else if(choice == 5)
   {
  
     cout<<"Max Depth: "<<t.maxDepth(root)<<endl;
   }

   else if(choice == 6)
   {
    cout<<"Enter value: ";
    int val;
    cin>>val;
     node* n2 = t.find(root, val);
    cout<<"Level of  "<<n2->info<<" : " <<t.getLevel(root,n2, 1)<<endl;
   }

   else if(choice == 7)
   {
   cout<<"Enter value: ";
    int val;
    cin>>val;
    node* n = t.find(root,val);
    node* par = t.parent(root, n, root);
    cout<<"Parent of " <<n->info <<": "<<par->info<<endl;
   }

    else if(choice == 8)
    {
     cout<<"Enter value: ";
     int val;
     cin>>val;
     node* n = t.find(root,val);
     node* sib = t.sibling(n);
     if(sib != NULL)
        cout<<"Sibling of  "<<n->info<<": "<<sib->info<<endl;
        else
        cout<<"No sibling"<<endl;



   }

  

    else if(choice == 9)
    {
    cout<<"Enter value: ";
    int val;
    cin>>val;
    node* n = t.find(root,val);
    if(n != NULL)
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;

    }

    else if(choice == 10)
    {
     
     t.deleteTree(root);

    }

    else if(choice == 11)
    {
        break;
    }

    else
    {
        cout<<"Invalid choice"<<endl;
    }

    }

    return 0;

}
           
