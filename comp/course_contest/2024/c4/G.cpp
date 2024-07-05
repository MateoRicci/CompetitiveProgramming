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

const ll MAXN = 1005;

int uf[MAXN];
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
ll kruskal(vector<vector<ll>> &g){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		int x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y)){
            r+=es[i].fst; // (x,y,c) belongs to mst
            g[x].pb(y);
            g[y].pb(x);
        }
	}
	return r; // total cost
}

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, vector<vector<ll>> &wy) {
    vis[v] = true;
    for (ll u : g[v]) {
        if (!vis[u]) {
            ll wp = v+1;
            if(wy[u][v]==0) wp = 0;
            cout << u+1 << " " << wp << "\n";
            dfs(u, g, vis,wy);
        }
    }
}



int main(){
    FIN;
    ll n,m,k,w;
	cin >> n >> m >> k >> w;

    ll t_cost1 = n*m;

    vector<vector<vector<char>>> levels(k, vector<vector<char>>(n, vector<char>(m)));

    fore(l,0,k){
        fore(i,0,n){
            fore(j,0,m){
                cin >> levels[l][i][j];
            }
        }
    }
    
    vector<vector<ll>> difs(k, vector<ll>(k, 0));

    fore(l,0,k){
        fore(p,l+1,k){
            fore(i,0,n){
                fore(j,0,m){
                    if(l!=p){
                        if(levels[l][i][j]!=levels[p][i][j]){
                            difs[l][p]++;
                            difs[p][l]++;
                        }
                    }
                }
            }
        }
    }

    vector<vector<ll>> wy(k,vector<ll>(k));

    vector<vector<ll>> g(k);
    fore(i,0,k){
        fore(j,i+1,k){
            if(i!=j){
                pair<ll,pair<ll,ll>> aux1,aux2;
                if(t_cost1 <= (difs[i][j]*w)){
                    aux1.fst = t_cost1;
                    aux2.fst = t_cost1;
                    wy[i][j] = 0;
                    wy[j][i] = 0;
                }
                else{
                    aux1.fst = difs[i][j]*w;
                    aux2.fst = difs[i][j]*w;
                    wy[i][j] = j+1;
                    wy[j][i] = i+1;
                }
                // g[i].pb(j);
                // g[i].pb(i);
                aux1.snd = {i,j};
                aux2.snd = {j,i};
                es.pb(aux1);
                es.pb(aux2);
            }   
        }
    }

    ll res = kruskal(g);
    cout << res + t_cost1 << "\n";
    
    ll prim = uf_find(0);

    cout << prim+1 << " " << 0 << "\n";

    vector<bool> vis(k);

    dfs(prim,g,vis,wy);

}