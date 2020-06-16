#include<iostream>
#include<unordered_map>
#include<cstring>
#include<string>
using namespace std;

class Student{
   public:

   string firstname;
   string lastname;
   string rollno;

   Student(string f,string l, string no){
        firstname = f;
        lastname = l;
        rollno = no;
   }
   bool operator ==(const Student &s) const{
      return rollno == s.rollno?true:false;
   }
};

class Hashfun{

    public:
    size_t operator()(const Student &s) const{
       return s.firstname.length()+s.lastname.length();
    }
};

int main(){

    unordered_map<Student,int,Hashfun> student_map;

    Student s1("Sourav","Rao","010");
    Student s2("MUkU", "jadu", "020");
    Student s3("ramu", "yadav", "030");
    Student s4("Riddhi", "daga", "010");

    //Add student  - marks to hashmap
    student_map[s1] = 100;
    student_map[s2] = 50;
    student_map[s3] = 7;
    student_map[s4] = 55;

    //to find only marks
    cout<<student_map[s4]<<endl;

    //iterator over all students
    for(auto s:student_map){
       cout<<s.first.firstname<<" "<<s.first.rollno<<" Marks "<<s.second<<endl;
    }

    return 0;
}