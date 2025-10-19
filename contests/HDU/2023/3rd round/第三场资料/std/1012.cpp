#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
typedef vector<ll>V;
const int N=50005;
int Case,n,q,i,x,cnt,ce,ans[N];ll A,B;
struct E{V s;int t;}e[N*3];
inline int compare(const V&a,const V&b){
  int n=a.size(),m=b.size(),i;
  if(a[0]!=b[0])return a[0]<b[0]?-1:1;
  for(i=1;i<n&&i<m;i+=2){
    if(a[i]!=b[i])return a[i]<b[i]?-1:1;
    if(!a[i])return 0;
    if(a[i+1]<b[i+1]){
      if(i+2>=n)return -1;
      return a[i+2]<b[i]?-1:1;
    }
    if(a[i+1]>b[i+1]){
      if(i+2>=m)return 1;
      return a[i]<b[i+2]?-1:1;
    }
  }
  if(i<n)return 1;
  if(i<m)return -1;
  return 0;
}
inline bool cmp(const E&a,const E&b){
  int sgn=compare(a.s,b.s);
  if(sgn)return sgn<0;
  return a.t<b.t;
}
inline P decode(const V&s){
  P ret(s[0],s[0]);
  for(int i=1;i+1<s.size();i+=2){
    if(s[i]==-1)ret.first+=ret.second*s[i+1];
    else ret.second+=ret.first*s[i+1];
  }
  return ret;
}
inline V zip(P p){
  V s;
  while(1){
    if(p.first==p.second)break;
    if(p.first>p.second){
      ll old=p.first;
      p.first%=p.second;
      if(!p.first)p.first=p.second;
      s.push_back((old-p.first)/p.second);
      s.push_back(-1);
    }else{
      ll old=p.second;
      p.second%=p.first;
      if(!p.second)p.second=p.first;
      s.push_back((old-p.second)/p.first);
      s.push_back(-2);
    }
  }
  s.push_back(p.first);
  reverse(s.begin(),s.end());
  return s;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>q;
    ce=0;
    for(i=1;i<=n;i++){
      cin>>A>>B;
      e[++ce].t=0;
      e[ce].s=zip(P(A,B));
    }
    for(i=1;i<=q;i++){
      ans[i]=0;
      cin>>A>>B;
      V s=zip(P(A,B));
      e[++ce].t=-i;
      e[ce].s=s;
      e[++ce].t=i;
      s.push_back(0);
      e[ce].s=s;
    }
    sort(e+1,e+ce+1,cmp);
    cnt=0;
    for(i=1;i<=ce;i++){
      x=e[i].t;
      if(!x)cnt++;
      if(x>0)ans[x]+=cnt;
      if(x<0)ans[-x]-=cnt;
    }
    for(i=1;i<=q;i++)cout<<ans[i]<<endl;
  }
}