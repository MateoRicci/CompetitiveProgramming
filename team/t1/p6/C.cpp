#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<bool> &done, vector<ll> &ind) {
    ll res = 1;
    vis[v] = true;
    for (ll u : g[v]) {
        ind[u]--;
        if (!vis[u] && done[u] && ind[u]==0) {
            res += dfs(u, g, vis, done, ind);
        }
    }
    return res;
}

int main(){
    FIN;
    ll n,m; cin >> n >> m;
    vector<ll> ind(n,0);
    vector<bool> done(n,false);
    vector<vector<ll>> g(n);

    fore(i,0,m){
        ll a,b; cin >> a >> b; a--; b--;
        g[a].pb(b);
        ind[b]++;
    }
    vector<bool> vis(n);
    ll res = 0; 
    fore(i,0,n){
        ll mat; cin >> mat; mat--;
        done[mat] = true;

        if(ind[mat]==0){
            res += dfs(mat, g, vis, done, ind);
        }
        cout << res << "\n";
    }

    return 0;
}

// Cueste lo que cueste el sabado tenemos que ganar