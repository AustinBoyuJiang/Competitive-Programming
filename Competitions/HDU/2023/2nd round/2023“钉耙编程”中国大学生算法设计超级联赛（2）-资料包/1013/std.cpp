#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
typedef double vec_type;
double eps=1e-6;
typedef pair<int,int> pii;
inline int sign(int v){
	if(v<0)
		return -1;
	if(v>0)
		return 1;
	return 0;
}
inline int sign(double v){
	if(abs(v)<eps)
		return 0;
	if(v<0)
		return -1;
	if(v>0)
		return 1;
	return -2;
}
struct vec2{
	vec_type x,y;
	vec2(){
		x=0;
		y=0;
	}
	vec2(vec_type x,vec_type y){
		this->x=x;
		this->y=y;
	}
	vec2& operator+=(const vec2& b){
		x+=b.x;
		y+=b.y;
		return *this;
	}
	vec2 operator+(const vec2& b)const{
		vec2 ret=*this;
		ret+=b;
		return ret;
	}
	vec2& operator-=(const vec2& b){
		x-=b.x;
		y-=b.y;
		return *this;
	}
	vec2 operator-(const vec2& b)const{
		vec2 ret=*this;
		ret-=b;
		return ret;
	}
	vec2& operator*=(vec_type v){
		x*=v;
		y*=v;
		return *this;
	}
	vec2 operator*(vec_type v)const{
		vec2 ret=*this;
		ret*=v;
		return ret;
	}
	vec2& operator/=(vec_type v){
		x/=v;
		y/=v;
		return *this;
	}
	vec2 operator/(vec_type v)const{
		vec2 ret=*this;
		ret/=v;
		return ret;
	}
	vec_type operator^(const vec2&  b)const{
		return x*b.y-y*b.x;
	}
	int operator<(const vec2& b)const{
		if(sign(x-b.x)==0)
			return y<b.y;
		return x<b.x;
	}
	int operator==(const vec2& b)const{
		if(sign(x-b.x))
			return 0;
		if(sign(y-b.y))
			return 0;
		return 1;
	}
	vec2 normalize()const{
		double v=hypot(x,y);
		return vec2(x/v,y/v);
	}
};
struct line{
	vec2 p,v;
	line(vec2 p,vec2 v){
		this->p=p;
		this->v=v;
	}
	line(){
	}
	double get_k(){
		return v.y/v.x;
	}
	double get_ik(){
		return v.x/v.y;
	}

};
struct segment{
	vec2 p1,p2,v;
	line l;
	segment(vec2 p1,vec2 p2){
		this->p1=p1;
		this->p2=p2;
		v=p2-p1;
		this->l.p=p1;
		this->l.v=v;
	}
	segment(){}
};
double distance(const vec2& a, const vec2& b){
	return hypot(a.x-b.x,a.y-b.y);
}
double distance(const vec2& p, const line& l){
	return abs((p-l.p)^l.v.normalize());
}
int point_is_point(const vec2& a,const vec2& b){
	return sign(distance(a,b))==0;
}
int point_line_side(const vec2& point, const line& line){
	return sign(line.v^(point-line.p));
}
int parallel(const line& a,const line &b){
	vec2 v1=a.v.normalize();
	vec2 v2=b.v.normalize();
	if(sign(v1^v2)==0)
		return 1;
	return 0;
}
int point_on_sigment(const vec2& point, const segment& segment){
	if(point_is_point(point,segment.p1)||point_is_point(point,segment.p2))
		return 1;
	if(sign((point-segment.p1)^segment.v)!=0)
		return 0;
	if(
		point.x>min(segment.p1.x,segment.p2.x)-eps&&
		point.x<max(segment.p1.x,segment.p2.x)+eps&&
		point.y>min(segment.p1.y,segment.p2.y)-eps&&
		point.y<max(segment.p1.y,segment.p2.y)+eps)
		return 1;
	return 0;
}
int segment_cross(const segment& s1,const segment& s2){
	// 0 not cross
	// 1 cross
	// 2 vertex collision, s2.p1 on s1
	// 3 vertex collision, s2.p2 on s1
	if(abs(s1.v^s2.v)<eps)
		return 0;
	vec_type x1,x2,x3,x4;
	vec_type y1,y2,y3,y4;
	x1=min(s1.p1.x,s1.p2.x);
	x2=max(s1.p1.x,s1.p2.x);
	y1=min(s1.p1.y,s1.p2.y);
	y2=max(s1.p1.y,s1.p2.y);

	x3=min(s2.p1.x,s2.p2.x);
	x4=max(s2.p1.x,s2.p2.x);
	y3=min(s2.p1.y,s2.p2.y);
	y4=max(s2.p1.y,s2.p2.y);

	if(x3>x2||x1>x4)
		return 0;
	if(y3>y2||y1>y4)
		return 0;
	if(point_on_sigment(s2.p1,s1))
		return 2;
	if(point_on_sigment(s2.p2,s1))
		return 3;
	if(
		point_on_sigment(s1.p1,s2)||
		point_on_sigment(s1.p2,s2))
		return 4;

	if(
		point_line_side(s1.p1,s2.l)*point_line_side(s1.p2,s2.l)==-1&&
		point_line_side(s2.p1,s1.l)*point_line_side(s2.p2,s1.l)==-1)
		return 1;
	return 0;
}

