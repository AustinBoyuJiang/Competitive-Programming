/*Author：AustinJiang
题目：可持久化线段树
时间复杂度：O(n*log(n))
算法：线段树，可持久化 */
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
const int N=2e6+10;
const int Q=1e5+10;

int n,q,tot,cnt,root[Q];

struct node{
	int lc,rc,mx;
} st[N];

void push_up(int rt){
	st[rt].mx=max(st[st[rt].lc].mx,st[st[rt].rc].mx);
}

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r){
		cin>>st[rt].mx;
		return;
	}
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt].mx;
	int mid=l+r>>1;
	if(y<=mid) return query(st[rt].lc,l,mid,x,y);
	else if(x>mid) return query(st[rt].rc,mid+1,r,x,y);
	else return max(query(st[rt].lc,l,mid,x,mid),query(st[rt].rc,mid+1,r,mid+1,y));
}

void update(int &rt,int rtk,int l,int r,int x,int y){
	st[rt=++tot]=st[rtk];
	if(l==r){
		st[rt].mx=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(st[rt].lc,st[rtk].lc,l,mid,x,y);
	else update(st[rt].rc,st[rtk].rc,mid+1,r,x,y);
	push_up(rt);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	build(root[++cnt],1,n);
	for(int i=1;i<=q;i++){
		int opt,k,x,y;
		cin>>opt>>k>>x>>y;
		if(opt==0) cout<<query(root[k],1,n,x,y)<<endl;
		else update(root[++cnt],root[k],1,n,x,y);
	}
	return 0;
}

