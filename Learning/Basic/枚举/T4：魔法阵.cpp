/*Author��AustinJiang
��Ŀ��T4:ħ���� 
ʱ�临�Ӷȣ�O((n/9)^2)
�㷨��ö�� 
��Դ��NOIP 2016
˼·����d-c��Ϊt����c-bΪt*6+k��b-aΪt*2��ö��t��a��d������ħ��ֵ���������˷�����*/
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
const int N=2e4;
const int M=5e4;

int n,m,val[M],cnt[N],a[N],b[N],c[N],d[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>val[i];
		cnt[val[i]]++;
	}
	for(int t=1;t*9<n;t++){
		int sum=0;
		for(int dx=t*9+2;dx<=n;dx++){
			int ax=dx-t*9-1;
			int bx=ax+t*2;
			int cx=dx-t;
			sum+=cnt[ax]*cnt[bx];//�����˾���k������a��b�ܺ�
			c[cx]+=cnt[dx]*sum;//�˷����� 
			d[dx]+=cnt[cx]*sum;
		}
		sum=0;
		for(int ax=n-t*9-1;ax>0;ax--){
			int bx=ax+t*2;
			int cx=bx+t*6+1;
			int dx=ax+t*9+1;
			sum+=cnt[cx]*cnt[dx];
			a[ax]+=cnt[bx]*sum;
			b[bx]+=cnt[ax]*sum;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<a[val[i]]<<' '<<b[val[i]]<<' '<<c[val[i]]<<' '<<d[val[i]]<<endl;
	return 0;
}

