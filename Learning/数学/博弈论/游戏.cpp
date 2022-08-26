/*
 * Author: Austin Jiang
 * Date: 7/16/2022 8:10:45 PM
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
#define endl '\n'
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

const int N = 110*4;
const int V = N*N;
int T=1,n,m,mx,cnt,tot,Map[N][N],ID[N][N];
int match[V],vis[V];
bool ans[V];
VI e[V];

bool OK(int x,int y){
	if(x<1||x>n) return 0;
	if(y<1||y>m) return 0;
	return Map[x][y];
}

bool DFS(int u,int k){
	if(vis[u]==k) return 0;
	vis[u]=k;
	for(auto v:e[u]){
		if(!match[v]||DFS(match[v],k)){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int Hungary(){
	int ans=0;
	rep(i,1,n) rep(j,1,m)
		if(Map[i][j]&&(i+j)%2)
			ans+=DFS(ID[i][j],ID[i][j]);
	return ans;
}

void find(int u){
	if(ans[u]) return;
	ans[u]=1;
	for(auto v:e[u])
		if(match[v]) find(match[v]);
}

void solve(int Case){
	read(n),read(m);
	rep(i,1,n){
		rep(j,1,m){
			Map[i][j]= getchar()=='.';
			if(Map[i][j]) ID[i][j]=++cnt;
		}
		getchar();
	}
	rep(i,1,n) rep(j,1,m){
		if(Map[i][j]) rep(k,0,3){
			int nx=i+dir[k][0];
			int ny=j+dir[k][1];
			if(OK(nx,ny))
				e[ID[i][j]].pb(ID[nx][ny]);
		}
	}
	tot=Hungary();
	if(tot*2==cnt){
		puts("LOSE");
		return;
	}
	rep(i,1,cnt){
		if(match[i])
			match[match[i]]=i;
	}
	rep(i,1,cnt){
		if(!match[i])
			find(i);
	}
	puts("WIN");
	rep(i,1,n) rep(j,1,m){
		if(ans[ID[i][j]]){
			print(i,' ');
			print(j,endl);
		}
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
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

