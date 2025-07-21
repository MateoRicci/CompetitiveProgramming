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

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pll> x(n), y(n);
        vector<pll> a(n);
        fore(i,0,n){
            cin >> x[i].fst >> y[i].fst, x[i].snd = i, y[i].snd = i;
            a[i] = make_pair(x[i].fst, y[i].fst);
        }
        sort(ALL(x));
        sort(ALL(y));
        ll suma = 0;
        fore(i,0,n/2){
            suma += abs(x[n-1-i].fst - x[i].fst) + abs(y[n-1-i].fst - y[i].fst);
        }
        set<pll> xs,ys;
        fore(i,0,n/2){
            xs.insert(make_pair(x[i].snd+1,x[n-1-i].snd+1));
            ys.insert(make_pair(y[i].snd+1,y[n-1-i].snd+1));
        }
        // ll suma2 = 0;
        // fore(i,0,n/2){
        //     ll i1 = x[i].snd;
        //     ll i2 = x[n-1-i].snd;
        //     suma2 += abs(a[i1].fst - a[i2].fst) + abs(a[i1].snd - a[i2].snd);
        // }
        // DGB(suma2);

        // suma2 = 0;
        // fore(i,0,n/2){
        //     ll i1 = y[i].snd;
        //     ll i2 = y[n-1-i].snd;
        //     suma2 += abs(a[i1].fst - a[i2].fst) + abs(a[i1].snd - a[i2].snd);
        // }
        // DGB(suma2);

        for(auto [a,b] : xs){
            cout << a << " " << b << "\n";
        }
        RAYA;
        for(auto [a,b] : ys){
            cout << a << " " << b << "\n";
        }
        // DGB(suma);
    }
}
