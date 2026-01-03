/*Author：AustinJiang
题目：牛为什么过马路1
时间复杂度：O(n*log(n))
算法：贪心
来源：USACO 2017 February Silver */
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
const int N=2e4+10;

int c,n,ans;
multiset<int> t;

struct cow{
	int x,y;
} q[N];

bool cmp(cow a,cow b){
	return a.y<b.y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n;
	for(int i=1,x;i<=c;i++)
		cin>>x,t.insert(x);
	for(int i=1;i<=n;i++)
		cin>>q[i].x>>q[i].y;
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++){
		auto ck=t.lower_bound(q[i].x);
		if(ck!=t.end()&&*ck<=q[i].y) ans++,t.erase(ck);
	}
	cout<<ans<<endl;
	return 0;
}

