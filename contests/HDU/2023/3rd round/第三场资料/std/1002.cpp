#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int N=50005,BATCH=23,D=5;
int Case,n,m,i,j,k,o,st[N],en[N],x[N][D],w[N],f[N],now,mx[BATCH*4][65537];
ull who[D][N][BATCH];
inline void up(int&a,int b){a<b?(a=b):0;}
inline void flip(ull*f,int x){f[x>>6]^=1ULL<<(x&63);}
inline bool check(int*a,int*b){
  for(int i=0;i<D;i++)if(a[i]>b[i])return 0;
  return 1;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>Case;
  while(Case--){
    cin>>n;
    for(i=0;i<n;i++){
      for(j=0;j<D;j++)cin>>x[i][j];
      cin>>w[i];
      f[i]=0;
    }
    for(i=0;i<n;i++)en[i>>6]=i;
    for(i=n-1;~i;i--)st[i>>6]=i;
    m=(n-1)>>6;
    int L,R;
    for(L=0;L<=m;L=R+1){
      R=min(L+BATCH-1,m);
      for(i=0;i<BATCH*4;i++)for(j=0;j<65536;j++)mx[i][j]=0;
      for(i=1;i<=n;i++)for(j=0;j<BATCH;j++){
        who[0][i][j]=0;
        who[1][i][j]=0;
        who[2][i][j]=0;
        who[3][i][j]=0;
        who[4][i][j]=0;
      }
      int ST=st[L],EN=en[R];
      for(i=ST;i<=EN;i++){
        o=i-ST;
        for(j=0;j<D;j++)flip(who[j][x[i][j]],o);
      }
      for(i=2;i<=n;i++)for(j=0;j<BATCH;j++){
        who[0][i][j]|=who[0][i-1][j];
        who[1][i][j]|=who[1][i-1][j];
        who[2][i][j]|=who[2][i-1][j];
        who[3][i][j]|=who[3][i-1][j];
        who[4][i][j]|=who[4][i-1][j];
      }
      for(i=L;i<=m;i++){
        int _ST=st[i],_EN=en[i];
        if(i>L){
          int lim=min(BATCH,i-L);
          for(j=_ST;j<=_EN;j++){
            now=f[j];
            int A=x[j][0],B=x[j][1],C=x[j][2],D=x[j][3],E=x[j][4];
            for(k=0;k<lim;k++){
              ull S=who[0][A][k]&who[1][B][k]&who[2][C][k]&who[3][D][k]&who[4][E][k];
              up(now,mx[k<<2][S&65535]);
              up(now,mx[(k<<2)+1][(S>>16)&65535]);
              up(now,mx[(k<<2)+2][(S>>32)&65535]);
              up(now,mx[(k<<2)+3][S>>48]);
            }
            f[j]=now;
          }
        }
        if(i<=R){
          for(j=_ST;j<=_EN;j++){
            now=f[j];
            for(k=_ST;k<j;k++)if(now<f[k]&&check(x[k],x[j]))now=f[k];
            now+=w[j];
            f[j]=now;
            o=j-ST;
            mx[o>>4][1<<(o&15)]=now;
          }
          o=(i-L)<<2;
          for(j=1;j<65536;j++){
            mx[o][j]=max(mx[o][j&-j],mx[o][j-(j&-j)]);
            mx[o+1][j]=max(mx[o+1][j&-j],mx[o+1][j-(j&-j)]);
            mx[o+2][j]=max(mx[o+2][j&-j],mx[o+2][j-(j&-j)]);
            mx[o+3][j]=max(mx[o+3][j&-j],mx[o+3][j-(j&-j)]);
          }
        }
      }
    }
    for(i=0;i<n;i++)cout<<f[i]<<endl;
  }
}