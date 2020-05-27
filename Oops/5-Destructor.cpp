#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int price;

public:
    int model_no;
    char *name;

    //Constructor
    Car()
    {
        //Override the default Constructor
        name = NULL;
        cout << "Making a car.." << endl;
    }
    // Constructor with parameters - Parametrised Constructor
    Car(int p, int mn, char *n)
    {
        price = p;
        model_no = mn;
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
    }

    //Deep Copy Constructor
    Car(Car &X)
    {
        // cout<<"Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }

    void operator=(Car &X)
    {
        cout << "In Copy Assignment Operator" << endl;
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }

    void setName(char *n)
    {
        if (name == NULL)
        {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        else
        {
            //Later...
            //Delete the oldname array and allocate a new one.
        }
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
    ~Car()
    {
        cout << "Destroying the Car " << name << endl;
        //Write code to delete all dynamic data member
        if (name != NULL)
        {
            delete[] name;
        }
    }
};

int main()
{

    Car C;
    //Initialisation
    //C.price =-500;
    C.setPrice(1500);
    C.setName("Nano");
    C.model_no = 1001;
    //C.start();
    C.print();

    Car D(100, 200, "BMW");

    Car E(200, 400, "Audi"); //Default Copy Constructor

    // E.name[0] ='G';
    D = E; //Copy Assigment Operator ->Shallow Copy
    D.name[0] = 'O';
    D.print();
    E.print();

    //Suppose we create a dynamic object
    Car *DC = new Car(100, 200, "Dynamic Tesla Car");

    delete DC;

    return 0;
}
