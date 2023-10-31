#include<cstdio>
const int N=55;
int Case,n,rate;char a[N][N],b[N*8][N*8];
bool check(){
  rate/=25;
  if(n*rate%4)return 0;
  int m=n*rate;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    int xl=i*rate,xr=xl+rate;
    int yl=j*rate,yr=yl+rate;
    char w=a[i][j];
    for(int A=xl;A<xr;A++)for(int B=yl;B<yr;B++)b[A][B]=w;
  }
  for(int i=0;i<m;i+=4)for(int j=0;j<m;j+=4){
    char w=b[i][j];
    for(int A=i;A<i+4;A++)for(int B=j;B<j+4;B++)if(b[A][B]!=w)return 0;
  }
  for(int i=0;i<m;i+=4){
    for(int j=0;j<m;j+=4)putchar(b[i][j]);
    puts("");
  }
  return 1;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&rate);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    if(!check())puts("error");
  }
}