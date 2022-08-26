#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
deque<int>q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(!q.empty() && a[i]<a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i-q.front()>=m){
			q.pop_front();
		}
		if(i>=m && i<=n-1) cout<<a[q.front()]<<' ';
	}
	cout<<a[q.front()]<<endl;
	q.clear();
	for(int i=1;i<=n;i++){
		while(!q.empty() && a[i]>a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i-q.front()>=m){
			q.pop_front();
		}
		if(i>=m && i<=n-1) cout<<a[q.front()]<<' ';
	}
	cout<<a[q.front()]<<endl;
	return 0;
}
