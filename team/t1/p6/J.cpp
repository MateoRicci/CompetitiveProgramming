#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    
    ll n,l,c; cin >> n >> l >> c;

    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    sort(ALL(a));
    reverse(ALL(a));
    
    ll i = 0;
    while(i<n){
        if(a[i]>c){
            cout << "N\n";
            return 0;
        }
        c = c- a[i];
        i += l;
    }
    cout << "S\n";
    

    return 0;
}

// Cueste lo que cueste el domingo tenemos que ganar