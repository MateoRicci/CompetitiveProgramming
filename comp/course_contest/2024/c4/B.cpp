#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n,m;

ll d(vector<vector<ll>> &g, ll i){
    ll grad = SZ(g[i]);
    return grad;

}

int main(){
    FIN;

    cin >> n >> m;

    vector<vector<ll>> g(n);
    ll res = 0;
    fore(i,0,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    fore(i,0,n){
        res += d(g,i);
    }
    cout << res << "\n";

}