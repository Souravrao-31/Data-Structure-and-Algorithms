#include <bits/stdc++.h>

#define pb push_back
#define MAX 10000000
#define ll long long int

using namespace std;

using u64 = uint64_t; //64 bit
using u128 = __uint128_t; // 128 bit

vector <int> primes  = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

u64 binpower(u64 base, u64 ex, u64 mod) {
	base %= mod;
	u64 res = 1;

	while(ex > 0) { // ex
		if(ex & 1) {
			res = (u128) res * base % mod;
		}
		base = (u128) base * base % mod;
		ex >>= 1; // ex = x / 2;
	}
	return res;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
	u64 x = binpower(a, d, n);
	if(x == 1 or x == (n - 1)) {
		return false;
	}

	for(int r = 1; r < s; r++) {
		x = (u128) x * x % n;
		if(x == (n - 1)) {
			return false;
		}
	}
	return true;
}

bool millerrobin(u64 n) {
	if(n < 2) return false;

	int r = 0;
	u64 d = n - 1;
	while((d & 1) == 0) {
		d >>= 1;
		r++;
	}
	for(int p : primes) {
		if(n == p) {
			return true;
		}
		if(check_composite(n, p, d, r)) {
			return false;
		}
	}
	return true;
}

void init()
{	
	u64 t;
	cin >> t;
	while(t--) {
		u64 n;
		cin >> n;
		if(millerrobin(n)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
int main()
{		 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		 
	init();
		 
	return 0;
}