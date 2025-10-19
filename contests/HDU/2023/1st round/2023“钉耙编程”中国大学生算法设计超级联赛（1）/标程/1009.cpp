#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
 
	int T;
	cin >> T;
 
	while (T--) {
		int n , m , x;
		cin >> n >> m >> x;
 
		int d = (m - 1) / n + 1;
		if (x <= d) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}
