/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
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
const int N=1e6+10;

int n,m,ans,p[N],cnt[N],sum[N];

bool check(int a,int b,int c){
	if(a>b) swap(a,b);
	if(b>c) swap(c,b);
	if(a>b) swap(a,b);
	int x=a+m/2+(m&1);
	int y=b+m/2+(m&1);
	int z=c+m/2+(m&1);
	int x1=a+m/2;
	int y1=b+m/2;
	int z1=c+m/2;
//	cout<<a<<' '<<b<<' '<<c<<' '<<x<<' '<<y<<' '<<z<<endl;
	return b<x&&c<y&&a<z%m&&c>x1&&a+m>y1&&b+m>z1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m<=6000){
		for(int i=1;i<=n;i++){
			cin>>p[i];
			cnt[p[i]]++;
			cnt[p[i]+m]++;
		}
		sum[0]=cnt[0];
		for(int i=1;i<m*2;i++)
			sum[i]=cnt[i]+sum[i-1];
		for(int a=0;a<m;a++){
			for(int b=a+1;b<a+m/2+(m&1);b++){
				int x=a+m/2;
				int y=b+m/2+(m&1);
				if(y>x+1) ans+=cnt[a]*cnt[b]*(sum[y-1]-sum[x]);
			}
			cnt[a]=0;
			cnt[a+m]=0;
			sum[0]=cnt[0];
			for(int i=1;i<m*2;i++)
				sum[i]=cnt[i]+sum[i-1];
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		for(int a=1;a<=n-2;a++){
			for(int b=a+1;b<=n-1;b++){
				for(int c=b+1;c<=n;c++){
//					cout<<a<<' '<<b<<' '<<c<<endl;
					if(check(p[a],p[b],p[c])){
//						cout<<1<<endl;
						ans++;
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

