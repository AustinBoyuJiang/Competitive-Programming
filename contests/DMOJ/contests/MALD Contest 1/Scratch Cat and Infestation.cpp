/*Author：AustinJiang
题目：Scratch Cat and Infestation
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
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,t[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	sort(t+1,t+n+1);
	int i=0,tot=0,day=0;
	while(1){
		tot+=tot/k;
		while(t[i+1]<=day) i++,tot++;
		if(tot>=n) break;
		if(t[i+1]<=day+1||tot>=k) day++;
		else day=t[i+1];
	}
	cout<<day<<endl;
	return 0;
}

