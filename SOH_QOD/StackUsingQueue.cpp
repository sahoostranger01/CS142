/* Program to implement a stack  
using queue */
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
class Queue
{
  public:
  Node * end;
  Node * front;
  Queue()
  {
      end=NULL;
      front=NULL;
  }
  void Enqueue(int value)
  {
      if(front==NULL)
      {
        Node * temp=new Node();
          temp->data=value;
          end=temp;
          front=temp;
      }
      else
      {
             Node * temp=new Node();
          temp->data=value;
          end->ptr=temp;
          end=temp;
      }
  }
  int Dequeue()
  {
      Node* temp=front;
      int del=temp->data;
      front=temp->ptr;
      temp->ptr=NULL;
      delete temp;
      return del;
  }
  bool isEmpty()
  {
      if(front==NULL || end==NULL)
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
          Node *current=front;
     while(current!=end)
     {
         count++;
         current=current->ptr;
     }
      }
     count++;
     return count;
  }
  void display()
  {
      Node * current=front;
      while(current!=NULL)
      {
      cout<<current->data<<" ";
      current=current->ptr;
      }
      cout<<endl;
  }
  int front_data()
  {
      return front->data;
  }
  int end_data()
  {
      return end->data;
  }
  
};

class Stack_using_queue
{ 
    public:
    Queue q;//object of Queue
    void push(int num)//function to push
    {
	q.Enqueue(num);
	while(q.front_data()!=num)//reversing the queue
	q.Enqueue(q.Dequeue());//by enqueuing the dequeued element,
    }
    int pop()//function to pop
    {
	return q.Dequeue();//dequeue the reversed queue
    }
    void display()//function to display
    {
	q.display();
    }
    int size()
    {
        return q.size();
    }
}; 
  
// Driver code 
int main() 
{ 
    Stack_using_queue s; //object
    //pusing values
    s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4); 
  
    cout << "current size: " << s.size()  
         << endl; 
    s.display();
    cout<<"After poping one element"<<endl;
    s.pop(); 
    s.display();
    cout<<"After poping 2 elements"<<endl;
    s.pop(); 
    s.display();
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
} 
