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
    ll t; cin >> t;
    //(a+b-1)/b
    while(t--){
        ll x,y,k; cin >> x >> y >> k;
        ll p1 = 0,p2 = 0;
        if(x>0) p1 += (x+k-1)/k;
        // DGB((x+k-1)/k);
        if(y>0) p2 += (y+k-1)/k;
        // DGB((y+k-1)/k);
        ll res = 0;
        if(p1>p2){
            res = p1*2-1;
        } else{
            res = p2 * 2;
        }
        cout << res << "\n";
    }
}