vector<vec2> convex_hull(vector<vec2>&dta){
	vector<int> vec;
	vector<vec2> ret;
	vector<int> used(dta.size());
	sort(dta.begin(),dta.end(),[](vec2 a,vec2 b){
		if(a.x==b.x)
			return a.y<b.y;
		return a.x<b.x;
	});
	vec.push_back(0);
	for(int i=1,tp;i<dta.size();i++){
		tp=vec.size()-1;
		while(vec.size()>=2&&(((dta[vec[tp]]-dta[vec[tp-1]])^(dta[i]-dta[vec[tp]]))<=0)){
			used[vec.back()]=0;
			vec.pop_back();
			tp--;
		}
		used[i]=1;
		vec.push_back(i);
	}
	int tmp=vec.size();
	for(int i=dta.size()-1,tp;i>=0;i--)
		if(!used[i]){
			tp=vec.size()-1;
			while(vec.size()>tmp&&(((dta[vec[tp]]-dta[vec[tp-1]])^(dta[i]-dta[vec[tp]]))<=0)){
				vec.pop_back();
				tp--;
			}
			vec.push_back(i);
		}
	vec.pop_back();
	for(auto e:vec)
		ret.push_back(dta[e]);
	return ret;
}
vec2 line_intersection(const line& l1,const line& l2){
	double k=((l2.p-l1.p)^l2.v)/(l1.v^l2.v);
	return l1.p+l1.v*k;
}
vector<vec2>dta[21];
vector<segment> segs;
vector<segment> edges;
vector<vec2> points;
segment ray_to_segment(vec2 p1,vec2 p2){
	vec2 v=(p2-p1).normalize();
	p2=p1+v*1.5e5;
	return segment(p1,p2);
}
void get_tan(int i,int j){
	vec2 p=dta[i][0];
	vec2 v1,v2,v3;
	for(int k=0;k<dta[j].size();k++){
		if(point_is_point(p,dta[j][k]))
			continue;
		if(k==0){
			v1=dta[j][k]-dta[j].back();
		}else{
			v1=dta[j][k]-dta[j][k-1];
		}
		if(k+1==dta[j].size()){
			v2=dta[j][0]-dta[j][k];
		}else{
			v2=dta[j][k+1]-dta[j][k];
		}
		v3=dta[j][k]-p;
		//TTT
		if((v1^v3)>-eps&&(v3^v2)>-eps){
			// cout<<"A"<<i<<' '<<j<<endl;
			segs.push_back(ray_to_segment(p,dta[j][k]));
		}else if((v1^v3)<eps&&(v3^v2)<eps){
			// cout<<"B"<<i<<' '<<j<<endl;
			segs.push_back(ray_to_segment(p,dta[j][k]));
		}
	}
}
void fst(vector<int> &a,bool inv){
	for(int n=a.size(),step=1;step<n;step*=2){
		for(int i=0;i<n;i+=2*step)
			for(int j=i;j<i+step;j++){
				int &u=a[j],&v=a[j+step];
				tie(u,v)=inv?pii(v,u-v):pii(u+v,u);
			}
	}
}
vector<int>vec;
int n;
double LIMIT=1e4;
int dp[40009];
int solve(){
	int nn=(1<<n)-1;
	for(int i=0;i<=nn;i++)
		dp[i]=100;
	dp[0]=0;
	int cnt=0;
	for(int i=nn;i>=0;i--){
		if(vec[i]){
			cnt++;
			for(int j=0;j<=nn;j++)
				if(dp[j]<100)
					dp[j|i]=min(dp[j|i],dp[j]+1);
		}
	}
	// cout<<n<<' '<<cnt<<endl;
	// for(int i=0;i<=nn;i++)
	// 	cout<<i<<' '<<dp[i]<<endl;
	return dp[nn];
}

