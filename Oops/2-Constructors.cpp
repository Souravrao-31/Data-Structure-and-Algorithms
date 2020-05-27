#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int price;

public:
    int model_no;
    char name[20];

    //Constructor
    Car()
    {
        //Override the default Constructor
        cout << "Making a car.." << endl;
    }
    // Constructor with parameters - Parametrised Constructor
    Car(int p, int mn, char *n)
    {
        price = p;
        model_no = mn;
        strcpy(name, n);
    }
    Car(Car &X)
    {
        cout << "Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        strcpy(name, X.name);
    }

    void start()
    {
        cout << "Grrrr...starting the car " << name << endl;
    }
    void setPrice(int p)
    {
        if (p > 1000)
        {
            price = p;
        }
        else
        {
            price = 1000;
        }
    }
    int getPrice()
    {
        return price;
    }
    void print()
    {
        cout << name << endl;
        cout << model_no << endl;
        cout << price << endl;
        cout << endl;
    }
};

int main()
{

    Car C;
    //Initialisation
    //C.price =-500;
    C.setPrice(1500);
    C.model_no = 1001;
    C.name[0] = 'B';
    C.name[1] = 'M';
    C.name[2] = 'W';
    C.name[3] = '\0';
    C.start();

    // cout<<C.price<<endl;
    cout << C.name << endl;
    cout << C.getPrice() << endl;

    Car D;
    D.setPrice(2000);
    cout << D.getPrice() << endl;

    Car E(100, 2001, "Ferrari");
    //E.print();

    //Copy Constructor is to create a copy of given object of the same type
    Car F(E);
    F.setPrice(2000);
    F.name[0] = 'G';
    F.print();
    E.print();

    Car G = F;
    G.print();
    F.print();

    return 0;
}
