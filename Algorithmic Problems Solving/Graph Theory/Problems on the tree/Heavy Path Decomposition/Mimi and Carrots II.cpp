/*Author：AustinJiang
题目：Mimi and Carrots II
时间复杂度：O(q*log(n)*log(n))
算法：树链剖分，线段树 
来源：DMOPC '20 Contest 7 P4 */
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
const int N=2e5+10;

int n,q,tot,fa[N],dep[N],siz[N],son[N],hson[N],tp[N],dfn[N],rnk[N],save[N],sum[N<<2];
VI e[N];

void dfs1(int u,int father){
	fa[u]=father;
	dep[u]=dep[fa[u]]+1;
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		dfs1(v,u);
		son[u]++;
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int top){
	tp[u]=top;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(!son[u]) return;
	dfs2(hson[u],top);
	for(auto v:e[u]){
		if(v==fa[u]||v==hson[u]) continue;
		dfs2(v,v);
	}
}

void update(int rt,int l,int r,int x,int y){
	sum[rt]+=y;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) update(rt<<1,l,mid,x,y);
	else update(rt<<1|1,mid+1,r,x,y);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

void update_node(int x){
	save[x]^=1;
	if(fa[x]) update(1,1,n,dfn[fa[x]],save[x]?1:-1);
}

int query_path(int x,int y){
	int ans=0;
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		ans+=query(1,1,n,dfn[tp[x]],dfn[x]);
		x=fa[tp[x]];
	}
	ans+=query(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	ans+=save[rnk[min(dfn[x],dfn[y])]]+save[fa[rnk[min(dfn[x],dfn[y])]]];
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=q;i++){
		int opt,x,y;
		cin>>opt;
		if(opt==1) cin>>x,update_node(x);
		else cin>>x>>y,cout<<query_path(x,y)<<endl;
	}
	return 0;
}

