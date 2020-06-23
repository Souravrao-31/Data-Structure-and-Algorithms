//BALIFE
/*
3
0 99 3

2
49 50

8
16 17 15 0 20 1 1 2

10
0 0 100 0 0 0 0 0 0 0

-1
o/p
34
-1
23
70

*/
#include<iostream >
using namespace std;

int main(){
    
    int arr[9000];
    int n, i, val, diff;

    while(1){
        //take input current test case
        int max_load = 0, load= 0;
        cin>>n;

        //Stop taking input if N = -1
        if(n == -1){
           break;
        }
        for(int i = 0; i<n;i++){
            cin >> arr[i];
            load += arr[i];
        }
        if(load%n != 0){
           cout<<-1<<endl;
        }
        //Find the load that is  to be divided equally
        load = load/n;

        //Greedy step
        for (int i = 0; i < n; i++)
        {
            // find the difference between final load to be assigned and current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout<<max_load<<endl;
    }
    return 0;
}