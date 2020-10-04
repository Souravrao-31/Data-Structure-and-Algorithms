#include <bits/stdc++.h>
#define lop(i,a,n) for(int i=a;i<n;i++)
#define ll long long int
#define F first
#define S second
#define pb push_back
using namespace std;

const int N = 1001;
typedef pair<ll, ll> pii;
vector <ll> v;
ll mat[N][N], aux[N][N];

void makematrix(ll M, ll N)
{
     for (ll i = 0; i < N; i++)
          aux[0][i] = mat[0][i];

     for (ll i = 1; i < M; i++)
          for (ll j = 0; j < N; j++)
               aux[i][j] = mat[i][j] + aux[i - 1][j];

     for (ll i = 0; i < M; i++)
          for (ll j = 1; j < N; j++)
               aux[i][j] += aux[i][j - 1];

}
inline ll get(ll tli, ll tlj, ll rbi, ll rbj)
{
     ll res = aux[rbi][rbj];
     if (tli > 0)
          res = res - aux[tli - 1][rbj];
     if (tlj > 0)
          res = res - aux[rbi][tlj - 1];
     if (tli > 0 && tlj > 0)
          res = res + aux[tli - 1][tlj - 1];
     return res;
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//      freopen("input4.txt", "r", stdin);
//      freopen("output4.txt", "w", stdout);
// #endif
     int t;
     t = 1;

     while (t--) {
          ll n, k;
          memset(mat, 0, sizeof(mat));
          memset(aux, 0, sizeof(aux));
          cin >> n >> k;
          lop(i, 0, k) {
               ll x, y;
               cin >> x >> y;
               mat[x - 1][y - 1] = 1;
          }
          makematrix(n, n);
          ll mx = 0;
          lop(i, 0, n) {
               lop(j, 0, n) {
                    ll ans = get(0, j + 1, i, n - 1);
                    ans = min(ans, get(0, 0, i, j));
                    ans = min(ans, get(i + 1, 0, n - 1, j));
                    ans = min(ans, get(i + 1, j + 1, n - 1, n - 1));
                    mx = max(mx, ans);
               }
          }
          cout << mx << '\n';
     }
     return 0;
}