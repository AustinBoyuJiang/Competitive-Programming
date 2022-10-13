/*Author：AustinJiang
题目：普通平衡树
时间复杂度：O(m*log(n))
算法：平衡树，FHQ-Treap */
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

int n,m,tot,root,val[N],lc[N],rc[N],rnd[N],sz[N],lazy[N];

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
}

void push_down(int rt){
	if(lazy[rt]){
		lazy[lc[rt]]^=1;
		lazy[rc[rt]]^=1;
		lazy[rt]=0;
		swap(lc[rt],rc[rt]);
	}
}

int newNode(int x){
	val[++tot]=x;
	rnd[tot]=rand();
	sz[tot]=1;
	return tot;
}

void split(int rt,int &a,int &b,int x){
	if(!rt){
		a=b=0;
		return;
	}
	push_down(rt);
	if(x<=sz[lc[rt]]) b=rt,split(lc[rt],a,lc[rt],x);
	else a=rt,split(rc[rt],rc[rt],b,x-sz[lc[rt]]-1);
	push_up(rt);
}

int merge(int a,int b){
	if(a*b==0) return a+b;
	if(rnd[a]<rnd[b]){
		push_down(a);
		rc[a]=merge(rc[a],b);
		push_up(a);
		return a;
	}
	else{
		push_down(b);
		lc[b]=merge(a,lc[b]);
		push_up(b);
		return b;
	}
}

void print(int rt){
	if(!rt) return;
	push_down(rt);
	print(lc[rt]);
	cout<<val[rt]<<' ';
	print(rc[rt]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		root=merge(root,newNode(i));
	for(int i=1;i<=m;i++){
		int l,r,a,b,c;
		cin>>l>>r;
		split(root,a,c,r);
		split(a,a,b,l-1);
		lazy[b]^=1;
		root=merge(merge(a,b),c);
	}
	print(root);
	return 0;
}

