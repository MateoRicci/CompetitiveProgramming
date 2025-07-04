#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
using int64 = long long;
const int64 INF = (int64)4e18;

struct DSU {
    vector<int> p, sz;
    vector<int64> best;

    DSU(int n) : p(n + 1), sz(n + 1, 1), best(n + 1, INF) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }

    void unite(int a, int b, int64 w) {
        a = find(a);
        b = find(b);
        if (a == b) {
            best[a] = min(best[a], w);
            return;
        }
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        best[a] = min({best[a], best[b], w});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        struct Edge {
            int u, v;
            int64 w;
        };

        vector<Edge> e(m);
        for (auto &ed : e) cin >> ed.u >> ed.v >> ed.w;

        sort(e.begin(), e.end(), [](auto &a, auto &b) {
            return a.w < b.w;
        });

        DSU dsu(n);
        int64 ans = INF;

        for (auto &ed : e) {
            dsu.unite(ed.u, ed.v, ed.w);
            int r = dsu.find(1);
            if (dsu.find(n) == r) {
                int64 cand = ed.w + dsu.best[r];
                ans = min(ans, cand);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}