#include<bits/stdc++.h>
using namespace std;
const int E=1e5;
int pos=-1,pos1,pos2,pos3,pos4;
char st[E],pre[20],mid[20],suf[20];
string str;

void build(int rt){
	pos++;
	st[rt]=str[pos];
	if(str[pos]=='#')return;
	pre[++pos2]=st[rt];
	build(rt*2);
	mid[++pos3]=st[rt];
	build(rt*2+1);
	suf[++pos4]=st[rt];
}

int main(){
	cin>>str;
	build(1);
	for(int i=1;i<E;i++){
		if(st[i]&&st[i]!='#')cout<<st[i];
	}
	cout<<endl;
	for(int i=1;i<=pos2;i++){
		cout<<pre[i];
	}
	cout<<endl;
	for(int i=1;i<=pos3;i++){
		cout<<mid[i];
	}
	cout<<endl;
	for(int i=1;i<=pos4;i++){
		cout<<suf[i];
	}
	cout<<endl;
}
