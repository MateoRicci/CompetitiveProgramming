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

ll n,x;

int main(){
    FIN;

    ll t; cin >> t;
    while(t--){
        cin >> n >> x;

        if(n<=2){
            cout << "1\n";
        }
        else{
            ll apart = n - 2;
            ll res = (apart/x) + 1;
            if((apart % x) != 0){
                res++;
            }
            cout << res << "\n";
        }
    }
    
    return 0;

}