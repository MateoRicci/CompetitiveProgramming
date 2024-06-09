#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool check = true;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;
    ll cant_l = 0;
    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
        if(SZ(g[u])==0) cant_l++;
    }
    if(SZ(g[v])!=0 && cant_l < 3){
        check = false;
    }
}

int main(){
    FIN;
    ll n;
	cin >> n;
    
    vector<vector<ll>> g(n);

    fore(i,1,n){
        ll aux; cin >> aux;
        g[aux-1].pb(i);
    }

    vector<bool> vis(n);
    dfs(0,g,vis);

    if(check) cout << "Yes\n";
    else cout<<"No\n";

}