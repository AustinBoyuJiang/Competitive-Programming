/*
 * Author: Austin Jiang
 * Date: 7/9/2022 4:18:31 PM
 * Problem: Redistributing Gifts
 * Description: dp[s][ed]表示牛的集合s，以ed牛结尾的环数量 
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define mid (l+r>>1)
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
    template<typename T> inline void print(T x) {if(x<0) x=-x,putchar('-'); if(x>9) print(x/10); putchar(x%10+'0');}
	template<typename T> inline void print(T x,char let) {print(x),putchar(let);}
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

const int N = 20;
int t=1,n,q,a[N][N],avi[N][N],LOG[1<<N];
ll f[1<<N],h[1<<N],dp[1<<N][N];

void solve(int Case){
	cin>>n;
	rep(i,0,n-1){
		rep(j,0,n-1) cin>>a[i][j],a[i][j]--;
		rep(j,0,n-1){
			avi[i][a[i][j]]=1;
			if(i==a[i][j]) break;
		}
	}
	int U=(1<<n)-1;
	rep(i,0,n-1) dp[1<<i][i]=1;
	rep(i,0,n-1) LOG[1<<i]=i;
	rep(s,1,U) rep(ed,0,n-1){
		if(!dp[s][ed]) continue;
		int st=LOG[lowbit(s)]; //x是集合s的起点 
		rep(i,st,n-1){
			if(i==st&&avi[ed][i]) h[s]+=dp[s][ed]; //闭环
			if(~s>>i&1&&avi[ed][i]) dp[s|1<<i][i]+=dp[s][ed];
		}
	}
	f[0]=1;
	rep(s,1,U){
		int x=LOG[lowbit(s)]; //x为s里的任意一头牛，为了保证乘法计数的结果不重复 
		for(int t=s;t;t=(t-1)&s)
			if(t>>x&1) f[s]+=h[t]*f[s^t];
	}
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		int g=0;
		rep(i,0,n-1) if(s[i]=='G') g|=1<<i;
		print(f[g]*f[g^U],'\n');
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	rep(Case,1,t) solve(Case);
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

