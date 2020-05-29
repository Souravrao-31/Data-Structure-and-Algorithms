// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;

int stoi(char ptr[], int i)
{

    if (i < 0)
        return 0;
    int t = stoi(ptr, i - 1);
    return t * 10 + (ptr[i] - '0');
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    cout << stoi(s, strlen(s) - 1);
    return 0;
}
