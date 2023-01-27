/*Author：AustinJiang
题目：染色 
时间复杂度：O(m*log(n)*log(n))
算法：树链剖分，线段树
来源：SDOI 2011*/
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

int n,m,tot,co[N],fa[N],dep[N],siz[N],hson[N],top[N],dfn[N],rnk[N];
VI e[N];

struct node{
	int sum=0,lx,rx,lazy=-1;
} st[N<<2];

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
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(!hson[u]) return;
	dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v!=fa[u]&&v!=hson[u]) dfs2(v,v);
	}
}

node merge(node a,node b){
	if(!a.sum) return b;
	if(!b.sum) return a;
	node ans;
	ans.sum=a.sum+b.sum-(a.rx==b.lx);
	ans.lx=a.lx;
	ans.rx=b.rx;
	return ans;
}

void push_up(int rt){
	st[rt]=merge(st[rt<<1],st[rt<<1|1]);
}

void push_down(int rt,int l,int mid,int r){
	if(st[rt].lazy!=-1){
		st[rt<<1].sum=st[rt<<1|1].sum=1;
		st[rt<<1].lx=st[rt<<1|1].lx=st[rt].lazy;
		st[rt<<1].rx=st[rt<<1|1].rx=st[rt].lazy;
		st[rt<<1].lazy=st[rt<<1|1].lazy=st[rt].lazy;
		st[rt].lazy=-1;
	}
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt].sum=1;
		st[rt].lx=co[rnk[l]];
		st[rt].rx=co[rnk[r]];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		st[rt].sum=1;
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

void solve(int a,int b,int c){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		update(1,1,n,dfn[top[a]],dfn[a],c);
		a=fa[top[a]];
	}
	if(dfn[a]>dfn[b]) swap(a,b);
	update(1,1,n,dfn[a],dfn[b],c);
}

int solve(int a,int b){
	node ans1,ans2,tmp,Min,Max;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]]){
			ans1=merge(query(1,1,n,dfn[top[a]],dfn[a]),ans1);
			a=fa[top[a]];
		}
		else{
			ans2=merge(query(1,1,n,dfn[top[b]],dfn[b]),ans2);
			b=fa[top[b]];
		}
	}
	tmp=query(1,1,n,min(dfn[a],dfn[b]),max(dfn[a],dfn[b]));
	Min=dfn[a]<dfn[b]?ans1:ans2;
	Max=dfn[a]<dfn[b]?ans2:ans1;
	swap(Min.lx,Min.rx);
	return merge(Min,merge(tmp,Max)).sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>co[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].pb(y);
		e[y].pb(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		char opt;
		int a,b,c;
		cin>>opt;
		if(opt=='C') cin>>a>>b>>c,solve(a,b,c);
		else cin>>a>>b,cout<<solve(a,b)<<endl;
	}
	return 0;
}

