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
typedef pair<ll,ll> ii;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &color, ll c) {
    vis[v] = true;

    if(color[v]==-1) color[v] = c;

    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis, color, 1-c);
        }
    }
}

bool isBip(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &color){
    vis[v] = true;

    for (ll u : g[v]) {
        if(color[v] == color[u]) return false;
    }

    return true;
}

int main(){
    FIN;
    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> g(n);
    fore(i,0,m){
        ll a,b; cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> vis(n,false), vis2(n,false);
    vector<ll> color(n,-1);

    // coloreo
    fore(i,0,n){
        dfs(i,g,vis,color,0);
    }
    
    // chequeo
    bool flag = true;
    fore(i,0,n){
        if(!isBip(i,g,vis2,color)){
            flag = false;
        }
    }

    if(!flag){
        cout << "IMPOSSIBLE\n";
    } else{
        fore(i,0,n) cout << color[i]+1 << " ";
        cout << "\n";
    }
}