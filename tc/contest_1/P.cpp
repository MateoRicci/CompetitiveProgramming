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
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ii> trace;
ll n;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, ll c){
    vis[v] = true;
    trace.pb({v,c});
    if(SZ(g[v])==1){
        ll a = g[v][0];
        if(!vis[a]){
            dfs(a,g,vis,1-c);
        }
    } else{
        ll a = g[v][0];
        ll b = g[v][1];
        if(a==v){
            if(!vis[a]){
                dfs(a,g,vis,1-c);
            }

            if(!vis[b]){
                dfs(b,g,vis,1-c);
            }
        } else{
            if(!vis[b]){
                dfs(b,g,vis,1-c);
            }

            if(!vis[a]){
                dfs(a,g,vis,1-c);
            }
        }
    }
    return;
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> a1(n),a2(n);
        vector<ll> counters(n);
        fore(i,0,n) {cin >> a1[i]; a1[i]--;counters[a1[i]]++;}
        fore(i,0,n) {cin >> a2[i]; a2[i]--; counters[a2[i]]++;}
        bool valid = true;
        fore(i,0,n){
            if(counters[i]!=2) valid = false;
        }
        if(!valid){
            show(-1);
        } else{
            vector<ii> aps(n,{-1,-1});
            fore(i,0,n){
                if(aps[a1[i]].fst==-1) aps[a1[i]].fst= i;
                else aps[a1[i]].snd = i;
            }
            fore(i,0,n){
                if(aps[a2[i]].fst==-1) aps[a2[i]].fst=n + i;
                else aps[a2[i]].snd = n + i;
            }
            // fore(i,0,n){
            //     cout << aps[i].fst << " " << aps[i].snd << "\n";
            // }
            vector<vector<ll>> g(2*n);
            fore(i,0,n){
                g[i].pb(n + i);
                g[i+n].pb(i);
            }
            vector<bool> marked(2*n);
            fore(i,0,n){
                if(marked[aps[i].fst]);
                marked[aps[i].fst] = true;
                marked[aps[i].snd] = true;
                if(g[aps[i].fst][0] != aps[i].snd){
                    g[aps[i].fst].pb(aps[i].snd);
                    g[aps[i].snd].pb(aps[i].fst);
                }
            }

            ll res = 0;
            ll res2 = 0;
            vector<ll> rec;
            vector<bool> vis(2*n);
            fore(i,0,2*n){
                if(vis[i]) continue;
                trace.clear();
                ll c = 0;
                dfs(i,g,vis,0);
                ll c0=0,c1=0;
                for(auto [v,c] : trace){
                    if(v>=n){
                        if(c==0) c0++; // cuento los colores 0 que aparecen
                        else c1++; // cuento los colores 1 que aparecen
                    }
                    // DGB(c0);
                    // DGB(c1);
                    // DGB(res);
                }
                if(c0<=c1){
                    res += c0;
                    for(auto [v,c] : trace){
                        if(v>=n){
                            if(c == 0){
                                // show("Pusheo1");
                                rec.pb((v-n)+1);
                            }
                        }
                    }
                } else{
                    res += c1;
                    for(auto [v,c] : trace){
                        if(v>=n){
                            if(c == 1){
                                // show("Pusheo2");                            
                                rec.pb((v-n)+1);
                            }
                        }
                    }
                }
                // for(auto [v,c] : trace) cout << v << " ";
                // show("");
            }
            show(res);
            for(auto e : rec) cout << e << " ";
            cout << "\n";
        }
    }
}