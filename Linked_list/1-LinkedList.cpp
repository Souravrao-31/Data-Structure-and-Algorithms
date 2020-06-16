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
         n->next =temp ->next; //jisko dalna h wo next element ko point krega
         temp->next =n;  //jha dalna h uske phle ement ko ise jodega
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
     //if linked list is empty
    if(head == NULL){
    return;
    }
    node*temp = head;

    //If head is to be removed
    if(p == 0){
    head = temp->next;
    free(temp);
    return;
    }
    // If position is more than number of ndoes
    for(int i=0; temp!=NULL && i<p-1;i++){
       temp = temp->next;
    }

    //if position is more than number of node
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     node*next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list
}

//Runner technique
node*midpoint(node*head){
    //middle of LL
  if(head == NULL || head->next == NULL){
    return head;
  }
  node*slow = head;
  node*fast = head->next;

  while(fast != NULL && fast->next != NULL ){
    fast = fast->next->next;
    slow = slow->next;
  }
   return slow;

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

istream& operator>>(istream& is,node*&head){
    Built_list(head);
    return is;
}

ostream& operator<<(ostream &os, node*head)
{
    print(head);
    return os;
}

void reverse(node*&head){
   node*C=head;  //Current
   node*P=NULL;  //Previous
   node*N;       //
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

node *Reverse_rec(node*&head){
    //Base case
    if(head->next == NULL || head == NULL){
       return head;
    }
    //Rec case
    node*smallHead = Reverse_rec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}

node*Merge_sorted_arr(node*a,node*b){
    if(a==NULL){
       return b;
    }
    else if(b==NULL){
       return a;
    }

    node*c;

    //Compare a and b for smaller element
    if(a->data < b->data){
       c = a;
       c->next = Merge_sorted_arr(a->next,b);

    }
    else{
        c=b;
        c->next = Merge_sorted_arr(a,b->next);
    }
    return c;
}
node*merge_sort(node*head){
    //T(n) = O(nlogn)  with base2
   //Base case
   if(head==NULL || head->next==NULL){
       return head;
   }
   //Rec case
   //1. Mid point
   node*mid = midpoint(head);

   node*a = head;
   node*b = mid->next;
   mid->next = NULL;

   //2. Recursively sort
   a=merge_sort(a);
   b=merge_sort(b);

   //3. Merge a and b
   node*c = Merge_sorted_arr(a,b);
   return c;
}

bool DetectCycle(node*head){
    /*
    Given a linked list, check if the linked list has loop or not.
    */
    //Floyd-cycle
    node*slow = head;
    node*fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main()
{

        node *head = NULL;
        //node *head2 =NULL;

         //InsertAtHead(head, 5);
        //  InsertAtHead(head, 4);
        //  InsertAtHead(head, 3);
        
        // insertAtTail(head,6);
        //insertAtTail(head, 1);
        //insertAtTail(head, 2);
        //InsertAtMiddle(head, 10, 4);
        // cout << "Length of LL " << length(head) << endl;

       
        // print(head);
        //reverse(head);

        //deleteAtHead(head);

       // deleteAtTail(head);
        //  deleteAtMiddle(head, 3);
        //  print(head);

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
         //Built_list(head);

         // print(head);

         //cin>>head>>head2;  //1 2 6 9 11 -1
         //cout<<head<<endl<<head2<<endl;  // 9 10 20 -1
         //print(head);
         
         //head = Reverse_rec(head);
         //print(head);
         //node*m = midpoint(head);
         //cout<<m->data;
          
        //  head = Merge_sorted_arr(head,head2);
        //  cout<<"Merged LL  "<<head;
        // cin>>head;
        // head = merge_sort(head);
        // cout<<head;
        

        return 0;
}