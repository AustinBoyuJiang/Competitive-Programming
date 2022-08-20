/*Author��AustinJiang
��Ŀ��Subsequences
ʱ�临�Ӷȣ�O(n^2)
�㷨����̬�滮 
��Դ��CF 1183H 
˼·��dp[i][j][k]��ʾǰi����ĸȡj����βΪk��������� 
*/
#include<bits/stdc++.h>
#define int long long
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
const int N=110;
const int K=26;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,pre[N],pos[K],dp[N][N];
string str;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>str;
	for(int i=1;i<=n;i++){
		pre[i]=pos[str[i-1]-'a'];
		pos[str[i-1]-'a']=i;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]-dp[pre[i]-1][j-1];
	int cnt=0,i=n,ans=0;
	while(cnt<k&&i>=0){
		ans+=min(dp[n][i],k-cnt)*(n-i);
		cnt+=dp[n][i];
		i--;
	}
	if(cnt>=k) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}

