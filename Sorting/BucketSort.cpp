#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student{
    public:
    int marks;
    string name;
};

//Bucket sort to student an array of students

void bucket_sort(Student s[],int n){

    //assuming marks are in range
    vector<Student> v[101];

    for(int i=0;i<n;i++){    //O(N)
      int m =s[i].marks;
      v[m].push_back(s[i]);
    }

    for(int i=100;i>=0;i--){
        for(vector<Student>::iterator it=v[i].begin();it!=v[i].end();it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }

}


int main(){
    Student s[100000];
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
     cin>>s[i].marks >>s[i].name;
    }
    bucket_sort(s,n);
    
    return 0;
}