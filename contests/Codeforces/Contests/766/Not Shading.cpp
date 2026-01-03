/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
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
const int N=100;

int n,cnt,a[N][N],r[N],c[N];

void solve(){
	memset(a,0,sizeof(a));
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	int n,m,R,C;
	cin>>n>>m>>R>>C;
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			if(x=='B'){
				r[i]=c[j]=1;
				a[i][j]=1;
				cnt++;
			}
		}
	}
	if(a[R][C]) cout<<0<<endl;
	else if(r[R]||c[C]) cout<<1<<endl;
	else if(cnt) cout<<2<<endl;
	else cout<<-1<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

