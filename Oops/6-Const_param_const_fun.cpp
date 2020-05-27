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
    const int tyres;

    //Constructor
    Car() : name(NULL), tyres(4)
    {
    }
    // Constructor with parameters - Parametrised Constructor
    Car(int p, int mn, char *n, int t = 4) : price(p), model_no(mn), tyres(t)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
    }

    //Deep Copy Constructor
    Car(Car &X) : tyres(X.tyres)
    {
        // cout<<"Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }

    void operator=(const Car &X)
    {
        cout << "In Copy Assignment Operator" << endl;
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }

    void setName(const char *n)
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

    void start() const
    {
        cout << "Grrrr...starting the car " << name << endl;
    }
    void setPrice(const int p)
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
    int getPrice() const
    {
        return price;
    }
    void print() const
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

    cout << E.tyres << endl;

    //Suppose we create a dynamic object
    Car *DC = new Car(100, 200, "Dynamic Tesla Car");

    delete DC;

    return 0;
}
