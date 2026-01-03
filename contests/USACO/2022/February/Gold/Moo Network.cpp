/*
 * Author: Austin Jiang
 * Date: 7/7/2022 3:32:20 PM
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
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 1e5+10;
const int Y = 12;
const int E = N*Y*2;
int n,tot,f[N];
VPI pos[Y];
ll ans;

struct edge{
	int u,v;
	ll w;
} e[E];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	f[find(x)]=find(y);
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		int x,y;
		read(x),read(y);
		pos[y].pb(mp(x,i));
		f[i]=i;
	}
	for(int i=0;i<=10;i++)
		sort(pos[i].begin(),pos[i].end());
	for(int i=0;i<=10;i++){
		for(auto j:pos[i]){
			for(int k=0;k<=10;k++){
				int a=lb(pos[k].begin(),pos[k].end(),mp(j.fir,0))-pos[k].begin();
				int b=a-1;
				if(k==i) a++;
				if(a<pos[k].size()){
					ll w=(ll)(i-k)*(i-k)+(ll)(j.fir-pos[k][a].fir)*(j.fir-pos[k][a].fir);
					e[++tot]={j.sec,pos[k][a].sec,w};
				}
				if(b>=0){
					ll w=(ll)(i-k)*(i-k)+(ll)(j.fir-pos[k][b].fir)*(j.fir-pos[k][b].fir);
					e[++tot]={j.sec,pos[k][b].sec,w};
				}
			}
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int x=e[i].u;
		int y=e[i].v;
		if(find(x)!=find(y)){
			merge(x,y);
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
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

