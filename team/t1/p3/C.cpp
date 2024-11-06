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

#define MOD 998244353

int main(){
    FIN;
    ll h,w; cin >> h >> w;
    ll x = h+w;
    ll res = 1;
    while(x--){
        res = (res*2)%MOD;
    }
    cout << res << "\n";
}

// hardcodingx