#include<bits/stdc++.h>
using namespace std;


namespace NT{

    template<class T>
    inline bool is_prime(T x) {
        if (x == 1) return false;
        for (T i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    
    inline void linear_sieve(int n, vector<int>& primes, vector<int>& low, vector<char>& is_prime) {
        primes.clear();
        low.assign(n + 1, 0);
        is_prime.assign(n + 1, true);
        if (n >= 0) is_prime[0] = false;
        if (n >= 1) is_prime[1] = false;

        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                low[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                long long x = 1LL * p * i;
                if (x > n) break;
                low[(int)x] = p;
                is_prime[(int)x] = false;
                if (i % x == 0) break;
            }
        }
    }

} using namespace NT;


const int MOD = 1e9+7;

namespace combi {

    template<class T1, class T2>
    inline T1 qpow(T1 a, T2 b) {
        T1 ans = 1;
        for(; b; b >>= 1) {
            if (b & 1){
            	ans  = ans * 1LL * a % MOD;
            }
            a = a * 1LL * a % MOD;
        }
        return ans;
    }

    template<class T>
    inline T inv(T x) {
        return qpow(x, (T)(MOD - 2)); // MOD must be prime
    }

    inline vector<long long> fact{1}, invfact{1};

    inline void _ensure(int n) {
        if ((int)fact.size() > n) return;
        int old = (int)fact.size() - 1;
        fact.resize(n + 1);
        for (int i = old + 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

        invfact.resize(n + 1);
        invfact[n] = inv(fact[n]);
        for (int i = n; i > old + 1; i--) invfact[i - 1] = invfact[i] * i % MOD;
    }

    inline long long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        _ensure(n);
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }

    inline long long P(int n, int k) {
        if (k < 0 || k > n) return 0;
        _ensure(n);
        return fact[n] * invfact[n - k] % MOD;
    }

} using namespace combi;
