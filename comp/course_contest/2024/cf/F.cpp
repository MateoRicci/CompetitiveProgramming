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

ll n;
ll dp[300005][2];
ll a[300005];

ll f(ll x,ll t){
    if(x>=n) return 0; // border
    if(dp[x][t]>=0) return dp[x][t]; // pre-calculated

    ll poke;

    // t=0 sumar t=1 restar
    if(t==0){
        poke = a[x];
        // dp[x][t] = max((poke - f(x+1, 1-t)), f(x+1, t)); // max entre sumarlo y buscar el proximo a restar y pasar al que sigue
    }else{
        poke = - a[x];
        // dp[x][t] = max((poke + f(x+1, 1-t)), f(x+1, t)); // max entre restarlo y buscar el proximo a sumar y pasar al siguiente
    }

    dp[x][t] = max((f(x+1,1-t) + poke), f(x+1,t));

    return dp[x][t];
}



int main(){
    FIN;

    ll t; cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        ll cer;
        cin >> n >> cer;
        fore(i,0,n){
            cin >> a[i];
        }
        ll res = f(0,0);

        // fore(i,0,n){
        //     cout << dp[i][0] << " " << dp[i][1] << "\n";
        // }

        cout << res << "\n";

    }

}

