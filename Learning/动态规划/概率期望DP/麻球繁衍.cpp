/*Author��AustinJiang
��Ŀ�������� 
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��dp[i][j]��ʾ��i����j��ë��ĸ��� 
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
const int N=1010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,m;
double p[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
		cin>>p[i];
	dp[1]=p[0];
	for(int i=2;i<=m;i++){
		double sum=1;
		for(int j=0;j<=n;j++){
			dp[i]+=p[j]*sum;
			sum*=dp[i-1];
		}
	}
	printf("%.7lf",pow(dp[m],k));
	return 0;
}

