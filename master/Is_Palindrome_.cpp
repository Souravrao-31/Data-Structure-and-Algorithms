// @author: Abhimanyu Maurya

#include<iostream>
using namespace std;

bool isPalindrome(int a[],int l,int r)
{
    if(l==r or l>r) return true;
    if(a[l]!=a[r]) return false;
    return isPalindrome(a,l+1,r-1);
}

int main()
{
    int t,A[100]={0};
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>A[i];
    }
    
    if(isPalindrome(A,0,t-1)) cout<<"true";
    else cout<<"false";

    return 0;
}
