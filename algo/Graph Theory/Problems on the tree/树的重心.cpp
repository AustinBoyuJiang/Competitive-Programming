/*Author：AustinJiang
题目：树的中心 
时间复杂度：O(n)
算法：DFS，图论*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e4+10;

int n,ans=INF,st[N],res[N];
VI e[N];

void dfs(int u,int fa){
	st[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		st[u]+=st[v];
		res[u]=max(res[u],st[v]);
	}
	res[u]=max(res[u],n-st[u]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans=min(ans,res[i]);
	for(int i=1;i<=n;i++)
		if(ans==res[i]) cout<<i<<' ';
	return 0;
}

