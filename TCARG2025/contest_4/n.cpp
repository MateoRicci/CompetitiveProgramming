#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
ll n,l,obj;
const int maxn = 21;
ld dp[1<<maxn];


const ld EPS = 1e-8;
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return atan2(y,x) - atan2(p.y,p.x);}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};


ii coord[maxn];
ld ang[maxn];
const ld INF  = 1e7;

ld get(int i, ld ini){
    pt pt_aux((ld)coord[i].fst - ini, (ld)coord[i].snd);
    ld ang1 = pt_aux.angle(pt(5,0));
    ld angbueno = acos(-1)-ang1-ang[i];  
    ld lon =sqrt((ld)coord[i].snd * (ld)coord[i].snd + ((ld)coord[i].fst - ini) * ((ld)coord[i].fst-ini));
    if(angbueno <= 0) return INF;
    return lon / sin(angbueno) * sin(ang[i]) + ini;
}


ld f(ll mk){
    if(mk == 0 ) return l;
    ld &r = dp[mk];
    if(r>=-(1e6)) return r;
    fore(i,0,n){
        if(mk&(1<<i)){
            r = max(r,get(i,f(mk^(1<<i))));
        }
    }
    return r;
}


int main(){
    JET
    fore(i,0,1<<maxn) dp[i] = -INF;
    cin>>n>>l>>obj;
    fore(i,0,n){
        ll x,y,a; cin>>x>>y>>a;
        coord[i] = {x,y};
        ang[i] = (ld)a/(ld)180 * acos(-1);
    }
    cout<<fixed<<setprecision(7)<<min(f((1<<n)-1), (ld)obj) - (ld)l<<"\n";

    return 0;
}
