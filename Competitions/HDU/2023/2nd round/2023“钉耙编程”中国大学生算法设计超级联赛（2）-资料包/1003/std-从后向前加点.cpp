#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+10;
struct node{
    int u,to;
}edge[MAXN<<1],edge1[MAXN<<2];
vector<int>G[MAXN];
int vis[MAXN],sta[MAXN],head[MAXN],low[MAXN],dfn[MAXN],sz[MAXN],a[MAXN],head1[MAXN],fa[MAXN];
int n,m,q,s,k,x,y,T,k1,dfstime,top,p,pd;
void add(int x,int y){
    edge[k].u=y;
    edge[k].to=head[x];
    head[x]=k++;
}
void add1(int x,int y){
    edge1[k1].u=y;
    edge1[k1].to=head1[x];
    head1[x]=k1++;
}
void tarjan(int now,int fa){
    low[now]=dfn[now]=++dfstime;
    sta[++top]=now;
    for (int i=head[now];~i;i=edge[i].to){
        int u=edge[i].u;
        if (u==fa||!vis[u]) continue;
        if (dfn[u]) low[now]=min(low[now],dfn[u]);
        else{
            tarjan(u,now);
            low[now]=min(low[now],low[u]);
            if (low[u]>=dfn[now]){
                p++;
                while (sta[top]!=u) {
                    add1(p,sta[top]); add1(sta[top],p);
                    top--;
                }
                top--; add1(p,u); add1(u,p);
                add1(now,p); add1(p,now);
            }
        }
    }
}
int dfs(int now,int fa,int x,int y){
    int sz=0;
    if (now==x||now==y) sz=1;
    for (int i=head1[now];i!=-1;i=edge1[i].to){
        int u=edge1[i].u;
        if (u==fa) continue;
        sz+=dfs(u,now,x,y);
    }
    if (sz==2&&!pd) pd=now;
    return sz;
}
int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}
void build(int x){
    for (int i=1;i<=n;i++) low[i]=dfn[i]=0;
    for (int i=1;i<=(n<<1);i++) head1[i]=-1;
    k1=0;top=0;dfstime=0;
    tarjan(x,0);
}
int solve(){
    int sum=0;
    pd=0;
    for (int i=1;i<=n;i++) fa[i]=i,vis[i]=1,G[i].clear();
    for (int i=1;i<=s;i++) vis[a[i]]=0,G[a[i]].push_back(a[i]);
    for (int i=1;i<=n;i++)if (vis[i]){
            for (int j=head[i];~j;j=edge[j].to){
                int v=edge[j].u;
                if (vis[v]) fa[getfather(v)]=getfather(i);
            }
        }
    int ans=0;
    for (int i=s;i>=1;i--){
        int u=a[i];
        for (int j=head[u];~j;j=edge[j].to){
            int v=edge[j].u;
            if (vis[v]){
                v=getfather(v);
                if (v!=u){
                    fa[v]=u;
                    for (int k=0;k<(int)G[v].size();k++) G[u].push_back(G[v][k]);
                    if (G[v].size()>=2) sum--;
                    G[v].clear();
                }
            }
        }
        vis[u]=1;
        if (G[u].size()>=2) sum++;
        if (sum>1) return i;
        if (G[u].size()>2){
            build(u);
            int x=G[u][0],y=G[u][1],z=G[u][2];
            dfs(x,0,y,z);
            if (pd>n) return i;
            ans=i;
            break;
        }
    }
    if (!pd) return 0;
    for (int i=1;i<=n;i++) fa[i]=i,vis[i]=1,sz[i]=0;
    for (int i=1;i<=s;i++) vis[a[i]]=0,sz[a[i]]=1;
    vis[pd]=0,sz[pd]=0;
    for (int i=1;i<=n;i++)if (vis[i]){
            for (int j=head[i];~j;j=edge[j].to){
                int v=edge[j].u;
                if (vis[v]) fa[getfather(v)]=getfather(i);
            }
        }
    for (int i=s;i>=1;i--){
        int u=a[i];
        if (u==pd) continue;
        for (int j=head[u];~j;j=edge[j].to){
            int v=edge[j].u;
            if (vis[v]){
                v=getfather(v);
                if (v!=u){
                    fa[v]=u;
                    sz[u]+=sz[v];
                }
            }
        }
        vis[u]=1;
        if (sz[u]>1) return min(i,ans);
    }
    return 0;
}
inline int read(){
    int X=0,f=0; char ch=0;
    while(!isdigit(ch)) {f|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return f?-X:X;
}
int main(){
    T=read();
    while (T--){
        n=read(); m=read(); s=read();
        p=n;
        for (int i=1;i<=n;i++) head[i]=-1;
        k=0;
        for (int i=1;i<=m;i++){
            x=read(); y=read();
            add(x,y); add(y,x);
        }
        for (int i=1;i<=s;i++) a[i]=read();
        printf("%d\n",solve());
    }
}