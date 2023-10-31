#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
typedef vector<P>V;
const int N=50005,M=131075;
int Case,n,m,i,op,x,y,pos[N];V ans,v[M];
inline void ext(V&nxt,P&now,const P&o){
  if(o.first>now.second+1){
    if(now.second>=0)nxt.push_back(now);
    now=o;
  }else{
    now.second=max(now.second,o.second);
  }
}
inline V push(V v,const P&o){
  for(int i=0;i<v.size();i++){
    v[i].first+=o.first;
    v[i].second+=o.second;
  }
  return v;
}
inline V combine(const V&a,const V&b){
  V nxt;
  int j=0,k=0;
  P now(0,-2);
  while(j<a.size()&&k<b.size())ext(nxt,now,a[j].first<b[k].first?a[j++]:b[k++]);
  while(j<a.size())ext(nxt,now,a[j++]);
  while(k<b.size())ext(nxt,now,b[k++]);
  nxt.push_back(now);
  return nxt;
}
inline V merge(const V&a,const V&b){
  if(!a.size())return b;
  if(!b.size())return a;
  V c=a;
  for(int i=0;i<b.size();i++)c=combine(c,push(a,b[i]));
  return c;
}
inline void init(int x){
  v[x].resize(2);
  v[x][0]=P(0,0);
  cin>>v[x][1].first>>v[x][1].second;
}
void build(int x,int a,int b){
  if(a==b){
    pos[a]=x;
    init(x);
    return;
  }
  int mid=(a+b)>>1;
  build(x<<1,a,mid);
  build(x<<1|1,mid+1,b);
  v[x]=merge(v[x<<1],v[x<<1|1]);
}
inline void change(int x){
  x=pos[x];
  init(x);
  for(x>>=1;x;x>>=1)v[x]=merge(v[x<<1],v[x<<1|1]);
}
void ask(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d){
    ans=merge(ans,v[x]);
    return;
  }
  int mid=(a+b)>>1;
  if(c<=mid)ask(x<<1,a,mid,c,d);
  if(d>mid)ask(x<<1|1,mid+1,b,c,d);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>m;
    build(1,1,n);
    while(m--){
      cin>>op>>x;
      if(op==1)change(x);
      else{
        cin>>y;
        ans.clear();
        ask(1,1,n,x,y);
        ll fin=0;
        for(i=0;i<ans.size();i++)fin+=ans[i].second-ans[i].first+1;
        cout<<fin<<endl;
      }
    }
  }
}