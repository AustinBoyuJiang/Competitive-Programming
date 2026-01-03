#include<bits/stdc++.h>
using namespace std;
const int E=2e4+10; 
int n,m,q,x,y,f[E];

int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	f[fx]=fy;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		merge(x,y);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		if(find(x)==find(y)) printf("Yes\n");
		else printf("No\n");
	}
}
