/*Author：AustinJiang
题目：Counting Haybales
时间复杂度：O(q*log(n))
算法：线段树 
来源：USACO 2015 December Contest, Platinum */
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

int n,q,sum[N*4],mn[N*4],lazy[N*4];

void push_up(int rt){
	sum[rt]=sum[rt*2]+sum[rt*2+1];
	mn[rt]=min(mn[rt*2],mn[rt*2+1]);
}

void push_down(int rt,int l,int mid,int r){
	lazy[rt*2]+=lazy[rt];
	lazy[rt*2+1]+=lazy[rt];
	sum[rt*2]+=lazy[rt]*(mid-l+1);
	sum[rt*2+1]+=lazy[rt]*(r-mid);
	mn[rt*2]+=lazy[rt];
	mn[rt*2+1]+=lazy[rt];
	lazy[rt]=0;
}

void build(int rt,int l,int r){
	if(l==r){
		cin>>sum[rt];
		mn[rt]=sum[rt];
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		lazy[rt]+=v;
		sum[rt]+=v*(r-l+1);
		mn[rt]+=v;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt*2,l,mid,x,y,v);
	else if(x>mid) update(rt*2+1,mid+1,r,x,y,v);
	else update(rt*2,l,mid,x,mid,v),update(rt*2+1,mid+1,r,mid+1,y,v);
	push_up(rt);
}

int query1(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) return query1(rt*2,l,mid,x,y);
	else if(x>mid) return query1(rt*2+1,mid+1,r,x,y);
	return query1(rt*2,l,mid,x,mid)+query1(rt*2+1,mid+1,r,mid+1,y);
}

int query2(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return mn[rt];
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) return query2(rt*2,l,mid,x,y);
	else if(x>mid) return query2(rt*2+1,mid+1,r,x,y);
	return min(query2(rt*2,l,mid,x,mid),query2(rt*2+1,mid+1,r,mid+1,y));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	build(1,1,n);
	for(int i=1;i<=q;i++){
		char opt;
		int a,b,c;
		cin>>opt>>a>>b;
		if(opt=='P') cin>>c,update(1,1,n,a,b,c);
		if(opt=='S') cout<<query1(1,1,n,a,b)<<endl;
		if(opt=='M') cout<<query2(1,1,n,a,b)<<endl;
	}
	return 0;
}

