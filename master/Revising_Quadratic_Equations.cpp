#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float a,b,c,d;
    cin>>a>>b>>c;
    d=b*b - (4*a*c);
    if(d<0)
        cout << "Imaginary";
    else 
    {
        float r1,r2;
        r1 = (-b - sqrt(d)) / 2 * a;
        r2 = (-b + sqrt(d)) / 2 * a;
        if(d==0)
        {
            cout << "Real and Equal\n";
        }
        else
        {
            cout << "Real and Distinct\n";
        }
        cout<<min(r1,r2)<<" "<<max(r1,r2);
    }
    return 0;
}
