/*Author：AustinJiang
题目：堵塞的交通 
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n;

struct node{
	bool u,d,l,r,p,q;
} g[N],st[N<<2];

void check(int rt,int id){
	st[rt].u=g[id].u|(g[id].d&g[id].l&g[id].r);
	st[rt].d=g[id].d|(g[id].u&g[id].l&g[id].r);
	st[rt].l=g[id].l|(g[id].u&g[id].d&g[id].r);
	st[rt].r=g[id].r|(g[id].u&g[id].d&g[id].l);
	st[rt].p=(g[id].u&g[id].l)|(g[id].d&g[id].r);
	st[rt].q=(g[id].u&g[id].r)|(g[id].d&g[id].l);
}

node merge(node a,node b){
	node res;
	res.u=(a.u&b.u)|(a.q&b.p);
	res.d=(a.d&b.d)|(a.p&b.q);
	res.l=a.l|(a.u&a.d&b.l);
	res.r=b.r|(b.u&b.d&a.r);
	res.p=(a.p&b.u)|(a.d&b.p);
	res.q=(a.q&b.d)|(a.u&b.q);
	return res;
}

void update(int rt,int l,int r,int r1,int c1,int r2,int c2,bool k){
	if(l+1==r&&l<=c1&&c2<=r){
		if(r1==r2){
			if(r1==1) g[l].u=k;
			else g[l].d=k;
		}
		else{
			if(c1==l) g[l].l=k;
			else g[l].r=k;
		}
		check(rt,l);
		return;
	}
	int mid=l+r>>1;
	if(c2<=mid) update(rt<<1,l,mid,r1,c1,r2,c2,k);
	if(mid<=c1) update(rt<<1|1,mid,r,r1,c1,r2,c2,k);
	st[rt]=merge(st[rt<<1],st[rt<<1|1]);
}

node query(int rt,int l,int r,int x,int y){
	if(x==y) return node();
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>=mid) return query(rt<<1|1,mid,r,x,y);
	else return merge(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid,r,mid,y));
}

bool ask(int r1,int c1,int r2,int c2){
	if(c1==c2){
		if(r1==r2) return 1;
		return query(1,1,n,1,c1).r|query(1,1,n,c1,n).l;
	}
	else{
		node a=query(1,1,n,1,c1);
		node b=query(1,1,n,c1,c2);
		node c=query(1,1,n,c2,n);
		if(r1==r2){
			if(r1==1) return b.u|(a.r&b.d&c.l)|(a.r&b.p)|(c.l&b.q);
			else return b.d|(a.r&b.u&c.l)|(b.p&c.l)|(b.q&&a.r);
		}
		else{
			if(r1==1) return b.q|(a.r&b.d)|(b.u&c.l)|(a.r&b.p&c.l);
			else return b.p|(a.r&b.u)|(b.d&c.l)|(a.r&b.q&c.l);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(1){
		int r1,c1,r2,c2;
		string opt;
		cin>>opt;
		if(opt=="Exit") break;
		cin>>r1>>c1>>r2>>c2;
		if(c1>c2) swap(c1,c2),(r1,r2);
		if(opt=="Open") update(1,1,n,r1,c1,r2,c2,1);
		if(opt=="Close") update(1,1,n,r1,c1,r2,c2,0);
		if(opt=="Ask") cout<<(ask(r1,c1,r2,c2)?"Y":"N")<<endl;
	}
	return 0;
}

