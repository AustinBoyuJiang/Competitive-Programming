#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

struct DSet {
    unsigned m = 0;
    inline void clear(){ m = 0; }
    inline void insert(int d){ m |= (1u<<d); }
    inline bool has(int d) const { return (m>>d)&1u; }
    inline void erase(int d){ m &= ~(1u<<d); }
    inline int size() const { return __builtin_popcount(m); }
	inline int lower_bound(int x) const {
	    unsigned t = m & (0x3FFu & (~0u << x));
	    if (!t) return -1;
	    return __builtin_ctz(t);
	}
};
static inline DSet allDigits(){ DSet d; d.m = (1u<<10)-1; return d; }

const int N = 20;

ll n;
int len,k,a[N],b[N];

inline int get(int a[]){
    unsigned mask = 0;
    rep(i,1,len) mask |= (1u<<a[i]);
    return __builtin_popcount(mask);
}

inline int assign(ll n){
	int len=0;
	while(n){
		len++;
		a[len]=n%10;
		n/=10;
	}
	a[len+1]=0;
	return len;
}

inline bool check(int st,DSet& d,int mx){
	rep(i,1,st-1) b[i]=0;
	DSet s;
	per(i,len,st) s.insert(b[i]);
	int i=1;
	while(s.size()<k&&i<st){
		int itr=d.lb(b[i]);
		if(itr==-1) continue;
		b[i]=itr;
		s.insert(b[i]);
		d.erase(itr);
		i++;
	}
	reverse(b+1,b+i);
	if(get(b)>=k){
		rep(i,1,mx) a[i]=b[i];
		return true;
	}
	return false;
}

void SOLVE(int Case){
	cin>>n>>k;
	len=assign(n);
	if(len<k){
		len=k;
		per(i,len,1){
			a[i]=len-i;
		}
		swap(a[len],a[len-1]);
	}
	while(true){
		int cnt=get(a);
		if(cnt==k) break;
		if(cnt>k){
			rep(st,2,len){
				DSet s;
				int mx=0,mn=9;
				per(i,len,st){
					s.insert(a[i]);
					chkmax(mx,a[i]);
					chkmin(mn,a[i]);
				}
				if(s.size()>k) continue;
				if(a[st-1]>mx){
					a[st]++;
					rep(i,1,st-1){
						a[i]=0;
					}
				}
				else{
					a[st-1]=s.lb(a[st-1]);
					rep(i,1,st-2){
						a[i]=mn;
					}
				}
				break;
			}
		}
		else{
			int mx=len+1;
			rep(st,1,mx){
				if(a[st]==9) continue;
				{
					rep(i,1,mx) b[i]=a[i];
					if(st==mx) len++;
					b[st]++;
					DSet d = allDigits();
                    per(i,len,st){
                        if(d.has(b[i])) d.erase(b[i]);
                    }
					if(check(st,d,mx)) break;
				}
				{
					rep(i,1,mx) b[i]=a[i];
					if(st==mx) len++;
					bool ok=st>1&&b[st]+2<=9&&b[st-1]==9;
					if(ok){
						b[st]+=2;
						DSet d = allDigits();
	                    per(i,len,st){
	                        if(d.has(b[i])) d.erase(b[i]);
	                    }
						if(check(st,d,mx)) break;
					}
				}
				{
					rep(i,1,mx) b[i]=a[i];
					DSet d = allDigits();
                    per(i,len,st+1){
                        if(d.has(b[i])) d.erase(b[i]);
                    }
					int itr=d.lb(b[st]+2);
					if(itr==-1||itr<=b[st]+1) continue;
					b[st]=itr;
					d.erase(itr);
					if(check(st,d,mx)) break;
				}
			}
		}
	}
	per(i,len,1){
		cout<<a[i];
	} cout<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}