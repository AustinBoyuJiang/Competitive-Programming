/*Author：AustinJiang
题目：Integer Diversity
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

int t,n,cnt[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			cnt[abs(x)]++;
		}
		for(int i=1;i<=100;i++)
			ans+=min(2,cnt[i]);
		ans+=min(1,cnt[0]);
		cout<<ans<<endl;
	}
	return 0;
}

