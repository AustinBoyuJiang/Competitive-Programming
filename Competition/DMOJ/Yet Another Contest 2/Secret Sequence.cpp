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

int n,q[N],a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		cout<<"? "<<1<<" "<<i<<endl;
		cout.flush();
		cin>>q[i];
		a[i]=q[i]^q[i-1];
	}
	cout<<"? "<<2<<" "<<3<<endl;
		cout.flush();
	cin>>q[1];
	a[1]=q[1]^q[3];
	a[2]=q[2]^a[1];
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<" "<<a[i];
	cout<<endl;
	return 0;
}

