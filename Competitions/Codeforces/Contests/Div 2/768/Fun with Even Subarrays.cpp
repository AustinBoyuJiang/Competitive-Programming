/*Author：AustinJiang
题目：Fun with Even Subarrays
时间复杂度：O(t*n)
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
const int N=1e5+10;

int t,n,a[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=1;i<n;i++){
		if(a[n-i]!=a[n]){
			i*=2;
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

