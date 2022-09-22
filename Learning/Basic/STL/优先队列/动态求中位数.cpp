/*Author：AustinJiang
题目：动态求中位数
时间复杂度：O(n*log(n))
算法：优先队列 */
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

int n;
PQ<int,VI,less<int>> a;
PQ<int,VI,greater<int>> b;

void add(int x){
	if(a.empty()) a.push(x);
	else if(a.size()<=b.size()){
		if(x<=b.top()) a.push(x);
		else{
			a.push(b.top());
			b.pop();
			b.push(x);
		}
	} 
	else{
		if(x>=a.top()) b.push(x);
		else{
			b.push(a.top());
			a.pop();
			a.push(x);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string opt;
		int x;
		cin>>opt;
		if(opt=="add") cin>>x,add(x);
		else if(a.empty()) cout<<"empty"<<endl;
		else cout<<a.top()<<endl;
	}
	return 0;
}

