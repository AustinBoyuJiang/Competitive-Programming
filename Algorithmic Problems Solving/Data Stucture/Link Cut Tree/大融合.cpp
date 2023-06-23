/*Author：AustinJiang
题目：大融合 
时间复杂度：O(q*log(n))
算法：动态树 
来源：BJOI 2014 */
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
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;

int n,q,siz[N],ft[N],fa[N],c[N][2],lazy[N];

bool nroot(int x){
	return c[fa[x]][0]==x||c[fa[x]][1]==x;
}

void push_up(int x){
	siz[x]=siz[lc]+siz[rc]+ft[x]+1;
}

void reverse(int x){
	swap(lc,rc);
	lazy[x]^=1;
}

void push_down(int x){
	if(lazy[x]){
		if(lc) reverse(lc);
		if(rc) reverse(rc);
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
	push_up(x);
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
		ft[x]-=siz[y];
		ft[x]+=siz[c[x][1]];
		c[x][1]=y;
		push_up(x);
	}
}

void make_root(int x){
	access(x);
	splay(x);
	reverse(x);
}

void split(int x,int y){
	make_root(x);
	access(y);
	splay(y);
}

void link(int x,int y){
	make_root(x);
	access(y);
	splay(y);
	fa[x]=y;
	ft[y]+=siz[x];
	push_up(y);
}

int query(int x,int y){
	split(x,y);
	push_up(x);
	return siz[x]*(siz[y]-siz[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		char opt;
		int x,y;
		cin>>opt>>x>>y;
		if(opt=='A') link(x,y);
		if(opt=='Q') cout<<query(x,y)<<endl;
	}
	return 0;
}

