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
const int N=2e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int q,cnt[N][3];
string str;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str>>q;
	for(int i=1;i<=str.size();i++){
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][2]=cnt[i-1][2];
		if(str[i-1]=='C') cnt[i][0]++;
		if(str[i-1]=='O') cnt[i][1]++;
		if(str[i-1]=='W') cnt[i][2]++;
	}
	while(q--){
		int l,r,a,b,c;
		cin>>l>>r;
		a=cnt[r][0]-cnt[l-1][0];
		b=cnt[r][1]-cnt[l-1][1];
		c=cnt[r][2]-cnt[l-1][2];
		if(!a&&!b&&!c){
			cout<<"N";
			continue;
		}
		if(!a&&b) a++,b--,c++;
		if(!a&&c) a++,b++,c--;
		b+=a-1;
		c+=a-1;
		a=1;
		if(b&1||c&1) cout<<"N";
		else cout<<"Y";
	}
	return 0;
}

