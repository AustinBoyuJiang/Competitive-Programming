#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,a,b;
vector<int> Map[E];

struct node{
	int son,fa,gr;
}st[E];

void dfs(int u,int fa){
	st[u].fa=fa;
	st[u].son=Map[u].size()-(fa!=0);
	st[u].gr=(st[fa].fa!=0);
	for(int i=0;i<Map[u].size();i++){
		if(Map[u][i]==fa) continue;
		dfs(Map[u][i],u);
		st[u].gr+=st[Map[u][i]].son;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(st[i].fa!=0) st[i].gr+=st[st[i].fa].son-1;
		cout<<st[i].gr<<' ';
	}
	cout<<endl;
}
