#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        vector<ll> w(n);
        fore(i,0,n) cin >> w[i];
        vector<ll> ps(n+1);
        ps[0] = w[0];
        fore(i,1,n) ps[i] = w[i] ^ ps[i-1];

        vector<vector<ll>> dp(n,vector<ll>(32,0));
        fore(i,0,n){
            if(i>0) dp[i] = dp[i-1];
            dp[i][__lg(w[i])] = i; // __lg me devuelve el bms
            dfore(j,30,0){ // dfore pq el bms cubre al resto
                dp[i][j] = max(dp[i][j],dp[i][j+1]);
            }
            // showAll(dp[i]);
        }

        while(q--){
            ll x; cin >> x;
            
            ll pos = n-1;
            while( pos >= 0 && x > 0){
                ll bms = __lg(x);
                ll next = dp[pos][bms]; // proxima posicion con el bms igual o mayor que el mio
                x ^= ps[pos] ^ ps [next]; // calculo el nuevo valor de x
                pos = next; // me muevo
                if(w[pos] > x) break;
                x ^= w[pos];
                pos--;
                if(pos < 0) break;
            }

            cout << n - (pos+1) << " ";
            
        }
        cout << "\n";
        

    }
/*
1
1 1
5
6
*/
}