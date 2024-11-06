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

// max x respect n = x/2 * x/2 + 1
int main(){
    FIN;

    vector<ll> dp(100005);
    dp[0]=0;dp[1]=0;dp[2]=0;
    fore(i,3,100005){
        dp[i] = ((i-1)*(i-2))/2 + dp[i-1];
    }


    ll t; cin >> t;
    while(t--){
        ll n,x; cin >> n >> x;
        ll res = 0;
        if(n<3 || x < 3) cout << res << "\n";
        else if(((x/2)*(x/2)+1)<=n){
            ll res = dp[x];
            cout << res << "\n";
        } else{
            ll max_n = floor(sqrt(n)) + 1;
            cout << max_n << "\n";
            cout << dp[n-3] << "\n";
        }   
    }
}
