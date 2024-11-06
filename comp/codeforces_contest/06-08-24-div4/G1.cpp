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
    // FIN;
    ll t; cin >> t;
    while(t--){
        
        ll inp;
        ll l = 1, r = 1000;
        while(l <= r){
            ll m = (l+r)/2;
            cout << "? " << 1 << " " << m << "\n";
            fflush(stdout);  
            cin >> inp;
            if(inp==-1)return 0;
            
            if(inp == m+1) r = m-1;
            else l = m+1;
        }
        cout << "! " << l << "\n";
    }
    
}

// ll a=0,b=1;
// cout << "? " << a << " " << b << "\n";
// fflush(stdout);

// Gallardo volvio a river


