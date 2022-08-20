/*
 * Author: Austin Jiang
 * Date: 8/14/2022 9:41:28 PM
 * Problem: Link with Level Editor II
 * Description: ¾ØÕó³Ë·¨£¬Ë«Ö¸Õë 
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
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

const int N = 5e3+10;
const int M = 30;
int T=1,n,m,k;

struct matrix{
	int p[M][M];
	
	inline matrix operator* (const matrix &other){
		matrix res;
		memset(res.p,0,sizeof(res.p));
		rep(i,1,m) rep(j,1,m) rep(k,1,m)
			res.p[i][j]+=p[i][k]*other.p[k][j];
		return res;
	}
	
	inline void clear(){
		memset(p,0,sizeof(p));
		rep(i,1,m) p[i][i]=1;
	}
	
} Map[N],ansl[N];

inline void solve(int Case){
	read(n),read(m),read(k);
	rep(i,1,n){
		Map[i].clear();
		int l=read();
		rep(j,1,l){
			int u=read(),v=read();
			Map[i].p[u][v]=1;
		}
	}
	int ans=0,r=1,rr=0;
	matrix ansr;
	rep(l,1,n){
		if(l>rr){
			ansr.clear();
			ansl[(rr=r)+1].clear();
			per(ll,rr,l) ansl[ll]=ansl[ll+1]*Map[ll];
		}
		while(r<=n){
			if((ansl[l]*ansr).p[1][m]>k) break;
			chkmax(ans,r-l+1);
			ansr=ansr*Map[++r];
		}
	}
	cout<<ans<<endl;
}

signed main(){
	srand(time(0));
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
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
    * Debug: (c) ¶ÔÅÄ
*/

