#include <iostream>
#include <unordered_map>
using namespace std;

/*
10
apple
apipie
appy
ape
boy
bottle
man
mango
sam
samsung
3
api
0
apipie
1
mang
0
*/
class Node {
    public:
    char data;
    bool terminal;

    unordered_map<char, Node*> children;

    Node(char data){
       this->data = data;
       this->terminal = false;
    }
};

class Trei{
    public:
   Node* root;
   int count;

   Trei(){
       this->root = new Node('\0');
       this->count = 0;
   }
   void addword(string str){
       Node *temp = root;
       for(int i = 0; i < str.size();i++){
           char ch = str[i];
          if(temp->children.count(ch)){
            temp = temp->children[ch];
          }
          else{
            Node *n = new Node(ch);
            temp->children[ch] = n;
            temp = n;
          }
       }
       temp->terminal = true;
   }

     bool Search(string str){
       Node *temp = root;
       for(int i = 0; i < str.size();i++){
           char ch = str[i];
          if(temp->children.count(ch)){
            temp = temp->children[ch];
          }
          else{
            return false;
          }
       }
        return temp->terminal ;
   }

};


int main(){
    
    Trei t;
    int n; cin >>n;

    while(n--){
        string str;
        cin>>str;
        t.addword(str);
    }

    int q;
    cin >>q;

    while(q--){
        string str;
        cin >>str;
        cout << t.Search(str) << endl;
    }
    return 0;
}