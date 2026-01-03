/*
 * Author: Austin Jiang
 * Date: 7/3/2022 3:39:23 PM
 * Problem: 
 * Description:
*/
#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,VI,greater<int>>;

namespace fast_io{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {print(x),putchar(let);}
} using namespace fast_io;

namespace comfun{
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 60;
const int A = 1010;
int t,n,dp[N][N*A];

int dfs(int i,int j){
	if(~dp[i][j]) return dp[i][j];
	if(j==1) return dp[i][j]=dfs(i+1,0);
	if(i&&!dfs(i-1,j)) return dp[i][j]=1;
	if(j&&!dfs(i,j-1)) return dp[i][j]=1;
	if(i&&j&&!dfs(i-1,j+1)) return dp[i][j]=1;
	if(i>1&&((!j&&!dfs(i-2,j+2))||(j&&!dfs(i-2,j+3)))) return dp[i][j]=1;
	return dp[i][j]=0;
}

void solve(){
	read(n);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		int x=read();
		if(x==1) cnt1++;
		else if(!cnt2) cnt2+=x;
		else cnt2+=x+1;
	}
	puts(dfs(cnt1,cnt2)?"YES":"NO");
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(t);
	memset(dp,-1,sizeof(dp));
	while(t--)
		solve();
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

