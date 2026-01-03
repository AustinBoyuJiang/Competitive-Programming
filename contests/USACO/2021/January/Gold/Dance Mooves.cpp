/*
 * Author: Austin Jiang
 * Date: 12/3/2022 9:23:21 PM
 * Problem:
 * Description:
*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
int n,m,k,res,p[N],f[N],to[N],ans[N],siz[N],tmp[N],cnt[N];
VPI pos[N];

int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	if(find(x)==find(y)) return;
	siz[find(y)]+=siz[find(x)];
	f[find(x)]=find(y);
}

void add(int x){
	if(!cnt[x]) res++;
	cnt[x]++;
}

void remove(int x){
	cnt[x]--;
	if(!cnt[x]) res--;
}

void work(int u){
	int tot=siz[find(u)];
	int M=min(m,tot*k);
	rep(i,0,tot-1){
		tmp[i]=u;
		u=to[u];
	}
	res=0;
	deque<int> rec;	
	rep(i,0,M/k-1){
		for(auto x:pos[tmp[i]]){
			add(x.fir);
			rec.pb(x.fir);
		}
	}
	int cur=0,j=M/k-1;
	rep(i,0,pos[tmp[(j+1)%tot]].size()-1){
		if(pos[tmp[(j+1)%tot]][i].sec>M%k) break;
		add(pos[tmp[(j+1)%tot]][i].fir);
		rec.pb(pos[tmp[(j+1)%tot]][i].fir);
		cur++;
	}
	ans[tmp[0]]=res;
	rep(i,1,tot-1){
		for(auto x:pos[tmp[i-1]]){
			remove(x.fir);
			rec.pop_front();
		}
		j=(j+1)%tot;
		rep(i,cur,(int)pos[tmp[j]].size()-1){
			add(pos[tmp[j]][i].fir);
			rec.pb(pos[tmp[j]][i].fir);
		}
		cur=0;
		rep(i,0,(int)pos[tmp[(j+1)%tot]].size()-1){
			if(pos[tmp[(j+1)%tot]][i].sec>M%k) break;
			add(pos[tmp[(j+1)%tot]][i].fir);
			rec.pb(pos[tmp[(j+1)%tot]][i].fir);
			cur++;
		}
		ans[tmp[i]]=res;
	}
	for(auto x:rec) remove(x);
}

void solve(int Case){
	cin>>n>>k>>m;
	rep(i,1,n){
		p[i]=i;
		f[i]=i;
		siz[i]=1;
		pos[i].pb({i,0});
	}
	rep(i,1,k){
		int a,b;
		cin>>a>>b;
		swap(p[a],p[b]);
		pos[p[a]].pb({a,i});
		pos[p[b]].pb({b,i});
	}
	rep(i,1,n){
		to[p[i]]=i;
		merge(i,p[i]);
	}
	rep(i,1,n){
		if(!ans[i]) work(i);
		cout<<ans[i]<<endl;
	}
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

