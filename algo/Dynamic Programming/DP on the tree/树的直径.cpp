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
typedef pair<int, int> PI;
typedef vector<int> VI;
using namespace std;

const int INF=LLONG_MAX;
const int N=1e4+10;

int n;
vector<int> Map[N];

PI dfs(int u,int fa){
	int ans=0,mx=0,cmx=0;
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		PI son=dfs(v,u);
		ans=max(ans,son.sec);
		cmx=max(cmx,min(mx,son.fir+1));
		mx=max(mx,son.fir+1);
	}
	ans=max(ans,mx+cmx);
	return mp(mx,ans);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		Map[u].pb(v);
		Map[v].pb(u);
	}
	cout<<dfs(1,0).sec<<endl;
	return 0;
}


