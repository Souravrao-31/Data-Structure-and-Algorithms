#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#include <cstdio>
#define FIO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int,int>
#define vll vector<int>
#define matrix vector<vll>
#define vllp vector<pii>
#define vllb vector<bool>
#define uset unordered_set<int>
#define pb(x) push_back(x)
#define endl '\n'
#define inf 1e18
#define mod 1000000007
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define facebook(t) cout<<"Case #"<<t<<": ";
#define pi 3.1415926536
using namespace std;

typedef tree <
pair<int, int>,
     null_type,
     less<pair<int, int>>,
     rb_tree_tag,
     tree_order_statistics_node_update >
     ordered_set;
void solve(int t) {

	int n;
	cin >> n;
	vll arr(n);
	priority_queue<pii> pq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0) pq.push({arr[i], i + 1});
	}

	vllp res;
	while (pq.size() > 1) {

		auto x = pq.top();
		pq.pop();
		auto y = pq.top();
		pq.pop();
		res.push_back({x.second, y.second});
		if (x.first > 1) {
			pq.push({x.first - 1, x.second});
		}
		if (y.first > 1) {
			pq.push({y.first - 1, y.second});
		}
	}
	cout << res.size() << endl;
	for (auto x : res) {
		cout << x.first << " " << x.second << endl;
	}

}

int32_t main() {
	FIO
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}