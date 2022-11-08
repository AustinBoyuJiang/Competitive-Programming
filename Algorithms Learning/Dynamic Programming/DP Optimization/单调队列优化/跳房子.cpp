#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const long long INF=1e18;
const int N=5e5+10;

int n,d,k,l,r,ans=-1,dist[N],val[N];

bool check(int g){
	//dp[i]表示花费g个金币改造后跳了n个格子的最大得分 
	int l=max(1,d-g),r=d+g,j=1,front,back,q[N];
	long long dp[N]={0};
	q[front=back=0]=0;
    for(int i=1;i<=n;i++){
        while(j<=n&&dist[j]+l<=dist[i]){
            while(front<=back&&dp[q[back]]<=dp[j])
				back--;
            q[++back]=j++;
        }
        while(front<=back&&dist[q[front]]+r<dist[i])
			front++;
        if(front<=back&&dist[q[front]]+l<=dist[i]) dp[i]=dp[q[front]]+val[i];
        else dp[i]=-INF;
        if(dp[i]>=k) return true;
    }
    return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++){
        cin>>dist[i]>>val[i];
        r=max(r,dist[i]);
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

