#include <bits/stdc++.h>

#define ll long long
#define Max 200005

using namespace std;

struct Tree{
	int l,r,sz,rnd,lazy1;
	ll num,sum,lazy2;
}t[Max];

struct Node{
    ll num;
    int id;
    inline bool operator<(const Node x){
        if(num!=x.num)return num<x.num;
        return id<x.id;
    }
}p[Max],q1[Max],q2[Max],q3[Max];

int T,n,m,len,cnt,a[Max],id[Max];
int root[3000],L[3000],R[3000];
int len1,len2,len3,now[4];

inline void up(int now){
	t[now].sum=t[t[now].l].sum+t[t[now].r].sum+t[now].num;
	t[now].sz=t[t[now].l].sz+t[t[now].r].sz+1;
	return;
}

inline void down(int now){
	if(t[now].l){
		t[t[now].l].num=t[t[now].l].num*t[now].lazy1-t[now].lazy2;
		t[t[now].l].sum=t[t[now].l].sum*t[now].lazy1-t[now].lazy2*t[t[now].l].sz;
		t[t[now].l].lazy1*=t[now].lazy1;
		t[t[now].l].lazy2=t[t[now].l].lazy2*t[now].lazy1+t[now].lazy2;
        if(t[now].lazy1==-1)swap(t[t[now].l].l,t[t[now].l].r);
	}
	if(t[now].r){
		t[t[now].r].num=t[t[now].r].num*t[now].lazy1-t[now].lazy2;
		t[t[now].r].sum=t[t[now].r].sum*t[now].lazy1-t[now].lazy2*t[t[now].r].sz;
		t[t[now].r].lazy1*=t[now].lazy1;
		t[t[now].r].lazy2=t[t[now].r].lazy2*t[now].lazy1+t[now].lazy2;
        if(t[now].lazy1==-1)swap(t[t[now].r].l,t[t[now].r].r);
	}
	t[now].lazy1=1;
	t[now].lazy2=0;
}

inline void split(int now,ll k,int&x,int&y){
	if(!now){
		x=y=0;
		return;
	}
	down(now);
	if(t[now].num<=k){
		x=now;
		split(t[now].r,k,t[now].r,y);
	}else{
		y=now;
		split(t[now].l,k,x,t[now].l);
	}
	up(now);
	return;
}

inline int merge(int x,int y){
	if(!x||!y)return x+y;
	down(x);down(y);
	if(t[x].rnd<t[y].rnd){
		t[x].r=merge(t[x].r,y);
		up(x);
		return x;
	}else{
		t[y].l=merge(x,t[y].l);
		up(y);
		return y;
	}
}

inline void down2(int now){
	down(now);
	if(t[now].l)down2(t[now].l);
	if(t[now].r)down2(t[now].r);
}

inline void down3(int now){
	down(now);
	if(t[now].l)down3(t[now].l);
    p[cnt].num=t[now].num;
    p[cnt].id=now;
    cnt++;
	if(t[now].r)down3(t[now].r);
}

inline void dfs(int now){
    down(now);
    if(t[now].l)dfs(t[now].l);
    cout<<now<<" "<<t[now].num<<'\n';
    if(t[now].r)dfs(t[now].r);
}

inline int build(int L,int R){
    if(L>R)return 0;
    int mid=(L+R)>>1;
    t[p[mid].id].l=build(L,mid-1);
    t[p[mid].id].r=build(mid+1,R);
    up(p[mid].id);
    return p[mid].id;
}

