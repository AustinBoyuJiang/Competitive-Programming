#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200005,M=524305,Q=200005;
int Case,n,q,start,i,j,x,y,g[N],w[Q],nxt[Q];ll ans[Q];
int a[N],d[N],l[N],r[N],pool[N];
int L,R;ll base;bool no;
int cnt[M];ll sum[M];
void build(int x,int a,int b){
  cnt[x]=sum[x]=0;
  if(a==b)return;
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void ins(int o){
  int c=lower_bound(pool+1,pool+n+1,o)-pool;
  int x=1,a=1,b=n,mid;
  while(1){
    cnt[x]++;
    sum[x]+=o;
    if(a==b)return;
    mid=(a+b)>>1;
    x<<=1;
    if(c<=mid)b=mid;else a=mid+1,x++;
  }
}
inline int delmin(){
  int x=1,a=1,b=n,mid;
  while(a<b){
    mid=(a+b)>>1;
    x<<=1;
    if(cnt[x])b=mid;else a=mid+1,x++;
  }
  int o=pool[a];
  for(;x;x>>=1)cnt[x]--,sum[x]-=o;
  return o;
}
inline void delmax(){
  int x=1,a=1,b=n,mid;
  while(a<b){
    mid=(a+b)>>1;
    x=x<<1|1;
    if(cnt[x])a=mid+1;else b=mid,x--;
  }
  int o=pool[a];
  for(;x;x>>=1)cnt[x]--,sum[x]-=o;
}
inline void adjust(int l,int r){
  while(L<R){
    if(l<=L&&L<=r)break;
    base+=delmin();
    L+=2;
  }
  while(L<R){
    if(l<=R&&R<=r)break;
    delmax();
    R-=2;
  }
  if(L==R&&L<l||L>r)no=1;
}
inline ll getsum(int k){
  int x=1,a=1,b=n,mid,t;ll ret=0;
  while(a<b){
    mid=(a+b)>>1;
    x<<=1;
    t=cnt[x];
    if(k<=t)b=mid;
    else{
      k-=t;
      ret+=sum[x];
      a=mid+1;
      x++;
    }
  }
  return ret+1LL*k*pool[a];
}
inline ll ask(int x){
  if(no||x<L||x>R||((x-L)&1))return -1;
  if(x==L)return base;
  return base+getsum((x-L)>>1);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>q>>start;
    for(i=1;i<=n;i++){
      cin>>x>>y>>l[i]>>r[i];
      a[i]=x,d[i]=pool[i]=y-x;
    }
    for(i=1;i<=n;i++)g[i]=0;
    for(i=1;i<=q;i++){
      cin>>x>>y;
      w[i]=y;
      nxt[i]=g[x];
      g[x]=i;
    }
    sort(pool+1,pool+n+1);
    build(1,1,n);
    L=R=start;
    base=0;
    no=0;
    for(i=1;i<=n;i++){
      if(!no){
        base+=a[i];
        ins(d[i]);
        L--,R++;
        adjust(l[i],r[i]);
      }
      for(j=g[i];j;j=nxt[j])ans[j]=ask(w[j]);
    }
    for(i=1;i<=q;i++)cout<<ans[i]<<endl;
  }
}