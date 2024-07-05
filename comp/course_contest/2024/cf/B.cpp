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


int main(){
    FIN;
    ll t; cin >> t;
    
    while(t--){
        ll n;
        cin >> n;
        string logp;
        cin >> logp;

        // ll x = 'A' - 64;
        // cout << x << "\n";

        ll res = 0;

        vector<ll> words(26,0);
        fore(i,0,n){
            ll x = logp[i] - 65;
            // cout << x << " ";
            words[x]++;
        }
        // cout << "\n";
        fore(i,0,26){
            // cout << words[i] << " ";
            if(words[i] >= i+1){
                res++;
            }
        }

        cout << res << "\n";
    }
    
    return 0;

}

