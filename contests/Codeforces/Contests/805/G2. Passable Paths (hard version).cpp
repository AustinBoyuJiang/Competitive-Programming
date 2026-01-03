/*
 * Author: Austin Jiang
 * Date: 7/18/2022 3:22:41 PM
 * Problem:
 * Description:
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
#define lc (mid<<1)
#define rc (mid<<1|1)
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
int T=1,n,q,f[N][20],dep[N],a[N];
VI e[N];

void dfs(int u,int fa){
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	rep(i,1,19) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	per(i,19,0){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	per(i,19,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

void solve(int Case){
	read(n);
	rep(i,1,n-1){
		int u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	read(q);
	while(q--){
		int k=read(),x,y;
		rep(i,1,k) read(a[i]);
		if(k==1){
			puts("YES");
			continue;
		}
		x=a[1];
		y=a[2];
		int flag=1;
		rep(i,3,k){
			int p=LCA(x,y);
			int A=LCA(x,a[i]);
			int B=LCA(y,a[i]);
			int C=LCA(A,y);
			if(A==x&&B==p){
				x=a[i];
				continue;
			}
			if(B==y&&A==p){
				y=a[i];
				continue;
			}
			if(A==C&&B==C&&(p==x||p==y)){
				if(dep[x]>dep[y]) y=a[i];
				else x=a[i];
				continue;
			}
			if(A==a[i]&&B==p) continue;
			if(A==p&&B==a[i]) continue;
			flag=0;
			break;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
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

