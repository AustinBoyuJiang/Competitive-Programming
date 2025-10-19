#include <bits/stdc++.h>

#define ll long long
#define Max 200005

using namespace std;

struct Tree{
    ll lazy1,lazy2,lazy3,cnt,minn,sum1,sum2;
}st[Max*4];

int T,n,m,a[Max];

inline Tree up(Tree ls,Tree rs){
    Tree ans;
    ans.lazy1=ans.lazy3=0;ans.lazy2=1;
    ans.minn=min(ls.minn,rs.minn);
    ans.sum1=ls.sum1+rs.sum1;
    ans.sum2=ls.sum2+rs.sum2;
    ans.cnt=ls.cnt+rs.cnt;
    return ans;
}

inline void down(int node,int L,int R){
    int ls=node<<1,rs=node<<1|1;
    int mid=(L+R)>>1;

        st[ls].lazy3+=st[node].lazy3;
        st[rs].lazy3+=st[node].lazy3;
        st[ls].sum1-=st[node].lazy3*st[ls].cnt;
        st[rs].sum1-=st[node].lazy3*st[rs].cnt;
        st[ls].minn-=st[node].lazy3;
        st[rs].minn-=st[node].lazy3;

        st[ls].lazy1=st[node].lazy1+st[ls].lazy1*st[node].lazy2;
        st[rs].lazy1=st[node].lazy1+st[rs].lazy1*st[node].lazy2;
        st[ls].lazy2*=st[node].lazy2;
        st[rs].lazy2*=st[node].lazy2;
        st[ls].sum2=st[node].lazy1*(mid-L+1-st[ls].cnt)+st[ls].sum2*st[node].lazy2;
        st[rs].sum2=st[node].lazy1*(R-mid-st[rs].cnt)+st[rs].sum2*st[node].lazy2;
    st[node].lazy1=st[node].lazy3=0;
    st[node].lazy2=1;
    return;
}

inline void build(int node,int L,int R){
    if(L==R){
        st[node].lazy1=st[node].lazy3=0;
        st[node].lazy2=1;
        st[node].minn=st[node].sum1=a[L];
        st[node].sum2=0;
        st[node].cnt=1;
        return;
    }
    int mid=(L+R)>>1;
    build(node<<1,L,mid);
    build(node<<1|1,mid+1,R);
    st[node]=up(st[node<<1],st[node<<1|1]);
    return;
}

inline void change(int node,int l,int r,int L,int R,int k){
    if(L>=l&&R<=r){
        if(st[node].cnt){
            if(L==R){
                if(st[node].sum1<k){
                    st[node].sum2=k-st[node].sum1;
                    st[node].sum1=st[node].cnt=0;
                    st[node].minn=1e18;
                }else{
                    st[node].minn=st[node].sum1=st[node].sum1-k;
                }
            }else{
                if(st[node].minn<k){
                    down(node,L,R);
                    int mid=(L+R)>>1;
                    change(node<<1,l,r,L,mid,k);
                    change(node<<1|1,l,r,mid+1,R,k);
                    st[node]=up(st[node<<1],st[node<<1|1]);
                }else{
                    st[node].lazy3+=k;
                    st[node].minn-=k;
                    st[node].sum1-=1ll*k*st[node].cnt;
                    st[node].lazy1=k-st[node].lazy1;
                    st[node].lazy2*=-1;
                    st[node].sum2=1ll*k*(R-L+1-st[node].cnt)-st[node].sum2;
                }
            }
        }else{
            st[node].lazy1=k-st[node].lazy1;
            st[node].lazy2*=-1;
            st[node].sum2=1ll*k*(R-L+1)-st[node].sum2;
        }
//        cout<<L<<" "<<R<<" "<<st[node].sum1<<" "<<st[node].sum2<<endl;
        return;
    }
    down(node,L,R);
    int mid=(L+R)>>1;
    if(l<=mid)change(node<<1,l,r,L,mid,k);
    if(r>mid)change(node<<1|1,l,r,mid+1,R,k);
    st[node]=up(st[node<<1],st[node<<1|1]);
    return;
}

inline Tree query(int node,int l,int r,int L,int R){
    if(L>=l&&R<=r)return st[node];
    down(node,L,R);
    int mid=(L+R)>>1;
    if(r<=mid)return query(node<<1,l,r,L,mid);
    if(l>mid)return query(node<<1|1,l,r,mid+1,R);
    return up(query(node<<1,l,r,L,mid),query(node<<1|1,l,r,mid+1,R));
}

int main(){
    freopen("data3.in","r",stdin);
    freopen("data3.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        build(1,1,n);
        for(int i=1;i<=m;i++){
            int opt;
            cin>>opt;
            if(opt==1){
                int l,r,x;
                cin>>l>>r>>x;
                change(1,l,r,1,n,x);
            }else{
                int l,r;
                cin>>l>>r;
                Tree ans=query(1,l,r,1,n);
                cout<<ans.sum1+ans.sum2<<'\n';
            }
        }
    }
    return 0;
}
