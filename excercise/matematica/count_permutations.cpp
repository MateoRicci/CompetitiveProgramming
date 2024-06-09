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

const ll MOD = 1000000007;


ll mul(ll a, ll b){
	return a*b%MOD;
}

ll fpow(ll a, ll b){ // iterativa (mas rapida)
	ll res=1;
	while(b>0){
		if(b%2==1){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD,b/=2;
	}
	return res;
}


int main(){
    FIN;
    ll t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll res = 1, fct = 1;
        fore(i,1,(2*n)+1){
            //cout << i << "\n";
            fct = mul(fct,i);
        }
        if(n>1){
            res = mul(fct,fpow(2,MOD-2)); // res/2
        }
        cout << res << "\n";
    }
    
}