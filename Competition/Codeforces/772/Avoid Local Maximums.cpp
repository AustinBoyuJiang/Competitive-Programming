/*Author：AustinJiang
题目：Avoid Local Maximums
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=2e5+10;

int t,n,a[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=0;
	int cnt=0;
	for(int i=2;i<n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			cnt++;
			a[i+1]=max(a[i],a[i+2]);
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
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

