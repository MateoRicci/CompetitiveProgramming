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
    ll a,b,c,d; cin >> a >> b >> c >> d;


    if(a+b==c+d) cout << "YES\n";
    else if(a+c==b+d) cout << "YES\n";
    else if(a+d==c+b) cout << "YES\n";
    else if(a==b+c+d) cout << "YES\n";
    else if(b==a+c+d) cout << "YES\n";
    else if(c==a+b+d) cout << "YES\n";
    else if(d==a+b+c) cout << "YES\n";
    else cout << "NO\n";
}

// hardcoding