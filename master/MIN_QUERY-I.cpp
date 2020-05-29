#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,q,o,l,r;
    cin>>n>>q;
    vector<int> arr(n,0);
    for(auto& i:arr) cin>>i;
    for (long i = 0; i < q; i++)
    {
        cin>>o>>l>>r;
        if (o==1)
        {
            //cout<<*min_element(arr.cbegin()+l-1,arr.cbegin()+r)<<"\n";
            int min=arr[l-1];
            for (int i = l; i < r; i++)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                }    
            }   
            cout<<min<<'\n';         
        }
        else if (o==2)
        {   
            //replace_if(arr.begin(),arr.end(),[&](auto& i) { return i == l;},r);
            for (int i = 0; i < n; i++)
            {
                if (arr[i]==l)
                {
                    arr[i]=r;
                }
                
            }
            
        }    
    }    
    return 0;
}