inline void change(int l,int r,ll k){
	if(id[l]==id[r]){
		// down2(root[id[l]]);
		// for(int i=l;i<=r;i++){
		// 	ll num=t[i].num;
        //     if(t[i].num<k)t[i].num=k-t[i].num;
        //     else t[i].num=k+t[i].num;
		// }
        // root[id[l]]=0;
        // for(int i=L[id[l]];i<=R[id[l]];i++){
        //     t[i].l=t[i].r=0;
        //     t[i].sz=1;
        //     t[i].sum=t[i].num;
        //     int x,y;
        //     split(root[id[l]],t[i].num,x,y);
        //     root[id[l]]=merge(x,merge(i,y));
        // }
        cnt=L[id[r]];
        down3(root[id[r]]);
        len1=len2=len3=0;
        for(int i=L[id[r]];i<=R[id[r]];i++){
            t[i].l=t[i].r=0;
            t[i].sz=1;
            if(p[i].id>=l&&p[i].id<=r){
                ll num=t[p[i].id].num;
                // cout<<t[i].num<<" ";
                if(t[p[i].id].num<k){
                    t[p[i].id].num=p[i].num=k-t[p[i].id].num;
                    q2[++len2]=p[i];
                }else{
                    t[p[i].id].num=p[i].num=k+t[p[i].id].num;
                    q3[++len3]=p[i];
                }
            }else{
                q1[++len1]=p[i];
            }
            t[p[i].id].sum=t[p[i].id].num;
            // cout<<t[i].num<<'\n';
        }
        for(int i=1;i<=len2/2;i++)swap(q2[i],q2[len2-i+1]);
        root[id[r]]=0;
        now[1]=now[2]=now[3]=1;
        for(int i=L[id[r]];i<=R[id[r]];i++){
            int x=0,P=0;
            if(now[1]<=len1&&(!x||t[x].num>q1[now[1]].num))x=q1[now[1]].id,P=1;
            if(now[2]<=len2&&(!x||t[x].num>q2[now[2]].num))x=q2[now[2]].id,P=2;
            if(now[3]<=len3&&(!x||t[x].num>q3[now[3]].num))x=q3[now[3]].id,P=3;
            p[i].id=x;
            now[P]++;
        }
        root[id[r]]=build(L[id[r]],R[id[r]]);
		return;
	}
	for(int i=id[l]+1;i<id[r];i++){
		int x,y;

		t[root[i]].lazy2+=k;
		t[root[i]].num=t[root[i]].num-k;
		t[root[i]].sum=t[root[i]].sum-k*t[root[i]].sz;
		split(root[i],-1,x,y);
        // dfs(x);
		t[x].lazy1*=-1;
		t[x].num*=-1;
		t[x].sum*=-1;
		t[x].lazy2*=-1;
        swap(t[x].l,t[x].r);

        // cout<<"!"<<endl;

        // dfs(y);
        t[y].lazy2-=k*2;
        t[y].num=t[y].num+k*2;
        t[y].sum=t[y].sum+k*2*t[y].sz;
		root[i]=merge(x,y);
	}

    // return;

    // down2(root[id[l]]);
    // for(int i=l;i<=R[id[l]];i++){
    //     ll num=t[i].num;
    //     // cout<<t[i].num<<" ";
    //     if(t[i].num<k)t[i].num=k-t[i].num;
    //     else t[i].num=k+t[i].num;
    //     // cout<<t[i].num<<'\n';
    // }
    // root[id[l]]=0;
    // for(int i=L[id[l]];i<=R[id[l]];i++){
    //     t[i].l=t[i].r=0;
    //     t[i].sz=1;
    //     t[i].sum=t[i].num;
    //     p[i].num=t[i].num;
    //     p[i].id=i;
    // }
    // sort(p+L[id[l]],p+R[id[l]]+1);
    // for(int i=L[id[l]];i<=R[id[l]];i++){
    //     root[id[l]]=merge(root[id[l]],p[i].id);
    // }


	// down2(root[id[r]]);
	// for(int i=L[id[r]];i<=r;i++){
    //     ll num=t[i].num;
    //     // cout<<t[i].num<<" ";
    //     if(t[i].num<k)t[i].num=k-t[i].num;
    //     else t[i].num=k+t[i].num;
    //     // cout<<t[i].num<<'\n';
    // }
    // root[id[r]]=0;
    // for(int i=L[id[r]];i<=R[id[r]];i++){
    //     t[i].l=t[i].r=0;
    //     t[i].sz=1;
    //     t[i].sum=t[i].num;
    //     p[i].num=t[i].num;
    //     p[i].id=i;
	// }
    // sort(p+L[id[r]],p+R[id[r]]+1);
    // for(int i=L[id[r]];i<=R[id[r]];i++){
    //     root[id[r]]=merge(root[id[r]],p[i].id);
    // }
    // return;

    cnt=L[id[l]];
    down3(root[id[l]]);
    len1=len2=len3=0;
    for(int i=L[id[l]];i<=R[id[l]];i++){
        t[i].l=t[i].r=0;
        t[i].sz=1;
        if(p[i].id>=l&&p[i].id<=r){
            ll num=t[p[i].id].num;
            // cout<<t[i].num<<" ";
            if(t[p[i].id].num<k){
                t[p[i].id].num=p[i].num=k-t[p[i].id].num;
                q2[++len2]=p[i];
            }else{
                t[p[i].id].num=p[i].num=k+t[p[i].id].num;
                q3[++len3]=p[i];
            }
        }else{
            q1[++len1]=p[i];
        }
        t[p[i].id].sum=t[p[i].id].num;
        // cout<<t[i].num<<'\n';
    }
    for(int i=1;i<=len2/2;i++)swap(q2[i],q2[len2-i+1]);
    // for(int i=1;i<len1;i++)if(q1[i].num>q1[i+1].num)cerr<<i<<" 233\n";
    // for(int i=1;i<len2;i++)if(q2[i].num>q2[i+1].num)cerr<<i<<" 2333\n";
    // for(int i=1;i<len3;i++)if(q3[i].num>q3[i+1].num)cerr<<i<<" 23333\n";
    root[id[l]]=0;
    now[1]=now[2]=now[3]=1;
    // sort(p+L[id[l]],p+R[id[l]]+1);
    for(int i=L[id[l]];i<=R[id[l]];i++){
        int x=0,P=0;
        if(now[1]<=len1&&(!x||t[x].num>q1[now[1]].num))x=q1[now[1]].id,P=1;
        if(now[2]<=len2&&(!x||t[x].num>q2[now[2]].num))x=q2[now[2]].id,P=2;
        if(now[3]<=len3&&(!x||t[x].num>q3[now[3]].num))x=q3[now[3]].id,P=3;
        p[i].id=x;
        now[P]++;
    }
    root[id[l]]=build(L[id[l]],R[id[l]]);

    cnt=L[id[r]];
    down3(root[id[r]]);
    len1=len2=len3=0;
    for(int i=L[id[r]];i<=R[id[r]];i++){
        t[i].l=t[i].r=0;
        t[i].sz=1;
        if(p[i].id>=l&&p[i].id<=r){
            ll num=t[p[i].id].num;
            // cout<<t[i].num<<" ";
            if(t[p[i].id].num<k){
                t[p[i].id].num=p[i].num=k-t[p[i].id].num;
                q2[++len2]=p[i];
            }else{
                t[p[i].id].num=p[i].num=k+t[p[i].id].num;
                q3[++len3]=p[i];
            }
        }else{
            q1[++len1]=p[i];
        }
        t[p[i].id].sum=t[p[i].id].num;
        // cout<<t[i].num<<'\n';
    }
    for(int i=1;i<=len2/2;i++)swap(q2[i],q2[len2-i+1]);
    root[id[r]]=0;
    now[1]=now[2]=now[3]=1;
    for(int i=L[id[r]];i<=R[id[r]];i++){
        int x=0,P=0;
        if(now[1]<=len1&&(!x||t[x].num>q1[now[1]].num))x=q1[now[1]].id,P=1;
        if(now[2]<=len2&&(!x||t[x].num>q2[now[2]].num))x=q2[now[2]].id,P=2;
        if(now[3]<=len3&&(!x||t[x].num>q3[now[3]].num))x=q3[now[3]].id,P=3;
        p[i].id=x;
        now[P]++;
    }
    root[id[r]]=build(L[id[r]],R[id[r]]);

    return;
}

