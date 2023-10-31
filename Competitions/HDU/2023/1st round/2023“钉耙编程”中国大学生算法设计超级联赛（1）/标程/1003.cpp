#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 105
#define N 505
#define INF 100000000000000
using namespace std;
long long dp[M][M][N];
int val[M],A[M];
int n,max_level,K,P;
long long Base[N];
long long Get_val(int x){
	int level=(x-1)/K,Kind=(x-1)%K+1;
	return 1ll*Base[level]*val[Kind];
}
long long Solve(int L,int R,int p){
	if(L>R){
		if(p==0)return 0;
		return -INF;
	}
	if(L==R){
		if(p==0)return val[A[L]];
		if(p==A[L])return 0;
		return -INF;
	}
	if(dp[L][R][p]!=-1)return dp[L][R][p];
	long long res=-INF;
	if(p==0){
		for(int mid=L;mid<R;mid++){
			if(Solve(L,mid,0)!=-INF&&Solve(mid+1,R,0)!=-INF)res=max(res,Solve(L,mid,0)+Solve(mid+1,R,0));
		}
		for(int i=1;i<=max_level*K;i++){
			long long tmp=Solve(L,R,i);
			if(tmp==-INF)continue;
			res=max(res,tmp+Get_val(i));
		}
	}else if(p<=K){
		for(int i=L;i<=R;i++){
			if(A[i]==p){
				if(Solve(L,i-1,0)!=-INF&&Solve(i+1,R,0)!=-INF)res=max(res,Solve(L,i-1,0)+Solve(i+1,R,0));
			}
		}
	}else{
		for(int i=L;i<R;i++){
			if(Solve(L,i,p-K)!=-INF&&Solve(i+1,R,p-K)!=-INF){
				res=max(res,Solve(L,i,p-K)+Solve(i+1,R,p-K));
			}
		}
	}
	dp[L][R][p]=res;
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	Base[0]=1;
	while(T--){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d%d",&n,&K,&max_level,&P);
		for(int i=1;i<=max_level;i++)Base[i]=1ll*Base[i-1]*P;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=K;i++)scanf("%d",&val[i]);
		printf("%lld\n",Solve(1,n,0));
	}
	return 0;
}
