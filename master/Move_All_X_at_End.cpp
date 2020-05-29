// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

void func(char a[])
{
    if (*a == '\0')
        return;
    for (char *i = a; *i != '\0'; i++)
    {
        while (*(a + 1) != '\0' and *a == 'x')
        {
            swap(*a, *(a + 1));
            a++;
        }
        func(a + 1);
    }
}

int main()
{

    char a[1001];
    cin.getline(a, 1000);
    func(a);
    cout << a;
    return 0;
}
