//Implementation of Singly Linked List using C++
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
        tail->ptr=head;
        
    }
    //Insert at 
    void InsertAt(int pos,int data)
    {
         //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current->ptr!=head;i++)
        {
            count++;
            current=current->ptr;
        }
        count++;
        //Put conditionon pos
        if(pos>0 && pos<=count)
        {
            //If position is 1st position
            if(pos==1)
            {
                Node *current=head;
                Node *raj=new Node();
                raj->data=data;
                raj->ptr=current;
                head=raj;
                tail->ptr=head;
            }
            else
            {
                //Reach the place before pos
                Node *current=head;
                int i=1;
                while(i<pos-1)
                {
                   i++;
                   current=current->ptr;
                }
                //Create the node
                Node *raj=new Node();
                raj->data=data;
                raj->ptr=current->ptr;
                current->ptr=raj;
            }
        }
        else
        {
            cout<<pos<<" is invalid position"<<endl;
        }
    }
    
    //Deletion of last element
    void del()
    {
        //store tail in temp
        Node *t=tail;
        //before tail has to point to NULL
         Node *current=head;
        while(current->ptr!=tail)
        {
            current=current->ptr;
        }
        current->ptr=head;
        //update tail
        tail=current;
        //delete temp
        delete t;
        
    }
    //count items
    int countItems()
    {
        Node *current=head;
        int length=0;
        while(current->ptr!=head)
        {
            length++;
            current=current->ptr;
        }
        length++;
        return length;
    }
    //Delete at position
    void deleteAt(int pos)
    {
        //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current->ptr!=head;i++)
        {
            count++;
            current=current->ptr;
        }
        count++;
        //Put condition for position
        if(pos>0 && pos<=count)
        {
            //If pos is 1st position
            if(pos==1)
            {
                Node *x=head;
                head=x->ptr;
                //x->ptr=NULL;
                tail->ptr=head;
                delete x;
            }
            else
            {
                //Reach the place before pos
                Node *current=head;
                int i=1;
                while(i<pos-1)
                {
                   i++;
                   current=current->ptr;
                }
                //copy the node to be deleted
                Node *t=current->ptr;
                //Pointer of the node before pos will point to the node after pos 
                current->ptr=(current->ptr)->ptr;
                //t->ptr=NULL;
                delete t;
            }
        }
        else
        {
            cout<<pos<<" is invalid position"<<endl;
        }
    }
    //Display
    
    void display()
    {
        Node *current=head;
        while(current->ptr!=head)
        {
            cout<<current->data<<"->";
            current=current->ptr;//Move to next node
            
        }
        cout<<current->data<<endl;
    }

};

int main()
{
    //Object of the class
    LinkedList l1;
    //Enter values
    for(int i=1;i<5;i++)
    {
        l1.insert(i);
    }
    //show output
    cout<<"Normal Display::"<<endl;
    l1.display();
    cout<<"The number of items before deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after deletion::"<<endl;
    l1.del();//use of delete
    l1.display();
    cout<<"The number of items after deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after insert at particular position example(valid 1)::"<<endl;
    l1.InsertAt(1,88);//use of insert at
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after insert at particular position example(invalid 1)::"<<endl;
    l1.InsertAt(-2,88);//use of insert at
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after insert at particular position example(invalid 1)::"<<endl;
    l1.InsertAt(88,88);//use of insert at
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after insert at particular position example(valid 2)::"<<endl;
    l1.InsertAt(2,5);//use of insert at
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after delete at particular position example(valid 1)::"<<endl;
    l1.deleteAt(1);//use of deleteAt
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after delete at particular position example(invalid 1)::"<<endl;
    l1.deleteAt(-1);//use of deleteAt
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after delete at particular position example(invalid 2)::"<<endl;
    l1.deleteAt(8998);//use of deleteAt
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Display after delete at particular position example(valid 2)::"<<endl;
    l1.deleteAt(3);//use of deleteAt
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    
    return 0;
}
