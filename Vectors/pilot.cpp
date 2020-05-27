#include <iostream>
#include <vector>
using namespace std;

int main(){

 vector <int> a;
 vector<int> b(5,10); //10 10 10 10 10
 vector<int> c(b.begin(),b.end());
 vector<int> d{1,2,3,4,5};

 //how can we iterate over the vector 3 m3thods
 for(int i=0;i<c.size();i++){
     cout<<a[i]<<" :";            //c
 }
  cout<<endl;

  for (auto it =b.begin();it != b.end();it++){
      cout<<(*it)<<" ";       //b
  }

  for(int x:d){
      cout<<x<<" ,";     //d
  }

  //Discuss more functions

  vector<int> v;
  int n;
  cin >> n;
  v.reserve(100);
  cout << v.capacity();
  cout << endl;

  for (int i = 0; i < n; i++)
  {
      int temp;
      cin >> temp;
      v.push_back(temp); //add element
  }

  v.pop_back(); //remove element from vector

  sort(v.begin(), v.end());

  
  for (int i = 0; i < v.size(); i++)
  {
      cout << v[i] << " ";
  }

  return 0;
}