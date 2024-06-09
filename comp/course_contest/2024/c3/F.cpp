
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

ll d(ll x, ll r){
    return (x+((3-r)%3))/3;
}

int main(){
    FIN;
    ll q;
    cin >> q;
    while(q--){

        ll w,f,n;
        cin >> w >> f >> n;
        ll sum_s = 0;
        vector<ll>s(n);
        fore(i,0,n){
            cin >> s[i];
            sum_s += s[i];
        }

        vector<bool> dp(sum_s+1);
        dp[0] = true;

        fore(i,0,n){
            for (int w = sum_s; w - s[i] >= 0; --w) {
                dp[w] = dp[w] || dp[w - s[i]];
            }
        }

        ll res = 10e9;
            for (int i = 0; i <= sum_s; ++i) {
                if (dp[i]) {
                    res = min(res, max((i + w - 1) / w, (sum_s - i + f - 1) / f));
                }
            }
            cout << res << "\n";
    }

}