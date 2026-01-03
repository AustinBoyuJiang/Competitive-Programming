/*Author：AustinJiang
题目：动态树
时间复杂度：O(m*log(n))
算法：LCT */
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
const int N=3e5+10;

int n,m,val[N],sum[N],fa[N],c[N][2],lazy[N];

bool nroot(int x){
	return c[fa[x]][0]==x||c[fa[x]][1]==x;
}

void push_up(int x){
	sum[x]=sum[c[x][0]]^sum[c[x][1]]^val[x];
}

void reverse(int x){
	swap(c[x][0],c[x][1]);
	lazy[x]^=1;
}

void push_down(int x){
	if(lazy[x]){
		if(c[x][0]) reverse(c[x][0]);
		if(c[x][1]) reverse(c[x][1]);
		lazy[x]=0;
	}
}

void push_all(int x){
	if(nroot(x)) push_all(fa[x]);
	push_down(x);
}

void rotate(int x){
	int y=fa[x],z=fa[y],k=c[y][1]==x,w=c[x][!k];
	if(nroot(y)) c[z][c[z][1]==y]=x;
	c[x][!k]=y;
	c[y][k]=w;
	if(w) fa[w]=y;
	fa[y]=x;
	fa[x]=z;
	push_up(y);
}

void splay(int x){
	push_all(x);
	while(nroot(x)){
		int y=fa[x],z=fa[y];
		if(nroot(y)) rotate((c[y][0]==x)^(c[z][0]==y)?x:y);
		rotate(x);
	}
	push_up(x);
}

void access(int x){
	for(int y=0;x;x=fa[y=x]){
		splay(x);
		c[x][1]=y;
		push_up(x);
	}
}

void make_root(int x){
	access(x); splay(x);
	reverse(x);
}

int find_root(int x){
	access(x); splay(x);
	while(c[x][0]){
		push_down(x);
		x=c[x][0];
	}
	splay(x);
	return x;
}

void split(int x,int y){
	make_root(x);
	access(y); splay(y);
}

void link(int x,int y){
	make_root(x);
	if(find_root(y)!=x) fa[x]=y;
}

void cut(int x,int y){
	make_root(x);
	if(find_root(y)==x&&fa[y]==x&&!c[y][0]){
		fa[y]=c[x][1]=0;
		push_up(x);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=m;i++){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==0) split(x,y),cout<<sum[y]<<endl;
		if(opt==1) link(x,y);
		if(opt==2) cut(x,y);
		if(opt==3) splay(x),val[x]=y;
	}
	return 0;
}

