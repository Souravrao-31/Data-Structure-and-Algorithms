#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a,string b){
    
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length() > b.length();

}

int main(){
    int n;
    cin>>n;
    //instead of using this char s[1000];
    //we will use vectors
    cin.get();

    string s[1000]; //vector

    

    for(int i=0;i<n;i++){
        getline(cin,s[i]); //cin.getline will not work

    }

    sort(s, s + n,compare);

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
     }


    return 0;
}