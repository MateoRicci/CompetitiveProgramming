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

ll INF = 1e10;
vector<ll> dijkstra(ll start, vector<vector<ii>> &g, ll bike, vector<ll> &s) {
    vector<ll> dist(SZ(g), INF);
    dist[start] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();
        if(bike > s[v]) bike=s[v];

        if (d_v != dist[v])
            continue;


        for (auto [to, len] : g[v]){
            if (dist[v] + len*bike < dist[to]) {
                dist[to] = dist[v] + len*bike;
                pq.push({dist[to], to});
            }

        }
    }    return dist;

}


int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll res = 0;
        n=0,m=0;
        cin >> n >> m;
        vector<vector<ii>> g(n);
        fore(i,0,m){
            pair<ll,ll> vec1,vec2;
            cin >> vec1.fst >> vec2.fst >> vec2.snd;

            vec1.fst--;
            vec2.fst--;
            vec1.snd = vec2.snd;

            g[vec1.fst].pb(vec2);
            g[vec2.fst].pb(vec1);
        }

        vector<ll> s(n);
        fore(i,0,n){
            cin >> s[i];
        }

        ll bike = s[0];

        vector<ll> dist = dijkstra(0,g,bike,s);
        ll min_dist = dist[n-1];

        fore(i,1,n){
            vector<ll> dist_temp = dijkstra(i,g,bike,s);
            if(dist_temp[n-1] + dist[i] < min_dist){
                fore(j,0,n){
                    dist[j] = min(dist_temp[j] + dist[i], dist[j]);
                }
                min_dist = dist_temp[n-1] + dist[i];
            }
        }

        res = dist[n-1];
        cout << res << "\n";
    }
}