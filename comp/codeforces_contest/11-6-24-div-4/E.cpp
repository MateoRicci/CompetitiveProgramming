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
        ll x,y,z,k;
        cin >> x >> y >> z >> k;

        ll res = 0;

        for(ll a = 1; a <= x; a++){
            for(ll b = 1; b <= y; b++){
                if(k % (a*b)) continue;
                ll c = k / (a*b);
                if(c > z) continue;
                ll pos = (ll)((x-a+1)*(y-b+1)*(z-c+1));
                res = max(res,pos);
            }
        }

        cout << res << "\n";
    }
}
