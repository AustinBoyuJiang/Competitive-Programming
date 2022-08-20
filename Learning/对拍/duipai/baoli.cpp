/*Author：AustinJiang
题目：
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
const int N=3e5+10;

int n,ans,a[N];

signed main(){
//	freopen("data.txt","r",stdin);
//	freopen("baoli.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int mn=0;
		for(int j=i+1;j<=n;j++){
			if(mn<min(a[i],a[j])) ans+=j-i+1;
			mn=max(mn,a[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

