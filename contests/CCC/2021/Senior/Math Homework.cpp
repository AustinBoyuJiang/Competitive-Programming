/*Author：AustinJiang
题目：Math Homework
时间复杂度：O(n*log(n)^2)
算法：线段树 
来源：CCC 2021 Senior */
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

int n,m,st[N<<2],lazy[N<<2];

struct QUERY{
	int a,b,c;
} q[N];

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

int lcd(int a,int b){
	return a*b/gcd(a,b);
}

void push_up(int rt){
	st[rt]=gcd(st[rt<<1],st[rt<<1|1]);
}

void push_down(int rt,int l,int mid,int r){
	st[rt<<1]=lcd(st[rt<<1],lazy[rt]);
	st[rt<<1|1]=lcd(st[rt<<1|1],lazy[rt]);
	lazy[rt<<1]=lcd(lazy[rt<<1],lazy[rt]);
	lazy[rt<<1|1]=lcd(lazy[rt<<1|1],lazy[rt]);
	lazy[rt]=1;
}

void build(int rt,int l,int r){
	st[rt]=lazy[rt]=1;
	if(l==r) return;
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		st[rt]=lcd(st[rt],v);
		lazy[rt]=lcd(lazy[rt],v);
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
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return gcd(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>q[i].a>>q[i].b>>q[i].c;
		update(1,1,n,q[i].a,q[i].b,q[i].c);
	}
	bool res=1;
	for(int i=1;i<=m;i++){
		if(query(1,1,n,q[i].a,q[i].b)!=q[i].c){
			res=0;
			break;
		}
	}
	if(!res) cout<<"Impossible"<<endl;
	else{
		for(int i=1;i<=n;i++)
			cout<<query(1,1,n,i,i)<<" ";
	}
	return 0;
}

