#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int>V;
typedef pair<int,V>P;
typedef long long ll;
const int N=55;
map<P,int>pre,nxt;
int Case,n,m,q,i,j,k,l,r,diff,x,cur,cnt[N],tmp[N];
vector<vector<int> >g[N];
vector<ll>f[N];
ll ans[N*2][N*2];
char s[N];
struct E{
  int a,b;
  void init(int sum,int diff){
    a=(sum+diff)/2;
    b=(sum-diff)/2;
  }
};
vector<E>e[N];
void prework(int n){
  V v;
  pre[P(0,v)]=1;
  cnt[0]=1;
  for(i=1;i<=n;i++){
    g[i-1].resize(cnt[i-1]);
    for(j=0;j<cnt[i-1];j++)g[i-1][j].resize(2);
    nxt.clear();
    cur=0;
    for(map<P,int>::iterator it=pre.begin();it!=pre.end();it++){
      for(j=1;j<=2;j++){
        m=it->first.second.size();
        for(k=0;k<m;k++)tmp[k]=it->first.second[k];
        tmp[m++]=j;
        while(m>=3&&tmp[m-3]<=tmp[m-2]&&tmp[m-2]>=tmp[m-1]){
          tmp[m-3]+=tmp[m-1]-tmp[m-2];
          m-=2;
        }
        V now(m);
        for(k=0;k<m;k++)now[k]=tmp[k];
        int&to=nxt[P(it->first.first+j,now)];
        if(!to)to=++cur;
        g[i-1][it->second-1][j-1]=to-1;
      }
    }
    swap(pre,nxt);
    cnt[i]=cur;
    e[i].resize(cur);
    for(map<P,int>::iterator it=pre.begin();it!=pre.end();it++){
      m=it->first.second.size();
      for(k=0;k<m;k++)tmp[k]=it->first.second[k];
      j=0,k=m-1,x=1,diff=0;
      while(j<=k){
        if(tmp[j]>tmp[k])diff+=x*tmp[j++];
        else diff+=x*tmp[k--];
        x*=-1;
      }
      e[i][it->second-1].init(it->first.first,diff);
    }
  }
  for(i=0;i<=n;i++)f[i].resize(cnt[i]);
}
int main(){
  prework(50);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n>>q>>s;
    for(i=0;i<=n;i++)for(j=0;j<cnt[i];j++)f[i][j]=0;
    f[0][0]=1;
    for(i=0;i<n;i++){
      l=0,r=1;
      if(s[i]=='1')r=0;
      if(s[i]=='2')l=1;
      for(j=0;j<cnt[i];j++)if(f[i][j])for(k=l;k<=r;k++)f[i+1][g[i][j][k]]+=f[i][j];
    }
    for(i=0;i<=n*2;i++)for(j=0;j<=n*2;j++)ans[i][j]=0;
    for(i=0;i<cnt[n];i++)ans[e[n][i].a][e[n][i].b]+=f[n][i];
    while(q--)cin>>i>>j,cout<<ans[i][j]<<endl;
  }
}