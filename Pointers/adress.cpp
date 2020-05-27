#include <iostream>
using namespace std;
int main() {
    int a=10;
    
    
    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<&a<<endl;

    float b=10.5;
    cout<<&b<<endl;

    char c='s';
    cout<<(int *)&c<<endl;

    return 0;

}
