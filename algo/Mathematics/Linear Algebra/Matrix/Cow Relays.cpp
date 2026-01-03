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
const int T=110;
const int L=1010;

int n,t,s,e,cnt,d[L],dist[T][T],ans[T][T];

void solve(){
	int copy[T][T];
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			copy[i][j]=ans[i][j];
	memset(ans,63,sizeof(ans));
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
				ans[i][j]=min(ans[i][j],copy[i][k]+dist[k][j]);
}

void muti(){
	int copy[T][T];
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			copy[i][j]=dist[i][j];
	memset(dist,63,sizeof(dist));
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
				dist[i][j]=min(dist[i][j],copy[i][k]+copy[k][j]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t>>s>>e;
	memset(dist,63,sizeof(dist));
	memset(ans,63,sizeof(ans));
	for(int i=1;i<=t;i++){
		int len,a,b;
		cin>>len>>a>>b;
		if(!d[a]) d[a]=++cnt;
		if(!d[b]) d[b]=++cnt;
		dist[d[a]][d[b]]=len;
		dist[d[b]][d[a]]=len;
	}
	for(int i=1;i<=cnt;i++)
		ans[i][i]=0;
	while(n){
		if(n%2) solve();
		muti();
		n/=2;
	}
	cout<<ans[d[s]][d[e]]<<endl;
	return 0;
}

