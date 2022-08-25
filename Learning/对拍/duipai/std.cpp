/*
 * Author: Austin Jiang
 * Date: 8/20/2022 5:09:32 PM
 * Problem: LCM Sum (hard version)
 * Description: Codeforces Round #813 (Div. 2)
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
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 1e5+10;
const int L = 2e5+10;
int T=1,n,R,ans[N];
VI f,f1,f2;
int tot=0;

struct query{
	int l,r,id;
	bool operator< (const query &other){
		return r<other.r;
	}
} q[N];

struct segment_tree{
	int sum[L<<2];
	
	inline void update(int rt,int l,int r,int x,int y){
		if(l==r){
			sum[rt]+=y;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(rt<<1,l,mid,x,y);
		else update(rt<<1|1,mid+1,r,x,y);
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
	
	inline int query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return sum[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
	}
} s1,s2;

inline void get_facts(int x,int lim){
	f.clear();
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			if(i<lim) f.pb(i);
			if(i!=x/i&&x/i<lim) f.pb(x/i);
		}
	}
	sort(f.begin(),f.end());
}

inline void add1(int k){ //lcm(i,j,k)==k
	get_facts(k,k);
	for(int i=0;i<f.size();i++)
		s1.update(1,1,R,f[i],f.size()-i-1);
}

inline void add2(int k){ //lcm(i,j,k)==k*2 && i+j>k
	get_facts(k*2,k);
	f1.clear();
	f2.clear();
	for(auto x:f){
		if(lcm(x,k)==k*2) f2.pb(x);
		else f1.pb(x);
	}
	for(int i=0,j=f2.size();i<f1.size();i++){ //lcm(i,k)==k && lcm(j,k)==k*2
		while(j<f2.size()&&f2[j]<=f1[i]) j++;
		while(j>0&&f2[j-1]>f1[i]&&f1[i]+f2[j-1]>k) j--;
		s2.update(1,1,R,f1[i],f2.size()-j);
	}
	for(int i=0,j=f1.size();i<f2.size();i++){ //lcm(i,k)==k*2 && lcm(j,k)==k
		while(j<f1.size()&&f1[j]<=f2[i]) j++;
		while(j>0&&f1[j-1]>f2[i]&&f2[i]+f1[j-1]>k) j--;
		s2.update(1,1,R,f2[i],f1.size()-j);
	}
	for(int i=0,j=f2.size();i<f2.size();i++){ //lcm(i,k)==k*2 && lcm(j,k)==k*2
		while(j<f2.size()&&f2[j]<=f2[i]) j++;
		while(j>0&&f2[j-1]>f2[i]&&f2[i]+f2[j-1]>k) j--;
		s2.update(1,1,R,f2[i],f2.size()-j);
	}
}

inline void solve(int Case){
	read(n);
	rep(i,1,n){
		read(q[i].l);
		read(q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+n+1);
	R=q[n].r;
	int k=0;
	rep(i,1,n){
		int l=q[i].l,r=q[i].r,id=q[i].id;
		while(k<r){
			k++;
			add1(k);
			add2(k);
		}
		ans[id]=(r-l)*(r-l+1)*(r-l-1)/6;
		ans[id]-=s1.query(1,1,R,l,r);
		ans[id]-=s2.query(1,1,R,l,r);
	}
	rep(i,1,n) write(ans[i],endl);
}

signed main(){
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//srand(time(0));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	rep(Case,1,T) solve(Case);
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
    * Debug: (c) ╤тед
*/

