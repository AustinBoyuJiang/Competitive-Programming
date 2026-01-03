/*
 * Author: Austin Jiang
 * Date: 9/6/2022 11:37:18 PM
 * Problem: Swap Swap Sort 
 * Description: 维护逆序对 + 暴力优化 
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

const int N = 1e5+10;
const int Q = 1e6+10;
const int K = 100;
int T=1,n,k,q,a[N],f[N],ans[Q],vis[N];
VPI q1[Q],q2[Q];
VI p[N];

struct segment_tree{
	int st[N<<2];
	
	void update(int rt,int l,int r,int x,int y){
		if(l==r){
			st[rt]+=y;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(rt<<1,l,mid,x,y);
		else update(rt<<1|1,mid+1,r,x,y);
		st[rt]=st[rt<<1]+st[rt<<1|1];
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(x>y) return 0;
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
	}
} st;

bool ok(int x){
	return p[x].size()<=K;
}

int solve0(){
	int ans=0;
	rep(i,1,n){
		ans+=st.query(1,1,k,a[i]+1,k);
		st.update(1,1,k,a[i],1);
	}
	return ans;
}

int solve1(int x,int y){
	int ans=0,j=0;
	for(int i=0;i<p[x].size();i++){
		while(j<p[y].size()&&p[y][j]<p[x][i]) j++;
		ans-=j;
		ans+=p[y].size()-j;
	}
	return ans;
}

void solve2(int x){
	fill(vis+1,vis+k+1,0);
	int cnt=0;
	rep(i,1,n){
		if(a[i]==x) cnt++;
		else vis[a[i]]+=cnt;
	}
	for(auto i:q1[x]){
		int id=i.fir,val=i.sec;
		ans[id]+=vis[val];
	}
	for(auto i:q2[x]){
		int id=i.fir,val=i.sec;
		ans[id]-=vis[val];
	}
}

void solve3(int x){
	fill(vis+1,vis+k+1,0);
	int cnt=0;
	per(i,n,1){
		if(a[i]==x) cnt++;
		else vis[a[i]]+=cnt;
	}
	for(auto i:q1[x]){
		int id=i.fir,val=i.sec;
		ans[id]-=vis[val];
	}
	for(auto i:q2[x]){
		int id=i.fir,val=i.sec;
		ans[id]+=vis[val];
	}
}

void solve(int Case){
	cin>>n>>k>>q;
	rep(i,1,k) f[i]=i;
	rep(i,1,n){
		cin>>a[i];
		p[a[i]].pb(i);
	}
	ans[0]=solve0();
	rep(i,1,q){
		int x;
		cin>>x;
		if(!ok(f[x])) q1[f[x]].pb({i,f[x+1]});
		else if(!ok(f[x+1])) q2[f[x+1]].pb({i,f[x]});
		else ans[i]=solve1(f[x],f[x+1]);
		swap(f[x],f[x+1]);
	}
	rep(i,1,k){
		if(!ok(i)){
			solve2(i);
			solve3(i);
		}
	}
	rep(i,1,q){
		ans[i]+=ans[i-1];
		cout<<ans[i]<<endl;
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
    * Debug: (c) 对拍
*/

