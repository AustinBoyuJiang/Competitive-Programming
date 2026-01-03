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
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){
    if(b > a){ a = b; return true; }
    return false;
}
template<class T> inline bool chkmin(T &a, const T &b){
    if(b < a){ a = b; return true; }
    return false;
}

const int N = 1e6 + 10;
int n, a[N];

int C3(int x){
    if(x < 3) return 0;
    return x*(x - 1)*(x - 2)/6;
}

void SOLVE(int Case){
    cin >> n;
    rep(i,1,n) cin >> a[i];

    unordered_map<int, int> freq;
    freq.reserve(n * 2);

    int pref = 0;
    freq[0] = 1;
    rep(i,1,n){
        pref^=a[i];
        freq[pref]++;
    }

    int tot = 1LL*n*(n+ 1)*(n + 2)/6;
    int over = 0;
    for(auto &kv : freq){
        int c = kv.S;
        over += C3(c + 1);
    }
    int ans = tot - over;
    cout << "Case #" << Case << ": " << ans << nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("stdin.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
    int T = 1;
    cin >> T;
    rep(i,1,T) SOLVE(i);
    return 0;
}
