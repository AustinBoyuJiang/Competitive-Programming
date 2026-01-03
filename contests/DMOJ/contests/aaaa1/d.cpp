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

const int N = 310;

int n,m,pos[N],dp[N],dp2[N],b[N];

void SOLVE(int Case){
    cin>>n>>m;
    int tot=n*m;
    rep(i,1,tot){
        int val;
        cin>>val;
        pos[val]=i;
    }
    int L=pos[0],R=pos[0];
    rep(k,1,tot-1){
        if(pos[k]<L || pos[k]>R){
            b[k]=true;
            L=min(L,pos[k]);
            R=max(R,pos[k]);
        }
        else b[k]=false;
    }
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    rep(k,1,tot-1){
        memset(dp2,0,sizeof(dp2));
        rep(j,1,tot){
            if(!dp[j])continue;
            if(b[k]){
                rep(i,j+1,tot){
                	dp2[i]=(dp2[i]+dp[j]*2%MOD)%MOD;
                }
            }else{
            	int d=j-k;
                if(d>0){
                	dp2[j]=(dp2[j]+dp[j]*d)%MOD;
                }
            }
        }
        memcpy(dp,dp2,sizeof(dp));
    }
    cout<<dp[tot]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	// cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}