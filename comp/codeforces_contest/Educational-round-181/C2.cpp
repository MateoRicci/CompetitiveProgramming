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
        ll l,r; cin >> l >> r;
        ll res = 0;

        // calculo para 2
        res += (r/2) - ((l-1)/2);

        // calculo para 3, sin contar las de 2?
        res += (r/3) - ((l-1)/3);
        res -= (r/6) - ((l-1)/6);

        // calculo para 5
        res += (r/5) - ((l-1)/5);
        res -= (r/10) - ((l-1)/10);
        res -= (r/15) - ((l-1)/15);
        res += (r/30) - ((l-1)/30);

        //calculo para 7
        res += (r/7) - ((l-1)/7);

        res -= (r/14) - ((l-1)/14);
        res -= (r/21) - ((l-1)/21);
        res -= (r/35) - ((l-1)/35);

        res += (r/42) - ((l-1)/42);
        res += (r/70) - ((l-1)/70);
        res += (r/105) - ((l-1)/105);

        res -= ((r/210) - ((l-1)/210));

        cout << (r-l+1) - res << "\n";
    }
}
