/*Author：AustinJiang
题目：树上启发式合并 
时间复杂度：O(n*log(n))
算法：树上启发式合并 
思路：求子树不同颜色数量 
*/
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
const int N=1e5+10;

int n,m,cnt,tot,col[N],siz[N],hson[N],dfn[N],rnk[N],f[N],ans[N];
VI e[N];

void in(int x){
	if(!f[col[x]]) cnt++;
	f[col[x]]++;
}

void out(int x){
	f[col[x]]--;
	if(!f[col[x]]) cnt--;
}

void dfs1(int u,int fa){
	siz[u]=1;
	dfn[u]=++tot;
	rnk[tot]=u;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int fa,bool keep){
	for(auto v:e[u]){
		if(v==fa||v==hson[u]) continue;
		dfs2(v,u,0);
	}
	if(hson[u]) dfs2(hson[u],u,1);
	for(auto v:e[u]){
		if(v==fa||v==hson[u]) continue;
		for(int i=dfn[v];i<dfn[v]+siz[v];i++) in(rnk[i]);
	}
	in(u);
	ans[u]=cnt;
	if(!keep) for(int i=dfn[u];i<dfn[u]+siz[u];i++) out(rnk[i]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>col[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}

