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
        string a,b;
        cin >> a;
        cin >> b;


        // vector<ll> s;
        ll res = SZ(a) + SZ(b);
        ll p1;
        fore(i,0,SZ(b)){
            p1 = i;
            fore(j,0,SZ(a)){
                if(p1 < SZ(b) && a[j] == b[p1]) p1++;
            }
            res = min(res, SZ(a) + SZ(b) - p1 + i); // total a + total b - end of subsequence + start of subsequence
        }

        cout << res << "\n";

    }   
}
