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
typedef int ll;
typedef pair<ll,ll> pll;
const ll INF = 1e8;
ll n, m; 
ll mt;

ll f(ll i, ll t,vector<vector<ll>> &dp, vector<vector<ll>> &g){
    if(t>=2*n) return INF;
    if(i>=n-1) return 0; // llegue
    if(dp[i][t]!=-1) return dp[i][t];
    ll k = (t % SZ(g[i]));
    ll a = f(g[i][k],t+1,dp,g);
    ll b = f(i,t+1,dp,g);
    ll res = INF;
    if(a < INF) res = min(res, (ll)(1 + a));
    if(b < INF) res = min(res, (ll)(1 + b));
    dp[i][t] = res;
    return dp[i][t];
}

// como se que llego como minimo en mt
ll f2(ll i, ll t, vector<vector<ll>> &dp, vector<vector<ll>> &g){
    if(t>mt) return INF;
    if(i>=n-1) return 0;
    if(dp[i][t]!=-1) return dp[i][t];
    ll k = (t % SZ(g[i]));
    ll a = f2(g[i][k],t+1,dp,g);
    ll b = f2(i,t+1,dp,g);
    ll res = INF;
    if(a < INF) res = min(res, (ll)a);
    if(b < INF) res = min(res, (ll)(1 + b));
    dp[i][t] = res;
    return dp[i][t];
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<ll>> g(n+5);
        fore(i,0,m){
            ll a,b; cin >> a >> b, a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<vector<ll>> dp(n, vector<ll>(2*n + 5,-1));
        ll res = f(0,0,dp,g);
        mt = res;
        fore(i,0,n) fore(j,0,2*n) dp[i][j] = -1;
        ll wait = f2(0,0,dp,g);
        cout << res << " " << wait << "\n";
    }
}
