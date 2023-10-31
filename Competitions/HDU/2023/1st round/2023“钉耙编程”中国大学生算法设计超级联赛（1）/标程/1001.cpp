#include<cstdio>
#include<algorithm>
#include<cmath>
#define M 5005
using namespace std;
struct E{
	int to,nx;
}edge[M<<1];
int tot,head[M];
void Addedge(int a,int b){
	edge[++tot].to=b;
	edge[tot].nx=head[a];
	head[a]=tot;
}
int sz[M],son[M],top[M],dep[M];
int Dfn[M],Low[M],tot_dfs;
int fa[M];
void dfs(int now){
	Dfn[now]=++tot_dfs;
	sz[now]=1;son[now]=0;
	for(int i=head[now];i;i=edge[i].nx){
		int nxt=edge[i].to;
		if(nxt==fa[now])continue;
		fa[nxt]=now;
		dep[nxt]=dep[now]+1;
		dfs(nxt);
		sz[now]+=sz[nxt];
		if(sz[son[now]]<sz[nxt])son[now]=nxt;
	}
	Low[now]=tot_dfs;
}
void dfs_top(int now){
	if(son[now]){
		top[son[now]]=top[now];
		dfs_top(son[now]);
	}
	for(int i=head[now];i;i=edge[i].nx){
		int nxt=edge[i].to;
		if(nxt==fa[now]||nxt==son[now])continue;
		top[nxt]=nxt;
		dfs_top(nxt);
	}
}
int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])b=fa[top[b]];
		else a=fa[top[a]];
	}
	return dep[a]<dep[b]?a:b;
}
bool In(int x,int y){
	return Dfn[y]<=Dfn[x]&&Dfn[x]<=Low[y];
}
int mark[M];
struct Point{
	int a,b;
};
Point Data[M][2];
int exgcd(int a,int b,int &x,int &y){
	int d=a; if(b==0) x=1,y=0; else{
		d=exgcd(b,a%b,y,x),y-=a/b*x;
	}
	return d;
}
int Get_ans(Point p1,Point p2){
	int val=p2.b-p1.b;
	val%=p2.a;
	while(val<0)val+=p2.a;
	while(val>p2.a)val-=p2.a;
	int a=p1.a,b=-p2.a;
	int x,y,d=exgcd(a,b,x,y);
	if(val%d!=0)return 1e9;
	x*=val/d;y*=val/d;
	int p=b/d,q=a/d;
	if(x<0){
		int k=ceil((1.0-x)/p);
		x+=p*k,y-=q*k;
	}else if(x>=0){
		int k=(x-1)/p;
		x-=p*k,y+=q*k;
	}
	return a*x+p1.b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		tot=0;
		scanf("%d%d",&n,&m);
		tot_dfs=0;
		for(int i=1;i<=n;i++)head[i]=mark[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Addedge(a,b);
			Addedge(b,a);
		}
		dfs(1);
		top[1]=1;
		dfs_top(1);
		for(int step=1;step<=m;step++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(a==c){printf("%d\n",a);continue;}
			int x1=LCA(a,b),x2=LCA(c,d);
			if(dep[x1]>dep[x2]){
				swap(a,c);
				swap(b,d);
				swap(x1,x2);
			}
			if(!In(a,x2)&&!In(b,x2)){
				puts("-1");
				continue;
			}
			int d1=dep[a]+dep[b]-2*dep[x1],d2=dep[c]+dep[d]-2*dep[x2];
			int p=a;
			while(1){
				Data[p][0]=(Point){2*d1,dep[a]-dep[p]};
				Data[p][1]=(Point){2*d1,2*d1-(dep[a]-dep[p])};
				mark[p]=step;
				if(p==x1)break;
				p=fa[p];
			}
			p=b;
			while(p!=x1){
				Data[p][0]=(Point){2*d1,d1-(dep[b]-dep[p])};
				Data[p][1]=(Point){2*d1,d1+(dep[b]-dep[p])};
				mark[p]=step;
				p=fa[p];
			}
			
			int ans_val=1e9,ans=-1;
			p=c;
			while(1){
				Point p1=(Point){2*d2,dep[c]-dep[p]};
				Point p2=(Point){2*d2,2*d2-(dep[c]-dep[p])};
				if(mark[p]==step){
					int res=1e9;
					res=min(min(Get_ans(p1,Data[p][0]),Get_ans(p1,Data[p][1])),min(Get_ans(p2,Data[p][0]),Get_ans(p2,Data[p][1])));
					if(res<ans_val){
						ans_val=res;
						ans=p;
					}
				}
				if(p==x2)break;
				p=fa[p];
			}
			p=d;
			while(p!=x2){
				Point p1=(Point){2*d2,d2-(dep[d]-dep[p])};
				Point p2=(Point){2*d2,d2+(dep[d]-dep[p])};
				if(mark[p]==step){
					int res=1e9;
					res=min(min(Get_ans(p1,Data[p][0]),Get_ans(p1,Data[p][1])),min(Get_ans(p2,Data[p][0]),Get_ans(p2,Data[p][1])));
					if(res<ans_val){
						ans_val=res;
						ans=p;
					}
				}
				p=fa[p];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
