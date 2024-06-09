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

vector<ll> dp(100005,-1), topo;

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

ll f(ll v, vector<vector<ll>> &g){
    if(v>=n) return 0; // border check
    if(SZ(g[v])==0) return 0; // checking no more connections
    if(dp[v]>= 0) return dp[v]; // calculated before

    for(auto u : g[v]){
        dp[v] = max(dp[v], 1 + f(u,g));
    }

    return dp[v];
}

int main(){
    FIN;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    fore(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
    }

    ll res = 0;
    fore(i,0,n){
        res = max(res,f(i,g));
    }
    cout << res << "\n";


}