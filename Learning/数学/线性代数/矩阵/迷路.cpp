/*Author: AustinJiang
题目: 迷路
时间复杂度: O(n*n*n*log(t))
算法: 矩阵，快速幂*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define for(i,n) for(int i=1;i<=n;i++)
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=INT_MAX;
const int N=11;
const int M=110;
const int MOD=2009;

int n,m,t,pos[N],len[N],e[N][N],flag[M][M],ans[M][M];

void muti(int a[M][M],int b[M][M]){
	int tmp[M][M];
	memset(tmp,0,sizeof(tmp));
	for(i,m) for(j,m) for(k,m)
		tmp[i][j]+=a[i][k]*b[k][j],tmp[i][j]%=MOD;
	for(i,m) for(j,m)
		a[i][j]=tmp[i][j];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(i,n){
		string str;
		cin>>str;
		for(j,n){
			e[i][j]=str[j-1]-'0';
			len[i]=max(len[i],e[i][j]-1);
		}
		pos[i]=pos[i-1]+len[i-1]+1;
	}
	for(i,n){
		for(j,n)
			flag[pos[i]+e[i][j]-1][pos[j]]|=e[i][j]>0;
		for(j,len[i])
			flag[pos[i]+j-1][pos[i]+j]=1;
	}
	m=pos[n]+len[n];
	for(i,m)
		ans[i][i]=1; 
	while(t){
		if(t%2) muti(ans,flag);
		muti(flag,flag);
		t/=2;
	}
	cout<<ans[1][pos[n]]<<endl;
	return 0;
}
