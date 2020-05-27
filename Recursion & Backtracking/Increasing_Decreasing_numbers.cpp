#include <iostream>
using namespace std;
/* without using loops we are printing the number upto n
in inc and dec order.
*/
void dec(int n){
    if (n==0)
    {
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

void inc(int n)
{
    if (n == 0)
    {
        return ;
    }
    inc(n - 1);    //this is n to n-1
    cout << n << " "; //it is only n
}
int main(){
    int n;
    cin>>n;
    dec(n);
    cout<<endl;
    inc(n);

    return 0;
}