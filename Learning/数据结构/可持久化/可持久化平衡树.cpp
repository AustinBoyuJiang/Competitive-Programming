/*Author：AustinJiang
题目：可持久化平衡树 
时间复杂度：O(n*log(n))
算法：平衡树，可持久化，FHQ-Treap */
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

int n,cnt,tot,root[N],val[N],lc[N],rc[N],rnd[N],sz[N];

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
}

int newNode(int x){
	val[++tot]=x;
	rnd[tot]=rand();
	sz[tot]=1;
	return tot;
}

int copyNode(int rt){
	val[++tot]=val[rt];
	lc[tot]=lc[rt];
	rc[tot]=rc[rt];
	rnd[tot]=rnd[rt];
	sz[tot]=sz[rt];
	return tot;
}

void split(int rt,int &a,int &b,int x){
	if(!rt){
		a=b=0;
		return;
	}
	int now=copyNode(rt);
	if(val[now]<=x) a=now,split(rc[now],rc[now],b,x);
	else b=now,split(lc[now],a,lc[now],x);
	push_up(now);
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

void insert(int k,int x){
	int a,b;
	split(root[k],a,b,x);
	root[cnt]=merge(merge(a,newNode(x)),b);
}

void remove(int k,int x){
	int a,b,c;
	split(root[k],a,c,x);
	split(a,a,b,x-1);
	b=merge(lc[b],rc[b]);
	root[cnt]=merge(merge(a,b),c);
}

int get_rank(int k,int x){
	int a,b,ans;
	split(root[k],a,b,x-1);
	ans=sz[a]+1;
	root[cnt]=merge(a,b);
	return ans;
}

int find(int rt,int x){
	if(x<=sz[lc[rt]]) return find(lc[rt],x);
	if(x==sz[lc[rt]]+1) return val[rt];
	return find(rc[rt],x-sz[lc[rt]]-1);
}

int get_val(int k,int x){
	root[cnt]=root[k];
	return find(root[cnt],x);
}

int pred(int k,int x){
	int a,b,ans;
	split(root[k],a,b,x-1);
	ans=sz[a]?find(a,sz[a]):-INT_MAX;
	root[cnt]=merge(a,b);
	return ans;
}

int succ(int k,int x){
	int a,b,ans;
	split(root[k],a,b,x);
	ans=sz[b]?find(b,1):INT_MAX;
	root[cnt]=merge(a,b);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(cnt=1;cnt<=n;cnt++){
		int k,opt,x;
		cin>>k>>opt>>x;
		if(opt==1) insert(k,x);
		if(opt==2) remove(k,x);
		if(opt==3) cout<<get_rank(k,x)<<endl;
		if(opt==4) cout<<get_val(k,x)<<endl;
		if(opt==5) cout<<pred(k,x)<<endl;
		if(opt==6) cout<<succ(k,x)<<endl;
	}
	return 0;
}

