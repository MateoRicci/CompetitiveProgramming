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
        vector<vector<ll>> a(n,vector<ll>(n));
        fore(i,0,n){
            string line; cin >> line;
            fore(j,0,n){
                a[i][j] = line[j] - '0';
            }
        }

        ll f = n/k;
        vector<vector<ll>> res(f,vector<ll>(f));
        for(ll i = 0; i<n;i+=k){
            for(ll j = 0; j<n;j+=k){
                ll p1 = i/k;
                ll p2 = j/k;
                res[p1][p2] = a[i][j];
            }
        }
        
        fore(i,0,f){
            fore(j,0,f){
                cout << res[i][j];
            }
            cout<<"\n";
        }
    }
}
