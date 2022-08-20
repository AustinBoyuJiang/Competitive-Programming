/*Author：AustinJiang
题目：Maximum Damage
时间复杂度：O(n*log(n)^2)
算法：二分，质数筛选法，前缀和 
来源：DMOJ Yet Another Contest 2 P3 */
#include<bits/stdc++.h>
#define int long long
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
const int N=3e6+10;
const int H=1e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,ans,cnt[H],flag[H];
VI prime,num[H],sum[H];

bool check(int x,int i){
	int l=0,r=num[i].size()-1,pos=r+1;
	while(l<=r){
		int mid=l+r>>1;
		if(num[i][mid]>x) r=mid-1,pos=mid;
		else l=mid+1;
	}
	return sum[i][pos-1]*(pos>0)+x*(num[i].size()-pos)>=x*m;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=2;i<H;i++){
		if(flag[i]) continue;
		prime.pb(i);
		for(int j=i;j<H;j+=i){
			flag[j]=1;
			int d=0,tmp=j;
			while(tmp%i==0){
				tmp/=i;
				d++;
			}
			for(int k=1;k<=cnt[j];k++)
				num[i].pb(d);
		}
		int tot=0;
		sort(num[i].begin(),num[i].end());
		for(auto x:num[i])
			sum[i].pb(tot+=x);
	}
	for(auto i:prime){
		if(num[i].empty()) continue;
		int l=0,r=sum[i][num[i].size()-1],res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)) l=mid+1,res=mid;
			else r=mid-1;
		}
		ans+=res;
	}
	cout<<ans<<endl;
	return 0;
}

