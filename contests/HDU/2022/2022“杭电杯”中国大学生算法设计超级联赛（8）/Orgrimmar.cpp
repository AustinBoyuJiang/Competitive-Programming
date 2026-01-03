/*
 * Author: Austin Jiang
 * Date: 8/10/2022 11:30:17 PM
 * Problem:
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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

const int N = 5e5+10;
int T=1,n,dp[N][2][2]; //dp[i][0/1][0/1]表示第i个点，取或者不取，是否有连边 
VI e[N];

void dfs(int u,int fa){
	dp[u][0][0]=0;
	dp[u][1][0]=1;
	dp[u][1][1]=1;
	int cv=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		dp[u][0][0]+=max(dp[v][0][0],max(dp[v][1][0],dp[v][1][1]));
		dp[u][1][0]+=dp[v][0][0];
		dp[u][1][1]+=dp[v][0][0];
		if(cv==0||dp[v][1][0]-dp[v][0][0]>dp[cv][1][0]-dp[cv][0][0]) cv=v;
	}
	if(cv) dp[u][1][1]+=dp[cv][1][0]-dp[cv][0][0];
	else dp[u][1][1]=-INF;
}

void solve(int Case){
	scanf("%d",&n);
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1){
		int u,v;	
		scanf("%d %d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	if(n<=0){
		printf("0\n");
		return;
	}
	dfs(1,0);
	int ans=max(dp[1][0][0],max(dp[1][1][0],dp[1][1][1]));
	printf("%d\n",ans);
}

signed main(){
    int size(512<<20);  // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	rep(Case,1,T) solve(Case);
    exit(0);
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
    * Debug: (c) 对拍
*/

