/*Author：AustinJiang
题目：矩阵行走
时间复杂度：O(n^2)
算法：记忆化DFS 
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
const int N=110;

int n,val[N][N],mx[N][N][N],dir[2][2]={{1,0},{0,1}};

bool ok(int x,int y){
	if(x>=1&&y>=1) return 1;
	return 0; 
}

int dfs(int a,int b,int c,int d){
	if(mx[a][b][c]!=-1) return mx[a][b][c];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			int na=a-dir[i][0];
			int nb=b-dir[i][1];
			int nc=c-dir[j][0];
			int nd=d-dir[j][1];
			if(ok(a,b)&&ok(c,d)) mx[a][b][c]=max(mx[a][b][c],dfs(na,nb,nc,nd)+abs(val[a][b]-val[c][d]));
		}
	}
	return mx[a][b][c];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>val[i][j];
	memset(mx,-1,sizeof(mx));
	mx[1][1][1]=0;
	cout<<dfs(n,n,n,n)<<endl;
	return 0;
}

