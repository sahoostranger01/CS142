//Include header files
#include <iostream>

using namespace std;

//Class for the node
class Node
{
    public:
    int data;//data of the node
    Node * left,*right;//ledt and right pointers
    Node(int val)//constructor
    {
        //Default values
        left=NULL;
        right=NULL;
        data=val;
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
            }
            else
               insertHelper(current->right,value);//otherwise recursion
        }
        else//inserting in the left side
        {
            if(current->left==NULL)//creating node at the null position
               current->left=new Node(value);
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
        //checks whether the value is equal to current node's data or currentis null
        if(current==NULL || value==current->data)
        return current;//return current node
        else if(value<current->data)//condition to search in the left side of the root
        search2(current->left,value);
        else//otherwise search in the left side of the root
        search2(current->right,value);
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
    b.display();//Display the values in in-order display pattern
    cout<<endl;
    //Use of search function
    if(b.search(4)==NULL)
    cout<<"4 is absent in the tree"<<endl;
    else
    cout<<"4 is present in the tree"<<endl;
    return 0;
}

