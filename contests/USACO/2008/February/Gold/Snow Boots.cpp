/*Author：AustinJiang
题目：Snow Boots
时间复杂度：O(n*log(n))
算法：线段树
来源：USACO2018FEB Gold */
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
const int M=1e5+10;

int n,m,ans[M];

struct snow{
	int pos,dep;
} a[N];

struct boot{
	int id,dep,step;
} q[N];

struct node{
	int mx,lx,rx,sz;
} st[N*4];

bool cmp1(snow a,snow b){
	return a.dep<b.dep;
}

bool cmp2(boot a,boot b){
	return a.dep<b.dep;
}

void push_up(int rt){
	st[rt].sz=st[rt*2].sz+st[rt*2+1].sz;
	st[rt].lx=st[rt*2].lx;
	st[rt].rx=st[rt*2+1].rx;
	if(st[rt*2].lx==st[rt*2].sz)
		st[rt].lx+=st[rt*2+1].lx;
	if(st[rt*2+1].rx==st[rt*2+1].sz)
		st[rt].rx+=st[rt*2].rx;
	st[rt].mx=max(st[rt*2].mx,st[rt*2+1].mx);
	st[rt].mx=max(st[rt].mx,st[rt*2].rx+st[rt*2+1].lx);
	st[rt].mx=max(st[rt].mx,st[rt].lx);
	st[rt].mx=max(st[rt].mx,st[rt].rx);
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt].mx=st[rt].lx=st[rt].rx=st[rt].sz=1;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		st[rt].mx=st[rt].lx=st[rt].rx=0;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(rt*2,l,mid,x,y);
	else update(rt*2+1,mid+1,r,x,y);
	push_up(rt);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].pos=i;
		cin>>a[i].dep;
	}
	for(int i=1;i<=m;i++){
		q[i].id=i;
		cin>>q[i].dep>>q[i].step;
	}
	sort(a+1,a+n+1,cmp1);
	sort(q+1,q+m+1,cmp2);
	build(1,1,n-2);
	for(int i=1,j=0;i<=m;i++){
		while(j<n&&a[j+1].dep<=q[i].dep)
			if(a[++j].pos!=1&&a[j].pos!=n) update(1,1,n-2,a[j].pos-1,1);
		if(st[1].mx<q[i].step)
			ans[q[i].id]=1;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

