// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char a[], int l, int r)
{
    if (l == r or l > r)
        return true;
    if (a[l] != a[r])
        return false;
    return isPalindrome(a, l + 1, r - 1);
}

int main()
{
    char A[100] = {0};
    cin >> A;
    if (isPalindrome(A, 0, strlen(A) - 1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
