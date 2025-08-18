#include<bits/stdc++.h>
using namespace std;
const int T = 1e5+10;
const int P = 3e5+10;
int n,l=1,citizenship=0,t[T],k[P],x[P],vis[T],st[T];
int main(){
	cin>>n;
	st[1]=1;
	for(int r=1;r<=n;r++){
		cin>>t[r]>>k[r];
		while(l<r && t[l]<=t[r]-86400){
			for(int i=st[l];i<st[l]+k[l];i++){
				vis[x[i]]--;
				if(vis[x[i]]==0)
					citizenship--;
			}	
			l++;
		}
		for(int i=st[r];i<st[r]+k[r];i++){
			cin>>x[i];
			vis[x[i]]++;
			if(vis[x[i]]==1)
				citizenship++;
		}
		st[r+1]=st[r]+k[r];
		cout<<citizenship<<endl;
	}
}
