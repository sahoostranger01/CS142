//Write a class House with required data and functions and implement in main function
#include <iostream>
#include<cstring>

using namespace std;
//Class Address
  class Address
  {
      //variables
      public:
      int hn;
      string cy;
      int zc;
//enter data
      void setup()
      {
          cout<<"Enter house number"<<endl;
          cin>>hn;
          cout<<"Enter city"<<endl;
          cin>>cy;
          cout<<"Enter zipcode"<<endl;
          cin>>zc;
      }
      //output function
      void display()
      {
          cout<<"House Address:: number= "<<hn<<", city= "<<cy<<" and zipcode= "<<zc<<endl;
      }
  };//end of class Address
  
  //class Room
  class Room
  {
      //variables
      public:
      float l,b,h;
      string pp;
//enter data
      void setup()
      {
                  cout<<"Enter length"<<endl;
                  cin>>l;
                  cout<<"Enter breadth"<<endl;
                  cin>>b;
                  cout<<"Enter height"<<endl;
                  cin>>h;
                  cout<<"Write purpose(kitchen/bedroom/bathroom)"<<endl;
                  cin>>pp;
      }
     
      void display()//Display
      {
            cout<<"The lenght,breadth,height of "<<pp<<" are respectively "<<l<<", "<<b<<" & "<<h<<endl;
      }
      float area()//To calculate area
      {
          return (float)(l*b);
      }
  };//end of class room
  class House{
      //variables
      public:
      string name;
  Address p;
  Room r[10];
  int rn;
  //enter data
  void setup()
  {
      cout<<"Enter the name of house"<<endl;
      cin>>name;
      cout<<"Enter address"<<endl;
      p.setup();
      cout<<"Enter number of rooms"<<endl;
      cin>>rn;
      //loop to set data for each room
      for(int n=1;n<=rn;n++)
      {
          cout<<"Enter for room"<<n<<endl;
          r[n].setup();
      }
      cout<<endl;
  }
  //display
  void display()
  {
      cout<<"Name of house:"<<name<<endl;
      cout<<"Address of house:"<<endl;
      p.display();
      cout<<"Room details"<<endl;
      //variables to count the no. of rooms
      int k=0,br=0,bt=0;
      //loop to count the number of different types of rooms
      for(int n=1;n<=rn;n++)
      {
           if(r[n].pp.compare("kitchen")==0)
              k++;
            else if(r[n].pp.compare("bedroom")==0)
              br++;
            else
              bt++;
      }
      //variable to calculate total area
      float totalarea=0;
      //loop to show details of each room and calcualte total area
    for(int n=1;n<=rn;n++)
      {
          r[n].display();
          totalarea=totalarea+r[n].area();
      }
      cout<<endl;
      cout<<"The house has "<<k<<" kitchen, "<<br<<" bedroom & "<<bt<<" bathroom"<<endl;
      cout<<"Total area of house is="<<totalarea<<endl;
  }
  
  //copyhouse function
  House copyHouse(string n,House h)
  {
      h.name=n;
      h.p=this->p;
      h.rn=this->rn;
      //loop to copy room details
      for(int i=1;i<=rn;i++)
      {
          h.r[i]=this->r[i];
      }
      return h;//returns new House
      
  }
};//end of class house

//main function

int main()
{
    House h1,h2,h3;//create three houses
    //Add details to each house and show them
    cout<<"Enter details of house 1"<<endl;
    h1.setup();
    h1.display();
    cout<<endl;
    
    cout<<"Enter details of house 2"<<endl;
    h2.setup();
    h2.display();
    cout<<endl;
    
    cout<<"Enter details of house 3"<<endl;
    h3.setup();
    h3.display();
    cout<<endl;
    
    //copy house 1 details to house 2 with required conditions
    h2=h1.copyHouse(h2.name,h2);
    //Dispaly the output after copy
    cout<<"Details of house1(after using copyHouse function)"<<endl;
    h1.display();
    cout<<endl;
    
    cout<<"Details of house2(after using copyHouse function)"<<endl;
    h2.display();

    return 0;
}

