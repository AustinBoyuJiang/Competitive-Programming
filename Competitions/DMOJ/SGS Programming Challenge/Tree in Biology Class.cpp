/*
 * Author: Austin Jiang
 * Date: 9/5/2022 9:32:41 PM
 * Problem: Tree in Biology Class
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int N = 2e5+10;
int T=1,n,q,tot,a[N],dep[N],sum[N],cpy[N],siz[N],dfn[N];
VI tmp,e[N];

struct QUERY{
	int u,v;
	
	bool operator< (const QUERY other){
		return dep[v]<dep[other.v];
	}
} query[N];

struct segment_tree{
	int st[N<<2],lazy[N<<2];
	
	void push_down(int rt){
		if(lazy[rt]){
			st[rt<<1]=lazy[rt];
			st[rt<<1|1]=lazy[rt];
			lazy[rt<<1]=lazy[rt];
			lazy[rt<<1|1]=lazy[rt];
			lazy[rt]=0;
		}
	}
	
	void update(int rt,int l,int r,int x,int y,int k){
		if(l==x&&r==y){
			st[rt]=k;
			lazy[rt]=k;
			return;
		}
		int mid=(l+r)>>1;
		push_down(rt);
		if(y<=mid) update(rt<<1,l,mid,x,y,k);
		else if(x>mid) update(rt<<1|1,mid+1,r,x,y,k);
		else update(rt<<1,l,mid,x,mid,k),update(rt<<1|1,mid+1,r,mid+1,y,k);
	}
	
	int query(int rt,int l,int r,int x){
		if(l==r) return st[rt];
		int mid=(l+r)>>1;
		push_down(rt);
		if(x<=mid) return query(rt<<1,l,mid,x);
		else return query(rt<<1|1,mid+1,r,x);
	}
} root;

int inv(int a){
	int b=MOD-2,ans=1;
	while(b){
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}

int getRoot(int u){
	return root.query(1,1,n,dfn[u]);
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	dfn[u]=++tot;
	sum[u]=a[u];
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		sum[u]=(sum[u]*sum[v])%MOD;
		siz[u]+=siz[v];
	}
	cpy[u]=sum[u];
}

void solve(int Case){
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	cin>>q;
	int ans=sum[1],cnt=0;
	root.lazy[1]=1;
	while(q--){
		int opt,u,v;
		cin>>opt;
		if(opt==1){
			cin>>u>>v;
			if(dep[u]>dep[v]) swap(u,v);
			query[++cnt]={u,v};
		}
		else{
			sort(query+1,query+cnt+1);
			tmp.clear();
			rep(i,1,cnt){
				int u=query[i].u;
				int v=query[i].v;
				tmp.pb(getRoot(u));
				ans=(ans+sum[v]+sum[getRoot(u)]*(inv(sum[v])-1))%MOD;
				sum[getRoot(u)]=sum[getRoot(u)]*inv(sum[v])%MOD;
				root.update(1,1,n,dfn[v],dfn[v]+siz[v]-1,v);
			}
			for(auto i:tmp) sum[i]=cpy[i];
			cout<<ans<<endl;
			root.lazy[1]=1;
			ans=sum[1];
			cnt=0;
		}
	}
}

signed main(){
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//srand(time(0));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	rep(Case,1,T) solve(Case);
    //exit(0);
	//system("fc stdout.txt out.txt");
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

