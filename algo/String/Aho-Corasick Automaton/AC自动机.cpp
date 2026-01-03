/*Author：AustinJiang
题目：AC自动机
时间复杂度：O(n+m)
算法：AC自动机 */
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

int n,tot,tr[N][26],fail[N],cnt[N];
string s;

void insert(string s){
	int u=0;
	for(int i=0;i<s.size();i++){
		int d=s[i]-'a';
		if(!tr[u][d]) tr[u][d]=++tot;
		u=tr[u][d];
	}
	cnt[u]++;
}

void getFail(){
	queue<int> q;
	for(int i=0;i<26;i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++){
			if(tr[u][i]){
				fail[tr[u][i]]=tr[fail[u]][i];
				q.push(tr[u][i]);
			}
			else{
				tr[u][i]=tr[fail[u]][i];
			}
		}
	}
}

int query(string s){
	int u=0,ans=0;
	for(int i=0;i<s.size();i++){
		int d=s[i]-'a';
		u=tr[u][d];
		int p=u;
		while(p&&cnt[p]!=-1){
			ans+=cnt[p];
			cnt[p]=-1;
			p=fail[p];
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		insert(s);
	}
	getFail();
	cin>>s;
	cout<<query(s)<<endl;
	return 0;
}

