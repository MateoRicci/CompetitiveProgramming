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

ll INF = 1e18;
vector<ll> dijkstra(ll start, vector<vector<ii>> &g) {
    vector<ll> dist(SZ(g), INF), pre(SZ(g), -1);
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
                pre[to] = v;
                pq.push({dist[to], to});
        }
    }

    return pre;
}

int main(){
    FIN;
	ll n,m;
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

    vector<ll> trace = dijkstra(0,g), res;

    ll pos = n-1;

    if(trace[pos]==-1){
        cout << -1 << "\n";
        return 0;
    }
    res.pb(pos+1);

    while(pos!=0){
        res.pb(trace[pos]+1);
        pos = trace[pos];
    }
    reverse(ALL(res));
    for(auto i : res){
        cout << i << " ";
    }
    cout << "\n";

}

