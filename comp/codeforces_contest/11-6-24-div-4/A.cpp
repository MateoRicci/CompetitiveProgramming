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
            vector<char> a(3), b(3);
            fore(i,0,3){
                cin >> b[i];
            }
            fore(i,0,3){
                cin >> a[i];
            }
            cout << a[0];
            cout << b[1];
            cout <<  b[2];
            cout << " ";

            cout << b[0];
            cout << a[1];
            cout << a[2];

            cout << "\n";
    }
}
