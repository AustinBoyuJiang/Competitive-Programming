#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long mod_pow(long long a,long long e=MOD-2){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /* pre-compute factorials and inverse factorials up to 5000 */
    const int MAXN = 5000;
    static long long fact[MAXN+1],invFact[MAXN+1];
    fact[0]=1;
    for(int i=1;i<=MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    invFact[MAXN]=mod_pow(fact[MAXN]);
    for(int i=MAXN;i;--i) invFact[i-1]=invFact[i]*i%MOD;

    auto nCr=[&](int n,int r)->long long{
        if(r<0||r>n) return 0;
        return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
    };
    auto nPr=[&](int n,int r)->long long{            // n P r
        if(r<0||r>n) return 0;
        return fact[n]*invFact[n-r]%MOD;
    };

    int T;  cin>>T;
    while(T--){
        int N;  cin>>N;
        vector<int> a(N);
        vector<int> used(N+1,0);
        for(int &x:a){
            cin>>x;
            if(x!=-1) used[x]=1;
        }
        /* gather missing numbers (ascending) */
        vector<int> miss;
        for(int v=1;v<=N;v++) if(!used[v]) miss.push_back(v);
        int K = (int)miss.size();

        /* prefix #known =val  :  knownLess[v] (0-based v) */
        vector<int> knownLess(N+1,0);
        for(int v=1;v<=N;v++){
            knownLess[v]=knownLess[v-1]+(used[v]?1:0);
        }

        /* pre-tables: pref1[u][j] = S_{t=j}  r_t * C(t,u-1)
                       pref2[u][j] = S_{t=j}  r_t * C(t-1,u-1)
           only for u=1 (u==0 handled separately).          */
        vector<vector<int>> pref1(K+1, vector<int>(K,0)),
                            pref2(K+1, vector<int>(K,0));

        for(int u=1;u<=K;u++){
            long long run1=0, run2=0;
            for(int j=0;j<K;j++){
                run1 = (run1 + 1LL*miss[j]*nCr(j,u-1))%MOD;
                long long c2 = (j? nCr(j-1,u-1):0);
                run2 = (run2 + 1LL*miss[j]*c2)%MOD;
                pref1[u][j] = (int)run1;
                pref2[u][j] = (int)run2;
            }
        }

        long long Kfact = fact[K];
        long long answer = 0;

        for(int l=0;l<N;l++){
            int u = 0;              // unknown counter in current sub-array
            int mkn = 0;            // max known in current sub-array
            for(int r=l;r<N;r++){
                if(a[r]==-1) ++u;
                else mkn = max(mkn, a[r]);

                if(!u){                 // no unknowns: deterministic
                    answer = (answer + Kfact * 1LL * mkn)%MOD;
                    continue;
                }
                /* how many missing numbers = mkn ? */
                int p = (mkn? (mkn-1-knownLess[mkn-1]) : 0);
                long long term1 = 0;
                if(u<=p){   // otherwise C(p,u)=0 so term1 vanishes
                    term1 = 1LL*mkn * nPr(p,u)%MOD * fact[K-u]%MOD;
                }

                auto getPref=[&](vector<vector<int>>& P,int U,int idx)->long long{
                    if(U==0) return 0;
                    if(idx<0) return 0;
                    return P[U][idx];
                };
                /* S r_j*(C(j,u-1)-C(j-1,u-1))   over j = p */
                long long sum1 = (getPref(pref1,u,K-1) - getPref(pref1,u,p-1) + MOD)%MOD;
                long long sum2 = (getPref(pref2,u,K-1) - getPref(pref2,u,p-1) + MOD)%MOD;
                long long diff = (sum1 - sum2 + MOD)%MOD;
                long long term2 = fact[K-u] * diff %MOD;

                answer = (answer + term1 + term2)%MOD;
            }
        }
        cout<<answer%MOD<<"\n";
    }
    return 0;
}

