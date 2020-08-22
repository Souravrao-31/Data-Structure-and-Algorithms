#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
	int t;
	cin>>t;
	while(t>0)
    {
    //getline(cin,s1);
	//getline(cin,s2);
    cin>>s1>>s2;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '0';
        }
        else
        {
            s1[i] = '1';
        }
    }
    cout << s1 << endl;
	t--;
    }
    return 0;
}