#include<iostream>
using namespace std ;

class Nodebst
{
    public:
    int data ;
    Nodebst* left;
    Nodebst* right;

    Nodebst()
    {
        left = right = NULL;
        data  = 0 ;
    }

};
class BST
{
    public:
    Nodebst* root ;
    BST()
    {
        root = NULL;
    }

    bool isemtpy()
    {
        if(root == NULL)
        {
            return true ;

        }
        else{

            return false ;

        }
    }
    bool search(int val)
    {
        Nodebst* temp = root ;
        while(temp != NULL)
        {
            if(temp->data == val)
            {
                return true ;
            }
            else if(val < temp->data)
            {
                temp = temp->left ;
            }
            else
            {
                temp = temp->right ;
            }
        }
        return false ;
    }

    void Insert(int val)
    {
        if(root == NULL)
        {
            root = new Nodebst();
            root->data = val;
            return ;
        }
        Nodebst* temp = root ;
        while(temp != NULL)
        {
            if(val < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = new Nodebst();
                    temp->left->data = val;
                    return ;
                }
                else
                {
                    temp = temp->left ;
                }
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = new Nodebst();
                    temp->right->data = val;
                    return ;
                }
                else
                {
                    temp = temp->right ;
                }
            }
        }
    }

    // smallest numberr
    int smallest(Nodebst* root)
    {
        if(root->left == NULL)
        {
            return root->data ;
        }
        else
        {
            return smallest(root->left);
        }
    }
    // larget numberr
    int lage(Nodebst* root)
    {
        if(root->right == NULL)
        {
            return root->data ;
        }
        else
        {
            return lage(root->right);
        }
    }

    int chota()
    {
        Nodebst* temp = root ;
        while(temp!=NULL)
        {
            if(temp->left )
            {
                temp = temp->left ;
            }
            else
            {
                return temp->data ;
            }
        }  
        return 0;      
    }

    int bara ()
    {
        Nodebst* temp = root ;
        while(temp!=NULL)
        {
            if(temp->right )
            {
                temp = temp->right ;
            }
            else
            {
                return temp->data ;
            }
        }
        return 0;     
    }

    // finding height of bst
    int height(Nodebst* root)
    {
        if(root == NULL)
        {
            return -1 ;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh > rh)
        {
            return lh+1 ;
        }
        else
        {
            return rh+1 ;
        }
    }

    // delete a Node
    void deleteNode(int val)
    {
        Nodebst* temp = root ;
        Nodebst* parent = NULL ;
        while(temp != NULL)
        {
            if(temp->data == val)
            {
                break ;
            }
            else if(val < temp->data)
            {
                parent = temp ;
                temp = temp->left ;
            }
            else
            {
                parent = temp ;
                temp = temp->right ;
            }
        }
        if(temp == NULL)
        {
            cout<<"Node not found"<<endl;
            return ;
        }
        if(temp->left == NULL && temp->right == NULL)
        {
            if(parent->left == temp)
            {
                parent->left = NULL ;
            }
            else
            {
                parent->right = NULL ;
            }
        }
        else if(temp->left == NULL)
        {
            if(parent->left == temp)
            {
                parent->left = temp->right ;
            }
            else
            {
                parent->right = temp->right ;
            }
        }
        else if(temp->right == NULL)
        {
            if(parent->left == temp)
            {
                parent->left = temp->left ;
            }
            else
            {
                parent->right = temp->left ;
            }
        }
        else
        {
            int smallest = smallest(temp->right);
            deleteNode(smallest);
            temp->data = smallest ;
        }
    }

    void Display()
    {
        if(root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return ;
        }
        Nodebst* temp = root ;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left != NULL)
            {
                cout<<"it's running"<<endl;
                temp = temp->left ;
            }
            else if(temp->right != NULL)
            {
                cout<<"It's running"<<endl;
                temp = temp->right ;
            }
            else
            {
                break ;
            }
        }
        cout<<endl;        
    }
};

int main()
{
    BST bst ;
    bst.Insert(10);
    bst.Insert(8);
    bst.Insert(40);
    bst.Insert(30);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(1);
    bst.Insert(50);
  // int num ;
    // cin>>num ;
    // if(bst.search(num) == true)
    // {
    //     cout<<"found"<<endl;
    // }
    // else
    // {
    //     cout<<"not found"<<endl;
    // }

    //smallest 
     cout<<bst.smallest(bst.root)<<endl;
     //largest 
     cout<<bst.lage(bst.root)<<endl;

        //Smallest Number 
        cout<<bst.chota()<<endl;
        //largest Number 
        cout<<bst.bara()<<endl;
        //height
        cout<<bst.height(bst.root)<<endl;
    // Display 
    //bst.Display();
    return 0 ;
}
