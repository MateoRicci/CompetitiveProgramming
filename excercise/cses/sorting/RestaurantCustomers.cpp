#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
	ll t = 1;
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ii> q;
        fore(i,0,n){
            ll q1,q2; cin >> q1 >> q2;
            q.pb({q1,1});
            q.pb({q2,-1});
        }
        sort(ALL(q));
        ll res = 0;
        ll act = 0;
        for(auto [a,b] : q){
            act += b;
            res = max(res,act);
        }
        cout << res << "\n";
    }
}