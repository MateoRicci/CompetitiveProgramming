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
typedef pair<ll,ll> pll;

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll a,b,k;
        cin >> a >> b >> k;
        if(k >= a && k >= b){
            cout << "1\n";
        } else if(gcd(a,b) != 1){
            // tengo que ver que pueda usar todo lo que queda
            ll h = gcd(a,b);
            a /= h, b /= h;
            if(a>b) swap(a,b);
            while(gcd(a,b)!=1){
                h = gcd(a,b);
                a /= h, b /= h;
            }
            if(b>k) cout << "2\n";
            else cout << "1\n";
        } else{
            cout << "2\n";
        }
    }
}
