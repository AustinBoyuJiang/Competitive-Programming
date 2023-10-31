#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int f[100007];
int k;

int dp(int x)
{
	if (f[x] != -1)
		return f[x];
	set<int> a;
	For(i, 1, x)
	{
		int j = x - i - k;
		if (j <= 0)
			continue;
		a.insert(dp(j) ^ dp(i));
	}
	int i = 0;
	while (a.count(i))
	{
		i++;
	}
	f[x] = i;
	return i;
}

void nim(int k)
{

	freopen("1.out", "w", stdout);

	//	cin >> n;

	memset(f, -1, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		f[i] = 1;
	}
	For(i, k + 1, 10000)
	{
		f[i] = dp(i);
	}

	// for (int i = 1; i <= 1000; i++)
	// {
	// 	cout << f[i];
	// 	if (i % 14) cout << '\n';
	// }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int n, k;
		cin >> k >> n;
		k -= 2;
		int len = k * 4 + 10;

		n %= len;
		if (n == 0)
			n = len;

		// [1] means 11111111... len = k
		// [2] means 22222222... len = k
		// nim = 11[1]01[1]12[2]21[2]22

		if (n == 3 + k)
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
}
