/*Author��AustinJiang
��Ŀ��k������ 
ʱ�临�Ӷȣ�O(n)
�㷨��ǰ׺�ͣ�ö�� 
��Դ�����ű����� */
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
const int N=1e5+10;
const int K=1e5+10;

int n,k,ans,sum[N],cnt[K];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cnt[0]=1;//sum[0]%k=0;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
		cnt[sum[i]%k]++;
	}
	for(int i=0;i<k;i++)
		ans+=cnt[i]*(cnt[i]-1)/2; //-1��Ϊ���ܰ����Լ���/2��Ϊһ������������һ����ǰ�� 
	cout<<ans<<endl;
	return 0;
}

