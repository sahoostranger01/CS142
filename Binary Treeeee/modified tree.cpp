//Include header files
#include <iostream>

using namespace std;

//Class for the node
class Node
{
    public:
    int data;//data of the node
    Node * left,*right,*parent;//ledt and right pointers
    Node(int val)//constructor
    {
        //Default values
        left=NULL;
        right=NULL;
        data=val;
        parent=NULL;
    }
};//End of the class

//Class for binary search tree
class Bist
{
    public:
    Node * root;//Root value
    Bist()//default constructor
    {
        root=NULL;
    }
    void insert(int value)//insert function
    {
        insertHelper(root,value);//call the function to use recursion
    }
    void insertHelper(Node * current, int value)//function to use recursion
    {
        //inserting data
        if(current==NULL)
        {
            current= new Node(value);//create new node
            if(root==NULL)//inserting first data
            root=current;//modify the root
            return;
        }
        else if(current->data < value)//inserting in right side
        {
            if(current->right==NULL)//creating node at the null position
            {
                
               current->right=new Node(value);
               current->right->parent=current;
            }
            else
               insertHelper(current->right,value);//otherwise recursion
        }
        else//inserting in the left side
        {
            if(current->left==NULL)//creating node at the null position
            {
               current->left=new Node(value);
               current->left->parent=current;
            }
               else
               insertHelper(current->left,value);//otherwise recursion
        }
        
    }
    void display()//display fucntion
    {
        display2(root);//recursion function
    }
    void display2(Node * cur)
    {
        if(cur==NULL)//if current position is null then return
        return;
        display2(cur->left);//dispaly left data
        cout<<cur->data<<",";//display the value(starting from leaf)
        display2(cur->right);//display right data
    }
    Node * search(int value)//search function
    {
        return search2(root,value);//retruns node
    }
    Node * search2(Node * current,int value)
    {
        //checks whether the value is equal to current node's data or current is null
        
            if(current==NULL || value==current->data)
            return current;//return current node
            else if(value<current->data)//condition to search in the left side of the root
            search2(current->left,value);
            else//otherwise search in the left side of the root
            search2(current->right,value);
      
        
    }
    //Function to find minimum in the subtree or tree
    Node* find_min(Node* curr)
    {
        if(curr!=NULL)//checks whether starting position is null
        {
            while(curr->left!=NULL)//loop to reach least element
            {
                curr=curr->left;//moves left
            }
        }
        return curr;//returns least valued node
    }
    //function to replace A with B at A's parent
    void replace_with_parent(Node* A,Node* B)
    {
        
        B->parent=A->parent;//change the parent
        //condtion to know at which side A is present at its parent and links A's parent to B
        if(A->parent->data<A->data)
        {
            A->parent->right=B;
        }
        else
        {
            A->parent->left=B;
        }
        B=A;//copy all parameters of A to B
        //point all the pointers of A to NULL
        A->parent=NULL;
        A->left=NULL;
        A->right=NULL;
    }
    //Swap values of two nodes
    void swap(Node * A,Node * B)
    {
        //Swapping using third variable (:P)
        int temp=A->data;
        A->data=B->data;
        B->data=temp;
    }
    //Function to delete node (T_T)
    void delete_node(int value)
    {
        if(search(value)!=NULL)//checks whether the value is present in the tree or not
        {
            if(root->data!=value)//if value is not equal to root's value
            {
                Node * curr=search(value);//points to the node containing value
                if(curr->left==NULL && curr->right==NULL)//if curr is leaf
                {
                    if(curr->parent->data>curr->data)//checks curr postion with respect to its parent
                    {
                        curr->parent->left=NULL;
                    }
                    else
                    {
                        curr->parent->right=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)//if curr has only one child(i.e right)
                {
                    replace_with_parent(curr,curr->right);//replace curr with curr's right node
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)//if curr has only one child(i.e left)
                {
                    replace_with_parent(curr,curr->left);//replace curr with curr's left node
                    delete curr;
                }
                else //if curr has two children
                {
                    swap(curr,find_min(curr->right));//swap values of curr and min in its right subtree
                    curr=find_min(curr->right);//reach to the required deleted value after swapping
                    if(curr->right!=NULL)//if curr has right child
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else //otherwise
                    {
                        //if curr is leaf and present at its parent's right
                        if(curr->parent->right->data==curr->data)
                        {
                            curr->parent->right=NULL;
                        }
                        else //otherwise
                        {
                            curr->parent->left=NULL;
                        }
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                    
            }
            else //if deleted node is root
            {
                Node * curr=root;
                //checks all the conditions previously checked and modify root
                if(curr->left==NULL && curr->right==NULL)
                {
                    root=NULL;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    root=curr->right;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    root=curr->left;
                    delete curr;
                }
                else
                {
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
            }
        }
        else //if value is absent in the tree
        {
            cout<<"Invalid node for deletion"<<endl;
        }
        
    }
};//end of class

//main function
int main()
{
    Bist b;//object of class Bist
    //Insert some values
    b.insert(10);
    b.insert(6);
    b.insert(13);
    b.insert(4);
    b.insert(3);
    b.insert(5);
    b.insert(8);
    b.insert(7);
    b.insert(9);
    b.insert(12);
    b.insert(15);
    b.insert(11);
    b.insert(17);
    b.display();//Display the values in in-order display pattern
    cout<<endl;
    
    int z;
    cout<<"Enter value to be searched"<<endl;
    cin>>z;
    //Use of search function
    if(b.search(z)==NULL)
    {
        cout<<z<<" is absent in the tree"<<endl;
    }
    else
    {
        if(b.search(z)!=b.root)
        cout<<z<<" is present in the tree and its parent is="<<b.search(z)->parent->data<<endl;
        else
        {
            cout<<z<<" is the value of root and hence no parent"<<endl;
        }
    }
    //Use of find minimum function
    if(b.find_min(b.root)!=NULL)
    {
        cout<<"Minimum value of the tree:"<<b.find_min(b.root)->data<<endl;
    }
    else
    {
        cout<<"invalid"<<endl;
    }
    
    //Use delete node function
    int n;
    cout<<"Enter data of node which is to be deleted"<<endl;
    cin>>n;
    b.delete_node(n);
    if(b.root!=NULL)
    {
        b.display();
        cout<<endl;
        cout<<"Root="<<b.root->data<<endl;
    }
    else
    {
        cout<<"No element in the tree after deletion"<<endl;
    }
    
    //Yahooooooo :)....  -->@
    return 0;
}

