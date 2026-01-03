/*Author：AustinJiang
题目：网络[ZJOI2012]
时间复杂度：O(c*k*log(n))
算法：动态树 
来源：ZJOI 2012 D2T2 */
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
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e4+10;
const int C=20;

int n,m,c,k;
map<PI,int> e;

struct lct{
	int val[N],mx[N],fa[N],c[N][2],lazy[N],in[N];
	
	bool nroot(int x){
		return c[fa[x]][0]==x||c[fa[x]][1]==x;
	}
	
	void push_up(int x){
		mx[x]=max(val[x],max(mx[lc],mx[rc]));
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
			rc=y;
			push_up(x);
		}
	}
	
	void make_root(int x){
		access(x),splay(x);
		reverse(x);
	}
	
	int find(int x){
		access(x),splay(x);
		while(lc) x=lc;
		splay(x);
		return x;
	}
	
	void split(int x,int y){
		make_root(x);
		access(y),splay(y);
	}
	
	void link(int x,int y){
		make_root(x);
		fa[x]=y;
		in[x]++;
		in[y]++;
	}
	
	void cut(int x,int y){
		split(y,x);
		fa[y]=lc=0;
		in[x]--;
		in[y]--;
	}
	
} co[C];

void update_node(int x,int y){
	for(int i=0;i<10;i++){
		co[i].splay(x);
		co[i].val[x]=y;
	}
}

string update_edge(int x,int y,int z){
	if(!e.count(mp(x,y))) return "No such edge.";
	if(e[mp(x,y)]==z) return "Success.";
	if(co[z].in[x]>1||co[z].in[y]>1) return "Error 1.";
	if(co[z].find(x)==co[z].find(y)) return "Error 2.";
	co[e[mp(x,y)]].cut(x,y);
	co[z].link(x,y);
	e[mp(x,y)]=z;
	e[mp(y,x)]=z;
	return "Success.";
}

int query_path(int x,int y,int z){
	if(co[z].find(x)!=co[z].find(y)) return -1;
	co[z].split(x,y);
	return co[z].mx[y];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		for(int j=0;j<c;j++) co[j].val[i]=x;
	}
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		co[w].link(u,v);
		e[mp(u,v)]=w;
		e[mp(v,u)]=w;
	}
	for(int i=1;i<=k;i++){
		int opt,x,y,z;
		cin>>opt;
		if(opt==0) cin>>x>>y,update_node(x,y);
		if(opt==1) cin>>x>>y>>z,cout<<update_edge(x,y,z)<<endl;
		if(opt==2) cin>>z>>x>>y,cout<<query_path(x,y,z)<<endl;
	}
	return 0;
}

