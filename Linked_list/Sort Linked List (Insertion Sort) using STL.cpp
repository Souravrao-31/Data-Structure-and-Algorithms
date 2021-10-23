/*
    Q) Given a linked list with n nodes. Sort the linked list using
    insertion sort.

Input Format
First line contains the number of nodes in the linked list n
and then next line contains n space separated integers representing
the node values of the linked list.

Constraints
n < 30

Output Format
Print the linked list after sorting it using insertion sort.

Sample Input
5
2 3 4 1 5


Sample Output
1 2 3 4 5



done it using STL


*/

#include <iostream>
#include <algorithm>
#include <forward_list>
using namespace std;



class Node
{
    public:
    
    int data;
    Node * next;
};


void createlinklist(Node*&head, int n)
{
    Node* temp;
    
    for(int i=0;i<n ;i++)
    {
        Node* newnode = new Node();
        
       // cout << "Enter the data of link " << i << " : ";
        cin>>newnode->data;

        newnode->next=NULL;
        
        
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        
        else
        {
            temp->next=newnode;
            // for adding node after a given node 
            temp=temp->next;
        }
    }
}





void insertionSort(int n, int arr[])
{
    
    int e;
    int j;
    
    for(int i = 1; i < n-1; i++)
    {
        e = arr[i];
        
        j = i-1;
        
        while(j>=0 && arr[j] > e)
        {
            
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = e;
        
    }
    
    
}



int main()
{
    
    int n;
    cin >> n;
    
    forward_list <int> name;
    
    int data;
    
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        name.push_front(data);
    }
    
    name.sort();
    
    for(auto i : name)
    {
        cout << i << " ";
    }


    return 0;
}


/*

Output
5
2 3 4 1 5
1 2 3 4 5 


*/
