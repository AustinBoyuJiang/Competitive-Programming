#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int T,n,P;

inline int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ans;
}

int main(){
	// freopen("data1.in","r",stdin);
	// freopen("data1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>P;
        if(!n){
            cout<<"0\n";
            continue;
        }
        if(n<6){
            cout<<(n/2+1)*15<<'\n';
            continue;
        }
        if(n&1){
            int t=n/6;
            int P1=(1-qpow(1-P+mod,t)+mod)%mod;//一种道具一个以��?
            int P2=(1-(qpow(1-P+mod,t)+1ll*qpow(1-P+mod,t-1)*P%mod*t%mod)%mod+mod)%mod;//一种道具两个以��?
            int PP=(1-1ll*(1-P1+mod)*(1-P2+mod)%mod+mod)%mod;//有体力药
            int p1=1ll*PP*P1%mod;
            int p2=1ll*PP*qpow(1-P+mod,t)%mod*P2%mod;
            int p3=1ll*PP*qpow(1-P+mod,t)%mod*(1ll*qpow(1-P+mod,t-1)*P%mod*t%mod)%mod;
            int p4=(1-((p1+p2)%mod+p3)%mod+mod)%mod;
            cout<<(((15ll*(n/2)%mod+22)*p1%mod
                   +(15ll*(n/2)%mod+21)*p2%mod)%mod
                  +((15ll*(n/2)%mod+18)*p3%mod
                   +(15ll*(n/2)%mod+15)*p4%mod)%mod)%mod<<'\n';
        }else{
            cout<<(15ll*(n/2)%mod+15)%mod<<'\n';
        }
    }
    return 0;
}
