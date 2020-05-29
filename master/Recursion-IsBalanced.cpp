// @author: Abhimanyu Maurya

#include <iostream>
#include <map>
#include <cstring>
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

bool isBracket(char c)
{
    if (c == '[' or c == '{' or c == '(' or c == ')' or c == '}' or c == ']')
        return true;
    return false;
}

bool isOpen(char c)
{
    if (c == '[' or c == '{' or c == '(')
        return true;
    return false;
}

map<char, char> close;

bool isBalance(char *s, char *e)
{
    if (*s == '\0')
        return true;
    if (e < s)
        return true;
    if (!isBracket(*s))
        return isBalance(s + 1, e);
    if (!isBracket(*e))
        return isBalance(s, e - 1);

    char *t;
    int count = 0;
    //finding its closing count for handelling ((()))
    for (t = s + 1; *t != '\0'; t++)
    {
        if (*t == *s)
            count++;
        else if (*t == close[*s] and count > 0)
            count--;
        else if (close[*s] == (*t) and count == 0)
            break;
    }
    if (*t != '\0' and t != e)
    {
        return isBalance(s + 1, t - 1) and isBalance(t + 1, e);
    }
    if (close[*s] == (*e))
    {
        if (isBalance(s + 1, e - 1))
            return true;
    }
    return false;
}

int main()
{
    char c[100];
    close['['] = ']';
    close['{'] = '}';
    close['('] = ')';
    cin >> c;
    if (isBalance(c, c + strlen(c) - 1))
        cout << "true";
    else
        cout << "false";
    return 0;
}
