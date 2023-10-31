#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long k;
char s[N];
void work(){
	scanf("%d%lld%s",&n,&k,s+1);
	if(n==1){
		if(k&1)puts("0");
		else puts("1");
		return;
	}
	bool f1=1;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			f1=0;break;
		}
	}
	if(f1){
		if(k==1){
			s[n]='0';
			printf("%s\n",s+1);
			return;
		}
	}
	long long cnt=k;
	for(int i=1;i<=n;++i){
		int j=i;
		while(j+1<=n&&s[j+1]==s[j])++j;
		if(cnt&&s[i]=='0'){
			for(int k=i;k<=j;++k)s[k]='1';
			--cnt;
		}
		i=j;
	}
	printf("%s\n",s+1);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)work();
}
