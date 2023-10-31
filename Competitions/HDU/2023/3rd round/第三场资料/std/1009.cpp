#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005,K=3,inf=~0U>>1;
int Case,n,i,j,mi,ma,l,r,mid,ans;
int cnt,t,q[N*2],f[N*2];bool vis[N*2];
int e[N*2][K];
struct DS{
  int q[N*2],h,t,d;
  int get(int val){
    if(h<=t){
      int x=q[h];
      if(e[x][d]<val-mid){
        h++;
        return x;
      }
    }
    if(h<=t){
      int x=q[t];
      if(e[x][d]>val+mid){
        t--;
        return x;
      }
    }
    return 0;
  }
  void reset(){h=1,t=n+n;}
}T[K];
inline bool cmp(int x,int y){return e[x][j]<e[y][j];}
void dfs0(int x){
  if(vis[x])return;
  vis[x]=1;
  for(int d=0;d<K;d++)while(1){
    int y=T[d].get(e[x][d]);
    if(!y)break;
    dfs0(y<=n?y+n:y-n);
  }
  q[++t]=x;
}
void dfs1(int x){
  if(!vis[x])return;
  vis[x]=0,f[x]=cnt;
  for(int d=0;d<K;d++)while(1){
    int y=T[d].get(e[x<=n?x+n:x-n][d]);
    if(!y)break;
    dfs1(y);
  }
}
inline bool check(){
  for(t=cnt=0,i=1;i<=n+n;i++)vis[i]=0;
  for(i=0;i<K;i++)T[i].reset();
  for(i=1;i<=n+n;i++)if(!vis[i])dfs0(i);
  for(i=0;i<K;i++)T[i].reset();
  for(i=t;i;i--)if(vis[q[i]])cnt++,dfs1(q[i]);
  for(i=1;i<=n;i++)if(f[i]==f[i+n])return 0;
  return 1;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n;
    for(i=1;i<=n;i++){
      for(j=0;j<K;j++)cin>>e[i][j];
      for(j=0;j<K;j++)cin>>e[i+n][j];
    }
    mi=inf,ma=-inf;
    for(i=1;i<=n+n;i++)for(j=0;j<K;j++){
      mi=min(mi,e[i][j]);
      ma=max(ma,e[i][j]);
    }
    for(j=0;j<K;j++){
      for(i=1;i<=n+n;i++)T[j].q[i]=i;
      T[j].h=1,T[j].t=n+n,T[j].d=j;
      sort(T[j].q+1,T[j].q+n+n+1,cmp);
    }
    l=0,r=ma-mi;
    while(l<=r){
      mid=(l+r)>>1;
      if(check())r=(ans=mid)-1;else l=mid+1;
    }
    cout<<ans<<endl;
  }
}