/*Author：AustinJiang
题目：轻拍牛头
时间复杂度：O(n*log(n))
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int M=1e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,num[N],cnt[M],ans[M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cnt[num[i]]++;
	}
	for(int i=1;i<M;i++)
		for(int j=i;j<M;j+=i)
			ans[j]+=cnt[i];
	for(int i=1;i<=n;i++)
		cout<<ans[num[i]]-1<<endl;
	return 0;
}