inline ll query(int l,int r){
	ll ans=0;
	if(id[l]==id[r]){
		down2(root[id[l]]);
		for(int i=l;i<=r;i++){
            // cout<<t[i].num<<" ";
			ans+=t[i].num;
		}
		return ans;
	}

	for(int i=id[l]+1;i<id[r];i++){
		ans+=t[root[i]].sum;
	}
    // cout<<ans<<" ";

	down2(root[id[l]]);
	for(int i=l;i<=R[id[l]];i++){
		ans+=t[i].num;
	}
    // cout<<ans<<" ";

	down2(root[id[r]]);
	for(int i=L[id[r]];i<=r;i++){
		ans+=t[i].num;
        // cout<<t[i].num<<" ";
	}
    // cout<<ans<<" ";

	return ans;
}

signed main(){
//    freopen("data4.in","r",stdin);
//    freopen("data4.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		len=sqrt(n);
		for(int i=1;i<=n;i++)root[id[i]]=L[id[i]]=R[id[i]]=0;
		for(int i=1;i<=n;i++){
			id[i]=(i-1)/len+1;
			if(!L[id[i]])L[id[i]]=i;
			R[id[i]]=i;
            // cout<<id[i]<<" ";
		}
        // cout<<'\n';
		for(int i=1;i<=n;i++){
			cin>>a[i];
			t[i].num=t[i].sum=a[i];
			t[i].lazy1=1;
			t[i].l=t[i].r=t[i].lazy2=0;
			t[i].sz=1;
			t[i].rnd=rand();
			int x,y;
			split(root[id[i]],t[i].num,x,y);
			root[id[i]]=merge(merge(x,i),y);
		}
		for(int i=1;i<=m;i++){
			int opt;
			cin>>opt;
			if(opt==1){
				int l,r,x;
				cin>>l>>r>>x;
				change(l,r,x);
			}else{
				int l,r;
				cin>>l>>r;
				cout<<query(l,r)<<'\n';
			}
		}
	}
	return 0;
}
