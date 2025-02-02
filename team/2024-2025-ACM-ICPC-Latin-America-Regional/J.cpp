#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
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

const double pi = acos(-1);

double g_to_rad(double alph){
    return (pi/double(180)) * alph;
}

double calc_z(ll h, double alph){
    double hip = double(h) / sin(g_to_rad(alph));
    return sqrt((hip*hip) - (h*h));
}


int main(){
    FIN;
    double alph; ll n;
    cin >> alph >> n;
    vector<ii> p(n);
    fore(i,0,n) cin >> p[i].fst >> p[i].snd;
    sort(ALL(p));
    double res = calc_z(p[0].snd, alph);
    double largest_end = calc_z(p[0].snd, alph)+p[0].fst;
    fore(i,1,n){
        // me fijo que queda mas lejos, el final anterior o el inicio actual
        largest_end = max((double)p[i].fst, largest_end);

        res += max(0.0, calc_z(p[i].snd, alph) + (double)p[i].fst - largest_end);

        // seteo un nuevo final en caso de ser necesario
        largest_end = max(calc_z(p[i].snd, alph) + (double)p[i].fst, largest_end);
    }
    cout << setprecision(6) << fixed << res << "\n";
    return 0;
}