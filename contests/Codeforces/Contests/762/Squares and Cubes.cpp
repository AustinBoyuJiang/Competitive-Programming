/*Author：AustinJiang
题目：
时间复杂度：O()
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
const int N=1e5+10;

int t;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		map<int,bool> s;
		int n;
		cin>>n;
		for(int i=1;i*i<=n;i++){
			s[i*i]=1;
		}
		for(int i=1;i*i*i<=n;i++){
			s[i*i*i]=1;
		}
		cout<<s.size()<<endl;
	}
	return 0;
}

