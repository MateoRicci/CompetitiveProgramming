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

ll prod(string &a){
    ll res = 1;
    if(SZ(a)==0) return 0;
    fore(i,0,SZ(a)) if(a[i]!='0')res *= (a[i]-'0');
    return res;
}


int main(){
    FIN;
    string n; cin >> n;
    ll res = 1;
    for(ll i = SZ(n)-1; i>0; i--){
        string k = n;
        k[i] = '9';
        if(k[i-1]!='0') k[i-1]--;

        // cout << "n: " << n << " k: " << k << "\n";
        // cout << prod(n) << " " << prod(k) << "\n";
        if(prod(n) < prod(k)) n = k;
    }
  
    res = prod(n);
    cout << res << "\n";
}

// Gallardo vuelve a river