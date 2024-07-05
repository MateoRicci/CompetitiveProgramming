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
        ll n;cin >> n;
        vector<ll> a(n);
        ll mults = 1;
        ll cant = 0;
        fore(i,0,n){
            cin >> a[i];
            mults *= a[i];
            ll aux = a[i];
            while(aux%2==0){
                cant++;
                aux /= 2;
            }
        } 

        // cant tiene la cantidad de 2, cant = k tengo 2^k, k >= n?
        ll res = -1;
        if(cant>=n){
            res = 0;
            cout << res << "\n";
        }else{

            ll falt = n - cant;
            // cout << "F1: " << falt << "\n";

            vector<ll> divs2;
            for(ll i = n; i > 0; i--){
                // cout << "i: " << i << "\n";
                if(i%2==0){
                    // cout << "entra\n";
                    
                    ll aux = i;
                    ll aux2 = 0;
                    while(aux%2==0){
                        aux2++;
                        aux /= 2;
                    }
                    divs2.pb(aux2);
                }
            }
            sort(ALL(divs2));
            reverse(ALL(divs2));
            // cout << "F2: " << falt << "\n";

            ll i = 0;
            ll muls = 0;

            while(i<SZ(divs2) && falt > 0){
                muls++;
                falt -= divs2[i];
                i++;
            }

            if(falt <= 0){
                res = muls;
                cout << res << "\n";
            }
            else{
                res = -1;
                cout << res << "\n";
            }
        }

    }

}

