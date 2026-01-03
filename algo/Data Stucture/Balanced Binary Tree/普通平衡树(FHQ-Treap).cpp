/*Author：AustinJiang
题目：普通平衡树 
时间复杂度：O(n*log(n))
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

int n,tot,root,val[N],lc[N],rc[N],rnd[N],sz[N];

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
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
	if(val[rt]<=x) a=rt,split(rc[rt],rc[rt],b,x);
	else b=rt,split(lc[rt],a,lc[rt],x);
	push_up(rt);
}

int merge(int a,int b){
	if(a*b==0) return a+b;
	if(rnd[a]<rnd[b]){
		rc[a]=merge(rc[a],b);
		push_up(a);
		return a;
	}
	else{
		lc[b]=merge(a,lc[b]);
		push_up(b);
		return b;
	}
}

void insert(int x){
	int a,b;
	split(root,a,b,x);
	root=merge(merge(a,newNode(x)),b);
}

void remove(int x){
	int a,b,c;
	split(root,a,c,x);
	split(a,a,b,x-1);
	b=merge(lc[b],rc[b]);
	root=merge(merge(a,b),c);
}

//int get_rank(int rt,int x){
//	if(!rt) return 1;
//	if(x<=val[rt]) return ranking(lc[rt],x);
//	return sz[lc[rt]]+1+ranking(rc[rt],x);
//}

int get_rank(int x){
	int a,b,ans;
	split(root,a,b,x-1);
	ans=sz[a]+1;
	root=merge(a,b);
	return ans;
}

int get_val(int rt,int x){
	if(x<=sz[lc[rt]]) return get_val(lc[rt],x);
	if(x==sz[lc[rt]]+1) return val[rt];
	return get_val(rc[rt],x-sz[lc[rt]]-1);
}

int pred(int x){
	int a,b,ans;
	split(root,a,b,x-1);
	ans=get_val(a,sz[a]);
	root=merge(a,b);
	return ans;
}

int succ(int x){
	int a,b,ans;
	split(root,a,b,x);
	ans=get_val(b,1);
	root=merge(a,b);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) insert(x);
		if(opt==2) remove(x);
		if(opt==3) cout<<get_rank(x)<<endl;
		if(opt==4) cout<<get_val(root,x)<<endl;
		if(opt==5) cout<<pred(x)<<endl;
		if(opt==6) cout<<succ(x)<<endl;
	}
	return 0;
}

