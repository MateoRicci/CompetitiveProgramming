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
        ll n; cin >> n;
        vector<ll> a(n);
        fore(i,0,n) cin >> a[i];
        map<ll,ll> mp;
        fore(i,0,n){
            mp[a[i]]++;
        }
        ll res = 0;
        fore(i,0,n+1) res = max(res,mp[i]);
        cout << n - res << "\n";
    }
}
