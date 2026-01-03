/*Author：AustinJiang
题目：软件包管理器 
时间复杂度：O(q*log(n)*log(n))
算法：树链剖分 
来源：NOI 2015 */
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

int n,q,tot,fa[N],siz[N],hson[N],top[N],dfn[N],rnk[N],sum[N<<2],lazy[N<<2];
VI e[N];

void dfs1(int u){
	siz[u]=1;
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
		if(v==hson[u]) continue;
		dfs2(v,v);
	}
}

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]!=-1){
		sum[rt<<1]=lazy[rt]*(mid-l+1);
		sum[rt<<1|1]=lazy[rt]*(r-mid);
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
		lazy[rt]=-1;
	}
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		sum[rt]=v*(r-l+1);
		lazy[rt]=v;
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

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		fa[i]++;
		e[fa[i]].pb(i);
	}
	dfs1(1);
	dfs2(1,1);
	memset(lazy,-1,sizeof(lazy));
	cin>>q;
	for(int i=1;i<=q;i++){
		string opt;
		int x,ans=0;
		cin>>opt>>x;
		x++;
		if(opt=="install"){		
			while(x){
				ans+=dfn[x]-dfn[top[x]]+1-query(1,1,n,dfn[top[x]],dfn[x]);
				update(1,1,n,dfn[top[x]],dfn[x],1);
				x=fa[top[x]];
			}
			cout<<ans<<endl;
		}
		else{
			cout<<query(1,1,n,dfn[x],dfn[x]+siz[x]-1)<<endl;
			update(1,1,n,dfn[x],dfn[x]+siz[x]-1,0);
		}
	}
	return 0;
}

