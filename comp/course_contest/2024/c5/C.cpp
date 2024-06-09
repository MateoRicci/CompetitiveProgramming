
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

ll n, prim;

ll firstPrimeDivisor(ll n) { // O raiz n
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n; // n is a prime number
}



int main(){
    FIN;

    cin >> n;
    ll aux = n;
    ll res = 0;

    if((n%2) != 0){ // impar - impar = par!!!!!!!
        prim = firstPrimeDivisor(n); // el primer primo va a ser impar
        aux = aux - prim;
        res++;
    }
    res = res + (aux/2);
    cout << res << "\n";
    
    return 0;

}



