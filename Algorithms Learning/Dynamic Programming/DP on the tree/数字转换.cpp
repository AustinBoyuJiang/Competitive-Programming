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
#define for(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int INF=LLONG_MAX;
const int N=5e4+10;
int n,ans;
vector<int> Map[N];

int get_number(int n){
	int cnt=0;
	for(i,sqrt(n)) cnt+=!(n%i)?n/i!=n&&n/i!=i?n/i+i:i:0;
	return cnt;
}

int dfs(int u,int fa){
	int mx=0,cmx=0;
	for(i,Map[u].size()){
		int v=Map[u][i-1];
		if(v==fa) continue;
		int son=dfs(v,u)+1;
		cmx=max(cmx,min(mx,son));
		mx=max(mx,son);
	}
	ans=max(ans,mx+cmx);
	return mx;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(u,n){
		int v=get_number(u);
		if(v>=u) continue;
		Map[u].pb(v);
		Map[v].pb(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

