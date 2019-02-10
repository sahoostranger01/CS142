/* Program to implement a queue 
using stack */
#include<iostream>
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
//Creating a Stack
class Stack
{
  public:
  Node * top;
  Stack()
  {
      top=NULL;
  }
  void push(int value)
  {
      Node * temp=new Node();
          temp->data=value;
      if(top==NULL)
      {
          top=temp;
      }
      else
      {
          temp->ptr=top;
          top=temp;
      }
  }
  int pop()
  {
      Node* temp=top;
      int del=temp->data;
      top=temp->ptr;
      temp->ptr=NULL;
      delete temp;
      return del;
  }
  bool isEmpty()
  {
      if(top==NULL)
      return true;
      else
      return false;
  }
  int size()
  {
      int count=0;
      if(isEmpty()==true)
      return count;
      else
      {
          Node *current=top;
     while(current!=NULL)
     {
         count++;
         current=current->ptr;
     }
      }
     return count;
  }
  void display()
  {
      display2(top);
  }
  void display2(Node * current)
  {
       if(current->ptr==NULL)
        cout<<current->data<<" ";
       else
      {
          display2(current->ptr);
          cout<<current->data<<" ";
      }
  }
  
  int top_data()
  {
      return top->data;
  }
  
};

class Queue_using_stack
{ 
    public:
    Stack s;//object of Queue
    void Enqueue(int num)//function to push
    {
        s.push(num);
    }
    int Dequeue()//function to pop
    {
	if(s.size()==0)
        cout<<"Stack Underflow"<<endl;
	else if(s.size()==1)
	s.pop();
    else
	{
	    int p=s.pop();//store the poped value of stack
	    Dequeue();//Recursively poping out the last element only
        s.push(p);//pusing the popped elements once again
	}
    }
    void display()//function to display
    {
	s.display();
    }
    int size()
    {
        return s.size();
    }
}; 
  
// Driver code 
int main() 
{ 
    Queue_using_stack q; //object
    //Enquing values
    q.Enqueue(1); 
    q.Enqueue(3);
    q.Enqueue(2);
    q.Enqueue(4);
  
    cout << "current size: " << q.size()  
         << endl; 
    q.display();
    cout<<endl;
    cout<<"After dequeuing one element"<<endl;
    q.Dequeue(); 
    q.display();
    cout<<endl;
    cout<<"After dequeuing 2 elements"<<endl;
    q.Dequeue(); 
    q.display();
    cout<<endl;
    cout << "current size: " << q.size()  
         << endl; 
    return 0; 
} 

