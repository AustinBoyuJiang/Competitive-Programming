/*
 * Author: Austin Jiang
 * Date: 12/11/2022 5:40:03 PM
 * Problem: PERIODNI ��������
 * Description:
*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
	template<typename T> inline T qpow(T a,T b){T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
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

const int N = 510;
const int K = 510;
const int H = 1e6+10;
int n,k,top,h[N],stk[N],lc[N],rc[N],siz[N],f[K],dp[N][K],fac[H],invfac[H];

int inv(int x){
	return qpow(x,MOD-2);
}

int C(int n,int m){
	if(n-m<0) return 0;
	return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}

void dfs(int u,int lb){
	if(lc[u]) dfs(lc[u],h[u]);
	if(rc[u]) dfs(rc[u],h[u]);
	siz[u]=siz[lc[u]]+siz[rc[u]]+1;
	memset(f,0,sizeof(f));
	rep(i,0,k) rep(j,0,i){
		f[i]+=dp[lc[u]][j]*dp[rc[u]][i-j]%MOD;
		f[i]%=MOD;
	}
	rep(i,0,k) rep(j,0,i){
		if(siz[u]-i<0) continue;
		dp[u][i]+=C(h[u]-lb,j)*fac[siz[u]-i+j]%MOD*invfac[siz[u]-i]%MOD*f[i-j]%MOD;
		dp[u][i]%=MOD;
	}
}

void solve(int Case){
	read(n),read(k);
	rep(i,1,n){
		read(h[i]);
		bool flag=0;
		while(top&&h[i]<h[stk[top]]) top--,flag=1;
		if(top) rc[stk[top]]=i;
		if(flag) lc[i]=stk[top+1];
		stk[++top]=i;
	}
	fac[0]=1;
	rep(i,1,H-1) fac[i]=fac[i-1]*i%MOD;
	invfac[H-1]=inv(fac[H-1]);
	per(i,H-1,1) invfac[i-1]=invfac[i]*i%MOD;
	dp[0][0]=1;
	dfs(stk[1],0);
	write(dp[stk[1]][k],endl);
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

