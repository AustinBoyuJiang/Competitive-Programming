#include <bits/stdc++.h>
using namespace std;

/* ---------- ???? + RMQ ---------- */
struct SuffixArray {
    vector<int> sa, rk, lcp;
    vector<vector<int>> st;
    int n;
    SuffixArray(const string& s){ build(s); }

    void build(const string& s){
        n=s.size();
        sa.resize(n); rk.resize(n);
        iota(sa.begin(),sa.end(),0);
        for(int i=0;i<n;++i) rk[i]=s[i];

        vector<int> tmp(n);
        for(int k=1;;k<<=1){
            auto cmp=[&](int i,int j){
                if(rk[i]!=rk[j]) return rk[i]<rk[j];
                int ri=i+k<n?rk[i+k]:-1;
                int rj=j+k<n?rk[j+k]:-1;
                return ri<rj;
            };
            sort(sa.begin(),sa.end(),cmp);
            tmp[sa[0]]=0;
            for(int i=1;i<n;++i)
                tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);
            rk.swap(tmp);
            if(rk[sa.back()]==n-1) break;
        }
        lcp.assign(n-1,0);
        for(int i=0,k=0;i<n;++i){
            if(rk[i]==0) continue;
            int j=sa[rk[i]-1];
            while(i+k<n && j+k<n && s[i+k]==s[j+k]) ++k;
            lcp[rk[i]-1]=k;
            if(k) --k;
        }
        int LOG=1; while((1<<LOG)<n) ++LOG;
        st.assign(LOG,vector<int>(n));
        st[0]=vector<int>(lcp.begin(),lcp.end()); st[0].push_back(0);
        for(int t=1;(1<<t)<n;++t)
            for(int i=0;i+(1<<t)<=n;++i)
                st[t][i]=min(st[t-1][i],st[t-1][i+(1<<(t-1))]);
    }
    int getLCP(int i,int j) const{
        if(i==j) return n-i;
        int ri=rk[i], rj=rk[j];
        if(ri>rj) swap(ri,rj);
        --rj;
        int k=__lg(rj-ri+1);
        return min(st[k][ri],st[k][rj-(1<<k)+1]);
    }
};
/* ---------- ??? ---------- */
struct Node{
    int pos;
    int grp;          // 0 = a, 1 = b
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    if(!(cin>>N>>K)) return 0;
    string a,b; cin>>a>>b;
    int M=N-K+1;

    string S=a; S.push_back(char('z'+1));   // ???
    int cut=S.size();                       // =|a|+1
    S+=b;
    SuffixArray SA(S);

    vector<Node> v;
    v.reserve(2*M);
    for(int i=0;i<M;++i) v.push_back({i,0});
    for(int i=0;i<M;++i) v.push_back({cut+i,1});

    auto cmp=[&](const Node& p,const Node& q){
        int l=SA.getLCP(p.pos,q.pos);
        if(l>=K) return p.pos<q.pos;        // **???:??????**
        return S[p.pos+l]<S[q.pos+l];
    };
    sort(v.begin(),v.end(),cmp);

    long long keep=0;
    vector<Node> st;
    for(auto &x:v){
        if(!st.empty() && st.back().grp!=x.grp){
            keep+=min(K,SA.getLCP(st.back().pos,x.pos));
            st.pop_back();
        }else st.push_back(x);
    }
    cout<<1LL*M*K - keep<<"\n";
    return 0;
}

