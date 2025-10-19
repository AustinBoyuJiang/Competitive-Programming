#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<ctime>
#include<queue>
#define eps 1e-8
using namespace std;
using int64=long long;
using uint64 = unsigned long long;
const double pi = acos(-1);
const double PI = acos(-1);
inline int sign(int64 k) {
	if(k > 0) {
		return 1;
	} else if(k < 0) {
		return -1;
	}
	return 0;
}
inline int sign(double k) {
	if(k > eps) {
		return 1;
	} else if(k < -eps) {
		return -1;
	}
	return 0;
}
double pow2(double x){return x*x;}

inline int comp(int64 k1 , int64 k2) {
	return sign(k1 - k2);
}
inline int comp(double k1 , double k2) {
	return sign(k1 - k2);
}

inline double sqr(double x){
	return x*x;
}

struct dbPoint {
	double x , y;

	dbPoint(double _x = 0 , double _y = 0) : x(_x) , y(_y) {}
	dbPoint operator + (const dbPoint &rhx) const {
		return (dbPoint){x + rhx.x , y + rhx.y};
	}
	dbPoint operator - (const dbPoint &rhx) const {
		return (dbPoint){x - rhx.x , y - rhx.y};
	}
	dbPoint operator * (const double &k) const {
		return (dbPoint){x * k , y * k};
	}
	dbPoint operator / (const double &k) const {
		return dbPoint(1.0*x / k , 1.0*y / k);
	}

	int operator ==(const dbPoint &rhx) const {
		return comp(x , rhx.x) == 0 && comp(y , rhx.y) == 0;
	}
	int operator !=(const dbPoint &rhx) const {
		return !((*this)==rhx);
	}
/*	Point turn(double k) {
		return (Point){x * cos(k) - y * sin(k) , x * sin(k) + y * cos(k)};
	}*/
	dbPoint turn90() {
		return (dbPoint){-y , x};
	}
	int operator <(const dbPoint &rhx) const {
		int d = comp(x , rhx.x);
		switch(d) {
			case -1:
				return 1;
			case 1:
				return 0;
			default:
				return comp(y , rhx.y) == -1;
		}
	}
	double abs() {
		return sqrt(x * x + y * y);
	}
	double abs2() {
		return x * x + y * y;
	}
	double dis(const dbPoint &rhx) const {
		return (*(this) - rhx).abs();
	}
	dbPoint getdel() { // ?
		if(sign(x) == -1 || (sign(x) == 0 && sign(y) == -1)) {
			return (*this) * (-1);
		} else {
			return (*this);
		}
	}
	int getP() const {
		return sign(y) == 1 || (sign(y) == 0 && sign(x) == 1);
	}
	void Print(){
		printf("%lf %lf\n",x,y);
	}
};
struct  Point  {
	int64 x , y;

	Point(int64 _x = 0 , int64 _y = 0) : x(_x) , y(_y) {}
	Point operator + (const Point &rhx) const {
		return (Point){x + rhx.x , y + rhx.y};
	}
	Point operator - (const Point &rhx) const {
		return (Point){x - rhx.x , y - rhx.y};
	}
	Point operator * (const int64 &k) const {
		return (Point){x * k , y * k};
	}
	/*dbPoint operator * (const double &k) const {
		return (dbPoint){1.0*x * k , 1.0*y * k};
	}*/
	
	int64 cross(Point _)const{
		return x*_.y-y*_.x;
	}
	int64 cross(Point a,Point b)const{
		return (a-*this).cross(b-*this);
	}
	int operator ==(const Point &rhx) const {
		return comp(x , rhx.x) == 0 && comp(y , rhx.y) == 0;
	}
	int operator !=(const Point &rhx) const {
		return !((*this)==rhx);
	}
/*	Point turn(double k) {
		return (Point){x * cos(k) - y * sin(k) , x * sin(k) + y * cos(k)};
	}*/
	Point turn90() {
		return (Point){-y , x};
	}
	int operator <(const Point &rhx) const {
		int d = comp(x , rhx.x);
		switch(d) {
			case -1:
				return 1;
			case 1:
				return 0;
			default:
				return comp(y , rhx.y) == -1;
		}
	}
	double abs() {
		return sqrt(x * x + y * y);
	}
	int64 abs2() {
		return x * x + y * y;
	}
	double dis(const Point &rhx) const {
		return (*(this) - rhx).abs();
	}
	Point getdel() { // ?
		if(sign(x) == -1 || (sign(x) == 0 && sign(y) == -1)) {
			return (*this) * (-1);
		} else {
			return (*this);
		}
	}
	int getP() const {
		return sign(y) == 1 || (sign(y) == 0 && sign(x) == 1);
	}
	void Print(){
		printf("%lld %lld\n",x,y);
	}
	dbPoint Change(){
		return (dbPoint){1.0*x,1.0*y};
	}
};

