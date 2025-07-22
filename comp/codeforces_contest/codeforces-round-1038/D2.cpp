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
typedef pair<ll,ll> pll;
const ll MAXN = 5005;
const ll MAXT = 3*MAXN;
const ll INF = 1e12;
ll n, m; 
vector<ll> g[MAXN];

ll f(ll i, ll t,vector<vector<ll>> &dp){
    if(t>=3*n) return INF;
    if(i==n-1){
        dp[i][t] = 0;
        return 0; // llegue
    } 
    if(dp[i][t]!=-1) return dp[i][t];
    ll k = (t % SZ(g[i]));
    dp[i][t] = min(0 + f(g[i][k],t+1,dp),1 + f(i,t+1,dp));
    return dp[i][t];
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        fore(i,0,m){
            ll a,b; cin >> a >> b, a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        vector<vector<ll>> dp(n, vector<ll>(3*n,-1));
        ll wait = f(0,0,dp);
        ll res = INF;
        fore(t,0,3*n){
            if(dp[n-1][t] == 0) res = min(res,t);
        }
        cout << res << " " << wait << "\n";
        fore(i,0,n)g[i].clear();
    }
}