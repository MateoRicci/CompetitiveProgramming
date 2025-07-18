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

ll n,m;
ll res = 0;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis, ll cats, vector<ll> &a){
    if(a[v]) cats++;
    else cats = 0;
    // DGB(cats);
    if(cats > m) return;
    vis[v] = true;
    ll cnt = 0;
    for(auto u : g[v]){
        if(!vis[u]){
            cnt++;
            dfs(u,g,vis,cats,a);
        }
    }
    if(!cnt) res++;
}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> a(n);
        vector<vector<ll>> g(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n-1){
            ll a,b; cin >> a >> b,a--,b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<bool> vis(n);
        dfs(0,g,vis,0,a);
        show(res);
    }
}
