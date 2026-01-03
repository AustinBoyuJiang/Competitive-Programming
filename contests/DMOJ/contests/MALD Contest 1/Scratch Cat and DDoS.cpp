/*Author：AustinJiang
题目：Scratch Cat and DDoS
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
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e4+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,cnt,flag[N];
string url[N];
set<string> ans;

bool find(int i){
	for(int j=0;j+4<=url[i].size();j++)
		if(url[i].substr(j,4)=="yubo") return 1;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>url[i];
		if(find(i)) flag[i-1]=flag[i]=flag[i+1]=1;
	}
	for(int i=1;i<=n;i++)
		if(flag[i]) ans.insert(url[i]);
	for(auto str:ans)
		cout<<str<<endl;
	return 0;
}

