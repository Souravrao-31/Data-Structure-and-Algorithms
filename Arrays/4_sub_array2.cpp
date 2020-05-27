#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i;
    int a[1000];
    int sum=0;
    int total=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
                sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum>total){
                total=sum;
            }
        }
    }
    cout<<"Max sum is- "<<total<<endl;
    return 0;
}
