/*Author：AustinJiang
题目：Air Cownditioning
时间复杂度：O(n)
算法：差分 
来源：USACO 2022 Bronze */
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

int n,ans,a[N],b[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]-=a[i];
	}
	for(int i=0;i<=n;i++)
		ans+=abs(b[i]-b[i+1]);
	cout<<ans/2<<endl;
	return 0;
}

