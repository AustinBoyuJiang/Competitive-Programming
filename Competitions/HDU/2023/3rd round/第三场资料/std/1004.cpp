#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>PI;
const int N=50005*2;
int Case,n,m,i,t,DX,DY;set<PI>ans,done;
struct P{
  int x,y;
  P(){}
  P(int _x,int _y){x=_x,y=_y;}
  P operator-(const P&b)const{return P(x-b.x,y-b.y);}
}a[N],b[N],q[N],pool[N];
inline ll cross(const P&a,const P&b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
inline bool cmp1(const P&a,const P&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
inline bool cmp2(const P&a,const P&b){return a.x==b.x?a.y>b.y:a.x<b.x;}
inline bool cmpd(const P&a,const P&b){
  if(a.x==b.x)return DY>=0?a.y<b.y:a.y>b.y;
  return DX>=0?a.x<b.x:a.x>b.x;
}
inline void check(int dx,int dy){
  if(done.find(PI(dx,dy))!=done.end())return;
  done.insert(PI(dx,dy));
  done.insert(PI(-dx,-dy));
  map<PI,int>T;
  int i,cnt=0;
  for(i=1;i<=m;i++)T[PI(b[i].x,b[i].y)]++;
  DX=dx,DY=dy;
  sort(b+1,b+m+1,cmpd);
  for(i=1;i<=m;i++){
    int&now=T[PI(b[i].x,b[i].y)];
    if(!now)continue;
    now--;
    cnt++;
    int&nxt=T[PI(b[i].x+dx,b[i].y+dy)];
    if(!nxt)return;
    nxt--;
  }
  if(cnt==n){
    ans.insert(PI(dx,dy));
    ans.insert(PI(-dx,-dy));
  }
}
inline void findline(const P&A,const P&B){
  int i,j,cp=0;
  for(i=1;i<=m;i++)if(!cross(B,a[i]-A))pool[++cp]=a[i];
  for(i=1;i<=cp;i++)for(j=1;j<=cp;j++)check(pool[i].x-pool[j].x,pool[i].y-pool[j].y);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n;
    m=n*2;
    for(i=1;i<=m;i++)cin>>a[i].x>>a[i].y,b[i]=a[i];
    ans.clear();
    done.clear();
    check(0,0);
    sort(a+1,a+m+1,cmp1);
    findline(a[1],P(0,1));
    findline(a[m],P(0,1));
    for(i=1,t=0;i<=m;i++){
      if(i>1&&a[i].x==a[i-1].x)continue;
      while(t>1&&1LL*(q[t].y-q[t-1].y)*(a[i].x-q[t].x)>=1LL*(a[i].y-q[t].y)*(q[t].x-q[t-1].x))t--;
      q[++t]=a[i];
    }
    for(i=1;i<t;i++)findline(q[i],q[i+1]-q[i]);
    sort(a+1,a+m+1,cmp2);
    for(i=1,t=0;i<=m;i++){
      if(i>1&&a[i].x==a[i-1].x)continue;
      while(t>1&&1LL*(q[t].y-q[t-1].y)*(a[i].x-q[t].x)<=1LL*(a[i].y-q[t].y)*(q[t].x-q[t-1].x))t--;
      q[++t]=a[i];
    }
    for(i=1;i<t;i++)findline(q[i],q[i+1]-q[i]);
    cout<<ans.size()<<endl;
    for(set<PI>::iterator it=ans.begin();it!=ans.end();it++)cout<<it->first<<" "<<it->second<<endl;
  }
}