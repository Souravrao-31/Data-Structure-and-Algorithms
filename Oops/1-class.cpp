#include <iostream>
using namespace std;

class car{
public:   //access modifier

int price;
int model;
char name[20];
   
    void print(){
        cout<<"ggggrrrrrrr.....car is starting "<<name<<endl;
    }

};
int main(){

   car c;
   c.price =500;
   c.model =1001;
   c.name[0] = 'B';
   c.name[1] ='M';
   c.name[2] ='W';
   c.name[3] ='\0';
   c.print();
  //cout<<c.price; not a good habbit mahe get and put function

    return 0;
}