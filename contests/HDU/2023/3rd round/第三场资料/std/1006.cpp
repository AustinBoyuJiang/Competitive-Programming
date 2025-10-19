#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int N=65;
int Case,n,i,j,x,y,g[N],v[N<<1],nxt[N<<1],ed,ans;
ull num[N][2];int val[N][2],f[N][2][2];
struct Item{
  ull num;int val,col;
  Item(){}
  Item(ull _num,int _val,int _col){num=_num,val=_val,col=_col;}
};
namespace Matroid{
const int M=N*2,E=100005,inf=~0U>>1,K=64;
int n,tot,ans,S,T,g[M],v[E],nxt[E],ed,q[E],h,t,d[M],pre[M],w[M],cnt[N];
bool in[M],use[M];
Item item[M];
ull base[K];
inline bool check1(){
  for(int i=0;i<tot;i++)if(cnt[i]>1)return 0;
  return 1;
}
inline bool check2(){
  int i,j;
  for(i=0;i<K;i++)base[i]=0;
  for(i=0;i<n;i++)if(use[i]){
    ull x=item[i].num;
    bool flag=0;
    for(j=0;j<K;j++)if(x>>j&1){
      if(!base[j]){
        base[j]=x;
        flag=1;
        break;
      }else x^=base[j];
    }
    if(!flag)return 0;
  }
  return 1;
}
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
inline void ext(int x,int y,int z){
  if(d[x]>=y)return;
  d[x]=y;
  pre[x]=z;
  if(in[x])return;
  q[++t]=x;
  in[x]=1;
}
inline bool find(){
  int i,j,S=n+1,T=n+2;
  for(ed=i=0;i<=T;i++)g[i]=w[i]=0;
  for(i=0;i<n;i++)if(!use[i]){
    w[i]=item[i].val;
    use[i]^=1;
    cnt[item[i].col]++;
    if(check1())add(S,i);
    if(check2())add(i,T);
    cnt[item[i].col]--;
    use[i]^=1;
  }else w[i]=-item[i].val;
  for(i=0;i<n;i++)if(use[i])for(j=0;j<n;j++)if(!use[j]){
    use[i]^=1,use[j]^=1;
    cnt[item[i].col]--;cnt[item[j].col]++;
    if(check1())add(i,j);
    if(check2())add(j,i);
    cnt[item[i].col]++;cnt[item[j].col]--;
    use[i]^=1,use[j]^=1;
  }
  for(i=0;i<=T;i++)d[i]=-inf,in[i]=0;
  q[h=t=1]=S;
  d[S]=0,in[S]=1;
  while(h<=t){
    int x=q[h++];
    for(i=g[x];i;i=nxt[i])ext(v[i],d[x]+w[v[i]],x);
    in[x]=0;
  }
  if(d[T]==-inf)return 0;
  ans+=d[T];
  while(pre[T]!=S){
    T=pre[T];
    if(use[T])cnt[item[T].col]--;else cnt[item[T].col]++;
    use[T]^=1;
  }
  return 1;
}
inline int intersection(const vector<Item>&pool,int _tot){
  int i;
  n=ans=0;
  tot=_tot;
  for(i=0;i<pool.size();i++)if(pool[i].val>=0)item[n++]=pool[i];
  for(i=0;i<tot;i++)cnt[i]=0;
  for(i=0;i<n;i++)use[i]=0;
  for(i=0;i<tot;i++)if(!find())return -1;
  return ans;
}
}
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x,int y){
  for(int i=g[x];i;i=nxt[i]){
    int u=v[i];
    if(u==y)continue;
    dfs(u,x);
  }
  for(int now=0;now<2;now++){
    int tot=0;
    vector<Item>pool;
    for(int i=g[x];i;i=nxt[i]){
      int u=v[i];
      if(u==y)continue;
      for(int j=0;j<2;j++)pool.push_back(Item(num[u][j],f[u][j][now],tot));
      tot++;
    }
    pool.push_back(Item(num[x][now],val[x][now],tot));
    tot++;
    if(y){
      for(int fa=0;fa<2;fa++){
        vector<Item>npool=pool;
        npool.push_back(Item(num[y][fa],0,tot));
        f[x][now][fa]=Matroid::intersection(npool,tot+1);
      }
    }else{
      ans=max(ans,Matroid::intersection(pool,tot));
    }
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    ans=-1;
    for(ed=i=0;i<=n;i++)g[i]=0;
    for(i=1;i<=n;i++)for(j=0;j<2;j++)scanf("%llu%d",&num[i][j],&val[i][j]);
    for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,0);
    printf("%d\n",ans);
  }
}