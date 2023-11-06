/*Jewel Heist in the Magical Woods

Imagine you are the prince/ princess in an enchanted forest adventure. You carry a magical bag
with a limited capacity of X units of power. There is a special tree in a forest that contains gems.
Each gem has its unique magical power values. You need to pick gems from the forest's BST and
keep them in your bag until your bag contains a total magical power of X units. And then......
RUNNNNN!!! Because there is a witch who caught you collecting her gems and now the witch is
running after you.
In this program first insert some gems into the enchanted forest's BST using hard coded provided
values. Each gem (node) should contain the gem name, its power, and the left and right node
pointers in your program.
First, insert the gems in the following order, with the provided power values (hard coded values
using call to the insert method. Do no take input from user).
1. "Diamond", 50
2. "Ruby", 30
3. "Sapphire", 70
4. "Pearl", 40
5. "Opal", 10
6. "Garnet", 60
7. "Zircon", 20
8. "Jade", 5
Then your menu-driven program should provide the following options:

• Display the magical tree. When user selects this option, ask which algorithm to use, pre-
order, post-order, or in-order, then traverse accordingly and display the gems (nodes).

• Search for a gem by specifying its power.
• Find the gem with the highest magical power.
• Pluck (remove) a gem from the BST, and put it in your bag.
Your goal is to fill your magical bag with gems from the BST until it reaches a total magical power
of X units.
• When it reaches the desired power of X units, display “You won! Now take your bag and
run from the forest”.
• Ensure the bag is not overfilled. In case it is, display a message “You lost! You bag burst.
Now run a save yourself from the witch”.
Note: For ease, just use the int variable to store the current power of your bag.*/

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
        string str;
        
    node(int val, string s)
    {
        info = val;
        left = NULL;
        right = NULL;
        str = s;
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

node* insert(node* curr,int val,string s)
{
 if(curr == NULL)
   {
    return new node(val,s);
   }

 if(val < curr->info)
   {
    curr->left = insert(curr->left,val,s);
    return curr;
   }
 else if(val > curr->info)
   {
    curr->right = insert(curr->right,val,s);
    return curr;
   }
   
     return curr;

}

 
void preOrder(node *n)
{
    if(n == NULL)
        return;
     cout<<n->str<<":\t";
    cout<<n->info<<"\t";
   
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;
    
    inOrder(n->left);
    cout<<n->str<<":\t";
    cout<<n->info<<"\t";
   
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
     cout<<n->str<<":\t";
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
        cout<<succ->info<<endl;
        cout<<pre->info<<endl;

        
        node *prepar = parent(root, pre, NULL);
        curr->info = pre->info;
        if (prepar->left == pre)
           prepar->left = pre->left;
         else
            prepar->right = pre->left;
        delete pre;
         return root;
        
        // else 
        // {
        // node *succpar = parent(root, succ, NULL);
           
        // curr->info = succ->info;
        // if (succpar->left == succ)
        // succpar->left = NULL;
        // else
        //     succpar->right = NULL;
        // delete succ;
        // return root;

        // }


    }

    return root;
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
    
    t.root = t.insert(t.root, 50,"Diamond");
    t.root = t.insert(t.root, 30,"Ruby");
    t.root = t.insert(t.root, 70,"Sapphire");
    t.root = t.insert(t.root, 40,"Pearl");
    t.root = t.insert(t.root, 10,"Opal");
    t.root = t.insert(t.root, 60,"Garnet");
    t.root = t.insert(t.root, 20,"Zircon");
    t.root = t.insert(t.root, 5,"Jade");
    
    cout<<"Welcome to the Magical Tree Forest Adventure"<<endl;
    int points = 0;
    int choice;
    while(1)
    {
        cout<<"1. Display Tree"<<endl;
        cout<<"2. Search for a Gem"<<endl;
        cout<<"3.Find the Gem with the Highest Value"<<endl;
        cout<<"4.Pluck a Gem From the tree"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            int choice2;
            cout<<"1. Preorder"<<endl;
            cout<<"2. Inorder"<<endl;
            cout<<"3. Postorder"<<endl;
            cin>>choice2;
            if(choice2 == 1)
            {
                t.preOrder(t.root);
                cout<<endl;
                printTree(t.root, NULL, false);
                cout<<endl;
            }
            else if(choice2 == 2)
            {
                t.inOrder(t.root);
                cout<<endl;
            }
            else if(choice2 == 3)
            {
                t.postOrder(t.root);
                cout<<endl;
            }
        }

        if(choice == 2)
        {
            int val;
            cout<<"Enter the power of the Gem you are looking for"<<endl;
            cin>>val;
            node *n = t.search(t.root, val);
            if(n == NULL)
                cout<<"Gem not found"<<endl;
            else
                cout<<"Gem found"<<endl;
                cout<<"Gem: "<<n->str<<endl;

    }

    if(choice == 3)
    {
        node *n = t.findMax(t.root);
        cout<<"The Gem with the highest power is: "<<n->str<<endl;
    }

    if(choice == 4)
    {
        int maxUnits = 100;
       
        int val;
        cout<<"Enter the power of the Gem you want to pluck"<<endl;
        cin>>val;
        node *n = t.search(t.root, val);
        if(n == NULL)
            cout<<"Gem not found"<<endl;
        else
        {
            cout<<"Gem found"<<endl;
            cout<<"Gem: "<<n->str<<endl;
            points = points + n->info;
            cout<<"You have "<<points<<" points"<<endl;
            t.deleteNode(val);
            if(points >= maxUnits)
            {
                cout<<"You have collected all the gems"<<endl;
                break;
            }

            
        }

    }
    }
    
   


    return 0;

}
           
