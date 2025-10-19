#include<iostream>
#include<algorithm>
using namespace std;
const int N=50005,M=200005,K=N+M;
int Case,n,q,i,ok[M],e[M][4],at[M],bit[M];
int f[K],son[K][2],val[K],mx[K],tmp[K];bool rev[K];
inline bool isroot(int x){return !f[x]||son[f[x]][0]!=x&&son[f[x]][1]!=x;}
inline void rev1(int x){if(!x)return;swap(son[x][0],son[x][1]);rev[x]^=1;}
inline void pb(int x){if(rev[x])rev1(son[x][0]),rev1(son[x][1]),rev[x]=0;}
inline void umax(int&a,int b){a<b?(a=b):0;}
inline void up(int x){
  mx[x]=val[x];
  if(son[x][0])umax(mx[x],mx[son[x][0]]);
  if(son[x][1])umax(mx[x],mx[son[x][1]]);
}
inline void rotate(int x){
  int y=f[x],w=son[y][1]==x;
  son[y][w]=son[x][w^1];
  if(son[x][w^1])f[son[x][w^1]]=y;
  if(f[y]){
    int z=f[y];
    if(son[z][0]==y)son[z][0]=x;else if(son[z][1]==y)son[z][1]=x;
  }
  f[x]=f[y];f[y]=x;son[x][w^1]=y;up(y);
}
inline void splay(int x){
  int s=1,i=x,y;tmp[1]=i;
  while(!isroot(i))tmp[++s]=i=f[i];
  while(s)pb(tmp[s--]);
  while(!isroot(x)){
    y=f[x];
    if(!isroot(y)){if((son[f[y]][0]==y)^(son[y][0]==x))rotate(x);else rotate(y);}
    rotate(x);
  }
  up(x);
}
inline void access(int x){for(int y=0;x;y=x,x=f[x])splay(x),son[x][1]=y,up(x);}
inline int root(int x){access(x);splay(x);while(son[x][0])x=son[x][0];splay(x);return x;}
inline void makeroot(int x){access(x);splay(x);rev1(x);}
inline void link(int x,int y){makeroot(x);f[x]=y;access(x);}
inline void cutf(int x){access(x);splay(x);f[son[x][0]]=0;son[x][0]=0;up(x);}
inline void cut(int x,int y){makeroot(x);cutf(y);}
inline int ask(int x,int y){makeroot(x);access(y);splay(y);return mx[y];}
inline void modify(int x,int p){for(;x<=q;x+=x&-x)bit[x]+=p;}
inline int getsum(int x){int t=0;for(;x;x-=x&-x)t+=bit[x];return t;}
inline void solve(){
  for(i=1;i<=q;i++)bit[i]=at[i]=0;
  for(i=1;i<=n+q;i++){
    f[i]=0;
    son[i][0]=son[i][1]=0;
    val[i]=mx[i]=0;
    rev[i]=0;
  }
  for(i=1;i<=q;i++)if(e[i][0]==1){
    at[e[i][3]]=i;
    val[n+i]=mx[n+i]=e[i][3];
  }
  int cnt=n-1;
  for(i=1;i<=q;i++)if(e[i][0]==1){
    int x=e[i][1],y=e[i][2],z=e[i][3];
    if(root(x)==root(y)){
      int o=ask(x,y);
      if(z>o)continue;
      o=at[o];
      cut(n+o,e[o][1]);
      cut(n+o,e[o][2]);
      modify(e[o][3],-1);
    }else cnt--;
    link(n+i,x);
    link(n+i,y);
    modify(z,1);
  }else if(!cnt&&at[e[i][2]]&&at[e[i][2]]<=i&&getsum(e[i][2])>=e[i][1])ok[i]++;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>q;
    for(i=1;i<=q;i++){
      cin>>e[i][0]>>e[i][1]>>e[i][2];
      if(e[i][0]==1)cin>>e[i][3];else ok[i]=0;
    }
    solve();
    for(i=1;i<=q;i++)if(e[i][0]==1)e[i][3]=q-e[i][3]+1;
    else{
      e[i][1]=n-e[i][1];
      e[i][2]=q-e[i][2]+1;
    }
    solve();
    for(i=1;i<=q;i++)if(e[i][0]==2)cout<<(ok[i]==2?"YES":"NO")<<endl;
  }
}