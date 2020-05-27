#include <iostream>
#include <cstring>
using namespace std;

bool ispermutation(char *s1,char *s2){
    int l1=strlen(s1);
    int l2=strlen(s2);
    if (l1!=l2){
        return false;
    }
    //checking frequency
    int freq[26] ={0};
//for s1
    for(int i=0;i<l1;i++)
    {
        freq[s1[i]-'a']++;
    }
    //for s2
    for(int j=0;j<l2;j++){
        freq[s2[j]-'a']--;
    }
    //
    for(int i=0;i<26;i++){
       if(freq[i]!=0) {
           return false;
       }
    }
    return true;

}
int main() {
    char s1[100];
    char s2[100];
    cin>>s1>>s2;
    if(ispermutation(s1,s2))
    {
        cout<<"Yes it is a permutation"<<endl;
    }
    else
    {
        cout<<"It is not"<<endl;
    }
}
