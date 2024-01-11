/*Author：AustinJiang
题目：Integers Shop
时间复杂度：O(n)
算法：
来源：
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
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;

int t,n;

void solve(){
	cin>>n;
	int minL=INF,minR=INF,minLR=INF;
	int x=INF,y=-INF;
	for(int i=1;i<=n;i++){
		int l,r,c;
		cin>>l>>r>>c;
		if(l<x){
			minL=INF;
			minLR=INF;
			x=l;
		}
		if(r>y){
			minR=INF;
			minLR=INF;
			y=r;
		}
		if(l==x&&r==y) minLR=min(minLR,c);
		if(l==x) minL=min(minL,c);
		if(r==y) minR=min(minR,c);
		cout<<min(minL+minR,minLR)<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

