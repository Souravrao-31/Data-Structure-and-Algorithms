#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
   unordered_map<string,vector<string> > phonebook;

   phonebook["Sourav"].push_back("7999037409");
   phonebook["Riddhi"].push_back("28511409");
   phonebook["Rp"].push_back("787409");
   phonebook["Muku"].push_back("79409");
   phonebook["Kajal"].push_back("79990");

   for(auto p:phonebook){
     cout<<"Name "<<p.first<<" -> ";
     for(string s:p.second){
        cout<<s<<",";
     }
     cout<<endl;
   }

   //
   string name;
   cin>>name;

   if(phonebook.count(name)==0){
       cout << "Absent";
   }
   else{
       for(string s:phonebook[name]){
         cout<<s<<endl;
       }
     
   }
   return 0;
}