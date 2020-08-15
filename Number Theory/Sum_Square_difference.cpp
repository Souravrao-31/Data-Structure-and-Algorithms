#include<iostream>
using namespace std;
/*project euler 6

The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .
*/

//O(1)
int sum(){
    long sum = 0;
    long squared = 0;
    long result = 0;
    
    const int N = 100;  // we cam change the value N
    
    sum = N * (N+1)/ 2;
    squared = (N * (N + 1) * (2 * N + 1)) / 6;
    
    result = sum * sum - squared;
    return result;
}
int main(){

  cout<<sum();
}

