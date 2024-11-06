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
        ll n,k; cin >> n >> k;
        vector<ii> f(n);
        vector<ll> mxp(n);
        fore(i,0,n) cin >>f[i].fst; // petalos
        fore(i,0,n) cin >>f[i].snd; // cantidad
        sort(ALL(f));

        // a cada petalo le asigno la cantidad maxima que puedo usar
        fore(i,0,n){
            mxp[i] = min(k/f[i].fst,f[i].snd);
        }
        ll res = 0;
        fore(i,0,n){
            res = max(res,mxp[i]*f[i].fst);
            ll rest = k - mxp[i]*f[i].fst;
            if(i!=n-1){
                if(f[i].fst+1 == f[i].fst){
                    ll maxi = max(rest/f[i+1].fst,f[i+1].snd); // veo cuantas de la siguiente flor puedo sumar
                    ll ax = mxp[i]*f[i].fst + maxi*f[i+1].fst;
                    // tengo que ver si me conviene quitar de mi flor actual para sumar mas
                    ll rest2 = k - ax;
                    ll res_aux = min({rest2,mxp[i],f[i+1].snd-maxi});
                    res = max(res,res_aux+ax);
                }
            }
        }
        

        cout << res << "\n";
    }

}


