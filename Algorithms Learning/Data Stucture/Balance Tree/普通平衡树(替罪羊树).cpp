/*Author：AustinJiang
题目：普通平衡树 
时间复杂度：O(n*log(n))
算法：平衡树，替罪羊树 */
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
const double alpha=0.75;

int n,cnt,tot,root,val[N],lc[N],rc[N],sz[N],fac[N],live[N],lrd[N];

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+1;
	fac[rt]=fac[rc[rt]]+fac[lc[rt]]+live[rt];
}

void init(int rt){
	lc[rt]=rc[rt]=0;
	sz[rt]=fac[rt]=live[rt]=1;
}

int new_node(int x){
	val[++tot]=x;
	init(tot);
	return tot;
}

bool balance(int rt){
	return (double) fac[rt]*alpha>max(fac[lc[rt]],fac[rc[rt]]);
}

void inorder(int rt){
	if(!rt) return;
	inorder(lc[rt]);
	if(live[rt]) lrd[++cnt]=rt;
	inorder(rc[rt]);
}

void build(int &rt,int l,int r){
	if(r<l){
		rt=0;
		return;
	}
	int mid=l+r>>1;
	rt=lrd[mid];
	if(l==r){
		init(rt);
		return;
	}
	build(lc[rt],l,mid-1);
	build(rc[rt],mid+1,r);
	push_up(rt);
}

void rebuild(int &rt){
	cnt=0;
	inorder(rt);
	if(!cnt) rt=0;
	else build(rt,1,cnt);
}

void check(int &rt,int x){
	if(!rt) return;
	if(!balance(rt)){
		rebuild(rt);
		return;
	}
	if(x<=val[rt]) check(lc[rt],x);
	else check(rc[rt],x);
}

void insert(int &rt,int x){
	if(!rt){
		rt=new_node(x);
		return;
	}
	if(x<=val[rt]) insert(lc[rt],x);
	else insert(rc[rt],x);
	push_up(rt);
}

int get_rank(int rt,int x){
	if(!rt) return 1;
	if(x<=val[rt]) return get_rank(lc[rt],x);
	else return get_rank(rc[rt],x)+fac[lc[rt]]+live[rt];
}

int get_val(int rt,int x){
	if(x<=fac[lc[rt]]) return get_val(lc[rt],x);
	if(x<=fac[lc[rt]]+live[rt]) return val[rt];
	return get_val(rc[rt],x-fac[lc[rt]]-live[rt]);
}

void del(int rt,int x){
	if(live[rt]&&fac[lc[rt]]+1==x){
		live[rt]=0;
		push_up(rt);
		return;
	}
	if(x<=fac[lc[rt]]+live[rt]) del(lc[rt],x);
	else del(rc[rt],x-fac[lc[rt]]-live[rt]);
	push_up(rt);
}

void remove(int x){
	del(root,get_rank(root,x));
	if((double)sz[root]*alpha>fac[root]) rebuild(root);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) insert(root,x),check(root,x);
		if(opt==2) remove(x);
		if(opt==3) cout<<get_rank(root,x)<<endl;
		if(opt==4) cout<<get_val(root,x)<<endl;
		if(opt==5) cout<<get_val(root,get_rank(root,x)-1)<<endl;
		if(opt==6) cout<<get_val(root,get_rank(root,x+1))<<endl;
	}
	return 0;
}

