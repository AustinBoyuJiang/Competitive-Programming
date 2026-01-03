/*Author：AustinJiang
题目：树链剖分 
时间复杂度：O(m*log(n)*log(n))
算法：树链剖分，LCA，线段树 */
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

int n,m,tot,root,val[N],fa[N][20],siz[N],dep[N],hson[N],top[N],dfn[N],rnk[N],sum[N<<2],lazy[N<<2];
VI e[N];

void dfs1(int u){
	siz[u]=1;
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;i<=17;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v!=hson[u]) dfs2(v,v);
	}
}

bool check(int x){
	int y=root;
	for(int i=17;i>=0;i--){
		if(dep[fa[y][i]]>=dep[x]) y=fa[y][i];
		if(x==y) return 1;
	}
	return 0;
}

int child(int x){
	int y=root;
	while(top[x]!=top[y]){
		y=top[y];
		if(fa[y][0]==x) return y;
		y=fa[y][0];
	}
	return hson[x];
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

void add_path(int x,int y,int k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],k);
		x=fa[top[x]][0];
	}
	update(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),k);
}

void add_subtree(int x,int k){
	if(x==root) update(1,1,n,1,n,k);
	else if(check(x)){
		update(1,1,n,1,n,k);
		update(1,1,n,dfn[child(x)],dfn[child(x)]+siz[child(x)]-1,-k);
	} 
	else update(1,1,n,dfn[x],dfn[x]+siz[x]-1,k);
}

int query_path(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]][0];
	}
	ans+=query(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	return ans;
}

int query_subtree(int x){
	if(x==root) return query(1,1,n,1,n);
	else if(check(x)) return query(1,1,n,1,n)-query(1,1,n,dfn[child(x)],dfn[child(x)]+siz[child(x)]-1);
	else return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=2;i<=n;i++){
		cin>>fa[i][0];
		e[fa[i][0]].pb(i);
	}
	root=1;
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++){
		int opt,x,y,k;
		cin>>opt;
		if(opt==1) cin>>root;
		if(opt==2) cin>>x>>y>>k,add_path(x,y,k);
		if(opt==3) cin>>x>>k,add_subtree(x,k);
		if(opt==4) cin>>x>>y,cout<<query_path(x,y)<<endl;
		if(opt==5) cin>>x,cout<<query_subtree(x)<<endl;
	}
	return 0;
}

