/*Author：AustinJiang
题目：阶乘尾零
时间复杂度：O(n*log(n))
算法：数论 */
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

int n,cnt1,cnt2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(;n>=1;n--){
		int tmp=n;
		while(tmp&&tmp%2==0){
			tmp/=2;
			cnt1++;
		}
		while(tmp&&tmp%5==0){
			tmp/=5;
			cnt2++;
		}
	}
	cout<<min(cnt1,cnt2)<<endl;
	return 0;
}

