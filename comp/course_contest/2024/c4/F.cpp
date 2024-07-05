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

const ll MAXN = 1000005;

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


int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll res = 1e18;
        n=0,m=0;
        cin >> n >> m;
        vector<vector<ii>> g(MAXN);
        vector<ll> u(m),v(m),w(m);
        fore(i,0,m){
                cin >> u[i] >> v[i] >> w[i];
                u[i]--; v[i]--;
        }

        vector<ll> s(n);
        fore(i,0,n){
            cin >> s[i];
        }

        // crear grafo auxiliar a partir de los valores obtenidos
        fore(i,0,m){ // bucle para las conexiones
            fore(j,0,n){ // bucle para las bicicletas
                g[n*u[i] + j].pb({n * v[i] + j,w[i] * s[j]});
                g[n*v[i] + j].pb({n * u[i] + j,w[i] * s[j]});
            }
        }

        fore(i,0,n){
            fore(j,0,n){
                if(i!=j){ // si no es el mismo nodo
                    // comparacion y de los caminos de las bicicletas
                    g[n*i + j].pb({n*i + i, 0}); // conecto todos los caminos con coste 0, que seria cambiar de bicicletas
                }
            }
        }

        vector<ll> dist(n*1000);

        dist = dijkstra(0,g);

        fore(i,0,n){
            res=min(res,dist[n*(n-1)+i]);
        }

        cout << res << "\n";
    }
}
