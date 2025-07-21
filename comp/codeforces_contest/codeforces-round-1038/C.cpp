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

bool compare(pair<pll,pll> a, pair<pll,pll> b) {
    return a.fst.fst < b.fst.fst;
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pll> a(n);
        fore(i,0,n)cin >> a[i].fst >> a[i].snd;
        // busco el mas lejos respecto al (0,0)
        ll pos = 0;
        ll dist_aux = 0;
        fore(i,0,n){
            if(abs(a[i].fst) + abs(a[i].snd) > dist_aux){
                pos = i;
                dist_aux = abs(a[i].fst) + abs(a[i].snd);
            }
        }
        ll x,y; x = a[pos].fst, y = a[pos].snd;
        // ahora que tengo mi par mas lejano, ordeno el resto respecto a ese par
        vector<pair<pll,pll>> b;
        fore(i,0,n){
            ll dist = abs(x-a[i].fst) + abs(y-a[i].snd);
            b.pb(make_pair(make_pair(dist,i),make_pair(a[i].fst,a[i].snd)));
        }
        sort(ALL(b),compare);
        ll suma = 0;
        fore(i,0,n/2){
            suma += abs(b[i].snd.fst - b[n-1-i].snd.fst) + abs(b[i].snd.snd - b[n-1-i].snd.snd);
            cout << b[i].fst.snd + 1 << " " << b[n-1-i].fst.snd + 1 << "\n";
        }
        DGB(suma);
    }
    return 0;
}