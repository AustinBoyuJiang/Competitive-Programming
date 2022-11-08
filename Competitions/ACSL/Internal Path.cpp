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
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int root,tot,ans;
string str;

struct node{
	int rt,lc,rc,dep;
	char s;
} st[N];

void insert(int &rt,char s,int dep){
	if(!rt){
		rt=++tot;
		st[rt].s=s;
		st[rt].dep=dep;
		ans+=dep;
		return;
	}
	if(s<=st[rt].s) insert(st[rt].lc,s,dep+1);
	else insert(st[rt].rc,s,dep+1);
}

signed main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
		insert(root,str[i],0);
	cout<<ans<<endl;
	cin>>ans;
	return 0;
}

