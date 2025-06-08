#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    
    ll A = a[1] - a[0];
    ll B = 2 * a[0] - a[1];

    fore(i,0,n){
        long long expected_ai = A * (i + 1) + B;
        if (a[i] != expected_ai) {
            cout << "NO\n";
            return;
        }
    }

    if (B % (n + 1) != 0) {
        cout << "NO\n";
        return;
    }
    ll k2 = B / (n + 1);
    if (k2 < 0) {
        cout << "NO\n";
        return;
    }
    long long k1 = A + k2;
    if (k1 < 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}