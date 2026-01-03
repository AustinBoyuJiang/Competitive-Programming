/*Author：AustinJiang
题目：火车进站 
时间复杂度：O(2^n)
算法：DFS，栈*/
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
const int N=100;

int n,x,cnt;
VI out;
stack<int> in; 

void dfs(){
	if(cnt>=20) return;
	if(out.size()==n){
		for(auto i:out)
			cout<<i;
		cout<<endl;
		cnt++;
		return;
	}
	if(!in.empty()){
		out.pb(in.top());
		in.pop();
		dfs();
		in.push(out.back());
		out.pop_back();
	}
	if(x<n){
		in.push(++x);
		dfs();
		x--;
		in.pop();
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dfs();
	return 0;
}
