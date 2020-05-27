#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
   int price;
public:
   int model_no;
   char *name;

    //constructor
    car(){
        //override the default constructor
        cout<<"making a car ..."<<endl;
    }

    //parameter constructor
    car(int p,int mn,char *n){
       price = p;
       model_no =mn;
       int l =strlen(n);
       name = new char[l+1];
       strcpy(name,n);
    }

    void setName(char *n){
       if(name==NULL){
           name = new char[strlen(n)+1];
           strcpy(name,n);
       }
       else{
           //later
           //delete the oldname array
       }
    }
    void start(){
        cout<<"Grrrr......starting the car"<<name<<endl;
    }
    void setprice(int p){
        if(p>1000){
            price =p;
        }
        else{
            price =1000;
        }
    }

     int getPrice(){
         return price;
     }

     void print(){
         cout<<name<<endl;
         cout <<model_no<< endl;
         cout <<price<< endl;
         cout << endl;
     }


};

int main(){


    Car c;
    c.setprice(1500);
    //c.setName("Lambo");
    c.model_no =1001;
    //c.start();
    c.print();

    Car D(100,200,"BMW");
    D.print();

    Car E(D);     //default copy constructor
    D.print();

    return 0;
}