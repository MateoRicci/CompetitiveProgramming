#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN = 20;
const ll MOD = 1e9 + 7;

int add(int a, int b){a+=b;return a<MOD ? a : a-=MOD;}
// int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll dp[(1 << MAXN) + 1][21];
ll n,m;

ll f(ll mask, ll estoy, vector<vector<ll>> &g){
    ll &r = dp[mask][estoy];
    if(estoy == n-1){
        if(mask == (1<<n) - 1){
            return 1;
        } else{
            return 0;
        }
    }
    if(r != -1) return r;

    r = 0;
    for(auto v : g[estoy]){
        if(!(mask & (1<<v))){
            r = add(f(mask ^ (1<<v), v,g), r);
        }
    }
    return r;
}

int main(){
    FIN;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    mset(dp,-1);
    fore(i,0,m){
        ll a,b;cin >> a >> b,a--,b--; g[a].pb(b);
    }
    ll res = f(1,0,g);
    // cout << dp[1][0] << "\n";
    cout << res%MOD << "\n";
}
