#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(int argc,char const *argv[]){
    
    queue<char> q;
    unordered_map<char,int> mp;

    char ch;
    cin>>ch;
    
    while(ch !='.'){
      q.push(ch);
      mp[ch]++;

      while(!q.empty()){
        if(mp[q.front()] > 1){
        q.pop();
        }
        else{
          cout<<q.front()<<"";
          break;
        }
      }
      if(q.empty()){
        cout<<"-1 ";
      }
     cin>>ch;
    }
    return 0;
}