/*Author：AustinJiang
题目：Light Heavy Edges
时间复杂度：O(t*m*log(n)*log(n))
算法：树链剖分，线段树 
来源：NOI '21 P1 */
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

int t,n,m,tot1,tot2,fa[N],dep[N],siz[N],hson[N],tp[N],dfn[N],rnk[N];
VI e[N];

struct node{
	int sum=0,lx=0,rx=0,lazy=0;
} st[N<<2];

void dfs1(int u,int father){
	fa[u]=father;
	dep[u]=dep[fa[u]]+1;
	siz[u]=1;
	hson[u]=0;
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int top){
	tp[u]=top;
	dfn[u]=++tot1;
	rnk[tot1]=u;
	if(hson[u]) dfs2(hson[u],top);
	for(auto v:e[u]){
		if(v==fa[u]||v==hson[u]) continue;
		dfs2(v,v);
	}
}

node merge(node a,node b){
	if(!a.lx) return b;
	if(!b.lx) return a;
	node res;
	res.lx=a.lx;
	res.rx=b.rx;
	res.sum=a.sum+b.sum+(a.rx==b.lx);
	return res;
}

void push_up(int rt){
	st[rt]=merge(st[rt<<1],st[rt<<1|1]);
}

void push_down(int rt,int l,int mid,int r){
	if(st[rt].lazy){
		st[rt<<1].sum=mid-l;
		st[rt<<1|1].sum=r-mid-1;
		st[rt<<1].lx=st[rt<<1|1].lx=st[rt].lazy;
		st[rt<<1].rx=st[rt<<1|1].rx=st[rt].lazy;
		st[rt<<1].lazy=st[rt<<1|1].lazy=st[rt].lazy;
		st[rt].lazy=0;
	}
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt].sum=0;
		st[rt].lx=st[rt].rx=++tot2;
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		st[rt].sum=r-l;
		st[rt].lx=v;
		st[rt].rx=v;
		st[rt].lazy=v;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	push_up(rt);
}

node query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return merge(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));
}

void solve1(int x,int y){
	tot2++;
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		update(1,1,n,dfn[tp[x]],dfn[x],tot2);
		x=fa[tp[x]];
	}
	update(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),tot2);
}

int solve2(int x,int y){
	node ans1,ans2,tmp,Min,Max;
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]>dep[tp[y]]){
			ans1=merge(query(1,1,n,dfn[tp[x]],dfn[x]),ans1);
			x=fa[tp[x]];
		}
		else{
			ans2=merge(query(1,1,n,dfn[tp[y]],dfn[y]),ans2);
			y=fa[tp[y]];
		}
	}
	tmp=query(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	Min=dfn[x]<dfn[y]?ans1:ans2;
	Max=dfn[x]<dfn[y]?ans2:ans1;
	swap(Min.lx,Min.rx);
	return merge(Min,merge(tmp,Max)).sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			e[a].pb(b);
			e[b].pb(a);
		}
		tot1=tot2=0;
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,n);
		for(int i=1;i<=m;i++){
			int opt,a,b;
			cin>>opt>>a>>b;
			if(opt==1) solve1(a,b);
			if(opt==2) cout<<solve2(a,b)<<endl;
		}
	}
	return 0;
}

