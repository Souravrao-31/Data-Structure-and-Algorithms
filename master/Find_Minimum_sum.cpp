// @author: Abhimanyu Maurya


#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;


//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);


int main()
{
    int t, k, freq[26];
    cin>>t;
    while (t--)
    {
        memset(freq,0,sizeof(freq));
        cin>>k;
        string s;
        cin>>s;
        for (int i = 0; s[i]!='\0' ; i++)
        {
            freq[s[i]-'a']++;
        }
        sort(freq,freq+26,greater<int>());
        while (k>0 and freq[0]>0)
        {
            freq[0]--;
            k--;
            sort(freq, freq + 26, greater<int>());
        }
        int sum = 0;
        for (int i = 0; i <26; i++)
        {
            if(freq[i]>0)
            {
                sum+=(freq[i]*freq[i]);
            }
            else break;
        }
        cout<<sum<<"\n";
    }
    
    return 0;
}
