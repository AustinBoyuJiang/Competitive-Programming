/*Author��AustinJiang
��Ŀ������I������ƴ��25'
ʱ�临�Ӷȣ�O(n*10)
�㷨��ö�� */
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

int n,k,ans,a[N],cnt[K][11];

inline int get_len(int x){
	int cnt=0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=10;j++)
			cnt[(a[i]%k)*((int)pow(10,j)%k)%k][j]++;//����ÿ������ǰ��nλ������ 
	}
	for(int i=1;i<=n;i++){
		ans+=cnt[(k-a[i]%k)%k][get_len(a[i])];
		if(((a[i]%k)*(int)pow(10,get_len(a[i]))+a[i])%k==0) ans--;//�������Լ�
	}
	cout<<ans<<endl;
	return 0;
}

