/*Author��AustinJiang
��Ŀ������ȥ�� 
ʱ�临�Ӷȣ�O(n*log(n))
�㷨��STL */
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
const int N=1e5+10;

int n;
set<string> words;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		transform(str.begin(),str.end(),str.begin(),::tolower);
		words.insert(str);
	}
	for(auto word:words) cout<<word<<endl;
	return 0;
}

