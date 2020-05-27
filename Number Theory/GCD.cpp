#include<iostream>
using namespace std;
/*
    relation between lcm and gcd.
    gcd * lcm = a*b
    a=12 b=20
    gcd=4
    a*b=240

    so, Lcm=60
*/
int gcd(int a,int b){
    return b==0? a:gcd(b,a%b);
}

int main(){

    int n1,n2;
    cin>>n1>>n2;

    cout<<gcd(n1,n2);
    return 0;
}