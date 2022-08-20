/*Author：AustinJiang
题目：桥
时间复杂度：O(m*log(m))
算法：线段树，最短路 
来源：TJOI2012 */
#pragma GCC optimize(2)
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

int n,m,ans1,ans2,tot,mn[N<<2],lazy[N<<2],flag[N];
VI e[N];

struct edge{
	int u,v,w,flag;
}ed[N];

struct dijkstra{
	int st,dist[N],vis[N],lca[N],lst[N],nxt[N];
	PQ<PI,VPI,greater<PI>> q;
	stack<int> stk;
	VI ee[N];
	
	inline void dijk(){
		memset(dist,0x3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		dist[st]=0;
		q.push(mp(0,st));
		while(!q.empty()){
			int u=q.top().sec; q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i:e[u]){
				int v=ed[i].u+ed[i].v-u;
				if(dist[u]+ed[i].w<dist[v]){
					dist[v]=dist[u]+ed[i].w;
					q.push(mp(dist[v],v));
					lst[v]=i;
				}
			}
		}
		for(int v=1;v<=n;v++){
			if(!lst[v]) continue;
			int u=ed[lst[v]].u+ed[lst[v]].v-v;
			ee[u].pb(lst[v]);
		}
		if(st==1) find(n);
	}
	
	inline void find(int u){
		if(st==1) flag[u]=1;
		if(lst[u]){
			int v=ed[lst[u]].u+ed[lst[u]].v-u;
			if(st==1) ed[lst[u]].flag=++tot;
			nxt[v]=lst[u];
			find(v);
		}
	}
	
	inline void build(int u){
		for(auto i:ee[u]){
			int v=ed[i].u+ed[i].v-u;
			build(v);
			if(flag[u]){
				while(!stk.empty()){
					lca[stk.top()]=u;
					stk.pop();
				}
			}
		}
		if(flag[u]) lca[u]=u;
		else stk.push(u);
	}
	
} d1,dn;

inline void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]!=INF){
		mn[rt<<1]=min(mn[rt<<1],lazy[rt]);
		mn[rt<<1|1]=min(mn[rt<<1|1],lazy[rt]);
		lazy[rt<<1]=min(lazy[rt<<1],lazy[rt]);
		lazy[rt<<1|1]=min(lazy[rt<<1|1],lazy[rt]);
		lazy[rt]=INF;
	}
}

inline void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		mn[rt]=min(mn[rt],v);
		lazy[rt]=min(lazy[rt],v);
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

inline int query(int rt,int l,int r,int x){
	if(l==r) return mn[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(x<=mid) return query(rt<<1,l,mid,x);
	else return query(rt<<1|1,mid+1,r,x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
		e[ed[i].u].pb(i);
		e[ed[i].v].pb(i);
	}
	d1.st=1,dn.st=n;
	d1.dijk(),dn.dijk();
	d1.build(1),dn.build(n);
	memset(mn,0x3f,sizeof(mn));
	memset(lazy,0x3f,sizeof(lazy));
	for(int i=1;i<=m;i++){
		if(ed[i].flag) continue;
		int x,y,w;
		if(d1.dist[ed[i].u]+dn.dist[ed[i].v]<d1.dist[ed[i].v]+dn.dist[ed[i].u]){
			x=ed[d1.nxt[d1.lca[ed[i].u]]].flag;
			y=ed[d1.lst[dn.lca[ed[i].v]]].flag;
			w=d1.dist[ed[i].u]+dn.dist[ed[i].v]+ed[i].w;
			if(d1.lca[ed[i].u]!=dn.lca[ed[i].v]) update(1,1,tot,y,x,w);
		}
		else{
			x=ed[d1.nxt[d1.lca[ed[i].v]]].flag;
			y=ed[d1.lst[dn.lca[ed[i].u]]].flag;
			w=d1.dist[ed[i].v]+dn.dist[ed[i].u]+ed[i].w;
			if(d1.lca[ed[i].v]!=dn.lca[ed[i].u]) update(1,1,tot,y,x,w);
		}
	}
	for(int i=1;i<=tot;i++)
		ans1=max(ans1,query(1,1,tot,i));
	for(int i=1;i<=tot;i++)
		if(ans1==query(1,1,tot,i)) ans2++;
	if(ans1==d1.dist[n]) ans2=m;
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}

