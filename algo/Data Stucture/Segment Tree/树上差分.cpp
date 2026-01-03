#include<bits/stdc++.h>
#define int long long
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
using namespace std;
const int INF=LLONG_MAX;
const int N=1e6+10;
int n,m,r,cnt,val[N],id[N],pos[N],dep[N],f[N][21],son[N];
vector<int> mst[N];

struct node{
	int dep,val,flag,sum;
} st[N*4];

inline void dfs(int u,int fa){
	id[++cnt]=u;
	pos[u]=cnt;
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<mst[u].size();i++){
		int v=mst[u][i];
		if(v==fa) continue;
		dfs(v,u);
		son[u]+=son[v]+1;
	}
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

inline void push_up(int rt){
	st[rt].val=st[rt<<1].val+st[rt<<1|1].val;
	st[rt].flag=st[rt<<1].flag+st[rt<<1|1].flag;
	st[rt].sum=st[rt<<1].sum+st[rt<<1|1].sum;
}

inline void build(int rt,int l,int r){
	if(l==r){
		st[rt].dep=dep[id[++cnt]];
		st[rt].val=val[id[cnt]];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

inline void update(int rt,int l,int r,int x,int v){
	if(l==r){
		st[rt].flag+=v;
		st[rt].sum+=v*st[rt].dep;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(rt<<1,l,mid,x,v);
	else update(rt<<1|1,mid+1,r,x,v);
	push_up(rt);
}

inline int query1(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt].val;
	int mid=(l+r)>>1;
	if(y<=mid) return query1(rt<<1,l,mid,x,y);
	else if(x>mid) return query1(rt<<1|1,mid+1,r,x,y);
	else return query1(rt<<1,l,mid,x,mid)+query1(rt<<1|1,mid+1,r,mid+1,y);
}

inline int query2(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt].flag;
	int mid=(l+r)>>1;
	if(y<=mid) return query2(rt<<1,l,mid,x,y);
	else if(x>mid) return query2(rt<<1|1,mid+1,r,x,y);
	else return query2(rt<<1,l,mid,x,mid)+query2(rt<<1|1,mid+1,r,mid+1,y);
}

inline int query3(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt].sum;
	int mid=(l+r)>>1;
	if(y<=mid) return query3(rt<<1,l,mid,x,y);
	else if(x>mid) return query3(rt<<1|1,mid+1,r,x,y);
	else return query3(rt<<1,l,mid,x,mid)+query3(rt<<1|1,mid+1,r,mid+1,y);
}

inline int get_val(int pos,int len){
	return query1(1,1,n,pos,pos+len);
}

inline int get_flag(int pos,int len){
	return query2(1,1,n,pos,pos+len);
}

inline int get_sum(int pos,int len){
	return query3(1,1,n,pos,pos+len);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mst[u].pb(v);
		mst[v].pb(u);
	}
	dfs(r,0);
	cnt=0;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int k,a,b,x,lca;;
		cin>>k>>a;
		if(k==1){
			cin>>b>>x;
			lca=LCA(a,b);
			update(1,1,n,pos[a],x);
			update(1,1,n,pos[b],x);
			update(1,1,n,pos[lca],-x);
			if(pos[f[lca][0]]) update(1,1,n,pos[f[lca][0]],-x);
		}
		else if(k==2) cout<<val[a]+get_flag(pos[a],son[a])<<endl;
		else cout<<get_val(pos[a],son[a])+get_sum(pos[a],son[a])-get_flag(pos[a],son[a])*(dep[a]-1)<<endl;
	}
	return 0;
}

