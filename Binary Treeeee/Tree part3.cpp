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
    
     int count(Node * curr)//count fucntion
     {
         int c=0;
         if(curr==NULL)//if curr is null
         return 0;
         else{
             c+=count(curr->left);//add the number of nodes present in the left side
             c+=count(curr->right);//add the number of nodes present in the right side
             return c+1;//return total no. of nodes
         }
     }
     int height(Node * curr)//height fucntion
     {
         if(curr==NULL)//if curr is null
         return 0;
         else{//otherwise
             
              int l = height(curr->left);//no. of left height
        int r = height(curr->right);//no. of right height
      
        /* use the larger one */
        if (l > r)  
            return(l+1);  
        else return(r+1);
         }
         
     }
     
     int rangeSearch(int k1,int k2)//function to display elements in the range
    {
        return rangeSearch2(root,k1,k2);//recursion
        cout<<endl;
    }//end of function
    int rangeSearch2(Node* current,int k1,int k2)//function to display elements in the range
    {
        if(current!=NULL)//if curr is null
        {
            if(current->data>=k1&&current->data<=k2)//check condition
	    {
           	cout<<current->data<<", ";
            	return (1+rangeSearch2(current->left,k1,k2)+rangeSearch2(current->right,k1,k2));//count the number of elements
	    }
	    else//otherwise
	    return rangeSearch2(current->left,k1,k2)+rangeSearch2(current->right,k1,k2);//count the number of elements
	}
        else
        return 0;
    }//end of the function
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
    
    
    cout<<"No. of nodes in the tree="<<b.count(b.root)<<endl;
    
    cout<<"Height of the tree="<<b.height(b.root)<<endl;
    
    cout<<"Number of elements in the range="<<b.rangeSearch(4,10);
    return 0;
}


