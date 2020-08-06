#include<iostream>

using namespace std;

int main(){ //O(n)   O(n)
    int N;
    cin>>N;

    int Repeating,Missing;
    int arr[N];
    bool present[N+1] = {false};

    for(int i=0;i<N;i++){
        cin>>arr[i];
      if(present[arr[i]]==true) Repeating=arr[i];

      present[arr[i]] = true;
        
    }

    for (int i = 1; i < N; i++)
    {
        if(present[i] == false){
          Missing = i;
          break;
        } 
    }
    
    cout<<Repeating<<"  "<<Missing;
}