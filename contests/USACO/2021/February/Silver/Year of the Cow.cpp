/*Author：AustinJiang
题目：Year of the Cow
时间复杂度：O(n*log(n))
算法：贪心 
来源：USACO 2021 February Contest, Silver
思路：
*/
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

int n,k,ans,y[N];
set<int> cy;
PQ<int,VI,less<int>> nxt;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cy.insert(0);
	for(int i=1;i<=n;i++){
		cin>>y[i];
		cy.insert((y[i]-1)/12+1);
	}
	int lst=0;
	for(auto x:cy){
		if(x-lst-1) nxt.push(x-lst-1);
		lst=x;
	}
	ans=lst*12;
	k--;
	while(k--&&!nxt.empty()){
		ans-=nxt.top()*12;
		nxt.pop();
	}
	cout<<ans<<endl;
	return 0;
}

