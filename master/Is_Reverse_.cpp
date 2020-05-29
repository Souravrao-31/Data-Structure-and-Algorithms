// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;

bool isReverse(char a[], char b[])
{
    int l1, l2;
    l1 = strlen(a);
    l2 = strlen(b);
    if (l1 != l2)
        return false;
    for (char *i = a, *j = b + l2 - 1; *i != '\0'; i++, j--)
    {
        if (*i != *j)
            return false;
    }
    return true;
}
int main()
{
    char a[100], b[100];

    cin.getline(a, 100);
    cin.getline(b, 100);
    if (isReverse(a, b))
        cout << "true";
    else
        cout << "false";

    return 0;
}
