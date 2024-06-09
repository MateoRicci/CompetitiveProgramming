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
vector<vector<ll>> p(2);
bool check = true;
void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &c) {
    vis[v] = true;
    if(c[v] == 0){
        c[v] = 1;
        p[0].pb(v);
    }
    for (ll u : g[v]) {
        if (!vis[u] && check) {
            if(c[v]==1){
                c[u] = 2;
                p[1].pb(u);
            }
            else if(c[v]==2){
                c[u] = 1;
                p[0].pb(u);
            }
            dfs(u, g, vis, c);
        }
        if(c[v] == c[u]) check = false;
    }
}

int main(){
    FIN;

    cin >> n >> m;

    vector<vector<ll>> g(n);
    fore(i,0,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ll> c(n,0);

    vector<bool> vis(n);
    fore(i,0,n){
        dfs(i,g,vis,c); 
    }
    
    if(!check) cout << -1 << "\n";
    else{
        cout << SZ(p[1]) << "\n";

        for(auto k : p[1]) {
            cout << k + 1 << " ";
        }
        cout << "\n";
        cout << SZ(p[0]) << "\n";
        for(auto k : p[0]) {
            cout << k + 1 << " ";
        }
        cout << "\n";
    }
    
    return 0;

}