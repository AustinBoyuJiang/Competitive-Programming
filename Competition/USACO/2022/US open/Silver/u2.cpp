/*Author��AustinJiang
��Ŀ��
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��
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
const int N=20;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int q,f[N][N];
string a,b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>q;
	for(char i='a';i<='r';i++){
		for(char j='a';j<='r';j++){
			string A,B;
			for(auto x:a)
				if(x==i||x==j) A+=x;
			for(auto x:b)
				if(x==i||x==j) B+=x;
			f[i-'a'][j-'a']=A==B;
		}
	}
	while(q--){
		string str;
		int ans=1;
		cin>>str;
		for(auto i:str)
			for(auto j:str)
				ans&=f[i-'a'][j-'a'];
		cout<<(ans?"Y":"N");
	}
	return 0;
}

