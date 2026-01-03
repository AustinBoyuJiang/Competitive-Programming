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
const int N=5e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,a[N],ans[N];
multiset<int> num;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num.insert(a[i]);
	}
	ans[1]=*num.begin();
	num.erase(num.begin());
	for(int i=2;i<=n;i++){
		auto pos=num.lower_bound(m-ans[i-1]);
		if(pos==num.end()){
			cout<<-1<<endl;
			return 0;
		}
		ans[i]=*pos;
		num.erase(pos);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
