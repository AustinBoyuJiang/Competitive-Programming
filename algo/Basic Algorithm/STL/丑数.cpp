/*Author：AustinJiang
题目：丑数 
时间复杂度：O(n*log(n))
算法：STL，优先队列 */
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

int n,x,cnt;
PQ<int,VI,greater<int>> q;
map<int,int> num;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	q.push(x=1);
	while(cnt<n){
		x=q.top();
		q.pop();
		cnt++;
		if(!num[x*2]) q.push(x*2),num[x*2]=1;
		if(!num[x*3]) q.push(x*3),num[x*3]=1;
		if(!num[x*5]) q.push(x*5),num[x*5]=1;
	}
	cout<<x<<endl;
	return 0;
}

