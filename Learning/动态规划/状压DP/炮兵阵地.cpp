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
#define random(a,b) rand()%(b-a+1)
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;
const int N=120;
const int TOT=100;

int n,m,tot,ans,a[N],sum[TOT],dp[N][TOT][TOT];
VI s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			a[i]<<=1;
			a[i]|=x=='P';
		}
	for(int i=0;i<1<<m;i++){
		if(i&i<<1) continue;
		if(i&i<<2) continue;
		s.pb(i);
	}
	tot=s.size();
	for(int i=0;i<tot;i++){
		int num=s[i];
		for(int j=1;j<=m;j++){
			sum[i]+=num%2;
			num>>=1;
		}
	}
	for(int i=1;i<=n+1;i++)
		for(int j=0;j<tot;j++){
			if(a[i]^(s[j]|a[i])) continue;
			for(int k=0;k<tot;k++){
				if(s[j]&s[k]) continue;
				for(int l=0;l<tot;l++){
					if(s[j]&s[l]) continue;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+sum[j]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	cout<<ans<<endl;
	return 0;
}

