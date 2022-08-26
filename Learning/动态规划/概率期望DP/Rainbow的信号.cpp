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
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int D=32;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,d[N][D];
double res[D];

inline double solve1(){
	double ans=0;
	for(int k=D-1;k>=0;k--){
		int cnt[2]={0,0};
		double tot=0;
		for(int i=1;i<=n;i++){
			if(d[i][k]) swap(cnt[0],cnt[1]);
			tot+=cnt[1];
			cnt[d[i][k]]++;
		}
		tot*=2;
		for(int i=1;i<=n;i++)
			tot+=d[i][k];
		ans=ans*2+tot/n/n;
	}
	return ans;
}

inline double solve2(){
	double tot,ans=0;
	int l[N],r[N];
	for(int k=D-1;k>=0;k--){
		l[0]=0,r[n+1]=n+1,tot=0;
		for(int i=1;i<=n;i++){
			if(d[i][k]==0) l[i]=i;
			else l[i]=l[i-1];
		}
		for(int i=n;i>=1;i--){
			if(d[i][k]==0) r[i]=i;
			else r[i]=r[i+1];
		}
		for(int i=1;i<=n;i++)
			tot+=max(0,r[i]-l[i]-1);
		ans=ans*2+tot*1.0/n/n;
	}
	return ans;
}

inline double solve3(){
	double tot,ans=0;
	int l[N],r[N];
	for(int k=D-1;k>=0;k--){
		l[0]=0,r[n+1]=n+1,tot=0;
		for(int i=1;i<=n;i++){
			if(d[i][k]==1) l[i]=i;
			else l[i]=l[i-1];
		}
		for(int i=n;i>=1;i--){
			if(d[i][k]==1) r[i]=i;
			else r[i]=r[i+1];
		}
		for(int i=1;i<=n;i++)
			tot+=min(n,n-r[i]+l[i]+1);
		ans=ans*2+tot*1.0/n/n;
	}
	return ans;
}

signed main(){
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=0;j<D;j++){
			d[i][j]=x&1;
			x>>=1;
		}
	}
	printf("%.3lf %.3lf %.3lf\n",solve1(),solve2(),solve3());
	return 0;
}

