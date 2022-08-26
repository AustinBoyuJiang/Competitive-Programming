/*Author：AustinJiang
题目：坐标查询 
时间复杂度：O(n*log(n))
算法：STL */
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

int n,m;
map<int,multiset<int>> xv,yv;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		xv[x].insert(y);
		yv[y].insert(x);
	}
	for(int i=1;i<=m;i++){
		int c,d;
		cin>>c>>d;
		if(c==0){
			cout<<xv[d].size()<<endl;
			for(auto y:xv[d])
				if(yv[y].count(d)) yv[y].erase(d);
			xv[d].clear();
		}
		else{
			cout<<yv[d].size()<<endl;
			for(auto x:yv[d])
				if(xv[x].count(d)) xv[x].erase(d);
			yv[d].clear();
		}
	}
	return 0;
}

