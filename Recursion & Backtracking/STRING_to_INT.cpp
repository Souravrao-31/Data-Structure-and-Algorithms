#include<iostream>
#include<cstring>
using namespace std;

int StI(char *a,int n){
   if(n==0){
     return 0;
   }
   int fetch_last_digit =a[n-1] - '0';   //fetch last digit.....
   int small_ans = StI(a,n-1);

   return small_ans * 10 + fetch_last_digit;

}
int main(){
    //We are going to apply reccursive  
    char a[] ="1234";
    int n = strlen(a);
    int x=StI(a,n);
    cout<<x<<endl;
    cout << x + 1;

    return 0;
}