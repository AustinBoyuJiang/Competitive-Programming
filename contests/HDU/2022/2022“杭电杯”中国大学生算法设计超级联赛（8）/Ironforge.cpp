/*
 * Author: Austin Jiang
 * Date: 8/14/2022 11:54:15 PM
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

const int N = 2e5+10;
int T=1,n,m,a[N],b[N],far[N][2],lst[N],pos[2][N];
int tot,prime[N],notPrime[N],low[N];

void solve(int Case){
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n-1) cin>>b[i];
	fill(lst+1,lst+N,0);
	rep(i,1,n-1){
		int x=a[i];
		while(x!=1){
			lst[low[x]]=i;
			x/=low[x];
		}
		pos[0][i]=lst[b[i]];
	}
	fill(lst+1,lst+N,n+1);
	per(i,n,2){
		int x=a[i];
		while(x!=1){
			lst[low[x]]=i;
			x/=low[x];
		}
		pos[1][i-1]=lst[b[i]];
	}
	far[n][1]=n;
	per(i,n-1,1){
		int &r=far[i][1]=i;
		while(r<n&&pos[0][r]>=i)
			r=far[r+1][1];
	}
	rep(i,1,n){
		int &l=far[i][0],&r=far[i][1];
		l=i;
		int dir=0,flag=0;
		while(flag<2){
			if(dir==0&&l>1&&pos[1][l-1]<=r){
				flag=0;
				chkmin(l,far[l-1][0]);
				chkmax(r,far[l-1][1]);
			}
			else if(dir==1&&r<n&&pos[0][r]>=l){
				flag=0;
				chkmin(l,far[r+1][0]);
				chkmax(r,far[r+1][1]);
			}
			else{
				dir^=1;
				flag++;
			}
		}
	}
	rep(i,1,m){
		int x,y;
		cin>>x>>y;
		if(y>=far[x][0]&&y<=far[x][1]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

void init(){
	notPrime[1]=1;
	rep(i,1,N-1){
		if(!notPrime[i]){
			prime[tot++]=i;
			low[i]=i;
		}
		for(int j=0;j<tot&&i*prime[j]<N;j++){
			notPrime[i*prime[j]]=1;
			low[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	init();
	cin>>T;
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

