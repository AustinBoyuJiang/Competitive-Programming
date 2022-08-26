/*Author：AustinJiang
题目：洞穴 
时间复杂度：O(q*log(n))
算法：线段树  */
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

int n,q,tot1,tot2,dfn[N],rnk[N],siz[N],co[N<<2],lazy[N<<2];
VI e[N];
map<int,int> res;

void dfs(int u,int fa){
	dfn[u]=++tot1;
	rnk[tot1]=u;
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}

void push_down(int rt){
	if(lazy[rt]!=-1){
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		co[rt<<1]=lazy[rt];
		co[rt<<1|1]=lazy[rt];
		lazy[rt]=-1;
	}
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		lazy[rt]=v;
		co[rt]=v;
		return;
	}
	push_down(rt);
	int mid=l+r>>1;
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
}

int query(int rt,int l,int r,int x){
	if(l==r) return co[rt];
	push_down(rt);
	int mid=l+r>>1;
	if(x<=mid) return query(rt<<1,l,mid,x);
	else return query(rt<<1|1,mid+1,r,x);
}

void cut(int x){
	res[query(1,1,n,dfn[x])]-=siz[x];
	update(1,1,n,dfn[x],dfn[x]+siz[x]-1,++tot2);
	res[tot2]=siz[x]; 
}

signed main(){
	freopen("data/9.in","r",stdin);
	freopen("data/9.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	res[0]=n;
	memset(lazy,-1,sizeof(lazy));
	for(int i=1;i<=q;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) cut(x);
		if(opt==2) cout<<res[query(1,1,n,dfn[x])]<<endl;
	}
	return 0;
}

