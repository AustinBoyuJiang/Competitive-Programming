#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 1e6+10;

int n,a[N],b[N],l[N],r[N],pos[N],vis[N];
queue<int> q;

void check(int i){
	if(vis[i]) return;
	if(l[i]<=pos[i]&&r[i]>=pos[i]){
		q.push(i);
		vis[i]=1;
	}
}

signed main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
		l[i]=0x3f3f3f3f;
		r[i]=-0x3f3f3f3f;
	}
	int j=1,m=0;
	rep(i,1,n){
		while(a[j]!=b[i]){
			j++;
			if(j>n){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if(i==1||b[i]!=b[i-1]){
			m++;
			pos[m]=j;
		}
		r[m]=max(r[m],i);
		l[m]=min(l[m],i);
	}
	vector<pair<char,pair<int,int>>> ans;
	rep(i,1,m){
//		cout<<l[i]<<" "<<r[i]<<" "<<pos[i]<<endl;
		check(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(l[u]<pos[u]){
			ans.push_back({'L',{l[u],pos[u]}});
		}
		if(r[u]>pos[u]){
			ans.push_back({'R',{pos[u],r[u]}});
		}
		if(u>1){
			r[u-1]=pos[u]-1;
			check(u-1);
		}
		if(u<m){
			l[u+1]=pos[u]+1;
			check(u+1);
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for(auto p:ans){
		cout<<p.first<<" "<<p.second.first-1<<" "<<p.second.second-1<<endl;
	}
	return 0;
}

