/*
 * Author: Austin Jiang
 * Date: 11/22/2022 11:52:10 PM
 * Problem: Replication
 * Description:
*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
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

const int N = 1010;
int n,d,ans,Map[N][N],dist[N][N],offset[N][N],vis[N][N],cnt[N][N];
VPI st,wl;

bool ok(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n;
}

void solve(int Case){
	cin>>n>>d;
	rep(i,1,n) rep(j,1,n){
		char x;
		cin>>x;
		Map[i][j]=x!='#';
		if(x=='S') st.pb({i,j});
		if(x=='#') wl.pb({i,j});
	}
	memset(dist,0x3f,sizeof(dist));
	queue<PI> q;
	for(auto u:wl){
		q.push(u);
		dist[u.fir][u.sec]=0;
	}
	while(!q.empty()){
		PI u=q.front(); q.pop();
		rep(i,0,3){
			int nx=u.fir+dir[i][0];
			int ny=u.sec+dir[i][1];
			if(ok(nx,ny)&&Map[nx][ny]&&dist[nx][ny]==INF){
				dist[nx][ny]=dist[u.fir][u.sec]+1;
				q.push({nx,ny});
			}
		}
	}
	memset(offset,0x3f,sizeof(offset));
	for(auto u:st){
		q.push(u);
		offset[u.fir][u.sec]=0;
	}
	while(!q.empty()){
		PI u=q.front(); q.pop();
		cnt[u.fir][u.sec]=min(offset[u.fir][u.sec]/d+1,dist[u.fir][u.sec]);
		rep(i,0,3){
			int nx=u.fir+dir[i][0];
			int ny=u.sec+dir[i][1];
			if(ok(nx,ny)&&Map[nx][ny]&&offset[nx][ny]==INF){
				offset[nx][ny]=offset[u.fir][u.sec]+1;
				if(offset[nx][ny]/d==dist[nx][ny])
					cnt[nx][ny]=dist[nx][ny];
				if(offset[nx][ny]/d<dist[nx][ny]){
					q.push({nx,ny});
				}
			}
		}
	}
	PQ<pair<int,PI>,vector<pair<int,PI>>,less<pair<int,PI>>> qq;
	rep(i,1,n) rep(j,1,n){
		if(cnt[i][j]){
			qq.push({cnt[i][j],{i,j}});
		}
	}
	memset(vis,0,sizeof(vis));
	while(!qq.empty()){
		PI u=qq.top().sec; qq.pop();
		if(vis[u.fir][u.sec]) continue;
		vis[u.fir][u.sec]=1;
		rep(i,0,3){
			int nx=u.fir+dir[i][0];
			int ny=u.sec+dir[i][1];
			if(ok(nx,ny)&&cnt[u.fir][u.sec]-1>cnt[nx][ny]){
				cnt[nx][ny]=cnt[u.fir][u.sec]-1;
				qq.push({cnt[nx][ny],{nx,ny}});
			}
		}
	}
	rep(i,1,n) rep(j,1,n) ans+=cnt[i][j]>0;
	cout<<ans<<endl;
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
//	freopen("stdout2.txt","w",stdout);
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

