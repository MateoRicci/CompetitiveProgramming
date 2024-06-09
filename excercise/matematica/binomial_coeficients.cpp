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

const ll MAXN=1e6+5;
ll fc[MAXN],fci[MAXN];

void factoriales(){
	fc[0]=1;
	fore(i,1,MAXN)fc[i]=mul(fc[i-1],i);
	fci[MAXN-1]=fpow(fc[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}

ll comb(ll n, ll k){
	return mul(fc[n],mul(fci[k],fci[n-k]));
}



int main(){
    FIN;
    ll t;
    cin >> t;
    factoriales();
    while(t--){
        ll a,b; cin >> a >> b;

        ll res = comb(a,b);
        cout << res << "\n";
    }

}