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
bool valid(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}
ll get_id(ll i, ll j) {
    return i * m + j;
}
pair<ll, ll> get_ij(ll id) {
    return {id / m, id % m};
}

void bfs(ll v, vector<vector<ll>> &g, vector<pair<bool,ii>> &vis) {
    queue<ll> q;
    vis[v].fst = true;
    q.push(v);
    while (!q.empty()) {

        v = q.front();
        q.pop();
        
        for (ll u : g[v]) {

            if (!vis[u].fst) {
				vis[u].fst = true;
				q.push(u);
                ii aux = get_ij(v);
                vis[u].snd = aux;

            }
        }
    }
}

vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


int main(){
    FIN;
	cin >> n >> m;
    ii a,b;
	vector<vector<char>> mat(n, vector<char>(m));
	fore(i,0,n){
		fore(j,0,m){
            cin >> mat[i][j];
            if(mat[i][j]=='A') a = {i,j};
            if(mat[i][j]=='B') b = {i,j};
        }
	}

    vector<vector<ll>> g(n * m);
    fore(i, 0, n) fore(j, 0, m) {
        if (mat[i][j] == '#') continue;
        for (auto [di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (valid(ni, nj) && (mat[ni][nj] == '.' || mat[ni][nj] == 'A' || mat[ni][nj] == 'B')) {
                g[get_id(i, j)].push_back(get_id(ni, nj));
                g[get_id(ni, nj)].push_back(get_id(i, j));
            }
        }
    }

    vector<pair<bool,ii>> vis(n*m, {false,{0,0}});
    bfs(get_id(a.fst,a.snd),g,vis);
    if(vis[get_id(b.fst,b.snd)].fst){
        cout << "YES\n";
        vector<char> res;
        vector<bool> vis2(n*m, false);
        ll pos = get_id(b.fst,b.snd);
        while(pos != get_id(a.fst,a.snd)){
            vis2[pos] = true;
            auto [di,dj] = vis[pos].snd;
            ll pos2 = get_id(di,dj);
            if(vis2[pos2])continue;
            auto [posi,posj] = get_ij(pos);
            if(posi<di){
                res.pb('U');
            } else if(posi>di){
                res.pb('D');
            } else if(posj<dj){
                res.pb('L');                
            } else{
                res.pb('R');
            }
            pos = get_id(di,dj);
        }
        reverse(ALL(res));
        cout << SZ(res) << "\n";
        for(auto i : res) cout << i;
        cout << "\n";

    } else{
        cout << "NO\n";
    }
}

