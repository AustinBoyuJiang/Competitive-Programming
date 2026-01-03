#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,x,y,k,st[E][20];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&st[i][0]);
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		k=log2(y-x+1);
		printf("%d\n",max(st[x][k],st[y-(1<<k)+1][k]));
	}
}
