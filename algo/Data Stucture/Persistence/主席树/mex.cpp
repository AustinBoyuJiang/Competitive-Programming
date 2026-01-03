/*Author：AustinJiang
题目：mex
时间复杂度：O(n*log(n))
算法：主席树 
来源：BZOJ */
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

int n,m,tot,a[N],root[N];

struct node{
	int lc,rc,mn;
} st[N*40];

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
}

void update(int &rt,int rtk,int l,int r,int pos,int x){
	st[rt=++tot]=st[rtk];
	if(l==r){
		st[rt].mn=x;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(st[rt].lc,st[rtk].lc,l,mid,pos,x);
	else update(st[rt].rc,st[rtk].rc,mid+1,r,pos,x);
	st[rt].mn=min(st[st[rt].lc].mn,st[st[rt].rc].mn);
}

int query(int rt,int l,int r,int x){
	if(l==r) return l;
	int mid=l+r>>1;
	if(st[st[rt].lc].mn<x) return query(st[rt].lc,l,mid,x);
	else return query(st[rt].rc,mid+1,r,x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	build(root[0],0,n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=n) update(root[i],root[i-1],0,n,a[i],i);
		else root[i]=root[i-1];
	}
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cout<<query(root[r],0,n,l)<<endl;
	}
	return 0;
}

