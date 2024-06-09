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

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
    }
}


int main(){
    FIN;
    ll res = 0;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ii> p(n);

    fore(i,0,n){
        cin >> p[i].fst;
        p[i].snd = i;
    }

    fore(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    sort(ALL(p));
    vector<bool> vis(n);
    fore(i,0,n){
        if(!vis[p[i].snd]){
            res += p[i].fst;
            dfs(p[i].snd,g,vis);
        }
    }


    cout << res << "\n";

}