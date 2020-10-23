#include<iostream>
#include<stack>
#define ll long long
using namespace std;

int prime[100000];

/*
You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

Input Format
First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints
N < 10^5
Q < 10^5
|Ai| < 10^9

Output Format
Output N lines, each line containing the number written on the card.

Sample Input
5 1
3 4 7 6 5
Sample Output
4
6
3
7
5
*/

int * primeSieve(){
    int n=100000;

    int p[100000];

    for(ll i=3;i<=n;i+=2) 
        p[i]=1;
        
    for(ll i=3;i<=n;i+=2){
        if(p[i])
        {
            for(ll j=i*i;j<=n;j+=2*i) 
             p[j]=0;
        }
    }

    p[2]=1;
    p[0]=p[1]=0;

    
    int c=0;
    for(int i=0;i<100000;i++){
        if(p[i]){
            prime[c]=i;
            c++;
        }
    }

    return prime;

}

int main(){
    int *prime=primeSieve(); // genrate prime
    int n,q;
    cin>>n>>q;
    stack<int> a[q+1];
    stack<int> b[q+1];  //make stacks array

   for(int i=0;i<n;i++){  // take input in a[0] stack
       int d;
       cin>>d;
       a[0].push(d);
   }

   for(int i=0;i<q;i++){
       int p=prime[i];
      
       while(!a[i].empty()){
            
            int d=a[i].top();
            
            if(d%p==0){   // if(a[i].top() % prime[i]==0) push into b else a
                b[i+1].push(d);
                
            }
            else{
                a[i+1].push(d);
               
            }
            a[i].pop();
       }
       
   }
   for(int i=0;i<q;i++){  // print from b1 to bq
       while(!b[i+1].empty()){
            cout<<b[i+1].top()<<endl;
            b[i+1].pop();
        }
   }

   while(!a[q].empty()){   // print aq
            cout<<a[q].top()<<endl;
            a[q].pop();
    }


   
}