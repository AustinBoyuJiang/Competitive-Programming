/*Author��AustinJiang
��Ŀ���������� 
ʱ�临�Ӷȣ�O(n^3)
�㷨����̬�滮 
��Դ��NOIP�����T1
˼·��dp[i][j]��ʾ�ϲ�����(i,j)�ͷŵ�������� 
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
const int N=210;

int n,ans,a[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n*2;i++)
		if(i<=n) cin>>a[i];
		else a[i]=a[i-n];
	for(int l=2;l<=n;l++){//���� 
		for(int i=1;i+l-1<=n*2;i++){//��˵� 
			int j=i+l-1;//�Ҷ˵� 
			for(int k=i;k<j;k++)//�ϵ� 
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl; 
	return 0;
}

