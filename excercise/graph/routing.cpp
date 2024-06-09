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

ll INF = 1e18;
vector<ll> dijkstra(ll start, vector<vector<ii>> &g) {
    vector<ll> dist(SZ(g), INF);
    dist[start] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();


        if (d_v != dist[v])
            continue;


        for (auto [to, len] : g[v])
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
        }
    }

    return dist;
}

bool valid(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < n;
} 

ll get_id(ll i, ll j) {
    return i * n + j;
}

vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){
    FIN;
	cin >> n;
	vector<vector<char>> mat(n, vector<char>(n));
	fore(i,0,n){
		fore(j,0,n){
            cin >> mat[i][j];
        }
	}

    vector<vector<ii>> gr(n * n), gb(n * n);
    fore(i, 0, n) fore(j, 0, n) {
        for (auto [di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (valid(ni, nj) && mat[ni][nj] == 'R') {
                // cout << mat[i][j] << "\n";
                ii aux1 = {get_id(ni, nj),0}, aux2 = {get_id(i, j),0};
                gr[get_id(i, j)].pb(aux1);
                gr[get_id(ni,nj)].pb(aux2);

                aux1 = {get_id(ni, nj),1}, aux2 = {get_id(i, j),1};
                gb[get_id(i, j)].pb(aux1);
                gb[get_id(ni, nj)].pb(aux2);
            }
            else if (valid(ni, nj) && mat[ni][nj] == 'B') {
                ii aux1 = {get_id(ni, nj),1}, aux2 = {get_id(i, j),1};
                gr[get_id(i, j)].pb(aux1);
                gr[get_id(ni, nj)].pb(aux2);

                aux1 = {get_id(ni, nj),0}, aux2 = {get_id(i, j),0};
                gb[get_id(i, j)].pb(aux1);
                gb[get_id(ni, nj)].pb(aux2);
            }
        }
    }


    // fore(i,0,SZ(gr)){
    //     cout << SZ(gr[i])<< "\n";
    //     for (auto [to, len] : gr[i]){
    //         cout << to << " : " << len << "\n";
    //     }
    // }

    vector<ll> dist;
    // dijkstra 1
    dist = dijkstra(get_id(0,0),gr);
    ll cantr = dist[get_id(n-1,n-1)];
    cout << cantr << "\n";
    
    // dijstra 2

    dist = dijkstra(get_id(n-1,0),gb);
    ll cantb = dist[get_id(0,n-1)];
    cout << cantb << "\n";
}