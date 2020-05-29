
#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char ch;
    cin>>ch;
    if (ch >= 'a' && ch <= 'z')
    {
        printf("lowercase");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("UPPERCASE");
    }
    else
    {
        printf("Invalid");
    }
    
    return 0;
}
