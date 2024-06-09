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

int uf[200005];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<ll,ll>>> es; // edges (cost,(u,v))
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		int x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y))r+=es[i].fst; // (x,y,c) belongs to mst
	}
	return r; // total cost
}

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
    }
}

int main(){
    FIN;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    fore(i,0,m){
        pair<ll,pair<ll,ll>> aux;
        cin >> aux.snd.fst >> aux.snd.snd >> aux.fst;
        g[aux.snd.fst-1].pb(aux.snd.snd-1);
        g[aux.snd.snd-1].pb(aux.snd.fst-1);
        es.pb(aux);
    }

    vector<bool> vis(n);
    dfs(0,g,vis);
    bool can = true;
    for(auto b : vis){
        if(!b) can = false;
    }
    if(can){
        ll res = kruskal();
        cout << res << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}