/*Author：AustinJiang
题目：XOR Mixup
时间复杂度：O()
算法：
来源：
思路：
*/
//#pragma GCC optimize(2)
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
const int N=110;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,a[N];

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum^=a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==sum^a[i]){
				cout<<a[i]<<endl;
				break;
			}
		}
	}
	return 0;
}

