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
const int N=5e5+10;

int x,y,g,cnt,ans,f[N];
map<string,int> id;

struct query{
	string a,b;
} q1[N],q2[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	f[find(x)]=y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<N;i++)
		f[i]=i;
	cin>>x;
	for(int i=1;i<=x;i++){
		cin>>q1[i].a>>q1[i].b;
		if(!id[q1[i].a]) id[q1[i].a]=++cnt;
		if(!id[q1[i].b]) id[q1[i].b]=++cnt;
	}
	cin>>y;
	for(int i=1;i<=y;i++){
		cin>>q2[i].a>>q2[i].b;
		if(!id[q2[i].a]) id[q2[i].a]=++cnt;
		if(!id[q2[i].b]) id[q2[i].b]=++cnt;
	}
	cin>>g;
	for(int i=1;i<=g;i++){
		string a,b,c;
		cin>>a>>b>>c;
		if(!id[a]) id[a]=++cnt;
		if(!id[b]) id[b]=++cnt;
		if(!id[c]) id[c]=++cnt;
		merge(id[a],id[b]);
		merge(id[b],id[c]);
	}
	for(int i=1;i<=x;i++){
		if(find(id[q1[i].a])!=find(id[q1[i].b])) ans++;
	}
	for(int i=1;i<=y;i++){
		if(find(id[q2[i].a])==find(id[q2[i].b])) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

