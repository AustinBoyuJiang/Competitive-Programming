/*Author：AustinJiang
题目：D2T3:列队 
时间复杂度：O(q*log(n))
算法：平衡树 
来源：NOIP2017 */
#include<bits/stdc++.h>
#define int long long
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
const int N=2e6;

int n,m,q,tot,root[N],lc[N],rc[N],fa[N],cnt[N],sz[N];

struct node{
	int l,r,d;
} st[N];

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

PI find(int rt,int x){
	if(x<=sz[lc[rt]]) return find(lc[rt],x);
	if(x<=sz[lc[rt]]+cnt[rt]) return mp(rt,st[rt].l+(x-sz[lc[rt]]-1)*st[rt].d);
	return find(rc[rt],x-sz[lc[rt]]-cnt[rt]);
}

void insert(int &rt,int l,int r,int d){
	if(!rt){
		rt=++tot;
		st[rt].l=l;
		st[rt].r=r;
		st[rt].d=d;
		cnt[rt]=sz[rt]=(r-l)/d+1;
		return;
	}
	insert(rc[rt],l,r,d);
	push_up(rt);
}

int Max(int rt){
	if(!rc[rt]) return rt;
	return Max(rc[rt]);
}

void remove(int &root,int rt){
	splay(root,rt);
	if(lc[rt]*rc[rt]==0){
		root=lc[rt]+rc[rt];
		fa[root]=0;
		return;
	}
	splay(root,Max(lc[rt]));
	rc[root]=rc[rt];
	push_up(root);
}

int pop(int &root,int x){
	PI res=find(root,x);
	int rt=res.fir;
	int val=res.sec;
	splay(root,rt);
	st[++tot].l=val+st[rt].d;
	st[tot].r=st[rt].r;
	st[tot].d=st[rt].d;
	st[rt].r=val-st[rt].d;
	rc[tot]=rc[rt];
	rc[rt]=tot;
	cnt[rt]=(st[rt].r-st[rt].l)/st[rt].d+1;
	cnt[tot]=(st[tot].r-st[tot].l)/st[tot].d+1;
	push_up(tot);
	push_up(rt);
	if(!cnt[rt]) remove(root,rt);
	if(!cnt[tot]) remove(root,tot);
	return val;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		insert(root[i],(i-1)*m+1,i*m-1,1);
	insert(root[0],m,n*m,m);
	for(int i=1;i<=q;i++){
		int x,y,ans;
		cin>>x>>y;
		if(x==n&&y==m){
			ans=find(root[0],x).sec;
		}
		else if(y==m){
			ans=pop(root[0],x);
			insert(root[0],ans,ans,1);
			splay(root[0],tot);
		}
		else{
			ans=pop(root[x],y);
			int tmp=pop(root[0],x);
			insert(root[x],tmp,tmp,1);
			splay(root[x],tot);
			insert(root[0],ans,ans,1);
			splay(root[0],tot);
		}
		cout<<ans<<endl;
	}
	return 0;
}

