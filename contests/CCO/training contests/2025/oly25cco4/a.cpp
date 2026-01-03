/*
 * Author: Austin Jiang
 * Date: 5/4/2025 1:28:41 AM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
#define FASTIO
//#define NDEBUG
#define OPTIMIZE
//#define INTTOLL

#ifdef OPTIMIZE
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#endif

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef INTTOLL
#define int long long
#endif

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

/* Pair */
#define fir first
#define sec second

/* STL */
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()

/* Random */
static std::mt19937 rng(
    (uint32_t)std::chrono::steady_clock::now()
        .time_since_epoch().count());

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.fir) ^ (hash<T2>{}(p.sec) << 1);
    }
};

/* Data type */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;
template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using UM = unordered_map<int,T>;
template <class T> using UPM = unordered_map<PI,T,pair_hash>;

/* Set up */
namespace FastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<class T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<class T> inline void write(T x,char ch) {write(x),putchar(ch);}
} using namespace FastIO;

void SETUP(){
	#ifdef FASTIO
	cin.tie(nullptr)->sync_with_stdio(false);
	#endif
	#ifdef READLOCAL
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	#endif
	srand(time(0));
}

/* Constants */
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#ifndef int
const int INF = 0x3f3f3f3f;
#else
const ll INF = LLINF;
#endif
const int MOD = 998244353;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
const unordered_set<char> vowel = {'a','e','i','o','u'};

/* Common functions */

