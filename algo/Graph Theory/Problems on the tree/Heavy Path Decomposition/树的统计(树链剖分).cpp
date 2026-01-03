/*Author：AustinJiang
题目：树的统计(树链剖分)
时间复杂度：O(m*log(n)*log(n))
算法：树链剖分，线段树 */
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

int n,q,tot,val[N],fa[N],dep[N],hson[N],siz[N],top[N],dfn[N],rnk[N],mx[N<<2],sum[N<<2];
VI e[N];

void dfs1(int u,int father){
	fa[u]=father;
	siz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(auto v:e[u]){
		if(v==fa[u]) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[hson[u]]<siz[v]) hson[u]=v;
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v==fa[u]||v==hson[u]) continue;
		dfs2(v,v);
	}
}

void push_up(int rt){
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int rt,int l,int r){
	if(l==r){
		mx[rt]=sum[rt]=val[rnk[l]];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int v){
	if(l==r){
		mx[rt]=v;
		sum[rt]=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,v);
	else update(rt<<1|1,mid+1,r,x,v);
	push_up(rt);
}

int query_max(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return mx[rt];
	int mid=l+r>>1;
	if(y<=mid) return query_max(rt<<1,l,mid,x,y);
	else if(x>mid) return query_max(rt<<1|1,mid+1,r,x,y);
	else return max(query_max(rt<<1,l,mid,x,mid),query_max(rt<<1|1,mid+1,r,mid+1,y));
}

int query_sum(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query_sum(rt<<1,l,mid,x,y);
	else if(x>mid) return query_sum(rt<<1|1,mid+1,r,x,y);
	else return query_sum(rt<<1,l,mid,x,mid)+query_sum(rt<<1|1,mid+1,r,mid+1,y);
}

int LCA_max(int x,int y){
	int ans=-INF;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=max(ans,query_max(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	ans=max(ans,query_max(1,1,n,dfn[x],dfn[y]));
	return ans;
}

int LCA_sum(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=query_sum(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	ans+=query_sum(1,1,n,dfn[x],dfn[y]);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		cin>>val[i];
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
		string opt;
		int a,b;
		cin>>opt>>a>>b;
		if(opt=="CHANGE") update(1,1,n,dfn[a],b);
		if(opt=="QMAX") cout<<LCA_max(a,b)<<endl;
		if(opt=="QSUM") cout<<LCA_sum(a,b)<<endl;
	}
	return 0;
}

