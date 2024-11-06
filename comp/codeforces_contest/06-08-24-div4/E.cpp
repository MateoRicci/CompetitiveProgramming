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
        ll l,r; cin >> l >> r;
        ll p = log2(l) / log2(3);
        p++; // round
        ll res = (2*p);
        while(r>l){
            ll aux = log2(r) / log2(3);
            ll q = pow(3,aux);
            ll c = r - max(q,l+1);
            res += (aux+1) * (c+1);
            r = q-1;
        }
        cout << res << "\n";
    }
    
}

// Gallardo volvio a river