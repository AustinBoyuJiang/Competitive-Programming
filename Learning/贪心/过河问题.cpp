/*Author：AustinJiang
题目：过河问题 
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

int n,ans,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(n>3){
		ans+=min(a[1]+a[2]*2+a[n],a[1]*2+a[n-1]+a[n]);
		n-=2;
	}
	if(n==2) ans+=a[2];
	else ans+=a[1]+a[2]+a[3];
	cout<<ans<<endl;
	return 0;
}

