#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

// fast exponentiation modulo MOD
long long modpow(long long a, long long e=MOD-2) {
    long long r=1;
    while(e){
        if(e&1) r=(r*a)%MOD;
        a=(a*a)%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Precompute factorials and inverse factorials up to 5000
    const int MAXN = 5000;
    static long long fact[MAXN+1], invfact[MAXN+1];
    fact[0]=1;
    for(int i=1;i<=MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXN] = modpow(fact[MAXN]);
    for(int i=MAXN;i>0;i--) invfact[i-1] = invfact[i]*i%MOD;

    auto C = [&](int n,int k){
        if(k<0||k>n) return 0LL;
        return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
    };

    int T; 
    cin>>T;
    while(T--){
        int N; 
        cin>>N;
        vector<int> p(N+1);
        for(int i=1;i<=N;i++){
            cin>>p[i];
        }

        // 2) Mark which values 1..N are already fixed
        vector<bool> present(N+1,false);
        for(int i=1;i<=N;i++){
            if(p[i]!=-1)
                present[p[i]] = true;
        }

        // 3) Build the sorted list of missing values
        vector<int> miss;
        miss.reserve(N);
        vector<int> isMiss(N+1,0), prefMiss(N+1,0);
        for(int v=1;v<=N;v++){
            if(!present[v]){
                miss.push_back(v);
                isMiss[v]=1;
            }
            prefMiss[v] = prefMiss[v-1] + isMiss[v];
        }
        int M = miss.size();  // total number of “?”

        // 4) Prefix-sum of question-marks to get k = # of ? in [l..r] in O(1)
        vector<int> prefQ(N+1,0);
        for(int i=1;i<=N;i++){
            prefQ[i] = prefQ[i-1] + (p[i]==-1);
        }

        // 5) Build a sparse-table on the fixed entries (treat “?”?0)
        int LOG = 32 - __builtin_clz(N);
        static int st[13][MAXN+1];
        for(int i=1;i<=N;i++){
            st[0][i] = (p[i]==-1 ? 0 : p[i]);
        }
        for(int k=1;k<LOG;k++){
            int len = 1<<(k-1);
            for(int i=1;i + (1<<k) -1 <= N; i++){
                st[k][i] = max(st[k-1][i], st[k-1][i+len]);
            }
        }
        static int lg2[MAXN+1];
        lg2[1]=0;
        for(int i=2;i<=N;i++) lg2[i] = lg2[i>>1]+1;
        auto getMax = [&](int L,int R){
            int k = lg2[R-L+1];
            return max(st[k][L], st[k][R - (1<<k) + 1]);
        };

        // 6) Precompute F[k] = sum over all ways a “?”-only segment of length k
        //    picks its maximum (then times k!*(M-k)! )
        vector<long long> F(M+1,0LL);
        for(int k=1;k<=M;k++){
            long long sum=0;
            // pick which missing value v (the i-th in sorted miss) is the max
            // there are C(i-1, k-1) ways to choose the other k-1 smaller ones
            for(int i=k;i<=M;i++){
                sum = (sum + (long long)miss[i-1] * C(i-1, k-1)) % MOD;
            }
            // multiply by k! * (M-k)! for the intra-/extra-segment permutations
            sum = sum * fact[k] % MOD * fact[M-k] % MOD;
            F[k] = sum;
        }

        // 7) Double-loop over all subarrays [l..r], accumulate contribution
        long long answer = 0;
        for(int l=1; l<=N; l++){
            for(int r=l; r<=N; r++){
                int k    = prefQ[r] - prefQ[l-1];  // # of “?” in this subarray
                int fmx  = getMax(l,r);            // largest fixed value (or 0)
                if(fmx>0){
                    // to make the max = fmx, we must forbid any missing > fmx
                    int m_le = prefMiss[fmx];       // how many missing < fmx
                    if(k <= m_le){
                        // #ways = C(m_le, k) * k! * (M-k)!
                        long long w = C(m_le, k);
                        w = w * fact[k] % MOD * fact[M-k] % MOD;
                        answer = (answer + w * fmx) % MOD;
                    }
                } else {
                    // segment has no fixed values ? must come entirely from “?”
                    if(k>0) answer = (answer + F[k]) % MOD;
                }
            }
        }

        cout<<answer<<"\n";
    }
    return 0;
}

