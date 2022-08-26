#include<bits/stdc++.h>
using namespace std;
const int E=1e6+10;
int n,pos,s[E];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pos);
		s[pos]++;
	}
	for(int i=0;i<E;i++){
		for(int j=0;j<s[i];j++){
			printf("%d ",i);			
		}
	}
}
