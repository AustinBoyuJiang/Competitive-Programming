/*
 * Author: Austin Jiang
 * Date: 7/20/2022 8:50:46 PM
 * Problem:
 * Description: O(T*n*logn^2)
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

namespace fast_io{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fast_io;

namespace comfun{
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 1e5+10;
int T=1,n,m,q;

struct disjoint_set{
	int tot,root[N];
	
	struct node{
		int lc,rc,fa,dep;
	} st[N*20];
	
	void build(int &rt,int l,int r){
		rt=++tot;
		if(l==r){
			st[rt].fa=l;
			st[rt].dep=1;
			return;
		}
		int mid=l+r>>1;
		build(st[rt].lc,l,mid);
		build(st[rt].rc,mid+1,r);
	}
	
	void update1(int &rt,int rtk,int l,int r,int pos,int x){
		st[rt=++tot]=st[rtk];
		if(l==r){
			st[rt].fa=x;
			return;
		}
		int mid=l+r>>1;
		if(pos<=mid) update1(st[rt].lc,st[rtk].lc,l,mid,pos,x);
		else update1(st[rt].rc,st[rtk].rc,mid+1,r,pos,x);
	}
	
	void update2(int &rt,int rtk,int l,int r,int pos,int x){
		st[rt=++tot]=st[rtk];
		if(l==r){
			st[rt].dep=x;
			return;
		}
		int mid=l+r>>1;
		if(pos<=mid) update2(st[rt].lc,st[rtk].lc,l,mid,pos,x);
		else update2(st[rt].rc,st[rtk].rc,mid+1,r,pos,x);
	}
	
	int query1(int rt,int l,int r,int pos){
		if(l==r) return st[rt].fa;
		int mid=l+r>>1;
		if(pos<=mid) return query1(st[rt].lc,l,mid,pos);
		else return query1(st[rt].rc,mid+1,r,pos);
	}
	
	int query2(int rt,int l,int r,int pos){
		if(l==r) return st[rt].dep;
		int mid=l+r>>1;
		if(pos<=mid) return query2(st[rt].lc,l,mid,pos);
		else return query2(st[rt].rc,mid+1,r,pos);
	}
	
	int find(int x,int p){
		if(query1(root[p],1,n,x)==x) return x;
		else return find(query1(root[p],1,n,x),p);
	}
	
	void merge(int x,int y,int k){{
		int fx=find(x,k-1),fy=find(y,k-1);
		int depx=query2(root[k-1],1,n,fx);
		int depy=query2(root[k-1],1,n,fy);
		if(depx<depy) update1(root[k],root[k-1],1,n,fx,fy);
		else if(depx>depy) update1(root[k],root[k-1],1,n,fy,fx);
		else{
			update1(root[k],root[k-1],1,n,fy,fx);
			update2(root[k],root[k],1,n,fx,depx+1);
		}}
	}
	
	bool check(int x,int y,int k){
		return find(x,k)==find(y,k);
	}
} g;


int get(int x,int y){
	int l=0,r=m,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(g.check(x,y,mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

struct segment_tree{
	int st[N<<2];
	
	void build(int rt,int l,int r){
		if(l==r){
			st[rt]=get(l,l+1);
			return;
		}
		int mid=l+r>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		st[rt]=max(st[rt<<1],st[rt<<1|1]);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		else return max(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));;
	}
} f;

void solve(int Case){
	read(n),read(m),read(q);
	g.build(g.root[0],1,n);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		g.merge(x,y,i);
	}
	f.build(1,1,n-1);
	for(int i=1;i<=q;i++){
		int l=read(),r=read();
		if(l==r) write(0,' ');
		else write(f.query(1,1,n-1,l,r-1),' ');
	}
	putchar('\n');
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	rep(Case,1,T) solve(Case);
	return 0;
}

/* stuff you should look for
    * read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow, check edge case
    * Debug: (b) create your own test case
    * Debug: (c) ╤тед
*/

