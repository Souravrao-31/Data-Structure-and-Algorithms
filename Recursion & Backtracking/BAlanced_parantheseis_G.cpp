// Problem link :
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int

void Generate(char *a, int o, int c, int i, int n)
{
    // Base case
    if (i == 2 * n)
    {
        // Then we need to stop and print the array
        a[i] = '\0';
        cout << a << endl;
        return;
    }

    if (o < n)
    {
        // Add '('
        a[i] = '(';
        Generate(a, o + 1, c, i + 1, n);
    }

    if (c < o)
    {
        // Add ')'
        a[i] = ')';
        Generate(a, o, c + 1, i + 1, n);
    }
}

int main()
{
    int n;
    cin >> n;
    char a[100];
    Generate(a, 0, 0, 0, n);

    return 0;
}
