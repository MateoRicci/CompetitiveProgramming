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

ll n,m;
void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
    }
}

bool valid(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}
ll get_id(ll i, ll j) {
    return i * m + j;
}
pair<ll, ll> get_ij(ll id) {
    return {id / m, id % m};
}

vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


int main(){
    FIN;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m));
	fore(i,0,n){
		fore(j,0,m){
            cin >> mat[i][j];
        }
	}

    vector<vector<ll>> g(n * m);
    fore(i, 0, n) fore(j, 0, m) {
        if (mat[i][j] == '#') continue;
        for (auto [di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (valid(ni, nj) && mat[ni][nj] == '.') {
                g[get_id(i, j)].push_back(get_id(ni, nj));
                g[get_id(ni, nj)].push_back(get_id(i, j));
            }
        }
    }


	vector<bool> vis(n*m, false);

    ll ans = 0;
    fore(id, 0, n * m) {
        auto [i, j] = get_ij(id);
        if (mat[i][j] == '#' || vis[id]) continue;
        ans++;
        dfs(id, g, vis);
    }

    cout << ans << "\n";

}