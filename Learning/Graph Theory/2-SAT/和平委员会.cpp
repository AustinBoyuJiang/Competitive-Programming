/*
 * Author: Austin Jiang
 * Date: 10/12/2022 12:55:22 PM
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

const int N = 2e4;
int T=1,n,m,tot,cnt,dfn[N],low[N],col[N],instk[N],vis[N],flag[N];
stack<int> stk,ans;
VI e[N];

int rev(int x){
	return (x-1^1)+1;
}

void dfs(int u){
	dfn[u]=low[u]=++tot;
	instk[u]=1,stk.push(u);
	for(auto v:e[u]){
		if(!dfn[v]) dfs(v);
		if(flag[v]) chkmin(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	col[u]=++cnt;
	instk[u]=0;
	while(stk.top()!=u){
		col[stk.top()]=cnt;
		instk[stk.top()]=0;
		stk.pop();
	}
	stk.pop();
}

bool find(int u){
	if(vis[u]) return 1;
	if(vis[rev(u)]){
		while(!ans.empty()) ans.pop();
		return 0;
	}
	vis[u]=1;
	ans.push(u);
	for(auto v:e[u]) if(!find(v)) return 0;
	return 1;
}

void solve(int Case){
	cin>>n>>m;
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		e[u].pb(rev(v));
		e[v].pb(rev(u));
	}
	rep(i,1,n*2) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n*2;i+=2){
		if(col[i]==col[i+1]){
			cout<<"NIE"<<endl;
			return;
		}
	}
	rep(i,1,n){
		if(flag[i]) continue;
		if(!find(i*2-1)) find(i*2);
		while(!ans.empty()){
			cout<<ans.top()<<endl;
			ans.pop();
		}
	}
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

