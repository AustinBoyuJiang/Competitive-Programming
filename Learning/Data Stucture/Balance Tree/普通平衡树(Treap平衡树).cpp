/*Author：AustinJiang
题目：普通平衡树 
时间复杂度：O(n*log(n))
算法：平衡树，Treap平衡树*/
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

int n,tot,root,predid,succid,ls[N],rs[N],val[N],rnd[N],cnt[N],sz[N];

void push_up(int rt){
	sz[rt]=sz[ls[rt]]+sz[rs[rt]]+cnt[rt];
}

void lturn(int &rt){
	int tmp=rs[rt];
	rs[rt]=ls[tmp];
	ls[tmp]=rt;
	push_up(rt);
	rt=tmp;
	push_up(tmp);
}

void rturn(int &rt){
	int tmp=ls[rt];
	ls[rt]=rs[tmp];
	rs[tmp]=rt;
	push_up(rt);
	rt=tmp;
	push_up(rt);
}

void insert(int &rt,int x){
	if(!rt){
		rt=++tot;
		val[rt]=x;
		rnd[rt]=rand();
		cnt[rt]=sz[rt]=1;
		return;
	}
	if(x<val[rt]){
		insert(ls[rt],x);
		if(rnd[ls[rt]]>rnd[rt]) rturn(rt);
	}
	else if(x>val[rt]){
		insert(rs[rt],x);
		if(rnd[rs[rt]]>rnd[rt]) lturn(rt);
	}
	else cnt[rt]++;
	push_up(rt);
}

void remove(int &rt,int x){
	if(!rt) return;
	if(x<val[rt]) remove(ls[rt],x);
	else if(x>val[rt]) remove(rs[rt],x);
	else{
		if(cnt[rt]>1){
			cnt[rt]--;
			sz[rt]--;
			return;
		}
		if(ls[rt]*rs[rt]==0) rt=ls[rt]+rs[rt];
		else{
			if(rnd[ls[rt]]>rnd[rs[rt]]) rturn(rt);
			else lturn(rt);
			remove(rt,x);
		}
	}
	push_up(rt);
}

void pred(int rt,int x){
	if(!rt) return;
	if(x<=val[rt]) pred(ls[rt],x);
	else predid=rt,pred(rs[rt],x);
}

void succ(int rt,int x){
	if(!rt) return;
	if(x>=val[rt]) succ(rs[rt],x);
	else succid=rt,succ(ls[rt],x);
}

int get_rank(int rt,int x){
	if(!rt) return 0;
	if(x<val[rt]) return get_rank(ls[rt],x);
	if(x>val[rt]) return sz[ls[rt]]+cnt[rt]+get_rank(rs[rt],x);
	return sz[ls[rt]]+1;
}

int get_val(int rt,int x){
	if(!rt) return 0;
	if(sz[ls[rt]]>=x) return get_val(ls[rt],x);
	if(sz[ls[rt]]+cnt[rt]>=x) return val[rt];
	return get_val(rs[rt],x-sz[ls[rt]]-cnt[rt]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) insert(root,x);
		if(opt==2) remove(root,x);
		if(opt==3) cout<<get_rank(root,x)<<endl;
		if(opt==4) cout<<get_val(root,x)<<endl;
		if(opt==5) pred(root,x),cout<<val[predid]<<endl;
		if(opt==6) succ(root,x),cout<<val[succid]<<endl;
	}
	return 0;
}

