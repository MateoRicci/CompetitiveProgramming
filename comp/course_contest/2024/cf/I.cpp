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

const ll MAXN = 200005;


ll uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<ll,ll> > > es; // edges (cost,(u,v))
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		ll x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y))r+=es[i].fst; // (x,y,c) belongs to mst
	}
	return r; // total cost
}

ll cant = 1;
void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            cant++;
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
        ll k,c; 
        cin >> k >> c;
        vector<ll> a(k);
        fore(i,0,k){
            cin >> a[i];
            a[i]--;
            if(i>0){
                es.pb({c,{a[i],a[i-1]}});
                es.pb({c,{a[i-1],a[i]}});
                g[a[i]].pb(a[i-1]);
                g[a[i-1]].pb(a[i]);
            }
        }
    }

    vector<bool> vis(n,false);
    
    dfs(0,g,vis);

    if(cant != n){
        cout << -1  << "\n";
    }
    else{
        ll res = kruskal();
        cout << res << "\n";
    }

}
