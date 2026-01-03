/*Author：AustinJiang
题目：普通平衡树
时间复杂度：O(n*log(n))
算法：平衡树，Splay平衡树 */
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

int n,tot,root,predid,succid,fa[N],lc[N],rc[N],val[N],cnt[N],sz[N];

bool dir(int rt){
	return lc[fa[rt]]==rt;
}

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+cnt[rt];
	fa[lc[rt]]=fa[rc[rt]]=rt;
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

void splay(int rt){
	while(fa[rt]){
		if(fa[fa[rt]]){
			if(dir(rt)==dir(fa[rt])) turn(fa[rt]);
			else turn(rt);
		}
		turn(rt);
	}
	root=rt;
	fa[root]=0;
}

int find(int rt,int x){
	if(!rt) return 0;
	if(x<val[rt]) return find(lc[rt],x);
	if(x>val[rt]) return find(rc[rt],x);
	return rt;
}

void pred(int rt,int x){
	if(!rt) return;
	if(x<=val[rt]) pred(lc[rt],x);
	else predid=rt,pred(rc[rt],x);
}

void succ(int rt,int x){
	if(!rt) return;
	if(x>=val[rt]) succ(rc[rt],x);
	else succid=rt,succ(lc[rt],x);
}

void merge(int x,int y){
	if(x*y==0){
		root=x+y;
		fa[root]=0;
		return;
	}
	pred(fa[x],val[fa[x]]);
	splay(predid);
	rc[root]=y;
	push_up(root);
}

void insert(int &rt,int x){
	if(!rt){
		rt=++tot;
		val[rt]=x;
		cnt[rt]=sz[rt]=1;
		return;
	}
	if(x<val[rt]) insert(lc[rt],x);
	else if(x>val[rt]) insert(rc[rt],x);
	else cnt[rt]++;
	push_up(rt);
}

void remove(int x){
	int rt=find(root,x);
	if(!rt) return;
	splay(rt);
	if(--cnt[rt]) push_up(rt);
	else merge(lc[rt],rc[rt]);
}

int get_rank(int rt,int x){
	if(x<val[rt]) return get_rank(lc[rt],x);
	if(x>val[rt]) return sz[lc[rt]]+cnt[rt]+get_rank(rc[rt],x);
	return sz[lc[rt]]+1;
}

int get_val(int rt,int x){
	if(x<=sz[lc[rt]]) return get_val(lc[rt],x);
	if(x<=sz[lc[rt]]+cnt[rt]) return val[rt];
	return get_val(rc[rt],x-sz[lc[rt]]-cnt[rt]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) insert(root,x),splay(find(root,x));
		if(opt==2) remove(x);
		if(opt==3) cout<<get_rank(root,x)<<endl;
		if(opt==4) cout<<get_val(root,x)<<endl;
		if(opt==5) cout<<get_rank(root,x)<<endl;
		if(opt==6) cout<<get_rank(root,x)<<endl;
		if(opt==5) pred(root,x),cout<<val[predid]<<endl;
		if(opt==6) succ(root,x),cout<<val[succid]<<endl;
	}
	return 0;
}

