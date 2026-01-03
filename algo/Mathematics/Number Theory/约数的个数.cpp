/*Author：AustinJiang
题目：约数的个数
时间复杂度：O(sqrt(n))
算法：数学 */
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

ll n,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0){
			ans++;
			if(n%(n/i)==0&&n/i!=i) ans++;
		}
	cout<<ans<<endl;
	return 0;
}

