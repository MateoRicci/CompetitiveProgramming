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

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        ll x,y;
        cin >> x >> y;
        // x = s(n), y = s(n+1)
        // s(n+1)  = s(n) + 1 - 9k (k consecutives 9)
        // y = x + 1 - 9k
        // y - x -1 = -9k
        // (y-x-1)/-9 = k => resto - 0?
        if((x+1-y) % 9 == 0 && ((x+1-y) / (9)) >= 0){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

}