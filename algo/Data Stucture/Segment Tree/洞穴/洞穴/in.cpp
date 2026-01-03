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
const int MAXN=1e5+10;

int N[10]={5,10,100,100,1000,1000,10000,10000,100000,100000};
int M[10]={4,8,80,100,800,1000,900,10000,100000,100000};
int t,now,a[MAXN],fa[MAXN];
VI e[MAXN]; 

void create_tree(int n){
	for(int i=1;i<=n;i++) a[i]=i;
	random_shuffle(a+1,a+n+1);
	for(int u=2;u<=n;u++){
		int v=(t==8?u-1:random(1,u-1));
		e[a[u]].pb(a[v]);
		e[a[v]].pb(a[u]);
		cout<<a[u]<<' '<<a[v]<<endl;
	}
}

void dfs(int u,int father){
	now=father;
	while(now==father) now=e[u][random(0,e[u].size()-1)];
	fa[now]=u; 
	cout<<now<<endl;
}

void create_data(int t){
	int n=N[t],m=M[t];
	cout<<n<<' '<<m<<endl;
	create_tree(n);
	now=1;
	for(int i=1;i<=m;i++){
		int opt=random(1,2);
		if(opt==1) if(now!=1&&e[now].size()==1) opt=2;
		cout<<opt<<' ';
		if(opt==1) dfs(now,fa[now]);
		else cout<<random(1,n)<<endl;
	}
}

signed main(){
	srand(time(NULL));
	char path[100];
	for(t=0;t<10;t++){
		sprintf(path,"data/%d.in",t+1);
		freopen(path,"w",stdout);
		create_data(t);
	}
	return 0;
}

