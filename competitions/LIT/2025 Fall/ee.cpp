#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    auto build_left_chain = [&](int start, int stop, vector<int>& vals) {
        vals.clear();
        int last = INT_MAX;
        for (int x = start; x >= 1 && x > stop; --x) {
            if (a[x] < last) {
                vals.push_back(a[x]);
                last = a[x];
            }
        }
    };
    auto build_right_chain = [&](int start, int stop, vector<int>& vals) {
        vals.clear();
        int last = INT_MAX;
        for (int x = start; x <= n && x < stop; ++x) {
            if (a[x] < last) {
                vals.push_back(a[x]);
                last = a[x];
            }
        }
    };

    auto day = [&](int s, int p) -> int {
        if (s == p) return 1;
        int d = 1;
        vector<int> Lvals, Rvals;

        if (s < p) {
            build_right_chain(s + 1, p, Rvals);
            build_left_chain(s - 1, 0, Lvals);

            int i = 0, j = 0;
            while (true) {
                int needVal = (i < (int)Rvals.size() ? Rvals[i] : a[p]);
                bool needIsP = (i == (int)Rvals.size());
                int leftVal = (j < (int)Lvals.size() ? Lvals[j] : INT_MAX);

                if (needVal <= leftVal) {
                    if (needIsP) return d + 1; 
                    ++d; ++i; 
                } else {
                    ++d; ++j;   
                }
                if (d > n + 5) return -1;     
            }
        } else {
            build_left_chain(s - 1, p, Lvals);
            build_right_chain(s + 1, n + 1, Rvals);

            int i = 0, j = 0;
            while (true) {
                int needVal = (i < (int)Lvals.size() ? Lvals[i] : a[p]);
                bool needIsP = (i == (int)Lvals.size());
                int rightVal = (j < (int)Rvals.size() ? Rvals[j] : INT_MAX);

                if (needVal <= rightVal) {
                    if (needIsP) return d + 1;
                    ++d; ++i;
                } else {
                    ++d; ++j;
                }
                if (d > n + 5) return -1;
            }
        }
    };

    while (q--) {
        int p, k; cin >> p >> k;
        long long ans = 0;
        for (int s = 1; s <= n; ++s) {
            int d = day(s, p);
            if (d == k) ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}