int main(void){
	int t;
	int m;
	cin>>t;
	while(t--){
		cin>>n;
		vec.clear();
		vec.resize(1<<n);
		edges.clear();
		segs.clear();
		points.clear();
		double x,y;
		if(n==1){
			cout<<1<<endl;
			continue;
		}

		for(int i=0;i<n;i++){
			dta[i].clear();
			cin>>m;
			for(int j=0;j<m;j++){
				cin>>x>>y;
				dta[i].emplace_back(x,y);
			}
			for(int j=0;j+1<m;j++)
				edges.push_back(segment(dta[i][j],dta[i][j+1]));
			edges.push_back(segment(dta[i][m-1],dta[i][0]));
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				get_tan(i,j);
		segs.push_back(segment(vec2(0,0),vec2(LIMIT,0)));
		segs.push_back(segment(vec2(0,0),vec2(0,LIMIT)));
		segs.push_back(segment(vec2(LIMIT,0),vec2(LIMIT,LIMIT)));
		segs.push_back(segment(vec2(0,LIMIT),vec2(LIMIT,LIMIT)));
		for(int i=0;i<segs.size();i++)
			for(int j=i+1;j<segs.size();j++)
				if(segment_cross(segs[i],segs[j])){
					vec2 p=line_intersection(segs[i].l,segs[j].l);
					if(p.x<-eps || p.y<-eps || p.x>LIMIT+eps || p.y>LIMIT+eps)
						continue;
					points.push_back(p);
				}
		int vv=0;
		int cnt=0;
		map<vec2,int>mp;
		for(auto p:points){
			cnt++;
			int v=0;
			for(int i=0;i<n;i++){
				mp.clear();
				segment s(dta[i][0],p);
				bool flag=true;
				for(auto e:edges){
					int op=segment_cross(s,e);
					if(op==1){
						flag=false;
						break;
					}else if(op==2 || op==3){
						vec2 edge_p;
						if(op==2){
							edge_p=e.p1;
						}else{
							edge_p=e.p2;
						}
						if(mp.count(edge_p)){
							if(mp[edge_p]==sign(s.v^e.v)){
								if(edge_p==p && mp[edge_p]==-1)
									continue;
								if(edge_p==dta[i][0] && mp[edge_p]==1)
									continue;
								flag=false;
								break;
							}
						}else{
							mp[edge_p]=sign(s.v^e.v);
						}
					}
				}
				if(flag)
					v|=(1<<i);
				vv|=v;
			}
			vec[v]=1;
		}
		cout<<solve()<<endl;
	}
	return 0;
}
