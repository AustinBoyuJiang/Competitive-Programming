#include<bits/stdc++.h>
using namespace std;
const int Mod = 666623333;
int T, n, m, Q, a[100005];
char s[200005];
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf("%s", s + 1);
			for (int j = m + 1; j <= m + m; j++)
				s[j] = s[j - m];
			int I = 1, J = 2;
			while (J <= m){
				ok:;
				for (int k = 0; k < m; k++){
					if (s[I + k] < s[J + k]){
						J += k;
						break;
					}
					if (s[I + k] > s[J + k]){
						int tmp = I;
						I = J;
						J = max(J, tmp + k);
						break;	
					}
				}
				J++;
			}
			a[i] = 0;
			for (int j = 0; j < m; j++)
				a[i] = (31ll * a[i] + s[I + j] - 'a' + 1) % Mod;
		}
		scanf("%d", &Q);
		while (Q--){
			int x, y;
			scanf("%d%d", &x, &y);
			if (a[x] == a[y])
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
