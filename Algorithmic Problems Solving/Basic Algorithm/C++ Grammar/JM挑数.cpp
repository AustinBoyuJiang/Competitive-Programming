/*Author：AustinJiang
题目：JM挑数
时间复杂度：O(n) */
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

int n,a[N],mx[N],mn[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		mx[i]=max(mx[i-1],a[i]);
	mn[n+1]=INF;
	for(int i=n;i>1;i--)
		mn[i]=min(mn[i+1],a[i]);
	for(int i=2;i<n;i++){
		if(mx[i-1]<a[i]&&a[i]<mn[i+1]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}

