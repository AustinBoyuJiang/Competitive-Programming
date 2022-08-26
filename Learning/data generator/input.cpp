/*Author：AustinJiang
题目：
时间复杂度：O()
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
const int T=30;
const int N=1000;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,fa[N+10];

void solve(){
	printf("%d\n",n=random(1,N));
	for(int i=1;i<=n;i++){
		fa[i]=i;
		swap(fa[i],fa[random(1,i)]);
	}
	for(int i=2;i<=n;i++)
		printf("%d %d\n",i,fa[i]);
	for(int i=1;i<=n;i++){
		int b=random(0,100);
		int a=random(0,b);
		printf("%d %d\n",a,b-a);
	}
}

signed main(){
	srand(time(NULL));
	printf("%d\n",t=random(1,T));
	while(t--)
		solve();
	return 0;
}

