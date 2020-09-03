#include <iostream> 
#include <vector>

using namespace std; 

class Missing{

public:
 
    int findMissing(vector<int> &ar) 
    { 
      int l = 0, r = ar.size(); 
    while (l <= r) { 
  
        int mid = (l + r) / 2; 
  
        // If this is the first element  
        // which is not index + 1, then  
        // missing element is mid+1 
        if (ar[mid] != mid + 1 &&  
                        ar[mid - 1] == mid) 
            return mid + 1; 
  
        // if this is not the first missing  
        // element search in left side 
        if (ar[mid] != mid + 1) 
            r = mid - 1; 
  
        // if it follows index+1 property then  
        // search in right side 
        else
            l = mid + 1; 
    } 
  
    // if no element is missing 
    return -1; 





    } 


};

// Driver code 
int main() 
{  
     vector<int> v;
    
     
      int n;cin>>n;

        for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
        }
       
    Missing m;
    cout<< m.findMissing(v);

  


  
	return 0; 
} 