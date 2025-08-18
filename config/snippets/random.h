#include<bits/stdc++.h>
using namespace std;


namespace rnd {
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    inline int randint(int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    }

    inline long long randll(long long l, long long r) {
        return uniform_int_distribution<long long>(l, r)(rng);
    }

    inline double randdouble(double l, double r) {
        return uniform_real_distribution<double>(l, r)(rng);
    }
} using namespace rnd;
