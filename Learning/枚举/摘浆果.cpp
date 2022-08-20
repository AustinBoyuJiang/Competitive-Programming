/*Author：AustinJiang
题目：Berry Picking
时间复杂度：O(maxn*n*log(n))
算法：枚举，贪心 
来源：USACO 2020 January Contest */
#include<bits/stdc++.h>
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
const int N=1e3+10;

int n,k,i,mx,tmp,ans,b[N];

bool cmp(int a,int b){
	return a%i>b%i;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		mx=max(mx,b[i]);
	}
	for(i=1;i<=mx;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)
			cnt+=b[j]/i;
		if(cnt<k/2) break;
		else if(cnt>=k) ans=i*(k/2);
		else{
			sort(b+1,b+n+1,cmp);
			int tmp=(cnt-k/2)*i;
			for(int j=1;j<=n&&j+cnt<=k;j++)
				tmp+=b[j]%i;
			ans=max(ans,tmp);
		}
	}
	cout<<ans<<endl;
	return 0;
}

