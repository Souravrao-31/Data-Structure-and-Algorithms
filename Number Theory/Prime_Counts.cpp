class Solution {
public:
    int countPrimes(int n) {
        if (n==0 || n==1) return false;
        vector<int> prime(n+1, 1);    // vector<int> is much faster than vector<bool>
        for (int p = 2; p*p < n; ++p) {
            if (!prime[p]) continue;
            for (int d = 2; (p*d) < n; ++d)
                prime[p*d] = 0;
        }
        return accumulate(prime.begin(), prime.end(), -3);
    }
};