namespace Comfun{
	template<class T> inline T lowbit(T x){return x&-x;}
	template<class T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<class T> inline T qpow(T a,T b){T ans=1;
	while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	inline int mex(VI v){VI vis(v.size(),0);for(int x:v) if(x<v.size()) vis[x]=1;
	int pos=0;while(pos<v.size()&&vis[pos]) pos++;return pos;}
	template<class T> inline void discrete(T *st,T *ed,T offset=0){ set<T> num(st,ed); Vec<T> pos(all(num));
	for (T *itr=st;itr!=ed;++itr){*itr=lb(all(pos),*itr)-pos.begin()+offset;}}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 2e5+10;

int n,q,sum;
unordered_map<int,int> id;
PI s[N];

struct segment{
	int id,l,r,len;
} segs[N];

struct segtree{
	int root,tot;
	
	struct node{
		int lc,rc;
		PI val={-1,-1};
	} st[N*30];
	
	void update(int &rt,int l,int r,int x,int y,PI v){
		if(!rt) rt=++tot;
		if(l==x&&r==y){
			st[rt].val=v;
			return;
		}
		int mid=l+r>>1;
		if(y<=mid) update(st[rt].lc,l,mid,x,y,v);
		else if(x>mid) update(st[rt].rc,mid+1,r,x,y,v);
		else{
			update(st[rt].lc,l,mid,x,mid,v);
			update(st[rt].rc,mid+1,r,mid+1,y,v);
		}
	}
	
	PI query(int &rt,int l,int r,int x){
		if(!rt) return {-1,-1};
		if(st[rt].val!=make_pair(-1,-1)) return st[rt].val;
		int mid=l+r>>1;
		if(x<=mid) return query(st[rt].lc,l,mid,x);
		else return query(st[rt].rc,mid+1,r,x);
	}
} lab1,lab2;

class SegmentListIdx{
    struct Node{
        segment seg;
        int pr,sz,ch[2],parent;
        Node(const segment& s,int _pr):seg(s),pr(_pr),sz(1),parent(-1){ch[0]=ch[1]=-1;}
    };

    vector<Node> pool;
    int root=-1;
    unordered_map<int,int> posOfId;   // ← 统一用这个名字

    int sz(int x)const{return x==-1?0:pool[x].sz;}
    void pull(int x){
        if(x==-1)return;
        for(int d:{0,1})if(pool[x].ch[d]!=-1)pool[pool[x].ch[d]].parent=x;
        pool[x].sz=1+sz(pool[x].ch[0])+sz(pool[x].ch[1]);
    }
    void split(int v,int k,int& a,int& b){
        if(v==-1){a=b=-1;return;}
        if(sz(pool[v].ch[0])>=k){
            split(pool[v].ch[0],k,a,pool[v].ch[0]); b=v;
        }else{
            split(pool[v].ch[1],k-sz(pool[v].ch[0])-1,pool[v].ch[1],b); a=v;
        }
        pool[v].parent=-1; pull(v);
    }
    int merge(int a,int b){
        if(a==-1||b==-1) return a==-1?b:a;
        if(pool[a].pr<pool[b].pr){
            pool[a].ch[1]=merge(pool[a].ch[1],b); pull(a); return a;
        }else{
            pool[b].ch[0]=merge(a,pool[b].ch[0]); pull(b); return b;
        }
    }
    int kthIdx(int v,int k)const{
        while(v!=-1){
            int lsz=sz(pool[v].ch[0]);
            if(k<lsz) v=pool[v].ch[0];
            else if(k==lsz) return v;
            else {k-=lsz+1; v=pool[v].ch[1];}
        }
        return -1;
    }
    int rankOfNode(int x)const{
        int res=sz(pool[x].ch[0]);
        while(pool[x].parent!=-1){
            int p=pool[x].parent;
            if(pool[p].ch[1]==x) res+=1+sz(pool[p].ch[0]);
            x=p;
        }
        return res;
    }
public:
    int positionOfId(int id)const{
        auto it=posOfId.find(id);
        return it==posOfId.end()?-1:rankOfNode(it->second);
    }
    bool insertAt(int pos,const segment& s){
        if(pos<0||pos>sz(root)||posOfId.count(s.id)) return false;
        int a,b; split(root,pos,a,b);
        int idx=pool.size();
        pool.emplace_back(s,(int)rng());       // 32?bit 随机优先级
        posOfId[s.id]=idx;
        root=merge(merge(a,idx),b);
        pool[root].parent=-1;
        return true;
    }
    bool push_back(const segment& s){return insertAt(sz(root),s);}
    bool removeId(int id){
        auto it=posOfId.find(id);
        if(it==posOfId.end()) return false;
        int idx=it->second, pos=rankOfNode(idx);
        int a,b,c; split(root,pos,a,b); split(b,1,b,c);
        root=merge(a,c);
        if(root!=-1) pool[root].parent=-1;
        posOfId.erase(it);
        return true;
    }
    template<class F> void traverse(F fn)const{dfs(root,fn);}
    const segment* getSegmentById(int id)const{
        auto it=posOfId.find(id);
        return it==posOfId.end()?nullptr:&pool[it->second].seg;
    }
    const segment* getSegmentByPos(int pos)const{
        if(pos<0||pos>=sz(root)) return nullptr;
        return &pool[kthIdx(root,pos)].seg;
    }
private:
    template<class F> void dfs(int v,F fn)const{
        if(v==-1) return;
        dfs(pool[v].ch[0],fn); fn(pool[v].seg); dfs(pool[v].ch[1],fn);
    }
};

inline void SOLVE(int Case){
	cin>>n;
	set<int> num;
	rep(i,1,n){
		cin>>s[i].fir>>s[i].sec;
		num.insert(s[i].fir);
		num.insert(s[i].sec);
	}
//	Vec<segment> seg;
    SegmentListIdx ds;
	int tot=0,lst=0;
	for(int x:num){
		if(x-lst-1>0){
			tot++;
//			seg.pb(segs[tot]={tot,lst+1,x-1,x-lst-1});
			ds.insertAt(tot-1,segs[tot]={tot,lst+1,x-1,x-lst-1});
		}
		tot++;
//		seg.pb(segs[tot]={tot,x,x,1});
		ds.insertAt(tot-1,segs[tot]={tot,x,x,1});
		id[x]=tot;
		lst=x;
	}
	if(lst<1e9){
		tot++;
//		seg.pb(segs[tot]={tot,lst+1,(int)1e9,(int)1e9-lst});
		ds.insertAt(tot-1,segs[tot]={tot,lst+1,(int)1e9,(int)1e9-lst}); 
	}
	rep(i,1,n){
		s[i].fir=id[s[i].fir];
		s[i].sec=id[s[i].sec];
	}
//	rep(i,1,n){
//		int pos=-1;
//		rep(j,0,(int)seg.size()-1){
//			if(seg[j].id==s[i].fir){
//				pos=j;	
//				break;
//			}
//		}
//		segment tmp=seg[pos];
//		seg.erase(seg.begin()+pos);
//		rep(j,0,(int)seg.size()-1){
//			if(seg[j].id==s[i].sec){
//				pos=j;	
//				break;
//			}
//		}
//		seg.insert(seg.begin()+pos,tmp);
//	}
	rep(i,1,n){
		segment tmp = *ds.getSegmentById(s[i].fir);
		ds.removeId(s[i].fir);
		int pos = ds.positionOfId(s[i].sec);
		ds.insertAt(pos, tmp);
	}
    ds.traverse([](const segment& s){
		lab1.update(lab1.root,1,1e9,sum+1,sum+s.len,{s.id,sum});
		lab2.update(lab2.root,1,1e9,s.l,s.r,{s.id,sum});
		sum+=s.len;
    });
//    for(segment s:seg){
//		cout<<s.id<<" "<<s.l<<" "<<s.r<<" "<<s.len<<endl;
//	}
//    ds.traverse([](const segment& s){
//		cout<<s.id<<" "<<s.l<<" "<<s.r<<" "<<s.len<<endl;
//    });
	cin>>q;
	rep(i,1,q){
		char opt;
		int x;
		cin>>opt>>x;
		if(opt=='P'){
			PI itm=lab2.query(lab2.root,1,1e9,x);
			cout<<x-segs[itm.fir].l+1+itm.sec<<endl;
		}
		else{
			PI itm=lab1.query(lab1.root,1,1e9,x);
			cout<<segs[itm.fir].l+x-itm.sec-1<<endl;
		}
	}
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	#ifdef SETMEM
    int size(512<<20);  //512MB
    __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	#endif
	#ifndef FILESCOMP
	SETUP();
	int CASE=1;
	#ifdef MULTICASES
	cin>>CASE;
	#endif
	rep(i,1,CASE){
		#ifdef LOCAL
		printf("Case #%d: \n",i);
		#endif
		SOLVE(i);
	}
	#else
	system("fc stdout.txt out.txt");
	#endif
	#ifdef SETMEM
    exit(0);
    #endif
	return 0;
}

/* stuff you should look for
	* read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow and edge case
    * Debug: (b) create your own test case
    * Debug: (c) adversarial testing
*/

