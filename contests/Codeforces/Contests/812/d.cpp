/*
 * Author: Austin Jiang
 * Date: 8/6/2022 9:04:24 AM
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

const int N = 1e5+10;
int T=1,n;

int ask(int a,int b){
	cout<<"? "<<a<<" "<<b<<endl;
	cout.flush();
	int res;
	cin>>res;
	return res;
}

int query(int a,int b,int c,int d){
	int res=ask(a,d);
	if(res==1) return ask(a,c)==1?a:c;
	if(res==2) return ask(b,d)==1?b:d;
	return ask(b,c)==1?b:c;
}

int dfs(int l,int r){
	int a,b,c,d;
	if(l+3==r){
		a=l,b=l+1,c=r-1,d=r;
	}
	else{
		int mid=l+r>>1;
		int midl=l+mid>>1;
		int midr=mid+1+r>>1;
		a=dfs(l,midl);
		b=dfs(midl+1,mid);
		c=dfs(mid+1,midr);
		d=dfs(midr+1,r);
	}
	return query(a,b,c,d);
}

void solve(int Case){
	cin>>n;
	if(n==1){
		cout<<"! "<<(ask(1,2)==1?1:2)<<endl;
	}
	else if(n&1){
		int mid=1<<(n-1);
		int a=dfs(1,mid),b=dfs(mid+1,1<<n);
		cout<<"! "<<(ask(a,b)==1?a:b)<<endl;
	}
	else{
		cout<<"! "<<dfs(1,1<<n)<<endl;
	}
	cout.flush();
}

signed main(){
	//cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>T;
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

