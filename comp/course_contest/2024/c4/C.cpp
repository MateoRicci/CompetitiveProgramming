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

ll n;
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &d) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            d[u] = d[v]+1;
            dfs(u, g, vis,d);
        }
    }
}


int main(){
    FIN;

    cin >> n;

    vector<vector<ll>> g(n+1);
    ll res = 0;
    map<string,ll> map;
    vector<string> words;
    set<string> strs;
    ll count = 0;
    fore(i,0,n){
        string a,b,c;
        cin >> a >> b >> c;

        transform(a.begin(), a.end(), a.begin(), asciitolower);
        transform(c.begin(), c.end(), c.begin(), asciitolower);

        if(!(strs.find(c) != strs.end())) {
            map[c] = count;
            count++;
            strs.insert(c);
        }

        if(!(strs.find(a) != strs.end())) {
            map[a] = count;
            count++;
            strs.insert(a);
        }

        g[map[c]].pb(map[a]);
        g[map[a]].pb(map[c]);

    }

    vector<bool> vis(n+1);
    vector<ll> d(n+1, 0);

    dfs(0,g,vis,d);

    for(auto k : d){
        res = max(res,k);
    }

    cout << res+1 << "\n";

}