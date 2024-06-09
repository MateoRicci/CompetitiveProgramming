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

int dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &sub) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            sub[v] += dfs(u, g, vis,sub);
            sub[v] += sub[u];
        }
    }
    return 1;
}

int main(){
    FIN;
	ll n;
	cin >> n;
    vector<vector<ll>> g(n);
    fore(i,1,n){
        ll aux; cin >> aux;
        g[aux-1].pb(i);
        g[i].pb(aux-1);
    }

    vector<bool> vis(n);
    vector<ll> sub(n, 0);

    dfs(0,g,vis,sub);

    for(auto k : sub){
        cout << k << " ";
    }
    cout << "\n";

    // dfs partiendo de la raiz, anotando los padres


}