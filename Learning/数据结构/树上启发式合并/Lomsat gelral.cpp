/*Author：AustinJiang
题目：Lomsat gelral
时间复杂度：O(n*log(n))
算法：书上启发式合并 
来源：CF600E */
#include<bits/stdc++.h>
#define int long long
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

int n,tot,mx,sum,cnt[N],ans[N],co[N],siz[N],hson[N],dfn[N],rnk[N];
VI e[N];

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

void add(int u){
	cnt[co[u]]++;
	if(cnt[co[u]]>mx){
		sum=0;
		mx=cnt[co[u]];
	}
	if(cnt[co[u]]==mx) sum+=co[u];
}

void dfs2(int u,int fa,bool keep){
	for(auto v:e[u]){
		if(v==fa||v==hson[u]) continue;
		dfs2(v,u,0);
	}
	if(hson[u]) dfs2(hson[u],u,1);
	for(auto v:e[u]){
		if(v==fa||v==hson[u]) continue;
		for(int i=dfn[v];i<dfn[v]+siz[v];i++){
			add(rnk[i]);
		}
	}
	add(u);
	ans[u]=sum;
	if(!keep){
		for(int i=dfn[u];i<dfn[u]+siz[u];i++) cnt[co[rnk[i]]]--;
		mx=0;
		sum=0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>co[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}

