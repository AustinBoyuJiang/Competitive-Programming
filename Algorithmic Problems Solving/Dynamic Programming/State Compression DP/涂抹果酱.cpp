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
const int N=1e4+10;
const int M=10;
const int TOT=50;
const int MOD=1e6;

int n,m,k,tot,cnt1,cnt2,K[M],f[M],s[TOT][M],dp[N][TOT];

bool ok(int j,int k){
	for(int i=1;i<=m;i++)
		if(s[j][i]==s[k][i]) return false;
	return true;
}

void init(int x,int len){
	f[len]=x;
	if(len==m){
		tot++;
		bool flag=true;
		for(int i=1;i<=m;i++){
			s[tot][i]=f[i];
			if(K[i]!=f[i]) flag=false;
		}
		dp[k][tot]=flag;
		return;
	}
	for(int i=1;i<=3;i++){
		if(x==i) continue;
		init(i,len+1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>K[i];
	init(0,0);
	for(int i=k-1;i>=1;i--)
		for(int j=1;j<=tot;j++)
			for(int k=1;k<=tot;k++){
				if(!ok(j,k)) continue;
				dp[i][j]+=dp[i+1][k]%MOD;
			}
	for(int i=k+1;i<=n;i++)
		for(int j=1;j<=tot;j++)
			for(int k=1;k<=tot;k++){
				if(!ok(j,k)) continue;
				dp[i][j]+=dp[i-1][k]%MOD;
			}
	for(int i=1;i<=tot;i++){
		cnt1+=dp[1][i]%MOD;
		cnt2+=dp[n][i]%MOD;
	}
	cout<<(cnt1*cnt2)%MOD<<endl;
	return 0;
}

