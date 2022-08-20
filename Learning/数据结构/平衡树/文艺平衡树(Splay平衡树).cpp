/*Author：AustinJiang
题目：文艺平衡树 
时间复杂度：O(m*log(n))
算法：平衡树，Splay平衡树
思路：lazy懒标记 
*/
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

int n,m,root,tot,lc[N],rc[N],fa[N],sz[N],lazy[N];

bool dir(int x){
	return lc[fa[x]]==x;
}

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
	fa[lc[rt]]=fa[rc[rt]]=rt;
}

void push_down(int rt){
	if(lazy[rt]){
		lazy[rt]=0;
		lazy[lc[rt]]^=1;
		lazy[rc[rt]]^=1;
		swap(lc[rt],rc[rt]);
	}
}

void turn(int x){
	int y=fa[x];
	if(dir(x)) lc[y]=rc[x],rc[x]=y;
	else rc[y]=lc[x],lc[x]=y;
	if(dir(y)) lc[fa[y]]=x;
	else rc[fa[y]]=x;
	fa[x]=fa[y];
	push_up(y);
	push_up(x);
}

void splay(int rt,int goal){
	while(fa[rt]!=goal){
		if(fa[fa[rt]]!=goal){
			if(dir(rt)==dir(fa[rt])) turn(fa[rt]);
			else turn(rt);
		}
		turn(rt);
	}
	if(!goal) root=rt,fa[root]=0;
}

void insert(int &rt,int x){
	if(!rt){
		rt=++tot;
		sz[rt]=1;
		return;
	}
	insert(rc[rt],x);
	push_up(rt);
}

int find(int rt,int x){
	push_down(rt);
	if(x<=sz[lc[rt]]) return find(lc[rt],x);
	if(x==sz[lc[rt]]+1) return rt;
	return find(rc[rt],x-sz[lc[rt]]-1);
}

void solve(int rt){
	if(!rt) return;
	push_down(rt);
	solve(lc[rt]);
	if(rt>1&&rt<n+2) cout<<rt-1<<' ';
	solve(rc[rt]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n+2;i++)
		insert(root,i),splay(tot,0);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		splay(find(root,l),0);
		splay(find(root,r+2),root);
		lazy[lc[rc[root]]]^=1;
	}
	solve(root);
	return 0;
}
