#include <iostream>
using namespace std;
class Stackarr
{
public:
//Declare array to store stack
int stack[100], n=100, top=-1;
//Push function to enter value
void push(int val) {
    //Check whether the position is less than the max size of the array
   if(top>=n-1)
      cout<<"Stack Overflow"<<endl; 
   else {
       //shift the position of top
      top++;
      stack[top]=val;//enter value at the top
   }
}
//Pop function to delete
void pop() {
   if(top<=-1)//Check whether the position is more than the min size of the array
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;//show the deleted value
      int temp=stack[top];
      top--;//Shift backward the position of top
      delete temp;
   }
}
//Function to display
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      //Display value from top to 0
      for(int i=top; i>=0; i--)
         cout<<stack[i]<<" ";
         cout<<endl;
   } else
      cout<<"Stack is empty";
}
};
int main() 
{
    Stackarr s;//Declare object of class
   int ch, val; 
   //Give options to user
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   //Switch case to show output for each option
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s.push(val);
            break;
         }
         case 2: {
            s.pop();
            break;
         }
         case 3: {
            s.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); 
      return 0;
}
