/*Author：AustinJiang
题目：晋升计数 
时间复杂度：O(n*log(n))
算法：主席树，DFS序，离散化 
来源：USACO 2017 January Contest, Platinum */
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

int n,cnt1,cnt2,tot,val[N],f[N],id[N],fa[N],ord[N],pos[N],sz[N],root[N];
set<int> num;
VI e[N];

struct node{
	int lc,rc,sum;
} st[N*21];

int find(int x){
	int l=1,r=cnt1;
	while(l<=r){
		int mid=l+r>>1;
		if(f[mid]==x) return mid;
		if(f[mid]<x) l=mid+1;
		if(f[mid]>x) r=mid-1;
	}
}

void dfs(int u){
	ord[++cnt2]=u;
	pos[u]=cnt2;
	sz[u]=1;
	for(auto v:e[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
}

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
}

void update(int &rt,int rtk,int l,int r,int x){
	st[rt=++tot]=st[rtk];
	st[rt].sum++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) update(st[rt].lc,st[rtk].lc,l,mid,x);
	else update(st[rt].rc,st[rtk].rc,mid+1,r,x);
}

int query(int rt,int rtk,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rtk].sum-st[rt].sum;
	int mid=l+r>>1;
	if(y<=mid) return query(st[rt].lc,st[rtk].lc,l,mid,x,y);
	else if(x>mid) return query(st[rt].rc,st[rtk].rc,mid+1,r,x,y);
	else return query(st[rt].lc,st[rtk].lc,l,mid,x,mid)+query(st[rt].rc,st[rtk].rc,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		num.insert(val[i]);
	}
	for(auto i:num)
		f[++cnt1]=i;
	sort(f+1,f+cnt1+1);
	for(int i=1;i<=n;i++)
		id[i]=find(val[i]);
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		e[fa[i]].pb(i);
	}
	dfs(1);
	build(root[0],1,n);
	for(int i=1;i<=n;i++)
		update(root[i],root[i-1],1,n,id[ord[i]]);
	for(int i=1;i<=n;i++){
		if(id[i]==n) cout<<0<<endl;
		else cout<<query(root[pos[i]],root[pos[i]+sz[i]-1],1,n,id[i]+1,n)<<endl;
	}
	return 0;
}

