#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
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
        ll n; cin >> n;
        map<ll,ll> mp;
        ll res = 0;
        fore(i,0,n){
            ll x; cin >> x;
            if(!mp[x]){
                res++;
                mp[((1LL << 31) - 1LL) ^ x]++;
            } else mp[x]--;
        }

        cout << res << "\n";
        
    }
    
}

// Gallardo volvio a river