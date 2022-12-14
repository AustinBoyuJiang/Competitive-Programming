/*
 * Author: Austin Jiang
 * Date: 12/2/2022 10:27:47 AM
 * Problem: Permutation
 * Description:
*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
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

const int N = 50;
int n;
long ans,dp[N][N][N][N];

struct node{
	int x,y;
} p[N];

bool getDir(node p,node a,node b){
	int x1=p.x-a.x,y1=p.y-a.y;
	int x2=b.x-a.x,y2=b.y-a.y;
	return x1*y2-x2*y1>=0;
}

bool check(node p,node a,node b,node c){
	return getDir(p,a,b)==getDir(p,b,c)&&getDir(p,a,b)==getDir(p,c,a);
}

void solve(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>p[i].x>>p[i].y;
	}
	rep(i,1,n) rep(j,1,n) rep(k,1,n){
		if(i==j||j==k||k==i) continue;
		dp[3][i][j][k]=1;
	}
	rep(tot,4,n){
		rep(i,1,n-2) rep(j,i+1,n-1) rep(k,j+1,n){
			int cnt=0;
			rep(l,1,n){
				if(l==i||l==j||l==k) continue;
				if(check(p[l],p[i],p[j],p[k])){
					dp[tot][i][j][k]=(dp[tot][i][j][k]+dp[tot-1][l][j][k])%MOD;
					dp[tot][i][j][k]=(dp[tot][i][j][k]+dp[tot-1][i][l][k])%MOD;
					dp[tot][i][j][k]=(dp[tot][i][j][k]+dp[tot-1][i][j][l])%MOD;
					cnt++;
				}
			}
			dp[tot][i][j][k]=(dp[tot][i][j][k]+dp[tot-1][i][j][k]*(cnt-tot+4))%MOD;
			dp[tot][i][k][j]=dp[tot][i][j][k];
			dp[tot][j][i][k]=dp[tot][i][j][k];
			dp[tot][j][k][i]=dp[tot][i][j][k];
			dp[tot][k][i][j]=dp[tot][i][j][k];
			dp[tot][k][j][i]=dp[tot][i][j][k];
			if(tot==n){
				ans+=dp[n][i][j][k]*6;
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	cin.tie(nullptr)->sync_with_stdio(false);
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

