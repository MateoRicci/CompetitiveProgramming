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

ll solve(ll p, ll a, ll b){
    ll res = 0, bb = b;
    while(bb<a){
        bb *= bb;
        res++;
    }
    if(res==0){ // => b >= a
        while(bb>a){
            bb = ll(sqrtl(bb));
            res--;
        }
        if(bb<a) res++;//precision fix
    }

    return max(0LL, p + res); // res positivo, le sumo la potencia del anterior, res negativo, el max entre 
}

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n), bs(n,0);
        fore(i,0,n) cin >> a[i];

        ll res = 0;
        
        ll i = 1;
        while(i<n){
                if(a[i]==1 && a[i-1] != 1){
                    res = -1;
                    break;
                } else{
                    ll aux = solve(bs[i-1],a[i-1],a[i]);
                    bs[i] = aux;
                    res+=aux;
                    i++;
                }
        }
        

        cout << res << "\n";
    }
   


}
