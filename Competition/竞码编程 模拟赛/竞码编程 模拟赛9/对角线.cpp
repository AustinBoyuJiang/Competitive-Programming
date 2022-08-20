/*Author：AustinJiang
题目：对角线 
时间复杂度：O()
算法：
来源：
思路：
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

int n,m;

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int x;
	while(x=gcd(n,m)!=1){
		n/=x;
		m/=x;
	}
	if((n+m)%2) cout<<"1/2"<<endl;
	else cout<<min(n,m)<<"/"<<max(n,m)<<endl;
	return 0;
}

