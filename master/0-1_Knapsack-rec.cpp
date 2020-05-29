#include <iostream>
using namespace std;
int kp(int w[], int v[], int cap, int n)
{
    //base case
    if (cap == 0 or n == 0)
        return 0;

    //wt of item gt cap
    if (w[n - 1] > cap)
        return kp(w, v, cap, n - 1);

    // recursive case
    return max(v[n - 1] + kp(w, v, cap - w[n - 1], n - 1), kp(w, v, cap, n - 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w[1000], v[1000], cap;
    cin >> n >> cap;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << kp(w, v, cap, n);
    return 0;
}
