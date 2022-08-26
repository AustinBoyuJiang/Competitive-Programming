/*Author：AustinJiang
题目：线段的覆盖
时间复杂度：O(n*log(n))
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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
const int N=1e6+10;

int n,ans;

struct segment{
	int x,y;
} st[N];

bool cmp(segment a,segment b){
	return a.y<b.y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>st[i].x>>st[i].y;
	sort(st+1,st+n+1,cmp);
	int lst=0;
	for(int i=1;i<=n;i++){
		if(st[i].x>=lst){
			ans++;
			lst=st[i].y;
		}
	}
	cout<<ans<<endl;
	return 0;
}

