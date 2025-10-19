/*Author：AustinJiang
题目：Keep the Average High
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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
const int N=1e5+10;

int t,a[N],f[N];

void solve(){
	int n,x,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>x;
	for(int i=1;i<=n;i++)
		a[i]-=x;
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		int sum=a[i]+f[i-1];
		f[i]=min(a[i],sum);
		if(sum<0){
			f[i]=a[++i];
			cnt++;
		}
	}
	cout<<n-cnt<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

