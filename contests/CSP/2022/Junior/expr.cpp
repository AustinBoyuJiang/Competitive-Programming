/*
 * Author: Austin Jiang
 * Date: 11/6/2022 11:21:37 PM
 * Problem: expr
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

const int N = 1e6+10;
int cnt1,cnt2,flag[N],lazy[N],l[N];
string str;
vector<pair<pair<char,int>,int>> expr;
stack<pair<char,int>> oper;
stack<int> stk;

void solve(int Case){
	cin>>str;
	int cnt=0;
	rep(i,0,str.size()-1){
		char x=str[i];
		if(x=='('){
			stk.push(i);
			cnt++;
			flag[cnt]=0;
			continue;
		}
		if(x==')'){
			l[i]=stk.top();
			stk.pop();
			flag[cnt]=0;
			cnt--;
			continue;
		}
		l[i]=i;
		if(x=='&'){
			if(flag[cnt]!=1){
				cnt++;
				lazy[l[i-1]]++;
				lazy[i]--;
			}
			flag[cnt]=1;
		}
		if(x=='|'){
			if(flag[cnt]==1) cnt--;
			flag[cnt]=2;
		}
		expr.pb({{x,i},cnt});
	}
	rep(i,0,str.size()-1) lazy[i]+=lazy[i-1];
	for(auto &x:expr){
		x.sec+=lazy[x.fir.sec];
//		cout<<x.sec<<" ";
	}
//	cout<<endl;
//	return;
	
	int del=-1,fl=0;
	for(auto v:expr){
		char x=v.fir.fir;
//		cout<<x<<" ";
		if(del!=-1){
			if(v.sec<del||(!fl&&v.sec==del)){
				del=-1;
			}
			else{
				if(v.sec>del) fl=0;
				if(fl&&v.sec==del){
					fl=0;
					del=-1;
				}
				continue;
			}
		}
		if(x=='&'&&oper.top().fir=='0'){
			fl=1;
			del=v.sec;
			cnt1++;
			continue;
		}
		if(x=='|'&&oper.top().fir=='1'){
			fl=1;
			del=v.sec;
			cnt2++;
			continue;
		}
		while(oper.size()>=3&&(x=='&'||x=='|')&&v.sec<oper.top().sec){
			char b=oper.top().fir;
			oper.pop();
			char s=oper.top().fir;
			oper.pop();
			char a=oper.top().fir;
			int c=oper.top().sec;
			oper.pop();
			if(s=='&'){
				if(a=='1'&&b=='1') oper.push({'1',c});
				else oper.push({'0',c});
			}
			else{
				if(a=='0'&&b=='0') oper.push({'0',c});
				else oper.push({'1',c});
			}
		}
		while(oper.size()>=2&&(x=='0'||x=='1')&&v.sec==oper.top().sec){
			char s=oper.top().fir;
			oper.pop();
			char a=oper.top().fir;
			oper.pop();
			if(s=='&'){
				if(x=='1'&&a=='1') x='1';
				else x='0';
			}
			else{
				if(x=='0'&&a=='0') x='0';
				else x='1';
			}
		}
		oper.push({x,v.sec});
	}
	while(oper.size()>=3){
		char b=oper.top().fir;
		oper.pop();
		char s=oper.top().fir;
		oper.pop();
		char a=oper.top().fir;
		int c=oper.top().sec;
		oper.pop();
		if(s=='&'){
			if(a=='1'&&b=='1') oper.push({'1',c});
			else oper.push({'0',c});
		}
		else{
			if(a=='0'&&b=='0') oper.push({'0',c});
			else oper.push({'1',c});
		}
	}
	cout<<oper.top().fir<<endl;
	cout<<cnt1<<" "<<cnt2<<endl;
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("expr.in","r",stdin);
//	freopen("expr.out","w",stdout);
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

