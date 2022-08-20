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
const int N=14;
const int TOT=400;
const int MOD=1e8;

int n,m,tot,a[N],dp[N][TOT];
VI s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			a[i]<<=1;
			a[i]|=x;
		}
	for(int i=0;i<1<<m;i++){
		if(i&i<<1) continue;
		s.pb(i);
	}
	tot=s.size();
	for(int i=0;i<tot;i++){
		if(a[1]^(s[i]|a[1])) continue;
		dp[1][i]=1;
	}
	for(int i=1;i<=n+1;i++)
		for(int j=0;j<tot;j++){
			if(a[i]^(s[j]|a[i])) continue;
			for(int k=0;k<tot;k++){
				if(s[j]&s[k]) continue;
				dp[i][j]+=dp[i-1][k];
				dp[i][j]%=MOD;
			}
		}
	cout<<dp[n+1][0]<<endl;
	return 0;
}

