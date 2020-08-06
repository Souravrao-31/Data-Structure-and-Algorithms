#include <iostream>
using namespace std;

/*

ake as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes and print the ans.

Output Format
String

Sample Input
acb
Sample Output
a2c-1b
*/
int main() 
{
    string str;
    cin>>str;

    for(int i=0;i<str.length()-1;i++)
    {
        cout<<str[i]<<str[i+1]-str[i];  
    }
    cout<<str[str.length()-1];
    return 0;
}