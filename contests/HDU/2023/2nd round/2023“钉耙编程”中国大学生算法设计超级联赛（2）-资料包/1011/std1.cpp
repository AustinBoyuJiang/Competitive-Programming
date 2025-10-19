#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const double E = exp(1);
double sum[N];

double calc(int n, int k) {
    if (k == 0) return 1.0 / n;
    return 1.0 * k / n * (sum[n - 1] - sum[k - 1]);
}

void work() {
    int n;
    cin >> n;
    int k = n / E;
    int ans = 0;
    double p = 1.0 / n;
    for (int i = max(k - 10, 1); i <= min(k + 10, n - 1); ++i) {
        double now = calc(n, i);
        if (now > p) {
            ans = i;
            p = now;
        }
    }
    cout << ans << "\n";
}

int main() {
    for (int i = 1; i < N; ++i) sum[i] = sum[i - 1] + 1.0 / i;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
