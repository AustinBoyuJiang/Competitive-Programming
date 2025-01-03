/*
 * Author: Austin Jiang
 * Date: 9/22/2022 3:50:59 PM
 * Problem: Winter Driving
 * Description:
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
int T=1,n,totsiz,res,ans,root,hson=INF,cnt1,cnt2,tot1,tot2,a[N],p[N];
VI siz[2],sum[2],e[N];

int findRoot(int u,int fa){
	int siz=a[u],mx=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		int res=findRoot(v,u);
		siz+=res;
		chkmax(mx,res);
	}
	chkmax(mx,totsiz-siz);
	if(mx<hson){
		root=u;
		hson=mx;
	}
	return siz;
}

int getSize(int u,int fa){
	int siz=a[u];
	for(auto v:e[u]){
		if(v==fa) continue;
		siz+=getSize(v,u);
	}
	res+=a[u]*(siz-1);
	return siz;
}

int tot=0;
void dfs(int pos,int k){
	if(pos==siz[k].size()){
		sum[k].pb(tot);
		return;
	}
	dfs(pos+1,k);
	tot+=siz[k][pos];
	dfs(pos+1,k);
	tot-=siz[k][pos];
}

int check(int i,int j){
	int x=sum[0][i]+tot2-sum[1][j];
	int y=sum[1][j]+tot1-sum[0][i];
	return x*y+a[root]*(x+y);
}

void solve(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		totsiz+=a[i];
	}
	rep(i,2,n){
		cin>>p[i];
		e[i].pb(p[i]);
		e[p[i]].pb(i);
	}
	findRoot(1,0);
	res=a[root]*(a[root]-1);
	for(auto v:e[root]){
		if(siz[0].size()*2<e[root].size()){
			siz[0].pb(getSize(v,root));
			tot1+=siz[0][siz[0].size()-1];
		}
		else{
			siz[1].pb(getSize(v,root));
			tot2+=siz[1][siz[1].size()-1];
		}
	}
	dfs(0,0),sort(all(sum[0]));
	dfs(0,1),sort(all(sum[1]));
	rep(i,0,sum[0].size()-1){
		int l=0,r=sum[1].size()-1;
		while(l<=r){
			int mid=l+(r-l)/3;
			int rmid=(r+mid)/2;
			if(check(i,mid)>check(i,rmid)){
				r=rmid-1;
				chkmax(ans,check(i,rmid));
			}
			else{
				l=mid+1;
				chkmax(ans,check(i,mid));
			}
		}
	}
	cout<<ans+res<<endl;
}
/*
37
5948 6516 436 4408 824 9605 7220 2958 1130 7141 1909 8797 3690 1889 593 1619 8419 7960 6021 9458 8517 2766 6514 5248 9073 9436 6526 9447 6448 9886 6673 5286 3661 500 2937 3902 3766
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

11655788958

5
5 2 3 4 5
1 1 1 1
*/

signed main(){
    int size(512<<20);  //512M
    __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//srand(time(0));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	rep(Case,1,T) solve(Case);
    exit(0);
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

