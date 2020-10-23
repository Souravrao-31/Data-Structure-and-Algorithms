/*
Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the sum of any of the non-empty subsets of the set A is zero.

Input Format
The first line contains an integer T, which is the total number of test cases.
T test cases follow.
Each test case consists of two lines.
The first line consists of a single integer N, which is the number of elements present in the set A.
The second line contains N space separated integers denoting the elements of the set A.

Constraints
1 â¤ T â¤10
1 â¤ N â¤ 4
-10^5 â¤ A[i] â¤ 10^5

Output Format
Print the answer for each testcase in a new line.
If the sum of any of the subset is zero, then print âYesâ (without quotes) else print âNoâ(without quotes).

Sample Input
1
4
1 3 2 -3
Sample Output
Yes
Explanation
The sum of the subset {3,-3} is zero.
*/
#include<bits/stdc++.h>
using namespace std;
bool isSumZero(vector<int> v, long long int sum = 0, int index = 0, int count = 0) {
    if (index >= v.size()) {
        //cout << sum << " ";
        return (sum == 0 && count > 0);
    }
    if (isSumZero(v, sum + v[index], index + 1, count + 1)) {
        return true;
    }
    return isSumZero(v, sum, index + 1, count);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        isSumZero(v) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}