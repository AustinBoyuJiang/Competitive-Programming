#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
const double E = exp(1);
double sum[N];

double calc(int n, int k) {
    if (k == 0) return 1.0 / n;
    return 1.0 * k / n * (sum[n - 1] - sum[k - 1]);
}

void work() {
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    while (r - l > 10) {
        int d = (r - l + 1) / 3;
        int mid1 = l + d;
        int mid2 = r - d;
        if (calc(n, mid1) > calc(n, mid2)) {
            r = mid2;
        }
        else {
            l = mid1;
        }
    }
    int ans = -1;
    double p = -1;
    for (int i = l; i <= r; ++i) {
        double now = calc(n, i);
        if (now > p) {
            p = now;
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i < N; ++i) sum[i] = sum[i - 1] + 1.0 / i;
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
