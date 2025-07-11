#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(ll a=b; a>=c; --a)
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

bool cmp(ii a, ii b){
    return a.snd < b.snd;
}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ii> islands(n);
        fore(i,0,n){
            cin >> islands[i].snd >> islands[i].fst;
        }
        set<ii> segments;
        fore(i,0,n-1){
            segments.insert({islands[i+1].fst - islands[i].snd, islands[i+1].snd - islands[i].fst});
        }
        vector<ll> p(m);
        fore(i,0,m){
            cin >> p[i];
        }
        vector<ll> res;
        for(auto puente : p){
            auto it = segments.lower_bound({puente,0});
            if(it == segments.end()) continue;
            ll l = it->snd, r = it->fst;
            if(!(puente >= l && puente <= r)) continue;

            

        }
        showAll(res);
    }
    return 0;
}