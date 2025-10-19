#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 7;
const int mod = 2000;
int dp[2005][2005], n, m, minn[2005][2005], a[maxn], pos[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int _;
	cin >> _;
	while (_--) {
		cin >> n >> m;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= m; j++) dp[i][j] = minn[i][j] = 2e9;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pos[i] = i % m;
		}
		int ans = 2e9;
		for (int i = 2; i <= m; i++) {
			for (int j = i - 1; j >= 1; j--) {
				dp[pos[i]][i - j] = a[i] + a[j];
				minn[pos[i]][i - j] = min(minn[pos[i]][i-j-1], dp[pos[i]][i-j]);
			}
		}
		for (int i = m + 1; i <= n; i++) {
			for (int j = i - 1; j >= i - m + 1; j--) {
				dp[pos[i]][i-j] = a[i] + minn[pos[j]][j-(i-m)];
				minn[pos[i]][i-j] = min(minn[pos[i]][i-j-1], dp[pos[i]][i - j]);
			}
		}
		
		for (int i = n - m + 1; i <= n; i++) {
			for (int j = i - 1; j >= n - m + 1; j--) {
				ans = min(ans, dp[pos[i]][i - j]);
			}
		}
		cout << ans << "\n";
	}
}
