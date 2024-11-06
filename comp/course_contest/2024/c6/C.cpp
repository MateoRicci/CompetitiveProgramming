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
        string s; cin >> s;
        ll res = LONG_LONG_MAX;
        ll cap = 0, uap = 0;
        for(auto c : s){
            if( c =='0') cap++;
            else uap++;
        }

        ll acap = 0, auap = 0;
        for(auto c : s){
            if( c =='0') acap++;
            else auap++;

            ll aux1 = (cap - acap) + auap;
            ll aux2 = (uap - auap) + acap;
            res = min(res,min(aux1,aux2));

        }
    
        
        cout << res << "\n";

    }

}