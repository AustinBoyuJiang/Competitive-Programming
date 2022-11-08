/*Author：AustinJiang
题目：math
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int unsigned long long
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

int t,n;

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

void solve(){
	int x,z;
	cin>>x>>z;
	int y=z/x/sqrt(gcd(x*x,z/x));
	if(x*y*gcd(x,y)==z) cout<<y<<endl;
	else cout<<-1<<endl;
}

signed main(){
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

