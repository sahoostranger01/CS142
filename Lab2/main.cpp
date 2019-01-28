//C++ program to reverse the linked list
#include <iostream>
using namespace std;
class Node{
    public:
    //Data
    int data;
    //Pointer to the next Node
    Node *ptr;
    //Constructor to make ptr to null
    Node()
    {
        ptr=NULL;
    }
};
class LinkedList{
    public:
    //Head-> circle type ptr
    Node *head;
    Node *tail;
    //Constructor
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    //Circle inside linked with each other
    //Rules how circle will be linked
    //Insertion
    void insert(int value)
    {
        //1st Node is added
        Node *temp=new Node();
        //Insert data in node
        temp->data=value;
        if(head==NULL)
        {
            //1st node only
            this->head=temp;
        }
        else
        {
        //Any other node
        tail->ptr=temp;
        }
        this->tail=temp;
    }
    //Function to access if in case the members of class are private 
    void revLL()
    {
        Node *temp=head;//copy head to another pointer
        revLL2(head);//call reverse function(passing head as parameter)
        head->ptr=NULL;//pointer of 1st node point to zero
        head=tail;//head points to last node
        tail=temp;//tail points to 1st node
    }
    //Function to reverse the link
    void revLL2(Node *current)
    {
        if(current->ptr->ptr==NULL)//Condtion to check whether current is at the 2nd last element 
        {
            current->ptr->ptr=current;//link pointer of last node to its previous one
            return;
        }
        else
        {
            revLL2(current->ptr);//recursion by passing next node
            current->ptr->ptr=current;//link reversly
        }
    }
    //Display
    
    void display()
    {
        Node *current=head;
        while(current!=NULL)//condition to check wheteher current position is last one
        {
            cout<<current->data<<"->";//display value of current node
            current=current->ptr;//shift to next node
            
        }
        cout<<"NULL"<<endl;//display null at the end
    }

};

int main()
{
    //Object of the class
    LinkedList l1;
    //Enter values
    for(int i=0;i<5;i++)
    {
        l1.insert(i);
    }
    l1.display();
    cout<<endl;
    
    cout<<"Reverse link"<<endl;
    //Call function
    l1.revLL();
    l1.display();
    return 0;
}


