/*Author：AustinJiang
题目：内卷 
时间复杂度：O(n*log(n))
算法：优先队列，贪心 
来源：jmcoding */
#pragma GCC optimize(2)
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

int n,sum,ans,a[N];
PQ<int,VI,less<int>> q1,q2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%n){
		cout<<-1<<endl;
		return 0;
	}
	int k=sum/n;
	for(int i=1;i<=n;i++){
		if(a[i]>k) q1.push(a[i]-k);
		if(a[i]<k) q2.push(k-a[i]);
	}
	while(!q1.empty()&&!q2.empty()){
		int t1=q1.top(),t2=q2.top();
		q1.pop(),q2.pop();
		if(t1>t2) q1.push(t1-t2);
		else if(t2>t1) q2.push(t2-t1);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

