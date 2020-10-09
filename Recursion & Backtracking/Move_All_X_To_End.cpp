#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int i = 0 , count_x = 0 , j = 0, n = str.size() ;
    string temp;
    while(i < n ){
        if(str[i] == 'x')
        count_x+=1;
        else {
            str[j++] = str[i];
        } 
        i++;
    }
    // cout << str <<endl;
    while(count_x--){
        str[j++] = 'x';
    } 
    cout << str;
}