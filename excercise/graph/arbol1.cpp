#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &p) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            p[u] = v+1;
            dfs(u, g, vis,p);
        }
    }
}

int main(){
    FIN;
	ll n,r;
	cin >> n >> r;
    r--;
    vector<vector<ll>> g(n);
    fore(i,0,n-1){
        ii aux; cin >> aux.fst >> aux.snd;
        aux.fst--;
        aux.snd--;
        g[aux.first].pb(aux.snd);
        g[aux.snd].pb(aux.fst);
    }

    vector<bool> vis(n);
    vector<ll> p(n);

    dfs(r,g,vis,p);

    for(auto k : p){
        cout << k << " ";
    }
    cout << "\n";

    // dfs partiendo de la raiz, anotando los padres


}