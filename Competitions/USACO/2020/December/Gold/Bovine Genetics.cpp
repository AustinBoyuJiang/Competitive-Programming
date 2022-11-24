/*
 * Author: Austin Jiang
 * Date: 11/23/2022 2:43:46 AM
 * Problem: Bovine Genetics
 * Description:
	做dp
	dp[i][j]表示前i个，最后一段长度为j 的方案数
	根据抽屉原理可以证明j<=4，因为任何一个字母在一段内不会出现两次 
	rep(i,1,n){
		rep(j,1,4){
			if(区间[i-j+1,i]之间没有字母出现两次){
				int pos=上一次a[i]出现的位置
				dp[i][j]=dp[i-j][i-j-pos+1];
			}
		}
	}
	除此之外，当枚举到一段的时候，需要枚举出这一段开头的字母的所有可能性
	时间复杂度最坏为O(n*64) 
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
int n,a[N],dp[N][5],flag1[5],flag2[5],f[5]={1,1,2,6,24};
string str;

void solve(int Case){
	cin>>str;
	n=str.size();
	rep(i,1,n){
		if(str[i-1]=='?') a[i]=0;
		if(str[i-1]=='A') a[i]=1;
		if(str[i-1]=='C') a[i]=2;
		if(str[i-1]=='G') a[i]=3;
		if(str[i-1]=='T') a[i]=4;
	}
	dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=1;
	rep(i,1,n){
		rep(v,1,4){
			if(a[i]!=v&&a[i]!=0) continue;
			memset(flag1,0,sizeof(flag1));
			int mx1=0,cnt1=0;
			rep(j,1,4){
				if(i-j+1<0) break;
				if(a[i-j+1]){
					flag1[a[i-j+1]]++;
					chkmax(mx1,flag1[a[i-j+1]]);
					if(mx1>=2) break;
				}
				else cnt1++;
				memset(flag2,0,sizeof(flag2));
				int mx2=0,cnt2=0;
				rep(k,1,4){
					if(i-j-k+1<0) break;
					if(flag2[v]) break;
					if(a[i-j-k+1]){
						flag2[a[i-j-k+1]]++;
						chkmax(mx2,flag2[a[i-j+1]]);
						if(mx2>=2) break;
					}
					else cnt2++;
					if(a[i-j-k+1]!=v&&a[i-j-k+1]!=0) continue;
					if(a[i-j-k+1]==v) dp[i][j]+=dp[i-j][k]*f[cnt1]*f[cnt2];
					else dp[i][j]+=dp[i-j][k]*f[cnt1]*f[cnt2-1];
					dp[i][j]%=MOD;
				}
			}
		}
	}
	cout<<(dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%MOD<<endl;
//	cout<<dp[5][1]<<endl;
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

