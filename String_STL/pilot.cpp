#include <iostream>
#include <string>
using namespace std;
int main(){
    string s0;
    string s1("Hello");
    string s2 ="sourav";
    string s3(s2);
    string s4(s3);

    char a[] ={'z','x','b','\0'};
    string s5(a);

    cout<<s0<<endl;
    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    if(s0.empty()){
        cout<<"s0 is an empty string"<<endl;
    }
    

    //append

    s0.append("I love c++");
    cout << s0 << endl;

    s0 += "and python";
    cout << s0 << endl;

    //Remove
    cout<<s0.length()<<endl;
    s0.clear();  //after clear it will remove
    cout << s0.length() << endl;

    //compare two strings
    s0 ="Apple";
    s1 ="Mango";
    cout<<s1.compare(s0)<<endl;
    cout<<s0.compare(s1)<<endl;

    //overload operators
    if(s1 > s0){
        cout<<"Mango is lexi greater than apple"<<endl;
    }

cout<<s0[0]<<endl;


//substrings
string s ="I want to have apple juice";
int idx =s.find("apple");
cout<<idx<<endl;


//remove a word from the string
string word ="apple";
int len =word.length();

cout<<s<<endl;
s.erase(idx,len);
cout<<s<<endl;

//Iterate over all the char in the string
for(int i=0;i<s1.length();i++){
    cout<<s1[i]<<":"<<endl;
}

  //iterators
  for (auto it = s1.begin(); it != s1.end(); it++)
  {
      cout<<(*it)<<" ,"<<endl;
  }
  
  //for each loop
  for(auto c:s1){
      cout<<c<<":::"<<endl;
  }


    return 0;
}