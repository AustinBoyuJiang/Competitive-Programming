/*
 * Author: Austin Jiang
 * Date: 7/6/2022 6:01:44 PM
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
    template<typename T> inline void print(T x) {if(x<0) x=-x,putchar('-'); if(x>9) print(x/10); putchar(x%10+'0');}
	template<typename T> inline void print(T x,char let) {print(x),putchar(let);}
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

const int N = 1e5+10;
const int M = 2e6+10;
int n,mx,a[N],sum[M];
ll ans;

int get(int i,int j){ //How many divided by i equals j
	return sum[i*j+i-1]-sum[i*j-1];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		sum[a[i]]++;
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=mx*2;i++)
		sum[i]+=sum[i-1];
	for(int i=1;i<=mx;i++){
		int cnt=0,pos1=0,pos2=0;
		for(int j=1;i*j<=mx;j++){
			int tot=get(i,j);
			if(tot%2){
				cnt++;
				if(cnt==1) pos1=j;
				if(cnt==2) pos2=j;
				if(cnt>2) break;
			}
		}
		if(cnt==2||cnt==1)
		if(abs(pos1-pos2)==1)
			ans+=get(i,max(pos1,pos2));
	}
	print(ans);
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

