/*Author��AustinJiang
��Ŀ���׳˵�Լ������
ʱ�临�Ӷȣ�O(n*sqrt(n))
�㷨������ */
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
const int N=100;

int n,ans=1,cnt[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(;n>=2;n--){
		int tmp=n,num=2;
		while(num<=sqrt(tmp)){
			if(tmp%num==0){
				tmp/=num;
				cnt[num]++;
			}
			else num++;
		}
		cnt[tmp]++;
	}
	for(int i=2;i<=N;i++)
		ans*=cnt[i]+1;
	cout<<ans<<endl;
	return 0;
}

