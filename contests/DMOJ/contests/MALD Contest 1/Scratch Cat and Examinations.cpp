/*Author：AustinJiang
题目：Scratch Cat and Examinations
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
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
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n;

void solve(bool el){
	int g,t,k;
	cin>>g>>t;
	k=(g*100+t-1)/t;
	if(k>100) cout<<"sus"<<endl;
	else if(k==100) cout<<"average"<<endl;
	else if(k>=98) cout<<"below average"<<endl;
	else if(k>=95) cout<<"can't eat dinner"<<endl;
	else if(k>=90) cout<<"don't come home"<<endl;
	else cout<<"find a new home"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
		solve(n);
	return 0;
}

