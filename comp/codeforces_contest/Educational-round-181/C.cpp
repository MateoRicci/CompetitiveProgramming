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
        // solo tengo que ver cuantos numeros multiplos de 2,3,5,7 hay en el rango
        ll res = 0;
        //primero le sumo los de 2

        ll sumar = 0;
        if(l % 2 == 0) res++;
        else l--,sumar++;
        ll k = r-l;
        res += k/2;
        l+=sumar;

        // ahora buscamos los de 3, y le sacamos los que comparten con 2
        if(l%3==0) res++;
        else{
            while(l%3) l--,sumar++;
        }
        k = r-l;
        res += k/3;
        res -= k/6;
        l+=sumar;

        // vamos con 5
        if(l%5==0) res++;
        else{
            while(l%5) l--,sumar++;
        }
        k = r-l;
        res += k/5;
        // le resto los de 2 y los de 3, y le sumo los de 3 y 5
        res -= k/10;
        res -= k/15;
        res += k/30;
        l+=sumar;

        // y ahora con el 7
        if(l%7==0) res++;
        else{
            while(l%7) l--,sumar++;
        }
        k = r-l;
        res += k/7;

        res -= k/14;
        res -= k/21;
        res -= k/35;

        res += k/42;
        res += k/70;
        res += k/105;

        res -= (k/210);
        l += sumar;

        cout << (r-l) - res << "\n";
    }
}
