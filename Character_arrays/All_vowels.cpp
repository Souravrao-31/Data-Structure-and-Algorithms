#include<bits/stdc++.h>

using namespace std;

bool isvowel(char ch){

        if(ch == 'a' || ch == 'e' || ch =='i' || ch =='o' || ch == 'u')

        return true;

    return false;

}

int main(){

        ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);

        int n; cin>>n;

        string str;

        cin>>str;

        set<char>s;

        for(int i = 0 ; i < n; i++){
             if(isvowel(str[i])){
                  s.insert(str[i]);
             }
       
        }

        

        if(s.size() == 5){
           cout<<"YES";
        }

     

        else

        cout<<"NO";

        return 0;

}

 