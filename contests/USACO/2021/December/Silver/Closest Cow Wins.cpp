/*Author：AustinJiang
题目：Closest Cow Wins
时间复杂度：O(n*log(n))
算法：优先队列，线段树，双指针 
来源：USACO 2022 December Silver */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
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

int k,m,n,ans,root,tot,f[N];
PQ<PI,VPI,less<PI>> q;

struct grass{
	int pos,val,co;
} g[N];

struct cow{
	int left,right,g1,g2;
} c[N];

bool cmp(grass a,grass b){
	return a.pos<b.pos;
}

struct node{
	int lc,rc,sum;
} st[10000000];

void push_up(int rt){
	st[rt].sum=st[st[rt].lc].sum+st[st[rt].rc].sum;
}

void update(int &rt,int l,int r,int x,int y){
	if(!rt) rt=++tot;
	if(l==r){
		st[rt].sum+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(st[rt].lc,l,mid,x,y);
	else update(st[rt].rc,mid+1,r,x,y);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(!rt) return 0;
	if(l==x&&r==y) return st[rt].sum;
	int mid=l+r>>1;
	if(y<=mid) return query(st[rt].lc,l,mid,x,y);
	else if(x>mid) return query(st[rt].rc,mid+1,r,x,y);
	else return query(st[rt].lc,l,mid,x,mid)+query(st[rt].rc,mid+1,r,mid+1,y);
}

void add(int pos,int x){
	update(root,0,1e9,pos,x);
}

int get(int l,int r){
	return query(root,0,1e9,max(l,0ll),min((ll)1e9,r));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>m>>n;
	for(int i=1;i<=k;i++){
		cin>>g[i].pos>>g[i].val;
		add(g[i].pos,g[i].val);
	}
	for(int i=1;i<=m;i++)
		cin>>f[i];
	sort(g+1,g+k+1,cmp);
	sort(f+1,f+m+1);
	f[0]=-INF;
	f[++m]=INF;
	for(int i=1;i<=m;i++){
		c[i].left=f[i-1];
		c[i].right=f[i];
	}
	int j=1;
	for(int i=1;i<=k;i++){
		while(j<m&&c[j+1].left<g[i].pos) j++;
		g[i].co=j;
	}
	for(int i=1;i<=k;i++){
		int l=c[g[i].co].left;
		int r=c[g[i].co].right;
		int pos=g[i].pos;
		int x=ceil((double)(pos+l+1)/2);
		int y=(pos+r-1)/2;
		c[g[i].co].g1=max(c[g[i].co].g1,get(x,y));
	}
	for(int i=1;i<=k;i++){
		c[i].g2=get(c[i].left,c[i].right)-c[i].g1;
		q.push(mp(c[i].g1,i));
	}
	while(n--){
		PI top=q.top();
		q.pop();
		ans+=top.fir;
		if(top.sec) q.push(mp(c[top.sec].g2,0));
	}
	cout<<ans<<endl;
	return 0;
}

