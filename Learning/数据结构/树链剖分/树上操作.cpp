/*Author：AustinJiang
题目：树上操作 
时间复杂度：O(m*log(n)*log(n))
算法：树上剖分，线段树 */
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

int n,m,tot,val[N],fa[N],dep[N],siz[N],hson[N],top[N],dfn[N],rnk[N],sum[N<<2],lazy[N<<2];
VI e[N];

void dfs1(int u,int father){
	fa[u]=father;
	dep[u]=dep[fa[u]]+1;
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int tp){
	dfn[u]=++tot;
	rnk[tot]=u;
	top[u]=tp;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v==fa[u]||v==hson[u]) continue;
		dfs2(v,v);
	}
}

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void push_down(int rt,int l,int mid,int r){
	sum[rt<<1]+=lazy[rt]*(mid-l+1);
	sum[rt<<1|1]+=lazy[rt]*(r-mid);
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}

void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=val[rnk[l]];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		sum[rt]+=v*(r-l+1);
		lazy[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

int get_sum(int x){
	int ans=0;
	while(x){
		ans+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		cin>>opt;
		if(opt==1) cin>>x>>y,update(1,1,n,dfn[x],dfn[x],y);
		if(opt==2) cin>>x>>y,update(1,1,n,dfn[x],dfn[x]+siz[x]-1,y);
		if(opt==3) cin>>x,cout<<get_sum(x)<<endl;
	}
	return 0;
}

