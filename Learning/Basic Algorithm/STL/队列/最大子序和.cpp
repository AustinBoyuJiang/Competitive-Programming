#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[300010],s[300010],l[300010];
deque<int>q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		while(!q.empty()&&s[i]<s[q.back()]){
			q.pop_back();
		}
		q.push_back(i); 
		if(i-m>=q.front()){
			q.pop_front();
		}
		l[i]=q.front();
		ans=max(ans,s[i]-s[l[i-1]]);
	}
	cout<<ans<<endl;
}
