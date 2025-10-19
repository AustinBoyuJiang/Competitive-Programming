#include <bits/stdc++.h>
using namespace std;

int build(const vector<int>& a, vector<int>& par, vector<int>& L, vector<int>& R){
    int n = (int)a.size() - 1;
    par.assign(n+1, 0);
    L.assign(n+1, 0);
    R.assign(n+1, 0);
    vector<int> st; st.reserve(n);
    for(int i=1;i<=n;i++){
        int last=0;
        while(!st.empty() && a[st.back()]<a[i]){
            last=st.back();
            st.pop_back();
        }
        if(!st.empty()){
            par[i]=st.back();
            R[st.back()]=i;
        }
        if(last){
            par[last]=i;
            L[i]=last;
        }
        st.push_back(i);
    }
    return st.front();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        if(a[1]!=1){
            cout<<-1<<"\n";
            continue;
        }
        vector<int> par,L,R;
        int root=build(a,par,L,R);
        vector<int> p; p.reserve(n);
        function<void(int)> dfs=[&](int u){
            if(!u) return;
            p.push_back(a[u]);
            dfs(L[u]);
            dfs(R[u]);
        };
        dfs(root);
        for(int i=0;i<n;i++){
            if(i) cout<<' ';
            cout<<p[i];
        }
        cout<<"\n";
        
        vector<int> b=p, pos(n+1);
        for(int i=0;i<n;i++) pos[b[i]]=i;
        for(int x=n;x>=1;x--){
            int i=pos[x];
            while(i>0 && b[i]<b[i-1]){
                swap(b[i],b[i-1]);
                pos[b[i]] = i;
                pos[b[i-1]] = i-1;
                --i;
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            if(b[i]!=a[i+1]){ ok=false; break; }
        }
        if(!ok){
            cout<<"WA"<<endl;
        }else{
        	cout<<"AC"<<endl;
        }
    }
    return 0;
}
