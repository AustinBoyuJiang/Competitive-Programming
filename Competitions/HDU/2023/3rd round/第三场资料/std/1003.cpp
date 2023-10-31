#include<cstdio>
typedef unsigned long long ull;
const int N=55,M=N*N,K=5;
int Case,n,m,k,i,j,x,y,id[N][N],u[M],v[M],keep[M],mark[M],preg[N],preh[N],pool[K][N*2];
ull ans,g[N],h[N],full,C[M][K];
inline void flip(int o){
  int x=u[o],y=v[o];
  g[x]^=1ULL<<y;
  h[y]^=1ULL<<x;
}
inline bool bfs(ull*g,int*pre){
  ull mask=full^1;
  int h=1,t=1;
  static int q[N];
  q[1]=0;
  while(h<=t){
    int x=q[h++];
    for(ull S=mask&g[x];S;S-=S&-S){
      mask^=S&-S;
      int y=__builtin_ctzll(S&-S);
      pre[y]=x;
      q[++t]=y;
    }
  }
  return t==n;
}
inline void ext(int x,int*pool,int&cp){
  if(mark[x])return;
  mark[x]=1;
  pool[cp++]=x;
}
void solve(int k,int m){
  if(!bfs(g,preg)||!bfs(h,preh)){
    ans+=C[m][k];
    return;
  }
  if(!k)return;
  int i,cp=0;
  for(i=1;i<n;i++){
    ext(id[preg[i]][i],pool[k],cp);
    ext(id[i][preh[i]],pool[k],cp);
  }
  for(i=0;i<cp;i++)mark[pool[k][i]]=0;
  for(i=0;i<cp;i++){
    int o=pool[k][i];
    if(keep[o])continue;
    m--;
    flip(o);
    solve(k-1,m);
    flip(o);
    keep[o]=k;
  }
  for(i=0;i<cp;i++)if(keep[pool[k][i]]==k)keep[pool[k][i]]=0;
}
int main(){
  for(C[0][0]=i=1;i<M;i++)for(C[i][0]=j=1;j<K;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    k=3;
    for(i=0;i<n;i++)g[i]=h[i]=0;
    for(i=0;i<m;i++){
      scanf("%d%d",&x,&y);
      x--,y--;
      id[x][y]=i;
      u[i]=x,v[i]=y;
      flip(i);
    }
    full=(1ULL<<n)-1;
    ans=0;
    solve(k,m);
    printf("%llu\n",ans);
  }
}