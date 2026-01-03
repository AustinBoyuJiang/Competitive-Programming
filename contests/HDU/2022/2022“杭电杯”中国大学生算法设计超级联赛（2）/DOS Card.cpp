/*
 * Author: Austin Jiang
 * Date: 7/24/2022 8:59:56 PM
 * Problem: DOS Card
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
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
const ll null=-LLINF;

const int N =2e5+10;
int T=1,n,m;
ll tmp[4];

struct node{
	int val,len=1;
	ll ans=null,cans=null,mx=null,cmx=null,mn=null,cmn=null;
	ll x=null,y=null;//++-,-++
	ll f1100,f1010,f110,f100,f101,f010,f11,f00,f10,f1,f0,f,cmx;
} st[N<<2];

inline void chkmax(ll &a,ll &b,ll c,ll d){
	tmp[0]=a,tmp[1]=b,tmp[2]=c,tmp[3]=d;
	sort(tmp,tmp+4);
	a=tmp[3];
	b=tmp[2];
}

inline void chkmin(ll &a,ll &b,ll c,ll d){
	tmp[0]=a,tmp[1]=b,tmp[2]=c,tmp[3]=d;
	if(tmp[0]==null) tmp[0]=LLINF;
	if(tmp[1]==null) tmp[1]=LLINF;
	if(tmp[2]==null) tmp[2]=LLINF;
	if(tmp[3]==null) tmp[3]=LLINF;
	sort(tmp,tmp+4);
	a=tmp[0];
	b=tmp[1];
	if(a==LLINF) a=null;
	if(b==LLINF) b=null;
}

inline ll sqr(ll a){
	if(a==null) return null; 
	return a*a;
}

inline node merge(node a,node b){
	node ans;
	ans.len=a.len+b.len;
	
	ans.mx=a.mx;
	ans.cmx=a.cmx;
	chkmax(ans.mx,ans.cmx,b.mx,b.cmx);
	
	ans.mn=a.mn;
	ans.cmn=a.cmn;
	chkmin(ans.mn,ans.cmn,b.mn,b.cmn);
	
	if(a.len&&b.len) chkmax(ans.cans,sqr(a.mx)-sqr(b.mn));
	if(a.len>=2) chkmax(ans.cans,a.cans);
	if(b.len>=2) chkmax(ans.cans,b.cans);
	
	if(ans.len>=3){
		if(a.len>=3) chkmax(ans.x,a.x);//++-|,+-+|
		if(b.len>=3) chkmax(ans.x,b.x);//|++-,|+-+
		if(a.len>=2&&b.len) chkmax(ans.x,a.cans+sqr(b.mx));//+-|+
		if(b.len>=2&&a.len) chkmax(ans.x,b.cans+sqr(a.mx));//+|+-
		if(a.len>=2&&b.len) chkmax(ans.x,sqr(a.mx)+sqr(a.cmx)-sqr(b.mn));//++|-
		if(b.len>=2&&a.len) chkmax(ans.x,sqr(a.mx)+sqr(b.mx)-sqr(b.mn));//+|-+
		
		if(a.len>=3) chkmax(ans.y,a.y);
		if(b.len>=3) chkmax(ans.y,b.y);
		if(a.len>=2&&b.len) chkmax(ans.y,a.cans-sqr(b.mn));//+-|-
		if(b.len>=2&&a.len) chkmax(ans.y,b.cans-sqr(a.mn));//-|+-
		if(b.len>=2&&a.len) chkmax(ans.x,sqr(a.mx)-sqr(b.mn)-sqr(b.cmn));//+|--
		if(a.len>=2&&b.len) chkmax(ans.x,sqr(a.mx)-sqr(a.mn)-sqr(b.mn));//-+|-
	}
	
	if(ans.len>=4){
		if(a.len>=4) chkmax(ans.ans,a.ans);
		if(b.len>=4) chkmax(ans.ans,b.ans);
		if(a.len>=1&&b.len>=3) chkmax(ans.ans,b.y+sqr(a.mx));
		if(a.len>=3&&b.len>=1) chkmax(ans.ans,a.x-sqr(b.mn));
		if(a.len>=2&&b.len>=2) chkmax(ans.ans,sqr(a.mx)+sqr(a.cmx)-sqr(b.mn)-sqr(b.cmn));
		if(a.len>=2&&b.len>=2) chkmax(ans.ans,a.cans+b.cans);
	}
	return ans;
}

inline node merge(node a,node b){
	node ans;
	ans.len=a.len+b.len;
	
	chkmax(ans.f1010,a.f+b.f1010);
	chkmax(ans.f1010,a.f1+b.f010);
	chkmax(ans.f1010,a.f10+b.f10);
	chkmax(ans.f1010,a.f101+b.f0);
	chkmax(ans.f1010,a.f1010+b.f);
	
	chkmax(ans.f1100,a.f+b.f1100);
	chkmax(ans.f1100,a.f1+b.f100);
	chkmax(ans.f1100,a.f11+b.f00);
	chkmax(ans.f1100,a.f110+b.f0);
	chkmax(ans.f1100,a.f1100+b.f);
}

inline void build(int rt,int l,int r){
	if(l==r){
		read(st[rt].val);
		st[rt].mx=st[rt].val;
		st[rt].mn=st[rt].val;
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	st[rt]=merge(st[rt<<1],st[rt<<1|1]);
}

inline node query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return merge(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));
}

inline void solve(int Case){
	read(n),read(m);
	build(1,1,n);
	while(m--){
		int l=read(),r=read();
		write(query(1,1,n,l,r).ans,'\n');
	}
}

signed main(){
//	cin.tie(nullptr)->sync_with_stdio(false);
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
    * Debug: (c) ╤тед
*/

