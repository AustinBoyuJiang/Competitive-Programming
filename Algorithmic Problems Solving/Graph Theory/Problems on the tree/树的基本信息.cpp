#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int E=1e3+10;
int n,q;
vector<PII> Map[E];

struct node{
	int val,depth,parent,dis,sz,sum,mx;
}s[E];

int dfs(int u,int depth,int parent, int distance){
	s[u].depth=depth;
	s[u].parent=parent;
	s[u].dis=s[parent].dis+distance;
	s[u].sz=1;
	s[u].sum=s[u].val;
	s[u].mx=s[u].val;
	for(int i=0;i<Map[u].size();i++){
		int v = Map[u][i].first;
		int w = Map[u][i].second;
		if(v == parent) continue;
		dfs(v,depth+1,u, w);
		s[u].sz+=s[v].sz;
		s[u].sum+=s[v].sum;
		s[u].mx=max(s[u].mx,s[v].mx);
	}
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].val;
	}
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Map[u].push_back(make_pair(v,w));
		Map[v].push_back(make_pair(u,w));
	}
	dfs(1,1,0,0);
	while(q--){
		int opt,x;
		cin>>opt>>x;
		if(opt==1){
			cout<<s[x].depth<<endl;
		}
		else if(opt==2){
			cout<<s[x].parent<<endl;
		}
		else if(opt==3){
			cout<<s[x].dis<<endl;
		}
		else if(opt==4){
			cout<<s[x].sz<<endl;
		}
		else if(opt==5){
			cout<<s[x].sum<<endl;
		}
		else if(opt==6){
			cout<<s[x].mx<<endl;
		}
	}
}
