/*Author：AustinJiang
题目：Not Adding
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
const int N=1e6+10;

int n,cnt,a[N],vis[N];

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	for(int i=1;i<N;i++){
		int res=0;
		for(int j=i;j<N;j+=i)
			if(vis[j]) res=gcd(res,j);
		if(res==i) cnt++;
	}
	cout<<cnt-n<<endl;
	return 0;
}

