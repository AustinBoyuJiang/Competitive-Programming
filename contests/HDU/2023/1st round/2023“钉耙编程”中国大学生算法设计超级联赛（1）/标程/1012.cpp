#include <bits/stdc++.h>

#define Max 200005

using namespace std;

const int mod=1e9+7;

struct Edge{
    int v,to;
}e[Max*2];

int T,n,sz,head[Max],f1[Max],f2[Max];

inline int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ans;
}

inline void add(int u,int v){
    e[++sz].v=v;e[sz].to=head[u];head[u]=sz;
}

inline void dfs1(int u,int fa){
    int now=0;
    for(int i=head[u];i;i=e[i].to){
        int v=e[i].v;
        if(v==fa)continue;
        dfs1(v,u);
        now^=(f1[v]+1);
    }
    f1[u]=now;
    return;
}

inline void dfs2(int u,int fa){
    for(int i=head[u];i;i=e[i].to){
        int v=e[i].v;
        if(v==fa)continue;
        f2[v]=f1[v]^((f2[u]^(f1[v]+1))+1);
        dfs2(v,u);
    }
    return;
}

int main(){
	freopen("1012.in","r",stdin);
//	freopen("data2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs1(1,1);
        f2[1]=f1[1];
        dfs2(1,1);
        int cnt=0;
        for(int i=1;i<=n;i++){
//        	cout<<f2[i]<<"  ";
            if(f2[i])cnt++;
        }
//        cout<<cnt<<'\n';
        cout<<1ll*cnt*qpow(n,mod-2)%mod<<'\n';
        for(int i=1;i<=n;i++)head[i]=0;
        sz=0;
    }
    return 0;
}
