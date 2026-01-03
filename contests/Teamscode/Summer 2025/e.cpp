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

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ if(b > a){ a = b; return true; } return false; }
template<class T> inline bool chkmin(T &a, const T &b){ if(b < a){ a = b; return true; } return false; }

const int N = 21;
const int M = 1e5+10;

int tot,n,m,col[M],a[N][M],cnt[1<<N],id[1<<N],sup[1<<N];

void SOLVE(int Case){
    cin>>n>>m;
    tot=(1<<n)-1;
    rep(i,1,n){
        rep(j,1,m){
            char x;
            cin>>x;
            a[i][j]=x-'0';
        }
    }
    rep(mask,0,tot){
        cnt[mask]=0;
    }
    rep(j,1,m){
        col[j]=0;
        per(i,n,1){
            col[j]<<=1;
            col[j]|=a[i][j];
        }
        cnt[col[j]]++;
        id[col[j]]=j;
    }
    ll comp_pairs=0;
    PI pr={-1,-1};
    rep(mask,1,tot-1){
        int comp=tot^mask;
        if(mask>comp) continue;
        ll add=1ll*cnt[mask]*cnt[comp];
        if(add){
            comp_pairs+=add;
            if(pr.F==-1){
                int a=id[mask], b=id[comp];
                if(a>b) swap(a,b);
                pr={a,b};
            }
        }
    }
    rep(mask,0,tot) sup[mask]=cnt[mask];
    rep(bit,0,n-1){
        rep(mask,0,tot){
            if((mask&(1<<bit))==0) sup[mask]+=sup[mask|(1<<bit)];
        }
    }
    ll ordered=0;
    rep(a_mask,0,tot){
        if(!cnt[a_mask]) continue;
        int need=tot^a_mask;
        ordered += 1ll * cnt[a_mask] * sup[need];
    }
    ll cover_pairs = (ordered - cnt[tot]) / 2;
    cover_pairs -= 1ll * cnt[0] * cnt[tot];

    if(cover_pairs!=1){
        cout<<"No"<<nl;
        return;
    }

    if(comp_pairs==1){
        cout<<"Yes"<<nl;
        cout<<pr.F<<" "<<pr.S<<nl;
        return;
    }

    int u=-1,v=-1;
    if(cnt[tot]==1){
        int singleMask=-1;
        rep(k,0,n-1){
            if(cnt[1<<k]==1){
                if(singleMask==-1) singleMask=(1<<k);
                else singleMask=-2;
            }
        }
        if(singleMask>0){
            u=id[tot];
            v=id[singleMask];
            if(u>v) swap(u,v);
        }
    }
    if(u!=-1){
        cout<<"Yes"<<nl;
        cout<<u<<" "<<v<<nl;
    }else{
        cout<<"No"<<nl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; cin>>T;
    rep(i,1,T) SOLVE(i);
    return 0;
}
