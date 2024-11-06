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
        ll a1,a2,b1,b2; cin >> a1 >> a2 >> b1 >> b2;

        vector<vector<ll>> rounds(4);
        rounds[0] = {a1,b1,a2,b2};
        rounds[1] = {a1,b2,a2,b1};
        rounds[2] = {a2,b1,a1,b2};
        rounds[3] = {a2,b2,a1,b1};
        ll res = 0;

        fore(cse,0,4){
            ll sunset_score = 0;
            ll slavic_score = 0;
        
            if(rounds[cse][0] > rounds[cse][1]) sunset_score++;
            else if(rounds[cse][0] < rounds[cse][1]) slavic_score++;
        
            if(rounds[cse][2] > rounds[cse][3]) sunset_score++;
            else if(rounds[cse][2] < rounds[cse][3]) slavic_score++;   

            if(sunset_score > slavic_score) res++;         
        }

        cout << res << "\n";
    }
    
}

// Gallardo volvio a river


