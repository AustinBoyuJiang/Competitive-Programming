/*Author：AustinJiang
题目：Convoluted Intervals
时间复杂度：O(m^2)
算法：前缀和，枚举，计数 
来源：USACO 2022 December Silver */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e4+10;

int n,m,a[N],b[N],sum[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		a[x]++;
		b[y]++;
	}
	for(int i=0;i<=2*m;i++){
		for(int j=0;j<=i;j++){
			sum[i]+=a[j]*a[i-j];
			sum[i+1]-=b[j]*b[i-j];
		}
	}
	for(int i=1;i<=2*m;i++)
		sum[i]+=sum[i-1];
	for(int i=0;i<=2*m;i++)
		cout<<sum[i]<<endl;
	return 0;
}

