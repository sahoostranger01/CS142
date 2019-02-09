#include <iostream>
using namespace std;
class Queuearr
{
public:
//Declare array to store queue
int queue[100], n = 100, front = - 1, end = - 1;
//Enqueue function to enter value
void Enqueue() {
    //Check whether the position is less than the max size of the array
   int val;
   if (end == n - 1)
      cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      end++;//shift the position of end
      queue[end] = val;//enter value at the end
   }
}
//Dequeue function to delete
void Dequeue() {
   if (front == - 1 || front > end)
   {
      cout<<"Queue Underflow ";
   return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;//show the deleted value
      front++;//Shift backward the position of front
   }
}
//Function to display
void Display() {
   if (front == - 1)//Check whether the Queueis empty
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      //Display value from front to rear
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}
};
int main() {
    Queuearr q;//Declare object of class
   int ch;
   //Give options to user
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   //Switch case to show output for each option
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: q.Enqueue();
         break;
      case 2: q.Dequeue();
         break;
      case 3: q.Display();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}
