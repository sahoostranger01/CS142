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

class Queue{
  public:
  Node * end;
  Node * front;
  LinkedList x;
  Queue()
  {
      end=NULL;
      front=NULL;
  }
  //Add value at 1st pos
  void Enqueue(int value)
  {
      x.insert(value);
      end=x.tail;
      front=x.head;
  }
  void Dequeue()
  {
      x.deleteAt(1);
      front=x.head;
  }
  bool isEmpty()
  {
      if(front==NULL)
      return true;
      return false;
  }
  int size()
  {
      return x.countItems();
  }
  void display()
  {
      x.display();
  }
};

int main()
{
    Queue y;
    for(int i=1;i<5;i++)
    {
        y.Enqueue(i);
    }
    cout<<"Aju"<<endl;
    y.display();
    cout<<endl;
    
    y.Dequeue();
    y.display();
    cout<<"Aju"<<endl;
    cout<<endl;
    
    cout<<y.size()<<endl;
    cout<<"Aju"<<endl;
   // x.display();
    cout<<endl;
    
    y.isEmpty();
    cout<<"Aju"<<endl;
    //x.display();
    cout<<endl;
    return 0;
}
