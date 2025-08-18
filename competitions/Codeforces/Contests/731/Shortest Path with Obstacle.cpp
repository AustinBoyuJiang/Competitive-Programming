/*Author：AustinJiang
题目：Shortest Path with Obstacle
时间复杂度：O(t)
来源：Codeforces Round #731 (Div. 3)
*/
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

int t,ax,ay,bx,by,fx,fy,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>ax>>ay;
		cin>>bx>>by;
		cin>>fx>>fy;
		ans=abs(ax-bx)+abs(ay-by);
		if((ax==fx&&fx==bx)&&((ay>fy&&fy>by)||(by>fy&&fy>ay))) ans+=2;
		if((ay==fy&&fy==by)&&((ax>fx&&fx>bx)||(bx>fx&&fx>ax))) ans+=2;
		cout<<ans<<endl;
	}
	return 0;
}

