/*Author：AustinJiang
题目：Hidden Permutations
时间复杂度：O()
算法：
来源：CF Hello2022
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
const int N=1e5+10;

int t,p[N];

int ask(int x){
	cout<<"? "<<x<<endl;
	cout.flush();
	int y;
	cin>>y;
	return y;
}

void solve(){
	int n;
	cin>>n;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		if(p[i]) continue;
		int x=ask(i);
		while(1){
			int y=ask(i);
			p[x]=y,x=y;
			if(p[x]) break;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<p[i]<<' ';
	cout<<endl;
	cout.flush();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

