#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<pair<ll,ll>> factorizar(ll n){
    vector<pair<ll,ll>> res;
    for(ll p=2; p*p <= n; p++){
    ll k=0;
        while(n%p==0){
            k++;
            n/=p;
        }
        if(k>0)res.push_back({p,k});
    }
    if(n>1)res.push_back({n,1});
    return res;
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> factos = factorizar(n);
        ll res = 1;
        for(auto [p,k] : factos){
            res *= 2*k + 1;
        }
        res = (res+1)/2;
        cout << res << "\n";
    }
}