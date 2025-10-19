#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1000005
#define INF 100000000000000
using namespace std;
struct E{
	int to,nx;
}edge[M<<1];
int tot,head[M];
void Addedge(int a,int b){
	edge[++tot].to=b;
	edge[tot].nx=head[a];
	head[a]=tot;
}
long long dp[M][3];
int fa[M];
int A[M];
inline void Add(long long &x,long long y){
	x+=y;
	if(x>=INF)x=INF;
}
void dfs(int now){
	dp[now][0]=dp[now][1]=dp[now][2]=0;
	dp[now][1]=A[now];dp[now][2]=INF;
	for(int i=head[now];i;i=edge[i].nx){
		int nxt=edge[i].to;
		if(nxt==fa[now])continue;
		fa[nxt]=now;
		dfs(nxt);
		dp[now][2]=min(dp[now][2]+min(dp[nxt][1],dp[nxt][2]),dp[now][0]+dp[nxt][1]);
		Add(dp[now][1],min(dp[nxt][0],min(dp[nxt][1],dp[nxt][2])));
		Add(dp[now][0],dp[nxt][2]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(head,0,sizeof(head));
		tot=0;for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Addedge(a,b);
			Addedge(b,a);
		}
		dfs(1);
		long long ans=min(dp[1][1],dp[1][2]);
		printf("%lld\n",ans);
	}
	return 0;
}
