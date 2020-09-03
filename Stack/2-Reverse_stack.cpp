/*
We can reverse a string in O(1) time if we internally represent the stack as a linked list. Reverse a stack would require a reversing a linked list which can be done with O(n) time and O(1) extra space.

Note that push() and pop() operations still take O(1) time.
*/

#include<iostream>
using namespace std;

class Stack_Node{
public:
    int data;
    Stack_Node* next;

    Stack_Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
  Stack_Node*Top;
 public:
    //O(1)
   void push(int data){
        if(Top == NULL){
          Top = new Stack_Node(data);
          return;
        }
        Stack_Node *s = new Stack_Node(data);
        s->next = Top;
        Top = s;
   }
  
    //O(1)
   Stack_Node* pop(){
       Stack_Node*s = Top;
       Top = Top->next ;
       return s;
   }

   void display(){
       Stack_Node* s = Top;
       while(s != NULL){
         cout<<s->data<<" ";
         s = s->next; 
       }
       cout<<endl;
   }
     
     //O(n)
   void reverse(){
       Stack_Node *prev, *curr, *succ;
       curr = prev = Top;
       curr = curr->next;
       prev->next = NULL;

       while(curr != NULL){
         succ = curr->next;
         curr->next = prev;
         prev = curr;
         curr = succ;
       }
       Top = prev;
   }

};
int main(){

    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(9);

    cout<<"Stack-> "<<endl;
    s->display();
    cout<<endl;
    //reverse
    s->reverse();

    cout<<"Reversed Stack "<<endl;
    s->display();

    return 0;
}