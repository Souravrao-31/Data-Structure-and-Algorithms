#include<iostream>
using namespace std;
//https://ide.codingblocks.com/s/221887

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int d){
        data =d;
        next =NULL;
    }

};

/*
class LinkedList{
  node*head;
  node*tail;
  public:
  LinkedList(){
      head=NULL;
      tail =NULL;
  }

};
*/


//passing a pointer variable by reference by *&head

void InsertAtHead(node*&head,int data){

   node*n = new node(data);    //DMA make new node
   n -> next =head;
   head =n;


}

int length(node*head){
   int len=0;
   while(head != NULL){
      head = head ->next;
      len +=1;

   }
   return len;

}

void insertAtTail(node*&head,int data){
   if(head == NULL){
    head= new node(data);
        return;
   }
  node*tail =head;
  while(tail->next != NULL){
    tail = tail ->next;
  }
  tail->next =new node(data);
  return;

}

void InsertAtMiddle(node *&head, int data,int p)
{
     if(head==NULL || p==0){
        InsertAtHead(head,data);
     }
     else if(p>length(head)){
          insertAtTail(head,data);
     }
     else{
         //insert in the middle
         //take the p-1 jump
         int jump=1;
         node*temp =head;
         while(jump <= p-1){
              temp = temp -> next;
              jump +=1;
            }
         node*n =new node(data);
         n->next =temp ->next;
         temp->next =n;
     }

}

    void print(node * head)
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }

void deleteAtHead(node*&head){
     if(head == NULL){
        return;
     }
     node*temp =head;
     head=head->next;
     delete temp;
     return;

}
void deleteAtTail(node*&head){
    
    node*prev =NULL;
    node*temp=head;

    while(temp ->next != NULL){
           prev=temp;
           temp= temp->next;

    }
    delete temp;
    prev ->next = NULL;
    return;


}

void deleteAtMiddle(node*head,int p){
     //

}

bool Search_Recursive(node*head,int key){

   //base case
   if(head == NULL){
       return false;
   }
   //rec case
   if(head ->data==key){
      return true;
   }
   else{
       return Search_Recursive(head->next,key);
   }
}

bool Search_Iteratively(node *head, int key)
{
    while(head != NULL){
       if(head ->data == key){
             return true;
       }
       head = head ->next;
    }
    return false;

}

bool Built_list(node*&head){
   int data;
   cin>>data;

   while(data != -1){
      insertAtTail(head,data);
      cin>>data;
   }

}

istream& operator >>(istream& is,node*&head){
    Built_list(head);
    return is;
}

ostream& operator<<(ostream &os, node*head)
{
    print(head);
    return os;
}

void reverse(node*&head){
   node*C=head;
   node*P=NULL;
   node*N;
   while(C != NULL){
     //save the next node
     N = C->next;
     //make the current node point to previous
     C->next=P;
     //just update prev and current
     P=C;
     C=N;
   }
    head=P;
}


int main()
{

        node *head = NULL;
        //node *head2 =NULL;

        //InsertAtHead(head, 5);
        //InsertAtHead(head, 4);
       // InsertAtHead(head, 3);

        //insertAtTail(head,6);

        //InsertAtMiddle(head,2,2);
        //print(head);
        //reverse(head);

        //deleteAtHead(head);

       // deleteAtTail(head);
        
        /*
        if(Search_Recursive(head,4)){
            cout<<"Element is Present"<<endl;
         }
         else{
             cout<<"Not Present"<<endl;
         }

         if (Search_Iteratively(head, 14))
         {
             cout << "Element is Present" << endl;
         }
         else
         {
             cout << "Not Present" << endl;
         }
       
       
       */
        Built_list(head);
        reverse(head);

        print(head);


        //cin>>head>>head2;
        //cout<<head<<endl<<head2;

        return 0;
}