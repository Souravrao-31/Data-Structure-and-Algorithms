// @author: Abhimanyu Maurya

#include <iostream>
#include <string>
using namespace std;

void remDupl(char *ptr, int A[])
{

    if (*ptr == '\0')
        return;
    else
    {
        if (A[*ptr] == 0)
        {
            cout << *ptr;
            A[*ptr]++;
        }
        remDupl(ptr + 1, A);
    }
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    int freq[256] = {0};
    remDupl(s, freq);

    return 0;
}
