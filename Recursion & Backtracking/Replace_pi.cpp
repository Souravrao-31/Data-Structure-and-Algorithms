#include<iostream>
using namespace std;
/*
Replace pi with 3.14
abcdpixyzxpi     abcd3.14xyz3.14
without using extra space
*/
void repl_pi(char a[],int i){
    if(a[i] == '\0' or a[i+1] == '\0'){
        return;
    }
    if (a[i] == 'p' and a[i+1] =='i')
    {    int j = i + 2;
         //
        while(a[j] != '\0'){
          j++;
        }
        while(j >= i+2){
            a[j+2] = a[j];
           j--;
        }
        //Replace + recursive call
        a[i] ='3';
        a[i+1] ='.';
        a[i+2] ='1';
        a[i+3] ='4';
        repl_pi(a,i+4);   //Go +4 position
    }
    else{
        //Go to the next position
        repl_pi(a,i+1);
    }
    
}
int main(){
    char a[100];
    cin>>a;
    repl_pi(a,0);
    cout<<a;

    return 0;
}