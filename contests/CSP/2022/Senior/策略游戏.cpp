/*
 * Author: Austin Jiang
 * Date: 11/14/2022 9:14:33 PM
 * Problem: 
 * Description:
*/

//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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

const int N = 1e5+10;
int n,m,q,a[2][N],sum[2][N][2];

struct segment_tree{
	int st[N<<2][4];
	
	void build(int k,int rt,int l,int r){
		if(l==r){
			st[rt][0]=a[k][l];
			st[rt][1]=a[k][l];
			if(a[k][l]>=0) st[rt][2]=a[k][l];
			else st[rt][2]=INF;
			if(a[k][l]<=0) st[rt][3]=a[k][l];
			else st[rt][3]=-INF;
			return;
		}
		int mid=l+r>>1;
		build(k,rt<<1,l,mid);
		build(k,rt<<1|1,mid+1,r);
		st[rt][0]=max(st[rt<<1][0],st[rt<<1|1][0]);
		st[rt][1]=min(st[rt<<1][1],st[rt<<1|1][1]);
		st[rt][2]=min(st[rt<<1][2],st[rt<<1|1][2]);
		st[rt][3]=max(st[rt<<1][3],st[rt<<1|1][3]);
	}
	
	int qmax(int rt,int l,int r,int x,int y,int k=0){
		if(l==x&&r==y) return st[rt][k];
		int mid=l+r>>1;
		if(y<=mid) return qmax(rt<<1,l,mid,x,y,k);
		else if(x>mid) return qmax(rt<<1|1,mid+1,r,x,y,k);
		else return max(qmax(rt<<1,l,mid,x,mid,k),qmax(rt<<1|1,mid+1,r,mid+1,y,k));
	}
	
	int qmin(int rt,int l,int r,int x,int y,int k=1){
		if(l==x&&r==y) return st[rt][k];
		int mid=l+r>>1;
		if(y<=mid) return qmin(rt<<1,l,mid,x,y,k);
		else if(x>mid) return qmin(rt<<1|1,mid+1,r,x,y,k);
		else return min(qmin(rt<<1,l,mid,x,mid,k),qmin(rt<<1|1,mid+1,r,mid+1,y,k));
	}
	
} A,B;

void solve(int Case){
	cin>>n>>m>>q;
	rep(i,1,n){
		cin>>a[0][i];
		if(a[0][i]>=0) sum[0][i][0]=1;
		if(a[0][i]<=0) sum[0][i][1]=1;
		sum[0][i][0]+=sum[0][i-1][0];
		sum[0][i][1]+=sum[0][i-1][1];
	}
	rep(i,1,m){
		cin>>a[1][i];
		if(a[1][i]>=0) sum[1][i][0]=1;
		if(a[1][i]<=0) sum[1][i][1]=1;
		sum[1][i][0]+=sum[1][i-1][0];
		sum[1][i][1]+=sum[1][i-1][1];
	}
	A.build(0,1,1,n);
	B.build(1,1,1,m);
	rep(i,1,q){
		int l1,r1,l2,r2,res1,res2;
		cin>>l1>>r1>>l2>>r2;
		bool x1=sum[0][r1][0]-sum[0][l1-1][0];
		bool y1=sum[0][r1][1]-sum[0][l1-1][1];
		bool x2=sum[1][r2][0]-sum[1][l2-1][0];
		bool y2=sum[1][r2][1]-sum[1][l2-1][1];
		
		if(x2&&y2){
			if(x1&&y1){
				int u=A.qmin(1,1,n,l1,r1,2)*B.qmin(1,1,m,l2,r2);
				int v=A.qmax(1,1,n,l1,r1,3)*B.qmax(1,1,m,l2,r2);
				if(u>v) res1=A.qmin(1,1,n,l1,r1,2);
				else res1=A.qmax(1,1,n,l1,r1,3);
			}
			else if(x1) res1=A.qmin(1,1,n,l1,r1,2);
			else if(y1) res1=A.qmax(1,1,n,l1,r1,3);
		}
		else if(x2) res1=A.qmax(1,1,n,l1,r1);
		else if(y2) res1=A.qmin(1,1,n,l1,r1);
		
		if(res1>=0) res2=res2=B.qmin(1,1,m,l2,r2);
		else res2=B.qmax(1,1,m,l2,r2);
		
//		if(x1&&y1){
//			if(x2&&y2){
//				int u=A.qmax(1,1,n,l1,r1)*B.qmin(1,1,m,l2,r2,2);
//				int v=A.qmin(1,1,n,l1,r1)*B.qmax(1,1,m,l2,r2,3);
//				if(u<v) res2=B.qmin(1,1,m,l2,r2,2);
//				else res2=B.qmax(1,1,m,l2,r2,3);
//			}
//			else if(x2) res2=B.qmin(1,1,m,l2,r2,2);
//			else if(y2) res2=B.qmax(1,1,m,l2,r2,3);
//		}
//		else if(x1) res2=B.qmin(1,1,m,l2,r2);
//		else if(y1) res2=B.qmax(1,1,m,l2,r2);
			
//		cout<<res1<<" "<<res2<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		cout<<res1*res2<<endl;
	}
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

