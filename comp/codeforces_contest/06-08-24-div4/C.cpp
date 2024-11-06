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
        ll n,s,m; cin >> n >> s >> m;
        set<ii> ts;
        fore(query,0,n){
            ll l,r; cin >> l >> r;
            ts.insert({l,r});
        }
        bool flag = false;
        ll pos = 0;
        fore(check,0,n){

            auto it = ts.begin();
            ii k = *it;
            if((k.fst-pos) >= s){
                flag = true;
                break;
            } else{
                pos = k.snd;
                ts.erase(it);
            }
        }
        if(m - pos >= s) flag = true;

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    
}

// Gallardo volvio a river