// L -> Line , S -> Segment
int inside(Point k1 , Point k2 , Point k3) { // k3 in [k1 , k2]
	return inside(k1.x , k2.x , k3.x) && inside(k1.y , k2.y , k3.y);
}
int64 dot(Point k1 , Point k2) {
	return k1.x * k2.x + k1.y * k2.y;
}
int64 cross(Point k1 , Point k2) {
	return k1.x * k2.y - k1.y * k2.x;
}
double cross(pair<double,double> k1 , pair<double,double> k2) {
	return k1.first * k2.second - k1.second * k2.first;
}
double cross(dbPoint k1 , dbPoint k2) {
	return k1.x * k2.y - k1.y * k2.x;
}

bool cmp(Point K1,Point K2){//jijiao sort
    if(K1.getP()!=K2.getP()){
        return K1.getP()==1;
    }else{
        return cross(K1,K2)>0;
    }
}

double get_angle(Point x,Point y){
	return acosl((x.abs2()+y.abs2()-x.dis(y)*x.dis(y))/(2.0l*x.abs()*y.abs()));
}
int checkLS(Point k1,Point k2,Point k3,Point k4){
	Point v=k2-k1;
	Point l=k3-k1,r=k4-k1;
	//if(cross(l,r)<0)swap(l,r);
	//printf("%lf %lf %lf\n",get_angle(v,Point(1,0)),get_angle(l,Point(1,0)),get_angle(r,Point(1,0)));
	//v.Print();l.Print();r.Print();
	//printf("@%lld @%lld\n",cross(l,v),cross(v,r));
	return sign(cross(l,v))*sign(cross(v,r))>=0;
}
Point Base;
bool cmp_cc(const Point x,const Point y){
	return Base.cross(x,y)>0;
}
bool Contain_convex(const vector<Point>&A,Point p){
	assert((int)A.size()>=3);
	Base=A[0];
	if(Base.cross(p,A[1])>0||Base.cross(p,A.back())<0)return false;
	//if(Base.cross(p,A[1])==0)puts("@");
	if(Base.cross(p,A[1])==0){
		if((p-Base).abs2()<=(A[1]-Base).abs2())return true;
		return false;
	}
	//if(Base.cross(p,A[1])==0&&(p-Base).abs2()>(A[1]-Base).abs2())return true;
	int i=lower_bound(A.begin(),A.end(),p,cmp_cc)-A.begin()-1;
	int j=i+1;
	assert(i>=0);
	assert(j<(int)A.size());
	return (A[i].cross(A[j],p))>=0ll;
}
int clockwise(Point k1 , Point k2) { //
	return sign(cross(k1,k2));
}
vector<Point> ConvexHull(vector<Point>A,int flag=1){//flag =0 not yange flag=1 yange
	int n=A.size();vector<Point>ans(n*2);
	sort(A.begin(),A.end());int now=-1;
	for(int i=0;i<n;i++){
		while(now>0&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag)now--;
		ans[++now]=A[i];
	}int pre=now;
	for(int i=n-2;i>=0;i--){
		while(now>pre&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag)now--;
		ans[++now]=A[i];
	}ans.resize(now);return ans;
}
vector<Point> Minkowski(vector<Point>A,vector<Point>B){
    vector<Point>C(A.size()+B.size()+1),v1(A.size()),v2(B.size());
	for(int i=0;i<(int)A.size();i++)v1[i]=A[(i+1)%A.size()]-A[i];
    for(int i=0;i<(int)B.size();i++)v2[i]=B[(i+1)%B.size()]-B[i];
    int cnt=0;
    C[cnt]=(A[0]+B[0]);
    int p1=0,p2=0;
    while(p1<(int)A.size()&&p2<(int)B.size()){
        ++cnt;
        if(sign(cross(v1[p1],v2[p2]))>=0)
            C[cnt]=C[cnt-1]+v1[p1++];
        else 
            C[cnt]=C[cnt-1]+v2[p2++];
    }
    while(p1<(int)A.size()){
        ++cnt;
        C[cnt]=C[cnt-1]+v1[p1++];
    }
    while(p2<(int)B.size()){
        ++cnt;
        C[cnt]=C[cnt-1]+v2[p2++];
    }
    return C;
}
struct Circle {
	Point o ; double r;
	int inside(Point k) {
		return comp(r , o.dis(k));
	}
	double area(){
		return PI*r*r;
	}
};
double TriAngleCircleInsection(Circle C, Point A, Point B)
{
    Point OA=A-C.o,OB=B-C.o;
    Point BA=A-B, BC=C.o-B;
    Point AB=B-A, AC=C.o-A;
    double DOA=OA.abs(),DOB=OB.abs(),DAB=AB.abs(),r=C.r;
    if(sign(cross(OA,OB))==0) return 0;
    if(sign(DOA-C.r)<0&&sign(DOB-C.r)<0) return cross(OA,OB)*0.5; 
    else if(DOB<r&&DOA>=r)
    {
        double x=(dot(BA,BC)+sqrt(r*r*DAB*DAB-cross(BA,BC)*cross(BA,BC)))/DAB;
        double TS=cross(OA,OB)*0.5;
        return asin(TS*(1-x/DAB)*2/r/DOA)*r*r*0.5+TS*x/DAB;
    }
    else if(DOB>=r&&DOA<r)
    {
        double y=(dot(AB,AC)+sqrt(r*r*DAB*DAB-cross(AB,AC)*cross(AB,AC)))/DAB;
        double TS=cross(OA,OB)*0.5;
        return asin(TS*(1-y/DAB)*2/r/DOB)*r*r*0.5+TS*y/DAB;
    }
    else if(fabs(cross(OA,OB))>=r*DAB||dot(AB,AC)<=0||dot(BA,BC)<=0)
    {
        if(dot(OA,OB)<0){
            if(cross(OA,OB)<0) return (-acos(-1.0)-asin(cross(OA,OB)/DOA/DOB))*r*r*0.5;
            else  return ( acos(-1.0)-asin(cross(OA,OB)/DOA/DOB))*r*r*0.5;
        }
        else      {
			return asin(cross(OA,OB)/DOA/DOB)*r*r*0.5;
		}
    }
    else
    {
        double x=(dot(BA,BC)+sqrt(r*r*DAB*DAB-cross(BA,BC)*cross(BA,BC)))/DAB;
        double y=(dot(AB,AC)+sqrt(r*r*DAB*DAB-cross(AB,AC)*cross(AB,AC)))/DAB;
        double TS=cross(OA,OB)*0.5;
        return (asin(TS*(1-x/DAB)*2/r/DOA)+asin(TS*(1-y/DAB)*2/r/DOB))*r*r*0.5 + TS*((x+y)/DAB-1);
    }
}
double Get_Area(vector<Point>A,Circle X){
	double res=0.0;
	int n=(int)A.size();
	A.push_back(A[0]);
	for(int i=0;i<n;i++){
		res+=TriAngleCircleInsection(X,A[i],A[i+1]);
	}
	return fabs(res);
}
double Get_ans(vector<Point>A,vector<Point>B,Circle X){
	int n=(int)A.size();
	for(int i=0;i<n;i++){
        A[i].x=-A[i].x;
        A[i].y=-A[i].y;
    }
    A=ConvexHull(A,1);
    B=ConvexHull(B,1);
    vector<Point>C=Minkowski(A,B);
    C=ConvexHull(C,1);
    return 1.0*Get_Area(C,X)/X.area();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
	    scanf("%d",&n);
	    vector<Point>A(n);
	    for(int i=0;i<n;i++)scanf("%lld%lld",&A[i].x,&A[i].y);
	    scanf("%d",&m);
	    vector<Point>B(m);
	    for(int i=0;i<m;i++)scanf("%lld%lld",&B[i].x,&B[i].y);
	    Circle X;
	    scanf("%lld%lld%lf",&X.o.x,&X.o.y,&X.r);
	    printf("%.4lf\n",Get_ans(A,B,X));
	}
	return 0;
}
