/*Author��AustinJiang
��Ŀ��ͬ�෽��
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
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
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int a,b;

void exgcd(int a,int b,int &x,int &y) {
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	int x,y;
	exgcd(a,b,x,y);
	cout<<x-((x-b+1)/b)*b<<endl;
	return 0;
}

