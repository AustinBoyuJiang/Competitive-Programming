/*Author：AustinJiang
题目：快速乘 
时间复杂度：O(log(a))
算法：数论，数学 */
#include<bits/stdc++.h>
#define int long long
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

int a,b,mod,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>mod;
	while(b){
		if(b&1) ans+=a,ans%=mod;
		a<<=1,a%=mod;
		b>>=1;
	}
	cout<<ans<<endl;
	return 0;
}

