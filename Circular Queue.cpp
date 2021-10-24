##Circular Queue

#Algorithm

//Insertion of an element

//STEP 1 START
//STEP 2 Store the element to insert in linear data structure
//STEP 3 Check if (front == 0 && rear == MAX-1) || (front == rear+1) then queue Overflow else goto step 4
//STEP 4 Check if (front == -1) then front = 0; rear= 0; else goto step 5
//STEP 5 Check if (rear == MAX -1) then rear=0; else rear= rear+1; and goto step 6
//STEP 6 Insert element cqueue_arr[rear] = item;
//STEP 7 STOP

##Program

#include <iostream>  
#define MAX 5  
using namespace std;  
/* 
 * Class Circular Queue 
 */  
class Circular_Queue  
{  
    private:  
        int *cqueue_arr;  
        int front, rear;  
    public:  
        Circular_Queue()  
        {  
            cqueue_arr = new int [MAX];  
            rear = front = -1;  
        }  
          
        void insert(int item)  
        {  
                int i=0;  
    while(1)  
    {  
     cout<<"If you want to enter the element in queue press 1 else 0\n";  
     cin>>i;  
     if(i==1)  
  
         {  if ((front == 0 && rear == MAX-1) || (front == rear+1))  
            {  
                cout<<"Queue Overflow \n";  
                return;  
            }  
            if (front == -1)  
            {  
                front = 0;  
                rear = 0;  
            }  
            else  
            {  
                if (rear == MAX - 1)  
                    rear = 0;  
                else  
                    rear = rear + 1;  
            }  
            cqueue_arr[rear] = item ;  
          }  
          else  
          display();}  
        }  
            void display()  
        {  
            int front_pos = front, rear_pos = rear;  
            if (front == -1)  
            {  
                cout<<"Queue is empty\n";  
                return;  
            }  
            cout<<"Queue elements :\n";  
            if (front_pos <= rear_pos)  
            {  
                while (front_pos <= rear_pos)  
                {  
                    cout<<cqueue_arr[front_pos]<<"  ";  
                    front_pos++;  
                }  
            }  
            else  
            {  
                while (front_pos <= MAX - 1)  
                {  
                    cout<<cqueue_arr[front_pos]<<"  ";  
                    front_pos++;  
                }  
                front_pos = 0;  
                while (front_pos <= rear_pos)  
                {  
                    cout<<cqueue_arr[front_pos]<<"  ";  
                    front_pos++;  
                }  
            }  
            cout<<endl;  
        }  
};  
int main()  
{  
    int item;  
    Circular_Queue cq;  
    cout<<"Input the element for insertion in queue : ";  
            cin>>item;      
            cq.insert(item);  
            cq.display();  
               return 0;  
}  


##Output
 /*   
If you want to enter the element in queue press 1 else 0                                                                           
1                                                                                                                                  
Inset the element in queue : 5                                                                                                    
If you want to enter the element in queue press 1 else 0                                                                           
1                                                                                                                                  
Inset the element in queue : 10                                                                                                    
If you want to enter the element in queue press 1 else 0                                                                           
1                                                                                                                                  
Inset the element in queue : 15                                                                                                    
If you want to enter the element in queue press 1 else 0                                                                           
0                                                                                                                                  
Queue is :                                                                                                                         
5 10 15                                                                                                                           
         */        


