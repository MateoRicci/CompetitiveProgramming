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

void bfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> &p) {
    queue<ll> q;
    vis[v] = true;
    q.push(v);
    while (!q.empty()) {

        v = q.front();
        q.pop();
        
        for (ll u : g[v]) {

            if (!vis[u]) {
				p[u] = v;
				vis[u] = true;
				q.push(u);

            }
        }
    }
}

int main(){
    FIN;
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> g(n);
	fore(i,0,m){
		ii e;
		cin >> e.fst >> e.snd;
		g[e.first-1].pb(e.snd-1);
		g[e.snd-1].pb(e.fst-1);
	}

	vector<bool> vis(n);
	vector<ll> p(n);
	p[0] = -1;
	bfs(0,g,vis,p);
	
	if(!vis[n-1]){
		cout << "IMPOSSIBLE" << "\n";
	}
	else{

		vector<ll> res;
		ll j = n-1;
		while(j != -1){
			res.pb(j+1);
			j = p[j];
		}
		reverse(res.begin(),res.end());

		ll r = res.size();

		cout << r << "\n";
		fore(i,0,r){
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}