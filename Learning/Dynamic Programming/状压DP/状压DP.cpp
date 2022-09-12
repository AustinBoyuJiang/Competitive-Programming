#include<bits/stdc++.h>
#define int long long
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;

int n,K,dp[20][200][200];
vector<PI> S;
int tot = 0;
void init(){//dp[i][j][k]��ʾ��i�У�״̬���Ϊj������k���������ܷ����� 
	for(int i=0;i<(1<<n);i++){
		if(i & (i << 1)) continue; 
		if(i & (i >> 1)) continue;
		//	count the number of King
		int num = 0, x = i;
		while(x != 0) {
			num += x % 2;
			x /= 2;
		}
		if(num>K) continue;
		S.push_back(mp(i, num)); 
	}
	tot = S.size();
	for(int i = 0; i < tot; i++) {
		dp[1][i][S[i].sec] = 1;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	init();
	for(int i = 2; i <= n+1; i++){//�� 
		for(int j1 = 0; j1 < tot; j1++){//����״̬ 
			for(int j2 = 0; j2 < tot; j2++){
				if(S[j1].fir&S[j2].fir) continue;
				if(S[j1].fir&(S[j2].fir << 1)) continue;
				if(S[j1].fir&(S[j2].fir >> 1)) continue;
				for(int k = S[j1].sec; k <= K; k++){//������
					dp[i][j1][k] += dp[i-1][j2][k-S[j1].sec];
				}
			}
		}
	}
//	int ans = 0;
//	for(int i = 0; i < tot; i++) {
//		ans += dp[n][i][K];
//	}
//	cout << ans << endl;
	cout << dp[n+1][0][K] << endl;
	return 0;
}

