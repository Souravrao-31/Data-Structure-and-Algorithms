// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;

void getdata(char *l, char *r)
{
    if (*l == '(' and *r == ')')
    {
        for (char *i = l + 1; i < r; i++)
            cout << *i;
    }
    else
    {
        if (*l != '(' and *r != ')')
        {
            getdata(l + 1, r - 1);
        }
        else if (*l == '(')
        {
            getdata(l, r - 1);
        }
        else if (*r == ')')
        {
            getdata(l + 1, r);
        }
    }
}

int main()
{

    char a[101];
    cin.getline(a, 100);
    getdata(a, a + (strlen(a) - 1));

    return 0;
}
