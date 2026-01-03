/*Author：AustinJiang
题目：树套树
时间复杂度：O(m*log(n)*log(n))
算法：树套树，线段树，平衡树 */
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
const int N=5e4+10;
const int E=N*20;

int n,m,tot,predid,succid,root[N<<2],lc[E],rc[E],fa[E],val[E],cnt[E],sz[E];

void push_up(int rt){
	sz[rt]=sz[lc[rt]]+sz[rc[rt]]+cnt[rt];
	fa[lc[rt]]=fa[rc[rt]]=rt; 
}

bool dir(int rt){
	return lc[fa[rt]]==rt;
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

void splay(int &root,int rt){
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

int Max(int rt){
	if(rc[rt]) return Max(rc[rt]);
	return rt;
}

int Min(int rt){
	if(lc[rt]) return Min(lc[rt]);
	return rt;
}

void merge(int &root,int x,int y){
	if(x*y==0){
		root=x+y;
		fa[root]=0;
		return;
	}
	splay(root,Max(x));
	rc[root]=y;
	push_up(root);
}

int find(int rt,int x){
	if(!rt) return 0;
	if(x<val[rt]) return find(lc[rt],x);
	if(x>val[rt]) return find(rc[rt],x);
	return rt;
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

void remove(int &root,int x){
	int rt=find(root,x);
	if(!rt) return;
	splay(root,rt);
	if(--cnt[rt]) push_up(rt);
	else merge(root,lc[rt],rc[rt]);
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

int get_max(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return val[Max(root[rt])];
	int mid=l+r>>1;
	if(y<=mid) return get_max(rt<<1,l,mid,x,y);
	else if(x>mid) return get_max(rt<<1|1,mid+1,r,x,y);
	else return max(get_max(rt<<1,l,mid,x,mid),get_max(rt<<1|1,mid+1,r,mid+1,y));
}

int get_min(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return val[Min(root[rt])];
	int mid=l+r>>1;
	if(y<=mid) return get_min(rt<<1,l,mid,x,y);
	else if(x>mid) return get_min(rt<<1|1,mid+1,r,x,y);
	else return min(get_min(rt<<1,l,mid,x,mid),get_min(rt<<1|1,mid+1,r,mid+1,y));
}

void build(int rt,int l,int r,int pos,int x){
	insert(root[rt],x);
	splay(root[rt],find(root[rt],x));
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) build(rt<<1,l,mid,pos,x);
	else build(rt<<1|1,mid+1,r,pos,x);
}

int update(int rt,int l,int r,int pos,int x){
	if(l==r){
		int res=val[root[rt]];
		remove(root[rt],res);
		insert(root[rt],x);
		splay(root[rt],find(root[rt],x));
		return res;
	}
	int mid=l+r>>1,res;
	if(pos<=mid) res=update(rt<<1,l,mid,pos,x);
	else res=update(rt<<1|1,mid+1,r,pos,x);
	remove(root[rt],res);
	insert(root[rt],x);
	splay(root[rt],find(root[rt],x));
	return res;
}

int query_rank(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		insert(root[rt],v);
		splay(root[rt],find(root[rt],v));
		int res=sz[lc[root[rt]]];
		remove(root[rt],v);
		return res;
	}
	int mid=l+r>>1;
	if(y<=mid) return query_rank(rt<<1,l,mid,x,y,v);
	else if(x>mid) return query_rank(rt<<1|1,mid+1,r,x,y,v);
	else return query_rank(rt<<1,l,mid,x,mid,v)+query_rank(rt<<1|1,mid+1,r,mid+1,y,v);
}

int query_val(int x,int y,int k){
	int l=get_min(1,1,n,x,y),r=get_max(1,1,n,x,y);
	while(l<=r){
		int mid=l+r>>1;
		if(query_rank(1,1,n,x,y,mid)<k) l=mid+1;
		else r=mid-1;
	}
	return r;
}

int query_pred(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		predid=0;
		pred(root[rt],v);
		if(!predid) return -INF;
		return val[predid];
	}
	int mid=l+r>>1;
	if(y<=mid) return query_pred(rt<<1,l,mid,x,y,v);
	else if(x>mid) return query_pred(rt<<1|1,mid+1,r,x,y,v);
	else return max(query_pred(rt<<1,l,mid,x,mid,v),query_pred(rt<<1|1,mid+1,r,mid+1,y,v));
}

int query_succ(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		succid=0;
		succ(root[rt],v);
		if(!succid) return INF;
		return val[succid];
	}
	int mid=l+r>>1;
	if(y<=mid) return query_succ(rt<<1,l,mid,x,y,v);
	else if(x>mid) return query_succ(rt<<1|1,mid+1,r,x,y,v);
	else return min(query_succ(rt<<1,l,mid,x,mid,v),query_succ(rt<<1|1,mid+1,r,mid+1,y,v));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		build(1,1,n,i,x);
	}
	for(int i=1;i<=m;i++){
		int opt,l,r,k;
		cin>>opt;
		if(opt==1) cin>>l>>r>>k,cout<<query_rank(1,1,n,l,r,k)+1<<endl;
		if(opt==2) cin>>l>>r>>k,cout<<query_val(l,r,k)<<endl;
		if(opt==3) cin>>l>>k,update(1,1,n,l,k);
		if(opt==4) cin>>l>>r>>k,cout<<query_pred(1,1,n,l,r,k)<<endl;
		if(opt==5) cin>>l>>r>>k,cout<<query_succ(1,1,n,l,r,k)<<endl;
	}
	return 0;
}

