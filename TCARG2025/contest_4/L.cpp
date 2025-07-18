#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define mset(a,v) memset((a),(v),sizeof(a))
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;

const ld EPS = 1e-6;

ld dp[(1<<20) + 1];
pair<ld,pair<int,int>> a[21];

ll n,l,r;

ld get(ld x1, ld x2, ld y2, ld ang){
	ld xaux = x2 - x1;
	ld alph = atan2(y2,xaux);
	ld beta = acos(-1.0) - alph - ang;
	ld b = sqrt((x2-x1)*(x2-x1) + (y2)*(y2));
	if(alph + ang >= acosl(-1.0) - ld(EPS)) {return ld(r);}
	ld c = (b*sin(ang))/sin(beta);
	return x1+c;
}

void f(int mask){
	if(mask == (1<<n) - 1) return;
	ld pos = dp[mask];
	ld npos = ld(l);

	// con la cantidad de bits prendidos de la mascara
	// voy a ver cual es el mejor candidato
	// luego la respuesta

	fore(i,0,n){
        if(!((1<<i) & mask)){
            // significa que esta lampara no la use
			ld npos = get(pos, ld(a[i].snd.fst), ld(a[i].snd.snd), a[i].fst);
			dp[mask|(1<<i)] = max(dp[mask|(1<<i)], npos);
        }
    }

	return;
}


int main(){
    FIN;
    ll t = 1;
    while(t--){
		cin >> n >> l >> r;
		fore(i,0,(1<<n)) dp[i] = ld(l);
		fore(i,0,n){
			int x, y, c; cin >> x >> y >> c;
			ld nc = ld(c) * (acos(-1.0)/ld(180.));
			a[i].fst = nc; a[i].snd.fst = x; a[i].snd.snd = y;
		}
		dp[0] = ld(l);
		fore(mask,0,1<<n){
			f(mask);
		}
		cout << setprecision(7) << fixed << min(ld(r-l),dp[(1<<n)-1] - ld(l)) << "\n";
    }
}