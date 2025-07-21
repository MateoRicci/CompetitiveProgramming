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
typedef pair<ll,ll> pll;

bool cmp_snd(pair<pll,ll> a, pair<pll,ll> b){
    return a.fst.snd < b.fst.snd;
}


int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<pll,ll>> a(n);
        ll med_y = 0;
        fore(i,0,n) cin >> a[i].fst.fst >> a[i].fst.snd, med_y+=a[i].snd, a[i].snd = i;
        if(med_y < 0){
            med_y = (med_y-n+1) / n;
        } else{
            med_y = (med_y+n-1) / n;
        }
        // armamos los dos vectores
        vector<pair<pll,ll>> arriba;
        vector<pair<pll,ll>> abajo;
        sort(ALL(a),cmp_snd);
        fore(i,0,n/2){
            abajo.pb(a[i]);
        } fore(i,n/2,n){
            arriba.pb(a[i]);
        }
        assert(SZ(arriba) == SZ(abajo));
        sort(ALL(arriba));
        sort(ALL(abajo));
        // RAYA;
        // for(auto [a,x] : arriba) cout << x << " ";
        // show("");
        // for(auto [a,x] : abajo) cout << x << " ";
        // show("");
        // RAYA;
        vector<pll> res(SZ(arriba));
        ll suma = 0;
        fore(i,0,SZ(arriba)){
            res[i] = {arriba[i].snd,abajo[SZ(abajo)-1-i].snd};
            suma += abs(arriba[i].fst.fst - abajo[SZ(abajo)-1-i].fst.fst) + abs(arriba[i].fst.snd - abajo[SZ(abajo)-1-i].fst.snd);
        }
        // DGB(suma);

        for(auto [x,y] : res) cout << x+1 << " " << y+1 << "\n";
    }
}