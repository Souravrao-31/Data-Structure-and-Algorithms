#include <iostream>
using namespace std;
int main(){

    int n,i;
    cin>>n;
    int a[1005];

    for(i =0;i<n;i++){
        cin>>a[i];
    }

    //cin>>key;2


   int largest =__INT_MAX__;
   int smallest =INT8_MIN;
   for ( i = 0; i < n; i++)
   {
       if (a[i]>largest)
       {
           largest=a[i];
       }
       if (a[i]<smallest)
       {
           smallest=a[i];
       }
 
   }
   
 
 cout<<"largest "<<largest<<endl;
 cout<<"smallest "<<smallest<<endl;
    return 0;
}