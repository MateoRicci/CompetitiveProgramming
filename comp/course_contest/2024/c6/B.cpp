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
    map<char,ll> m;
    char l = 'a';
    fore(i,1,27){
        m[l] = i;
        l = l + 1;
        // cout << l << "\n";
    }
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll res = 0;
        for(auto c : s) res = max(res,m[c]);
        cout << res << "\n";
    }

}