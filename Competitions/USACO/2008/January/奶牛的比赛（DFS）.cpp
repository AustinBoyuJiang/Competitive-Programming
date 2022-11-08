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
const int N=110;

int n,m,a,b,ans,cnt1[N],cnt2[N],vis[N];
VI up[N],down[N];

void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int dfs1(int u){
	cnt1[u]++;
	vis[u]=1;
	for(int i=0;i<up[u].size();i++){
		int v=up[u][i];
		if(vis[v]) continue;
		dfs1(v);
	}
}

int dfs2(int u){
	cnt2[u]++;
	vis[u]=1;
	for(int i=0;i<down[u].size();i++){
		int v=down[u][i];
		if(vis[v]) continue;
		dfs2(v);
	}
}

signed main(){
	IOS();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		up[b].pb(a);
		down[a].pb(b);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs1(i);
		memset(vis,0,sizeof(vis));
		dfs2(i);
	}
	for(int i=1;i<=n;i++)
		if(cnt1[i]+cnt2[i]==n+1) ans++;
	cout<<ans<<endl;
	return 0;
}

