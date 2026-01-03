#include<bits/stdc++.h>
using namespace std;
const int E = 1e5+10;
int n,ans,a[E],b[E],c[E];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	long long r=1,l=1,ans=0;
	for(int i=1;i<=n;i++){
		while(r<=n && a[r]<b[i]){
			r++;
		}
		while(l<=n && c[l]<=b[i]){
			l++;
		}
		ans+=(r-1)*(n+1-l);
	}
	cout<<ans<<endl;
}
