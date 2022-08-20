/*Author：AustinJiang
题目：三分法 
时间复杂度：O(n*log(10000000))
算法：三分法 
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
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,a[N],b[N],c[N];

double calc(double x){
	double res=-INF;
	for(int i=1;i<=n;i++)
		res=max(res,a[i]*x*x+b[i]*x+c[i]);
	return res;
}

double solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	double l=0,r=1000;
	while(l<=r){
		double mid=(l+r)/2;
		double x=calc(mid-0.0000001);
		double y=calc(mid);
		double z=calc(mid+0.0000001);
		if(x>y&&y>z) l=mid+0.0000001;
		else if(x<y&&y<z)r=mid-0.0000001;
		else return y;
	}
}

signed main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		printf("%.4lf\n",solve());
	return 0;
}

