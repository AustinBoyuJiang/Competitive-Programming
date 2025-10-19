#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int MOD = 1e9+7;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1e6+10;

namespace combi {

    template<class T1, class T2>
    inline T1 qpow(T1 a, T2 b) {
    	if(b == 0) return 1;
    	if(a >= MOD) a %= MOD;
    	if(a == 0) return 0;
    	b %= MOD - 1;
        T1 ans = 1;
        for(; b; b >>= 1) {
            if (b & 1){
            	ans  = ans * 1LL * a % MOD;
            }
            a = a * 1LL * a % MOD;
        }
        return ans;
    }

    template<class T>
    inline T inv(T x) {
        return qpow(x, (T)(MOD - 2)); // MOD must be prime
    }

} using namespace combi;

int n,a,b,ini[100],dv[100];
unordered_map<int,unordered_map<int,int>> vis;
vector<int> p;

int C(int n,int m){
	if(vis[n][m]) return vis[n][m];
	int ans=ini[n-m];
	ans*=dv[n-m];
	ans%=MOD;
	// cout<<ans<<" "<<n<<" "<<m<<endl;
	vis[n][m]=ans;
	return ans;
}

int get(int k,int n){
	unordered_map<int,int> cnt;
	for(int i=2;i*i<=k;i++){
		int tmp=0;
		while(k%i==0){
			k/=i;
			tmp++;
		}
		if(tmp>0){
			cnt[i]=tmp;
		}
	}
	if(k>1) cnt[k]=1;
	int ans=1;
	for(PI p:cnt){
		ans*=C(n+p.S-1,n-1);
		ans%=MOD;
	}
	return ans;
}

void SOLVE(int Case){
	cin>>n>>a>>b;
	ini[0]=1;
	rep(i,1,99){
		ini[i]=(i+n-1)%MOD*ini[i-1]%MOD;
	}
	int ans=0;
	for(int i=1;i*i<=b;i++){
		if(b%i==0){
			if(i*i==b){
				if(i<=a){
					int res=get(i,n);
					ans+=res*res%MOD;
					ans%=MOD;
				}
			}
			else{
				if(i<=a){
					int res=get(i,n)*get(b/i,n);
					ans+=res%MOD;
					ans%=MOD;
					if(b/i<=a){
						ans+=res%MOD;
						ans%=MOD;
					}
				}
			}
		}
	}
	cout<<"Case #"<<Case<<": "<<ans<<endl;
}

void init(){
	dv[1]=inv(1);
	rep(i,2,99){
		dv[i]=dv[i-1]*inv(i)%MOD;
		dv[i]%=MOD;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	init();
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}