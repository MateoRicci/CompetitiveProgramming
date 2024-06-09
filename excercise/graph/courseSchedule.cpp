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

vector<ll> topoSort(vector<vector<ll>>& g) {
	vector<ll> indeg(SZ(g)), ret;
	for (auto& li : g) for (ll x : li) indeg[x]++;
	queue<ll> q; // use priority_queue for lexic. largest ans.
	fore(i,0,SZ(g)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		ll i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (ll x : g[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}

int main(){
    FIN;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    fore(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
    }

    vector<ll> topo;
    topo = topoSort(g);
    
    if(SZ(topo)!=n){
        cout << "IMPOSSIBLE\n";
    }else{
        bool check = true;
        vector<ll>pos(n);
        //fore(i,0,n) pos[topo[i]] = i;
        // for (ll v = 0; v < SZ(g); ++v) {
        //     for (ll u : g[v]) {
        //         if (pos[v] >= pos[u]) {
        //             check = false;
        //         }
        //     }
        // }

        if(!check){
            cout << "IMPOSSIBLE\n";
        }
        else{
            for(auto k : topo){
                cout << k+1 << " ";
            }
            cout << "\n";
        }
    }

}