#include<iostream>
#include<algorithm>
#include<sstream>
#include<tuple>

using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    string s;
    cin>>s;
    istringstream iss(s);
    while (iss)
    {
        int t;
        iss>>t;
        cnt++;
    }
    cout<<cnt;
    auto t = make_tuple(iss);
   for (int i = 0; i < count; i++)
   {
       /* code */
   }
   
    
    return 0;
}
