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
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> g(n);
	fore(i,0,m){
		ii e;
		cin >> e.fst >> e.snd;
		g[e.first-1].pb(e.snd-1);
		g[e.snd-1].pb(e.fst-1);
	}

    vector<ll> roads;
    vector<bool> vis(n, 0);
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            dfs(i, g, vis);
            roads.pb(i);
            count++;
        }
    }
    ll res = count - 1;

    cout << res << "\n";
    if(res>0){
        fore(i,0,SZ(roads)-1){
            cout << roads[i]+1 << " " << roads[i+1]+1 << "\n";
        }
    }
}