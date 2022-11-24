/*
 * Author: Austin Jiang
 * Date: 11/14/2022 11:26:46 PM
 * Problem:
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
#define all(v) v.begin(),v.end()
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

/* Common constants, functions, and data structures */
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

namespace comfun{
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline T pow(T a,T b){T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<typename T> inline T inv(T x){return pow(x,MOD-2);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

struct fenwick{
	int sum[(int)1e6+10];
	void add(int x,int y){ for(int i=x;i<=1e6;i+=lowbit(i)) sum[i]+=y;}
	int ask(int x,int y){ int res=0; for(int i=y;i>0;i-=lowbit(i)) res+=sum[i];
	for(int i=x-1;i>0;i-=lowbit(i)) res-=sum[i]; return res;}
};

struct fenwick_interval{
	int d[(int)1e6+10][2];
	void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	int add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 2e5+10;
int n,q,k,tot,v[N],siz[N],dep[N],hson[N],top[N],dfn[N],rnk[N],f[N][25];
VI e[N];

struct node{
	int ans[3][3],len=1;
	node(){
		memset(ans,0x3f,sizeof(ans));
	}
} st[N<<2];

node merge(node x,node y){
	node res;
	res.len=x.len+y.len;
	if(res.len==2){
		res.ans[0][1]=x.ans[0][0];
		res.ans[1][0]=y.ans[0][0];
		res.ans[0][0]=x.ans[0][0]+y.ans[0][0];
		return res;
	}
	if(res.len<=4){
		rep(l,0,2) rep(r,0,res.len-1-l){
			if(l+1>x.len){
				res.ans[l][r]=y.ans[l-x.len][r];
			}
			else if(r+1>y.len){
				res.ans[l][r]=x.ans[l][r-y.len];
			}
			else{
				res.ans[l][r]=x.ans[0][x.len-1]+y.ans[y.len-1][0];
			}
		}
	}
	rep(l,0,2) rep(r,0,2){
		if(l+1>x.len){
			res.ans[l][r]=y.ans[l-x.len][r];
		}
		else if(r+1>y.len){
			res.ans[l][r]=x.ans[l][r-y.len];
		}
		else rep(i,0,2) rep(j,0,2-i){
			chkmin(res.ans[l][r],x.ans[l][i]+y.ans[j][r]);
		}
	}
	return res;
}

node flip(node x){
	node res=x;
	rep(l,0,2) rep(r,0,2){
		res.ans[l][r]=x.ans[r][l];
	}
	return res;
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt].ans[0][0]=v[rnk[l]];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	st[rt]=merge(st[rt<<1],st[rt<<1|1]);
}

node query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return merge(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));
}

node find(int x,int tar){
	node res;
	bool flag=0;
	while(top[x]!=top[tar]){
		if(!flag) res=flip(query(1,1,n,dfn[top[x]],dfn[x])),flag=1;
		else res=merge(res,flip(query(1,1,n,dfn[top[x]],dfn[x])));
		x=f[top[x]][0];
	}
	if(!flag) res=flip(query(1,1,n,dfn[tar],dfn[x]));
	else res=merge(res,flip(query(1,1,n,dfn[tar],dfn[x])));
	return res;
}

void dfs1(int u,int fa){
	siz[u]=1;
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	rep(i,1,20) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v==f[u][0]||v==hson[u]) continue;
		dfs2(v,v);
	}
}

PI LCA(int x,int y){
	bool flip=0;
	if(dep[x]<dep[y]){
		flip=1;
		swap(x,y);
	}
	per(i,20,0){
		if(dep[f[x][i]]>dep[y]) x=f[x][i];
		if(f[x][0]==y){
			if(flip) return {f[x][0],x};
			else return {x,f[x][0]};
		}
	}
	if(dep[x]!=dep[y]) x=f[x][0];
	per(i,20,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	if(flip) return {f[x][0],x};
	else return {x,f[x][0]};
}

void solve(int Case){
//	node a[110];
//	rep(i,1,7) a[i].ans[0][0]=i;
//	node res=a[1];
//	rep(i,2,7) res=merge(res,a[i]);
//	cout<<res.ans[0][0]<<endl;
//	return;
	
	cin>>n>>q>>k;
	rep(i,1,n) cin>>v[i];
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	rep(i,1,q){
		int x,y;
		cin>>x>>y;
		PI lca=LCA(x,y);
		cout<<lca.fir<<" "<<lca.sec<<endl;
		cout<<merge(find(x,lca.fir),flip(find(y,lca.sec))).ans[0][0]<<endl;
	}
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int CASE=1;
	//cin>>CASE;
	rep(Case,1,CASE) solve(Case);
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
    * Debug: (c) duipai
*/

