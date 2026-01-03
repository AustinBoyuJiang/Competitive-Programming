/*
 * Author: Austin Jiang
 * Date: 10/10/2022 9:50:08 AM
 * Problem: 后缀自动机 (SAM)
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

const int N = 2e6+10;
int T=1,n,ans,in[N],cnt[N],len[N],f[N];
string s;

struct SAM{
	struct state{
		int len,link,flag;
		map<char,int> next;
	} st[N];
	
	int tot=0,last=-1;
	
	void init(){
		st[0].len=0;
		st[0].link=-1;
		tot++;
		last=0;
	}
	
	void extend(char c){
		int cur=tot++;
		st[cur].len=st[last].len+1;
		cnt[cur]=1;
		int p=last;
		while(p!=-1&&!st[p].next.count(c)){
			st[p].next[c]=cur;
			p=st[p].link;
		}
		if(p==-1) st[cur].link=0;
		else{
			int q=st[p].next[c];
			if(st[p].len+1==st[q].len){
				st[cur].link=q;
			}
			else{
				int clone=tot++;
				st[clone].len=st[p].len+1;
				st[clone].link=st[q].link;
				st[clone].next=st[q].next;
				st[clone].flag=0;
				while(p!=-1&&st[p].next[c]==q){
					st[p].next[c]=clone;
					p=st[p].link;
				}
				st[q].link=st[cur].link=clone;
			}
		}
		last=cur;
	}
} sam;

bool cmp(int a,int b){
	return sam.st[a].len>sam.st[b].len;
}

void solve(int Case){
	cin>>s;
	n=s.size();
	sam.init();
	rep(i,0,n-1) sam.extend(s[i]);
	rep(i,0,sam.tot-1){
		for(auto v:sam.st[i].next)
			in[v.sec]++;
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:sam.st[u].next){
			chkmax(len[v.sec],len[u]+1);
			if(!--in[v.sec])
				q.push(v.sec);
		}
	}
	rep(i,0,sam.tot-1) f[i]=i;
	sort(f,f+sam.tot,cmp);
	rep(i,0,sam.tot-1)
		cnt[sam.st[f[i]].link]+=cnt[f[i]];
	rep(i,0,sam.tot-1)
		if(cnt[i]>1) chkmax(ans,cnt[i]*len[i]);
	cout<<ans<<endl;
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

