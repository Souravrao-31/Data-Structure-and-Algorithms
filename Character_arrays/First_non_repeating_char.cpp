#include<bits/stdc++.h>
using namespace std;


char first_non_repeating_char(string str){

    int n = str.length();
    char c;
    map<char,int> hmp;
    map<char,int>::iterator it;
     
     if(str.empty())
        return '0';

    for(int i=0;i<n;i++){
        c =str.at(i);
        it = hmp.find(c);
        if(it != hmp.end()){
            it->second += 1;
        }
        else{
            hmp.insert(pair<char,int>(c,1));
        }
    }

    for(int i=0;i<n;i++){
        c =str.at(i);
        it = hmp.find(c);
        if(it->second == 1){
            return c;
        }
    }
    return '0';

}
//
int main(){
    
    string str;
    getline(cin,str);
    cout<<first_non_repeating_char(str);
    return 0;
}