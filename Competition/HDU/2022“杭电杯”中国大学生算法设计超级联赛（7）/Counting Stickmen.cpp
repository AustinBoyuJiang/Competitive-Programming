/*
 * Author: Austin Jiang
 * Date: 8/8/2022 10:15:07 PM
 * Problem: Counting Stickmen
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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
const int MOD = 998244353;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 5e5+10;
int T=1,n,ans,d[N][3];
VI e[N];

int get(int x,int y){
	int head=max(0ll,d[x][1]-3);
	int arm=max(0ll,d[x][2]-(d[y][1]>1));
	int leg=max(0ll,d[y][1]-1);
	return head*(arm*(arm-1)/2)%MOD*((leg*(leg-1)/2)%MOD);
}

void dfs1(int u,int fa){
	d[u][1]=e[u].size();
	d[u][2]=d[fa][1]>1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		d[u][2]+=d[v][1]>1;
		d[u][2]%=MOD;
	}
}

void dfs2(int u,int fa){
	ans=(ans+get(u,fa))%MOD;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs2(v,u);
		ans=(ans+get(u,v))%MOD;
	}
}

void solve(int Case){
	read(n);
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1){
		int u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	ans=0;
	dfs1(1,0);
	dfs2(1,0);
	write(ans,endl);
}
/*
1
11
1 2
2 3
2 11
3 4
3 5
3 9
4 6
5 7
5 8
9 10
*/

signed main(){
//	cin.tie(nullptr)->sync_with_stdio(false);
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

