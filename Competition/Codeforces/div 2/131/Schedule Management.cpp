/*
 * Author: Austin Jiang
 * Date: 7/8/2022 7:52:52 AM
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
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,VI,greater<int>>;

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
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 2e5+10;
int t,n,m,a[N],cnt[N];
PI mn[N<<2],mx[N<<2];

void build(int rt,int l,int r){
	if(l==r){
		mn[rt]=mx[rt]={cnt[l],l};
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		mn[rt]=mx[rt]={y,x};
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,y);
	else update(rt<<1|1,mid+1,r,x,y);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

void solve(){
	cin>>n>>m;
	fill(cnt+1,cnt+n+1,0);
	for(int i=1;i<=m;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	build(1,1,n);
	while(1){
		PI u=mx[1],v=mn[1];
		if(u.fir>cnt[u.sec]){
			cout<<u.fir<<endl;
			break;
		}
		if(u.fir<=v.fir+1){
			cout<<u.fir<<endl;
			break;
		}
		update(1,1,n,u.sec,u.fir-1);
		update(1,1,n,v.sec,v.fir+2);
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>t;
	while(t--) solve();
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

