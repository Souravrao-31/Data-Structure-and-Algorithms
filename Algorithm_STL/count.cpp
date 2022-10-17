#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    cout << "This program demonstrates the use of the count() STL method\n";

    vector<int> numbers = { 10,20,30,50,10,20,10,85,83,17,10,85,10 };
    
    cout << "Original List of Numbers : ";
    for (size_t i = 0; i < numbers.size(); ++i)
        cout << numbers[i] << " ";
    cout << endl;

    cout << "There are " << count(numbers.begin(), numbers.end(), 10) << " 10s in the list\n";
    cout << "There are " << count(numbers.begin(), numbers.end(), 20) << " 20s in the list\n";
    cout << "There are " << count(numbers.begin(), numbers.end(), 85) << " 85s in the list\n";
    cout << "There are " << count(numbers.begin(), numbers.end(), 11) << " 11s in the list\n";
    cout << "There are " << count(numbers.begin(), numbers.end(), 17) << " 17s in the list\n";

    return 0;

}

