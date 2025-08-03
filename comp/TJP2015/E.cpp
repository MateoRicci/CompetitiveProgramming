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
    ll n,m; cin >> n >> m;
    vector<ll> a(n,0);
    map<ll,ll> comp;
    set<ll> used;
    ll cont = 0;

    vector<ll> sis(n),tms(n);
    fore(i,0,n) cin >> sis[i];
    fore(i,0,n) cin >> tms[i];

    fore(i,0,n){
        ll s = sis[i], t = tms[i];
        if(!used.count(s)){
            // si no use esta mesada
            comp[s] = cont;
            a[cont] += t;
            cont++;
            used.insert(s);
        } else{
            a[comp[s]] += t;
        }
    }
    ll res = 0;
    for(auto val : a){
        res = max(res,val);
    }
    cout << res << "\n";
}
