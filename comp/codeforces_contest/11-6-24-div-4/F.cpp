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
        ll h, n; cin >> h >> n;
        vector<ii> a(n);
        fore(i,0,n) cin >> a[i].fst;
        fore(i,0,n) cin >> a[i].snd;
        set<ii> s;
        for(int i = 0; i < n; i++){
			s.insert({1, i});
		}
        ll res = 1;
        while(h>0){
            auto [turn, i] = *s.begin();
            s.erase(s.begin());
            res = turn;
            h -= a[i].fst;  
			s.insert({turn + a[i].snd, i});
        }

        cout << res << "\n";
    }
}
