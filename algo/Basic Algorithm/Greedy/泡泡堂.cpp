/*Author：AustinJiang
题目：泡泡堂 
时间复杂度：O(n*log(n))
算法：贪心 
来源：各省省选 */
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

int n,a[N],b[N];

int solve(){
	int i=1,j=1,k=n,l=n,ans=0;
	while(i<=k){
		if(a[i]>b[j]) i++,j++,ans+=2;
		else if(a[k]>b[l]) k--,l--,ans+=2;
		else ans+=a[i++]==b[l--];
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<solve()<<' ';
	swap(a,b);
	cout<<n*2-solve()<<endl;
	return 0;
}

