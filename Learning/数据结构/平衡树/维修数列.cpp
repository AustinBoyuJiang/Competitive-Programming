/*Author：AustinJiang
题目：维修数列
时间复杂度：O(m*log(n))
算法：平衡树，Splay平衡树 
来源：NOI 2005 */
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
const int N=4e6+10;

int n,m,tot,root;
int a[N],val[N];
int lc[N],rc[N],fa[N];
int sum[N],sz[N];
int lazy1[N],lazy2[N],flag[N];
int mx[N],lx[N],rx[N];

bool dir(int rt){
	return lc[fa[rt]]==rt;
}

void push_up(int rt){
	sum[rt]=sum[lc[rt]]+sum[rc[rt]]+val[rt];
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
	fa[lc[rt]]=fa[rc[rt]]=rt;
	lx[rt]=lx[lc[rt]];
	rx[rt]=rx[rc[rt]];
	lx[rt]=max(lx[rt],sum[rt]);
	rx[rt]=max(rx[rt],sum[rt]);
	lx[rt]=max(lx[rt],sum[lc[rt]]+val[rt]);
	rx[rt]=max(rx[rt],sum[rc[rt]]+val[rt]);
	lx[rt]=max(lx[rt],sum[lc[rt]]+val[rt]+lx[rc[rt]]);
	rx[rt]=max(rx[rt],sum[rc[rt]]+val[rt]+rx[lc[rt]]);
	mx[rt]=val[rt];
	mx[rt]=max(mx[rt],max(lx[rt],rx[rt]));
	mx[rt]=max(mx[rt],rx[lc[rt]]+val[rt]);
	mx[rt]=max(mx[rt],lx[rc[rt]]+val[rt]);
	mx[rt]=max(mx[rt],max(mx[lc[rt]],mx[rc[rt]]));
	mx[rt]=max(mx[rt],rx[lc[rt]]+lx[rc[rt]]+val[rt]);
}

void push_down(int rt){
	if(flag[rt]){
		flag[rt]=0;
		flag[lc[rt]]=1;
		flag[rc[rt]]=1;
		lazy1[lc[rt]]=lazy1[rt];
		lazy1[rc[rt]]=lazy1[rt];
		val[lc[rt]]=val[rc[rt]]=lazy1[rt];
		sum[lc[rt]]=lazy1[rt]*sz[lc[rt]];
		sum[rc[rt]]=lazy1[rt]*sz[rc[rt]];
		if(lazy1[rt]<=0){
			mx[lc[rt]]=lx[lc[rt]]=rx[lc[rt]]=lazy1[rt];
			mx[rc[rt]]=lx[rc[rt]]=rx[rc[rt]]=lazy1[rt];
		}
		else{
			mx[lc[rt]]=lx[lc[rt]]=rx[lc[rt]]=sum[lc[rt]];
			mx[rc[rt]]=lx[rc[rt]]=rx[rc[rt]]=sum[rc[rt]];
		}
	}
	if(lazy2[rt]){
		lazy2[rt]=0;
		lazy2[lc[rt]]^=1;
		lazy2[rc[rt]]^=1; 
		swap(lc[rt],rc[rt]);
		swap(lx[lc[rt]],rx[lc[rt]]);
		swap(lx[rc[rt]],rx[rc[rt]]);
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

int find(int rt,int x){
	push_down(rt);
	if(!rt) return 0;
	if(x<=sz[lc[rt]]) return find(lc[rt],x);
	if(x==sz[lc[rt]]+1) return rt; 
	return find(rc[rt],x-sz[lc[rt]]-1);
}

void add(int &rt,int x){
	if(!rt){
		rt=++tot;
		val[rt]=sum[rt]=x;
		mx[rt]=lx[rt]=rx[rt]=x;
		sz[rt]=1;
		return;
	}
	add(rc[rt],x);
	push_up(rt);
}

int build(int l,int r){
	if(r<l) return 0;
	int mid=l+r>>1;
	int rt=++tot;
	val[rt]=sum[rt]=a[mid];
	mx[rt]=lx[rt]=rx[rt]=a[mid];
	lc[rt]=build(l,mid-1);
	rc[rt]=build(mid+1,r);
	push_down(rt);
	push_up(rt);
	return rt;
}

void insert(int pos,int num){
	for(int i=1;i<=num;i++)
		cin>>a[i];
	int rt=build(1,num);
	splay(find(root,pos-1),0);
	splay(find(root,pos),root);
	lc[rc[root]]=rt;
	push_up(rc[root]);
	push_up(root);
}

void remove(int pos,int num){
	splay(find(root,pos-1),0);
	splay(find(root,pos+num),root);
	lc[rc[root]]=0;
	push_up(rc[root]);
	push_up(root);
}

void make_same(int pos,int num,int x){
	splay(find(root,pos-1),0);
	splay(find(root,pos+num),root);
	int rt=lc[rc[root]];
	flag[rt]=1;
	lazy1[rt]=x;
	val[rt]=x;
	sum[rt]=x*sz[rt];
	if(x<=0) mx[rt]=lx[rt]=rx[rt]=x;
	else mx[rt]=lx[rt]=rx[rt]=sum[rt];
	push_up(rc[root]);
	push_up(root);
}

void reverse(int pos,int num){
	splay(find(root,pos-1),0);
	splay(find(root,pos+num),root);
	lazy2[lc[rc[root]]]^=1;
	swap(lx[lc[rc[root]]],rx[lc[rc[root]]]);
	push_up(rc[root]);
	push_up(root);
}

int get_sum(int pos,int num){
	splay(find(root,pos-1),0);
	splay(find(root,pos+num),root);
	return sum[lc[rc[root]]];
}

int get_max_sum(){
	splay(find(root,1),0);
	splay(find(root,sz[root]),root);
	return mx[lc[rc[root]]];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	add(root,0);
	add(root,0);
	insert(2,n);
	for(int i=1;i<=m;i++){
		int pos,num,x;
		string opt;
		cin>>opt;
		if(opt=="INSERT") cin>>pos>>num,insert(pos+2,num);
		if(opt=="DELETE") cin>>pos>>num,remove(pos+1,num);
		if(opt=="MAKE-SAME") cin>>pos>>num>>x,make_same(pos+1,num,x);
		if(opt=="REVERSE") cin>>pos>>num,reverse(pos+1,num);
		if(opt=="GET-SUM") cin>>pos>>num,cout<<get_sum(pos+1,num)<<endl;
		if(opt=="MAX-SUM") cout<<get_max_sum()<<endl;
	}
	return 0;
}

