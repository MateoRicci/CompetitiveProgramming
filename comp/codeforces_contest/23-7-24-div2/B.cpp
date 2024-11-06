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
        vector<ll> f(n);
        fore(i,0,n) cin >>f[i];

        ll res = 0;

        sort(ALL(f));
        // reverse(ALL(f));
        // me paro en esta flor,
        // veo hasta donde puedo avanzar
        // llego hasta una flor x
        // paso mi primer puntero a la primer flor dinstinta de la anterior


        ll i = 0;
        ll j = 0;
        ll val = 0;
        ll c=k;
        bool flag = false;
        while(i<n){
            if(f[j] - f[i] > 1 || flag){
                // cout << "i: " << i << " j: " << j << " c: " << c << " val: " << val << "\n";
                res = max(res,val);
                val -= f[i];
                c += f[i];
                i++;
                flag = false;
            } else{
                // cout << "i: " << i << " j: " << j << " c: " << c << " val: " << val << "\n";
                if(j>=n) break;
                if(c - f[j] >= 0){
                    val += f[j];
                    c -= f[j];
                    j++;
                } else flag = true;
            }
        }
        res = max(res,val);

        cout << res << "\n";
    }

}
