/*
 * Author: Austin Jiang
 * Date: 7/14/2022 2:33:18 AM
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

const int N = 5e5+10;
int t,n[N],a[N],tot=5e5;
VI A[N];

int solve(){
	t++;
	n[t]=random(1,min(100000,tot));
	tot-=n[t];
	A[t].clear();
	A[t].pb(0);
	rep(i,1,n[t]) a[i]=i;
	rep(i,1,n[t]) swap(a[random(1,i)],a[i]);
	rep(i,1,n[t]) A[t].pb(i/a[i]);
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(tot)
		solve();
	cout<<t<<endl;
	rep(i,1,t){
		cout<<n[i]<<endl;
		rep(j,1,n[i])
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
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

