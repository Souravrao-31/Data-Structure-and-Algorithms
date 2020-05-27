#include <iostream>
#include <cstring>
using namespace std;
void rotate(char *a,int k){
    int i=strlen(a);
     //cout<<i<<" "<<k<<endl;     6 3
    while(i>=0){
        a[i+k]=a[i];
        i--;
    }
    i=strlen(a);
    int j=i-k;
     //cout<<i<<" "<<k<<endl;    9 3
    int s=0;
    while(j<i){
        a[s]=a[j];
        s++;
        j++;
    }
    //cout<<i<<" "<<k<<endl;    9 3
    a[i-k]='\0';
}
int main() {
    char a[100]="Sourav";
    int k=3;
    rotate(a,k);
    cout<<a;
    
}
