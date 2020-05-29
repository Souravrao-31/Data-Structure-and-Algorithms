// @author: Abhimanyu Maurya

#include <iostream>
#include <unordered_map>
using namespace std;
#define ll long long


ll exchange(ll n, unordered_map<ll, ll>& state)
{
    if (n <= 0)
        return 0;
    if (state.find(n) != state.end())
        return state.at(n);
    ll res = exchange(n / 2, state) + exchange(n / 3, state) + exchange(n / 4, state);
    if (res < n)
        res = n;
    state[n]=res;
    return res;
}

int main()
{
    ll n;
    cin >> n;
    unordered_map<ll, ll> state(0);
    cout << exchange(n, state);

    return 0;
}