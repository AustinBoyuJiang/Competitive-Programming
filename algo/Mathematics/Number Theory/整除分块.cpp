/*Author：AustinJiang
题目：整除分块 
时间复杂度：O(n^0.5)
算法：数论 */
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
const int N=1e5+10;

int n,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans+=(r-l+1)*(n/l);
	}
	cout<<ans<<endl;
	return 0;
}

