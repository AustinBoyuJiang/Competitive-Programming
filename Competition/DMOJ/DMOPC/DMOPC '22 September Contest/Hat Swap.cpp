/*
 * Author: Austin Jiang
 * Date: 9/30/2022 8:49:01 AM
 * Problem:
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
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

const int N = 1e6+10;
int T=1,n,m,c[N],dist[2][N];
PI disc[2][N][2];
VI e[N];

void bfs(int st,int k){
	memset(dist[k],0x3f,sizeof(dist[k]));
	dist[k][st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(dist[k][v]!=INF) continue;
			dist[k][v]=dist[k][u]+1;
			q.push(v);
		}
	}
}

int check(int i){
	if(disc[0][i][0].fir==INF||disc[1][i][0].fir==INF) return INF;
	if(disc[0][i][0].sec==disc[1][i][0].sec){
		return min(disc[0][i][0].fir+disc[1][i][1].fir,disc[0][i][1].fir+disc[1][i][0].fir);
	}
	return disc[0][i][0].fir+disc[1][i][0].fir;
}

void solve(int Case){
	cin>>n>>m;
	rep(i,1,n) cin>>c[i];
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	bfs(1,0);
	bfs(n,1);
	rep(i,1,n){
		disc[0][i][0]=disc[0][i][1]={INF,INF};
		disc[1][i][0]=disc[1][i][1]={INF,INF};
	}
	rep(i,1,n){
		chkmin(disc[0][c[i]][1],max(disc[0][c[i]][0],{dist[0][i],i}));
		chkmin(disc[0][c[i]][0],{dist[0][i],i});
	}
	rep(i,1,n){
		chkmin(disc[1][c[i]][1],max(disc[1][c[i]][0],{dist[1][i],i}));
		chkmin(disc[1][c[i]][0],{dist[1][i],i});
	}
	int ans=INF;
	rep(i,1,n){
		chkmin(ans,check(i));
	}
	if(ans==INF) ans=-1;
	cout<<ans<<endl;
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
    * Debug: (c) ����
*/

