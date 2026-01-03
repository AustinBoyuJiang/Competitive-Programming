/*Author：AustinJiang
题目：割点(割顶)
时间复杂度：O(n)
算法：强连通，Tarjan */
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
const int N=2e4+10;

int n,m,num,cnt,ans[N],dfn[N],low[N];
VI e[N];

void dfs(int u,int root){
	dfn[u]=low[u]=++num;
	ans[u]=!root;
	for(auto v:e[u]){
		if(!dfn[v]){
			dfs(v,0);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) ans[u]++;
		}
		else low[u]=min(low[u],dfn[v]);
	}
	cnt+=ans[u]>1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,1);
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(ans[i]>1) cout<<i<<' ';
	return 0;
}

