// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

// define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

void print(char s[], char o[], int p, char table[][5])
{
    if (s[p] == '\0')
    {
        o[p] = '\0';
        cout << o << "\n";
        return;
    }

    int t = s[p] - '0';
    for (size_t j = 0; table[t][j] != '\0'; j++)
    {
        o[p] = table[t][j];
        print(s, o, p + 1, table);
    }
}

int main()
{
    char table[][5] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char s[11], o[11];
    cin >> s;
    print(s, o, 0, table);
    return 0;
}
