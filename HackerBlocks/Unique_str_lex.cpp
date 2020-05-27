#include<iostream>
#include<stack>
#include<climits>

using namespace std;



void str(){
   char a[1000001];
   cin>>a;
   int last_index[26] ={0};
   int presentInstack[26] ={0};
   for (int i = 0; a[i] != '\0'; i++)
   {
       
       last_index[a[i] -'a'] =i;
   }

   stack <int> s;

   for(int i=0;a[i] != '\0';i++){
        char ch =a[i];
        if(!presentInstack[ch -'a']){
            while(!s.empty() && ch <s.top() && last_index[s.top() - 'a'] > i){
                presentInstack[s.top()-'a'] =false;
                s.pop();
            }

            s.push(ch);
            presentInstack[ch-'a']=true;
        }
   }
   
    int k=s.size();
    char *ans =new char[k+1];
    ans[k--]='\0';
    
    while(!s.empty() ){
       ans[k]=s.top();
       s.pop();
       k--;
    }
    cout<<ans<<endl;
}

int main(){
    str();
    return 0;
}