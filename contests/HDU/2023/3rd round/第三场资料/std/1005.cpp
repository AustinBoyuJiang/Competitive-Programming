#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3005,P=1000000007;
int Case,n,m,i,j,sum,ans,a[N],b[N],f[N];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for(m=0,i=1;i<=n;i++)if(i==1||b[i]>b[i-1])b[++m]=b[i];
    for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    sort(a+1,a+n+1);
    for(i=1;i<=m;i++)f[i]=1;
    printf("%d\n",m);
    for(i=2;i<=n;i++){
      sum=ans=0;
      for(j=a[i-1];j<a[i];j++)up(sum,f[j]);
      for(j=a[i];j<=m;j++){
        up(sum,f[j]);
        f[j]=sum;
        up(ans,sum);
      }
      printf("%d\n",ans);
    }
  }
}