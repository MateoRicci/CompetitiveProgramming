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
    ll n; cin >> n;
    set<string> names;
    fore(i,0,n){
        ll aux = SZ(names);
        string nam; cin >> nam;
        names.insert(nam);
        if(aux==SZ(names)) cout << "YES\n";
        else cout << "NO\n";
    }


}