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
    //Insert at 
    void InsertAt(int pos,int data)
    {
         //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current!=NULL;i++)
        {
            count++;
            current=current->ptr;
        }
        //Put condition for pos
        if(count==0)
        {
            if(pos==1)
            {
                Node *current=head;
                Node *raj=new Node();
                raj->data=data;
                raj->ptr=current;
                head=raj;
            }
            else
            cout<<pos<<" is invalid position"<<endl;
        }
        else
        {
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
        current->ptr=NULL;
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
        while(current!=NULL)
        {
            length++;
            current=current->ptr;
        }
        return length;
    }
    //Delete at position
    void deleteAt(int pos)
    {
        //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current!=NULL;i++)
        {
            count++;
            current=current->ptr;
        }
        //Put condition for position
        if(pos>0 && pos<=count)
        {
            //If pos is 1st position
            if(pos==1)
            {
                Node *x=head;
                head=head->ptr;
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
                //Reach next place after pos 
                Node *next=head;
                int j=0;
                while(j<pos)
                {
                   j++;
                   next=next->ptr;
                }
                //Pointer of the node before pos will point to the node after pos 
                current->ptr=next;
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
        while(current!=NULL)
        {
            cout<<current->data<<"->";
            current=current->ptr;//Move to next node
            
        }
        cout<<"NULL"<<endl;
    }

};
class Stack{
    public:
    Node * top;
    LinkedList l1;
    Stack(){
        top = NULL;
    }
    // Pushes on top
    void push(int value){
        // void insertAt(int value, int pos){
        l1.InsertAt(1,value);
        //top = new_head;
        top = l1.head ;
    }
    // Pops the top
    void pop(){
        // void deleteAt(int pos){
        l1.deleteAt(1);
        //top = new_head;
        top = l1.head;
    }
    bool isEmpty(){
        if(top == NULL) return true;
        return false;
    }
    int size(){
        return l1.countItems();
    }
    void topDisplay(){
    }
    void display(){
        l1.display();
    }
};



int main(){
    Stack s1;

    for(int i = 0; i < 5 ; i++)
        s1.push(i);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    cout<<"Poping after deleting all elements"<<endl;
    s1.pop();
    s1.display();
    
    
}