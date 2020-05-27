#include <iostream>
#include <cstring>

using namespace std;
int main(){

    char a[1000];
    char largest[1000];

    int n;
    cin>>n;

     int len=0;
     int largest_len=0;

    cin.get(); 
         //for removing null space
    
    for(int i=0;i<n;i++){
         cin.getline(a,1000);
         
         len=strlen(a);
         if(len > largest_len){
             largest_len =len;
             strcpy(largest,a);

         }
     

    }

    cout << largest << " and " << largest_len << endl;
    return 0;

}