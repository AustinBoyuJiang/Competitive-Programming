/*Author：AustinJiang
题目：旅游航道 
时间复杂度：O(n)
算法：图论，强连通 */
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
const int N=3e4+10;

int n,m,id,num,ans,dfn[N],low[N],vis[N];
VPI e[N];

void dfs(int u){
	dfn[u]=low[u]=++num;
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[i.sec]) continue;
		vis[i.sec]=1;
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) ans++;
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m,n){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			e[i].clear();
		ans=0,num=0,id=0;
		for(int i=1;i<=m;i++){
			int a,b;
			cin>>a>>b;
			e[a].pb(mp(b,++id));
			e[b].pb(mp(a,id));
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

