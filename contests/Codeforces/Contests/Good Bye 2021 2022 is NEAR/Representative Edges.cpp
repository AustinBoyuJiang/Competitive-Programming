/*Author：AustinJiang
题目：Representative Edges
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
const int N=100;

int t,n,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int ans=INF;
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					double x=a[i];
					double y=(double)a[l]-(double)(a[r]-a[l])/(r-l)*(l-i);
					if(fabs(x-y)>1e-9){
						cnt++;
					}
				}
				ans=min(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

