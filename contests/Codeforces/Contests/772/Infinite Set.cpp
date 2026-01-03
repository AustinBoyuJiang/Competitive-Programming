/*Author：AustinJiang
题目：Infinite Set
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=2e5+10;
const int MOD=1e9+7;

int n,p,ans,a[N],sum[N];
map<int,bool> flag;

bool check(int x){
	while(x){
		if(flag[x]) return 0;
		if(x%4==0) x>>=2;
		else if(x&1) x>>=1;
		else break;
	}
	if(flag[x]) return 0;
	else return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	sum[0]=1,sum[1]=1;
	for(int i=2;i<=p;i++)
		sum[i]=(sum[i-1]+sum[i-2])%MOD;
	for(int i=1;i<=p;i++)
		sum[i]=(sum[i]+sum[i-1])%MOD;
	for(int i=1;i<=n;i++){
		if(!check(a[i])) continue;
		flag[a[i]]=1;
		if(p-(int)log2(a[i])-1>=0)
			ans=(ans+sum[p-(int)log2(a[i])-1])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}

