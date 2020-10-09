#include <iostream>
using namespace std;

void hanoi(int n, char src, char helper, char dest)
{
    if (n == 0)
    {
        return;
    }
    hanoi(n - 1, src, dest,helper);

    cout << "move " << n << " disk from " << src << " --> " << dest << endl;

    hanoi(n - 1,helper,src,dest);
}

int main(){

    int n;
    cin>>n;

    hanoi(n, 'A' ,'B', 'C' );
    return 0;
}