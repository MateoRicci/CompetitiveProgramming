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

bool cmp(pair<ii,ll> a, pair<ii,ll> b){
    return a.fst.snd < b.fst.snd;
}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ii> islands(n);
        fore(i,0,n){
            cin >> islands[i].fst >> islands[i].snd;
        }
        vector<pair<ii,ll>> segments(n-1);
        fore(i,0,n-1){
            segments[i] = {{islands[i+1].fst - islands[i].snd, islands[i+1].snd - islands[i].fst},i};
        }
        sort(ALL(segments),cmp);
        set<ii> puentes;
        fore(i,0,m){
            ll p; cin >> p; puentes.insert({p,i+1});
        }
        vector<ll> res(n-1,-1);
        for(auto seg : segments){
            ll l = seg.first.first;
            ll r = seg.first.second;
            ll i = seg.second;
            auto it = puentes.lower_bound({l,0});
            if(it == puentes.end()) continue;
            ll p = it->first;
            ll ip = it->second;
            if(p > r) continue;
            puentes.erase(it);
            res[i] = ip;
        }
        for(auto x : res){
            if(x==-1){
                show("No");
                return 0;
            }
        }
        show("Yes");
        showAll(res);
    }
    return 0;
}