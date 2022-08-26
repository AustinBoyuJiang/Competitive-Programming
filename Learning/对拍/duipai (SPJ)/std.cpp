/*
 * Author: Austin Jiang
 * Date: 7/14/2022 12:37:04 AM
 * Problem: Permutation Restoration
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
int t=1,n,ans[N],sum[N<<2];

struct seg{
	int l,r,id;
} a[N];

bool cmp(seg a,seg b){
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}

void build(int rt,int l,int r){
	sum[rt]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

void update(int rt,int l,int r,int x){
	sum[rt]++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) update(lc,l,mid,x);
	else update(rc,mid+1,r,x);	
}

int query(int rt,int l,int r,int x,int y){
	if(l==r){
		if(sum[rt]) return -1;
		else return l;
	}
	int mid=l+r>>1;
	if(l==x&&r==y){
		if(sum[lc]!=mid-l+1) return query(lc,l,mid,l,mid);
		else if(sum[rc]!=r-mid) return query(rc,mid+1,r,mid+1,y);
		else return -1;
	}
	if(y<=mid) query(lc,l,mid,x,y);
	else if(x>mid) query(rc,mid+1,r,x,y);
	else{
		int res1=query(lc,l,mid,x,mid);
		int res2=query(rc,mid+1,r,mid+1,y);
		if(res1==-1) return res2;
		else if(res2==-1) return res1;
		else return min(res1,res2);
	};
}

void solve(int Case){
	read(n);
	rep(i,1,n){
		int x;
		read(x);
		if(x==0){
			a[i].l=i+1;
			a[i].r=n;
		}
		else{
			a[i].l=i/(x+1)+1;
			a[i].r=i/x;
		}
		a[i].id=i;
//		cout<<i<<" "<<x<<": "<<a[i].l<<" "<<a[i].r<<endl;
	}
	sort(a+1,a+n+1,cmp);
	build(1,1,n);
	rep(i,1,n){
		int pos=query(1,1,n,a[i].l,a[i].r);
		update(1,1,n,pos);
		ans[a[i].id]=pos;
	}
	rep(i,1,n)
		cout<<ans[i]<<" ";
	cout<<endl;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(t);
	rep(Case,1,t) solve(Case);
//	build(1,1,5);
//	update(1,1,5,3);
//	cout<<query(1,1,5,3,4)<<endl;
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

/*
1
42
0 0 0 0 1 0 0 4 0 0 0 0 1 0 0 0 1 1 3 1 3 0 1 1 0 0 6 0 0 1 1 4 11 0 1 0 3 38 1 1 1 4
*/
