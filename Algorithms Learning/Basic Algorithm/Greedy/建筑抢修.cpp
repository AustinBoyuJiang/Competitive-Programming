/*Author：AustinJiang
题目：建筑抢修 
时间复杂度：O(n*log(n))
算法：贪心 
来源：各省省选 */
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
const int N=2e5+10;

int n,now,ans;
PQ<int,VI,less<int>> q;

struct building{
	int a,b;
} t[N];

bool cmp(building a,building b){
	return a.b<b.b;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b;
	}
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(now+t[i].a<=t[i].b){
			q.push(t[i].a);
			now+=t[i].a;
			ans++;
		}
		else{
			if(t[i].a<q.top()){
				now+=t[i].a-q.top();
				q.pop();
				q.push(t[i].a);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

