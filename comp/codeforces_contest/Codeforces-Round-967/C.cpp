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
        ll n,q; cin >> n >> q;
        vector<char> a(n),b(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) cin >> b[i];

        //creamos el arreglo para las querys
        vector<vector<ll>> f1(n+1,vector<ll>(26,0)),f2(n+1,vector<ll>(26,0));
        fore(i,1,n+1){
            ll x,y;
            x = a[i-1] - 'a';
            y = b[i-1] - 'a';
            f1[i][x]++; // sumo la actual
            f2[i][y]++; // sumo la acutal
            // cout << "DIFS N" << i << "\n";
            fore(j,0,26){ // sumo las anteriores
                f1[i][j]+= f1[i-1][j];
                f2[i][j]+= f2[i-1][j];
                // cout << "f1: " << f1[i][j] << " f2: " << f2[i][j] << "\n";
            }
        }

        while(q--){
            ll l,r; cin >> l >> r;
            ll dif = 0;
            
            fore(i,0,26){
                dif += abs((f1[r][i] - f1[l-1][i]) - (f2[r][i] - f2[l-1][i]));
            }
            ll res = dif/2;
            cout << res << "\n";
        }

    }
}

