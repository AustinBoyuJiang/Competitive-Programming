/*
 * Author: Austin Jiang
 * Date: 9/25/2022 9:24:45 PM
 * Problem: Best Cow Line
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
int T=1,n,m,sa[N],id[N],rk[N],oldrk[N],cnt[N];
char s[N];

void solve(int Case){
	cin>>n;
	m=n*2;
	rep(i,1,n) cin>>s[i];
	rep(i,1,n) s[n+i]=s[n-i+1];
	
	rep(i,1,m) cnt[rk[i]=s[i]]++; 
	rep(i,1,300) cnt[i]+=cnt[i-1];
	per(i,m,1) sa[cnt[rk[i]]--]=i;
	
	memcpy(oldrk,rk,sizeof(rk));
	rep(i,1,m) rk[sa[i]]=rk[sa[i-1]]+
	!(oldrk[sa[i]]==oldrk[sa[i-1]]);
	
	for(int w=1;w<m;w<<=1){
		memcpy(id,sa,sizeof(sa));
		memset(cnt,0,sizeof(cnt));
		rep(i,1,m) cnt[rk[id[i]+w]]++;
		rep(i,1,m) cnt[i]+=cnt[i-1];
		per(i,m,1) sa[cnt[rk[id[i]+w]]--]=id[i];
		
		memcpy(id,sa,sizeof(sa));
		memset(cnt,0,sizeof(cnt));
		rep(i,1,m) cnt[rk[id[i]]]++;
		rep(i,1,m) cnt[i]+=cnt[i-1];
		per(i,m,1) sa[cnt[rk[id[i]]]--]=id[i];
		
		memcpy(oldrk,rk,sizeof(rk));
		rep(i,1,m) rk[sa[i]]=rk[sa[i-1]]+
		!(oldrk[sa[i]]==oldrk[sa[i-1]]&&
		oldrk[sa[i]+w]==oldrk[sa[i-1]+w]);
	}
	
	int l=1,r=n,cnt=0;
	rep(i,1,n){
		if(rk[l]<rk[n*2-r+1]) cout<<s[l++];
		else cout<<s[r--];
		if(i%80==0) cout<<endl;
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
    * Debug: (c) ����
*/

