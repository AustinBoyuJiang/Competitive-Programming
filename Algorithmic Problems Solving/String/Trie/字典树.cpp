/*Author£ºAustinJiang
ÌâÄ¿£º×ÖµäÊ÷
Ê±¼ä¸´ÔÓ¶È£ºO(n*|S|)
Ëã·¨£º×Ö·û´®£¬×ÖµäÊ÷ */
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
const int N=1e6+10;

int n,ans,tot,trie[N][10],cnt[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		int rt=0,flag=1;
		for(int i=0;i<str.size();i++){
			if(!trie[rt][str[i]-'0']) trie[rt][str[i]-'0']=++tot,flag=0;
			rt=trie[rt][str[i]-'0'];
			if(cnt[rt]) ans=1;
		}
		cnt[rt]=1;
		ans|=flag;
	}
	cout<<(ans?"YES":"NO")<<endl;
	return 0;
}

